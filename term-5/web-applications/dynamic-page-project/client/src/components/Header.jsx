import plusSvg from '../assets/svg/plus.svg';

export function Header() {
  return (
    <header className="flex flex-row p-5 justify-between border-b-2 border-gray-100">
      <div className="flex items-center">
        <h1 className="text-primary font-semibold text-2xl">Jobriver</h1>
      </div>
      <nav className="flex items-center justify-center">
        <ul className="flex flex-row gap-3">
          <li className="flex items-center">
            <a href="/">Home</a>
          </li>
          <li>
            <a
              href="/add-job"
              className="flex flex-row justify-between bg-primary rounded-md px-3 py-2 text-white items-center gap-3"
            >
              <img
                src={plusSvg}
                alt="Add Job"
                className="w-5 h-5"
              />
              <p>Add Job</p>
            </a>
          </li>
        </ul>
      </nav>
    </header>
  );
}
