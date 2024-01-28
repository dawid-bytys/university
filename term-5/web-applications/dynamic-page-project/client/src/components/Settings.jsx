import searchSvg from '../assets/svg/search.svg';
import locationSvg from '../assets/svg/location-point.svg';
import arrowDownSvg from '../assets/svg/angle-down.svg';

const cities = [
  'All cities',
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

export function Settings({ handleFiltersChange }) {
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
          name="search"
          placeholder="Search job title or keyword"
          className="w-full p-3 bg-neutral-100"
          onChange={handleFiltersChange}
        />
      </div>
      <div className="flex">
        <div className="flex-1 cursor-pointer flex items-center flex-row rounded-md border-2 border-neutral-100 hover:border-primary hover:transition-colors">
          <div className="flex items-center justify-center p-3">
            <img
              src={locationSvg}
              alt="Location"
              className="w-7 h-7"
            />
          </div>
          <select
            name="city"
            selected="All cities"
            onChange={handleFiltersChange}
            className="cursor-pointer w-full bg-transparent p-3 appearance-none"
          >
            {cities.map((city) => (
              <option
                key={city}
                value={city}
              >
                {city}
              </option>
            ))}
          </select>
          <div className="flex items-center justify-center p-3">
            <img
              src={arrowDownSvg}
              alt="Arrow down"
              className="w-7 h-7"
            />
          </div>
        </div>
      </div>
    </div>
  );
}
