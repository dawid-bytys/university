import { About } from './About';
import { NoCreditCardInfo } from './NoCreditCardInfo';

export function HeroSection() {
  return (
    <section className="flex flex-col gap-10">
      <NoCreditCardInfo />
      <About />
    </section>
  );
}
