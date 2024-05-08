import datetime
import sys

import requests
from bs4 import BeautifulSoup


def get_html(url):
    response = requests.get(url)

    if response.status_code != 200:
        print(f"Failed to fetch data from {url}")
        sys.exit(1)

    return response.text


def get_temp(soup):
    temp_element = soup.find("span", class_="tab-temp-high")
    return temp_element["data-value"]


def get_sunrise(soup):
    sibling_element = soup.find("span", {"aria-label": "Sun rise."})
    return sibling_element.find_next("time").text


def get_sunset(soup):
    sibling_element = soup.find("span", {"aria-label": "Sun set."})
    return sibling_element.find_next("time").text


if __name__ == "__main__":
    current_date = datetime.datetime.now().date()
    url = (
        f"https://www.metoffice.gov.uk/weather/forecast/u2yhfsccj#?date=${current_date}"
    )
    html = get_html(url)
    soup = BeautifulSoup(html, "html.parser")

    current_temp = get_temp(soup)
    sunrise = get_sunrise(soup)
    sunset = get_sunset(soup)

    print(f"Current temperature: {current_temp}°C")
    print(f"Sunrise: {sunrise}")
    print(f"Sunset: {sunset}")

    sys.exit(0)
