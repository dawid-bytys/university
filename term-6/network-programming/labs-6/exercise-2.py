import requests
import sys


def check_website(url, expected_content):
    try:
        response = requests.get(url, timeout=10)
        if response.status_code != 200:
            return False

        content_type = response.headers.get("Content-Type", "")
        if "text/html" not in content_type:
            return False

        if expected_content not in response.text:
            return False

        return True
    except requests.RequestException as e:
        return False


def main():
    url = "http://th.if.uj.edu.pl/"
    expected_content = "Institute of Theoretical Physics"

    if check_website(url, expected_content):
        print("Strona działa poprawnie.")
        sys.exit(0)
    else:
        print("Strona nie działa poprawnie.")
        sys.exit(1)


if __name__ == "__main__":
    main()
