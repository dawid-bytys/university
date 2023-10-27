import { Exchange } from './Exchange/Exchange';
import { Transactions } from './Transactions/Transactions';

export function ExchangeCard() {
  return (
    <div className="flex flex-col bg-[#262626] border-[1px] border-[#333333] p-5 rounded-xl">
      <div className="flex flex-col gap-5">
        <Transactions />
        <Exchange />
      </div>
    </div>
  );
}
