import searchSvg from '../assets/svg/search.svg';
import locationSvg from '../assets/svg/location-point.svg';
import tuneSvg from '../assets/svg/tune-variant.svg';

const cities = [
  'Warsaw',
  'Cracow',
  'Wroclaw',
  'Poznan',
  'Gdansk',
  'Lodz',
  'Szczecin',
  'Bydgoszcz',
  'Lublin',
  'Katowice',
  'Bialystok',
  'Gdynia',
];

export function Settings() {
  return (
    <div className="flex flex-col gap-5">
      <div className="flex flex-row rounded-md bg-neutral-100">
        <div className="flex items-center justify-center p-3">
          <img
            src={searchSvg}
            alt="Search"
            className="w-7 h-7"
          />
        </div>
        <input
          type="text"
          placeholder="Search job title or keyword"
          className="w-full p-3 bg-neutral-100"
        />
      </div>
      <div className="flex flex-row gap-3">
        <div className="flex flex-row rounded-md border-2 border-neutral-100 basis-1/2">
          <div className="flex items-center justify-center p-3">
            <img
              src={locationSvg}
              alt="Location"
              className="w-7 h-7"
            />
          </div>
          <select className="w-full bg-transparent p-3">
            {cities.map((city) => (
              <option
                key={city}
                value={city}
              >
                {city}
              </option>
            ))}
          </select>
        </div>
        <div className="flex flex-row items-center rounded-md border-2 border-neutral-100 basis-1/2">
          <div className="flex items-center justify-center p-3">
            <img
              src={tuneSvg}
              alt="Tune"
              className="w-7 h-7"
            />
          </div>
          <p className="p-3 w-full">Filters</p>
        </div>
      </div>
    </div>
  );
}
