import spinnerSvg from '../assets/svg/spinner.svg';

export function Loading() {
  return (
    <div className="flex flex-1 items-center justify-center">
      <img
        src={spinnerSvg}
        alt="spinner"
        className="w-16 h-16"
      />
    </div>
  );
}
