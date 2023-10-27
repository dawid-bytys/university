import { TransactionCard } from './TransactionCard';

export function Transactions() {
  return (
    <div>
      <h3 className="font-poppins-medium mb-5">Your Transactions</h3>
      <TransactionCard
        user="John Doe"
        amount="$42.00"
        className="relative z-50"
      />
      <TransactionCard
        user="Alan Smith"
        amount="-$23.00"
        className="mx-[20px] relative top-[-30px] z-40 opacity-60"
      />
      <TransactionCard
        user="Will Johnson"
        amount="-$68.00"
        className="mx-[50px] relative top-[-60px] z-30 opacity-40"
      />
    </div>
  );
}
