import sys
import time
from itertools import combinations

import requests


def get_artist_data(artist_id):
    while True:
        try:
            response = requests.get(f"https://api.discogs.com/artists/{artist_id}")
            response.raise_for_status()
            data = response.json()

            if not data.get("groups"):
                print(f"Jedno z podanych ID ({artist_id}) nie jest artystą zespołowym.")
                sys.exit(1)

            return data
        except requests.exceptions.HTTPError as e:
            if response.status_code == 429:
                print(f"Przekroczono limit zapytań. Powtarzam za 5 sekund...")
                time.sleep(5)
            else:
                print(
                    f"Nie udało się pobrać danych dla artysty o ID: {artist_id} (HTTP {response.status_code})"
                )
                sys.exit(1)
        except requests.exceptions.RequestException as e:
            print(f"Błąd podczas pobierania danych dla artysty o ID: {artist_id}: {e}")
            sys.exit(1)


def get_common_bands(artists):
    artist_data = {}

    for artist_id in artists:
        data = get_artist_data(artist_id)
        artist_data[artist_id] = {
            "name": data["name"],
            "bands": {
                member["id"]: member["name"] for member in data.get("groups", [])
            },
        }

    common_bands = {}

    for size in range(len(artists), 1, -1):
        for subset in combinations(artists, size):
            subset_bands = set(artist_data[subset[0]]["bands"].keys())

            for artist_id in subset[1:]:
                subset_bands.intersection_update(artist_data[artist_id]["bands"].keys())

            for band_id in subset_bands:
                band_name = artist_data[subset[0]]["bands"][band_id]

                if band_name not in common_bands:
                    common_bands[band_name] = []

                common_bands[band_name].append(
                    {artist_id: artist_data[artist_id]["name"] for artist_id in subset}
                )

    final_common_bands = {}

    for band_name, members_list in common_bands.items():
        filtered_members_list = []

        for members in members_list:
            if not any(
                set(members).issubset(set(other_members))
                for other_members in filtered_members_list
            ):
                filtered_members_list.append(members)

        final_common_bands[band_name] = filtered_members_list

    return final_common_bands


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Podaj co najmniej jeden identyfikator artysty.")
        sys.exit(1)

    artist_ids = list(set(sys.argv[1:]))
    final_common_bands = get_common_bands(artist_ids)

    if final_common_bands:
        for band_name in sorted(final_common_bands.keys()):
            print(f"Zespół: {band_name}")

            for members in final_common_bands[band_name]:
                for artist_id, artist_name in members.items():
                    print(f" - {artist_name}")
    else:
        print("Brak wspólnych zespołów dla dowolnych kombinacji artystów.")

    sys.exit(0)
