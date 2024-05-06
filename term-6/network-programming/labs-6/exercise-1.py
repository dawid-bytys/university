import sys
import aiohttp
import asyncio


async def fetch_server_header(session, url, port):
    try:
        if port == 80:
            full_url = f"http://{url}"
        elif port == 443:
            full_url = f"https://{url}"

        async with session.get(full_url, timeout=10) as response:
            server_header = response.headers.get("Server", "Brak nagłówka Server")

        return server_header
    except Exception as e:
        print(f"Wyjątek: {e}")
        sys.exit(1)


async def main():
    if len(sys.argv) < 2:
        print("Podaj przynajmniej jeden adres strony internetowej.")
        sys.exit(1)

    async with aiohttp.ClientSession() as session:
        for website in sys.argv[1:]:
            print(f"{website}:")

            http_server = await fetch_server_header(session, website, 80)
            print(f"port 80: {http_server}")

            https_server = await fetch_server_header(session, website, 443)
            print(f"port 443: {https_server}\n")

    sys.exit(0)


if __name__ == "__main__":
    asyncio.run(main())
