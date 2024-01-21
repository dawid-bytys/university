import { Link } from 'react-router-dom';
import plusSvg from '../assets/svg/plus.svg';

export function Header() {
  return (
    <header className="flex flex-row justify-between border-b-2 border-gray-100 p-5 sm:p-10">
      <Link
        to="/"
        className="flex items-center"
      >
        <h1 className="text-primary font-semibold text-2xl sm:text-3xl">Jobriver</h1>
      </Link>
      <nav className="flex items-center justify-center">
        <ul className="flex flex-row gap-3 sm:text-lg md:gap-10 font-medium">
          <li className="flex items-center">
            <Link to="/">Home</Link>
          </li>
          <li>
            <Link
              to="/add-job"
              className="flex flex-row justify-between bg-primary rounded-md px-3 py-2 md:px-5 md:py-4 text-white items-center gap-3"
            >
              <img
                src={plusSvg}
                alt="Add Job"
                className="w-5 h-5"
              />
              <p>Add Job</p>
            </Link>
          </li>
        </ul>
      </nav>
    </header>
  );
}
