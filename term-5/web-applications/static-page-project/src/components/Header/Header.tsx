import { HamburgerBtn } from './HamburgerBtn';
import { Logo } from './Logo';

export function Header() {
  return (
    <header className="flex flex-row justify-between z-10 bg-[#262626] mx-10 mt-10 p-5 rounded-full border-[1px] border-[#333333]">
      <Logo />
      <HamburgerBtn />
    </header>
  );
}
