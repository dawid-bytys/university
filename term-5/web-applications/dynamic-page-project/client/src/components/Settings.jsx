import searchSvg from '../assets/svg/search.svg';

export function Settings() {
  return (
    <div>
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
    </div>
  );
}
