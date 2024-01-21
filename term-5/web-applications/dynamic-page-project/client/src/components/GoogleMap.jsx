import { APIProvider, Map } from '@vis.gl/react-google-maps';

export function GoogleMap() {
  const position = { lat: 51.9189046, lng: 19.1343786 };

  return (
    <APIProvider apiKey={import.meta.env.VITE_GOOGLE_MAPS_API_KEY}>
      <div className="w-full h-full">
        <Map
          zoom={7}
          center={position}
          zoomControl={false}
          streetViewControl={false}
          scaleControl={false}
          mapId={import.meta.env.VITE_GOOGLE_MAPS_MAP_ID}
        />
      </div>
    </APIProvider>
  );
}
