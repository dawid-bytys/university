import { ExchangeArticle } from './ExchangeArticle/ExchangeArticle';
import { InfoArticle } from './InfoArticle/InfoArticle';

export function HeroSection() {
  return (
    <section className="flex flex-col gap-10">
      <InfoArticle />
      <ExchangeArticle />
    </section>
  );
}
