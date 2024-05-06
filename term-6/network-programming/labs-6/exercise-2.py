import aiohttp
import asyncio
import sys


async def check_website(url, expected_string):
    try:
        timeout = aiohttp.ClientTimeout(total=10)

        async with aiohttp.ClientSession(timeout=timeout) as session:
            async with session.get(url) as response:
                if response.status != 200:
                    print(f"Błąd: Oczekiwano statusu 200, otrzymano {response.status}")
                    return False

                content_type = response.headers.get("Content-Type", "")
                if "text/html" not in content_type:
                    print(
                        f"Błąd: Oczekiwano typu zawartości text/html, otrzymano {content_type}"
                    )
                    return False

                text = await response.text()
                if expected_string not in text:
                    print(f"Błąd: Nie znaleziono oczekiwanego ciągu znaków na stronie.")
                    return False

                return True

    except Exception as e:
        print(f"Wyjątek: {e}")
        return False


async def main():
    url = "http://th.if.uj.edu.pl/"
    expected_string = "Institute of Theoretical Physics"
    result = await check_website(url, expected_string)

    if result:
        print("Strona działa poprawnie.")
        sys.exit(0)
    else:
        print("Strona nie działa poprawnie.")
        sys.exit(1)


if __name__ == "__main__":
    asyncio.run(main())
