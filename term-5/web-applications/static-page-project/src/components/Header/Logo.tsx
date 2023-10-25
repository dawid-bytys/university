import { LogoIcon } from '../Icons/LogoIcon';

export function Logo() {
  return (
    <div className="flex flex-row gap-2 items-center">
      <LogoIcon
        width="30"
        height="31"
      />
      <span className="text-white font-poppins-medium text-[20px]">YourBanK</span>
    </div>
  );
}
