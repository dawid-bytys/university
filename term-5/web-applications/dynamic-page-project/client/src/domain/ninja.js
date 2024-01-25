export async function fetchGeolocation(city) {
  const response = await fetch(`https://api.api-ninjas.com/v1/geocoding?city=${city}`, {
    headers: {
      'X-Api-Key': import.meta.env.VITE_NINJA_API_KEY,
    },
  });

  if (!response.ok) {
    throw new Error(response.statusText);
  }

  const data = await response.json();

  return {
    city: data[0].name,
    lat: data[0].latitude,
    lng: data[0].longitude,
  };
}
