import { AmountTile } from './AmountTile';
import { CurrencyTile } from './CurrencyTile';

export function ExchangeGrid() {
  return (
    <div className="grid grid-cols-2 divide-x-[1px] divide-y-[1px] divide-[#333333] grid-rows-2 border-[1px] border-[#333333] rounded-xl">
      <CurrencyTile
        iconPath="src/assets/png/poland-flag.png"
        shortName="PLN"
        fullName="Polish Zloty"
      />
      <CurrencyTile
        iconPath="src/assets/png/us-flag.png"
        shortName="USD"
        fullName="United States Dollar"
      />
      <AmountTile />
      <AmountTile />
    </div>
  );
}
