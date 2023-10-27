import { ExchangeCard } from './ExchangeCard/ExchangeCard';

export function ExchangeArticle() {
  return (
    <article className="relative">
      <img
        src="src/assets/svg/arrows.svg"
        alt="Arrows"
        className="absolute top-[-50px] right-[-50px]"
      />
      <ExchangeCard />
    </article>
  );
}
