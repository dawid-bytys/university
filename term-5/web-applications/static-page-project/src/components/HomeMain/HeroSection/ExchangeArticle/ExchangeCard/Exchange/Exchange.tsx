import { ExchangeBtn } from './ExchangeBtn';
import { ExchangeGrid } from './ExchangeGrid/ExchangeGrid';

export function Exchange() {
  return (
    <div className="relative mt-[-40px]">
      <h3 className="font-poppins-medium mb-5">Money Exchange</h3>
      <ExchangeGrid />
      <ExchangeBtn />
    </div>
  );
}
