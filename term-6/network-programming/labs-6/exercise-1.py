import sys
import requests


def fetch_server_header(url, port):
    try:
        if port == 80:
            response = requests.get(f"http://{url}", timeout=5)
        elif port == 443:
            response = requests.get(f"https://{url}", timeout=5)
        else:
            return "Nieprawidłowy port."

        return response.headers.get("Server", "Nagłówek Server nie został znaleziony.")
    except requests.RequestException as e:
        return f"Error: {str(e)}"


def main():
    if len(sys.argv) < 2:
        print("Podaj przynajmniej jedną nazwę domeny.")
        sys.exit(1)

    for website in sys.argv[1:]:
        server_http = fetch_server_header(website, 80)
        server_https = fetch_server_header(website, 443)
        print(f"{website} - port 80: {server_http}")
        print(f"{website} - port 443: {server_https}")


if __name__ == "__main__":
    main()
