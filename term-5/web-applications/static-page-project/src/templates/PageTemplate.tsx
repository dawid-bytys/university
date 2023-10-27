import { Footer } from '@/components/Footer/Footer';
import { Header } from '@/components/Header/Header';
import Particles from '@/assets/svg/particles.svg';

interface ChildrenProps {
  children: React.ReactNode;
}

export function PageTemplate({ children }: ChildrenProps) {
  return (
    <div className="h-full w-full bg-secondary flex flex-col font-poppins-regular">
      <img
        src={Particles}
        alt="particles"
        className="z-0 absolute top-0 left-0 z-1"
      />
      <Header />
      {children}
      <Footer />
    </div>
  );
}
