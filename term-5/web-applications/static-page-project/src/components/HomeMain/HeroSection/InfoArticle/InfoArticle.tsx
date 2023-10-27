import { About } from './About';
import { NoCreditCardInfo } from './NoCreditCardInfo';

export function InfoArticle() {
  return (
    <article className="flex flex-col gap-10">
      <NoCreditCardInfo />
      <About />
    </article>
  );
}
