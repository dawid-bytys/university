import { APIProvider, Map, AdvancedMarker } from '@vis.gl/react-google-maps';
import { randomGradient } from '../utils';
import clsx from 'clsx';

export function GoogleMap({
  jobs,
  zoom = 7,
  position = { lat: 51.9189046, lng: 19.1343786 },
  isSingleOffer = false,
}) {
  return (
    <APIProvider apiKey={import.meta.env.VITE_GOOGLE_MAPS_API_KEY}>
      <div className="w-full h-full">
        <Map
          zoom={zoom}
          center={position}
          zoomControl={false}
          streetViewControl={false}
          scaleControl={false}
          mapId={import.meta.env.VITE_GOOGLE_MAPS_MAP_ID}
        >
          {jobs.map(({ location: { lat, lng }, image }) => (
            <AdvancedMarker
              key={`${lat}-${lng}`}
              position={{ lat, lng }}
            >
              <MapPin
                image={image}
                isSingleOffer={isSingleOffer}
              />
            </AdvancedMarker>
          ))}
        </Map>
      </div>
    </APIProvider>
  );
}

function MapPin({ image, isSingleOffer }) {
  return (
    <div
      className={clsx({
        'aspect-square w-12 h-12 p-2 rounded-full shadow': true,
        'animate-bounce': isSingleOffer,
        [randomGradient()]: true,
      })}
    >
      <img
        src={image}
        alt="map pin"
        className="w-full h-full rounded-full"
      />
    </div>
  );
}
