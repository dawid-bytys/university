import { TransactionIcon } from '@/components/Icons/TransactionIcon';

interface TransactionCardProps {
  user: string;
  amount: string;
  className?: string;
}

export function TransactionCard({ user, amount, className }: TransactionCardProps) {
  return (
    <div
      className={`flex flex-row justify-between bg-[#262626] border-[1px] border-[#333333] p-5 rounded-xl ${
        className || ''
      }`}
    >
      <div className="flex row gap-4">
        <div className="flex items-center justify-center">
          <div className="flex items-center justify-center bg-primary rounded-full w-[40px] h-[40px]">
            <TransactionIcon
              width="20"
              height="20"
            />
          </div>
        </div>
        <div className="flex flex-col">
          <p>Transaction</p>
          <p>{user}</p>
        </div>
      </div>
      <div className="flex flex-col justify-end">
        <p>{amount}</p>
      </div>
    </div>
  );
}
