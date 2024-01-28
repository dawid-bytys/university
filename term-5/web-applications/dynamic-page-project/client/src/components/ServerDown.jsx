import serverDownSvg from '../assets/svg/server-down.svg';

export function ServerDown() {
  return (
    <div className="flex flex-col items-center justify-center flex-1 gap-10 p-10 md:p-0">
      <h2 className="text-3xl font-bold text-center">Server is currently down!</h2>
      <img
        src={serverDownSvg}
        alt="Server Down"
        className="w-96 h-96 object-contain"
      />
    </div>
  );
}
