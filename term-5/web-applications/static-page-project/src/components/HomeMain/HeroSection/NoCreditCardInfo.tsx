import { TickIcon } from '../../Icons/TickIcon';

export function NoCreditCardInfo() {
  return (
    <div className="flex flex-row items-center p-3 bg-[#262626] rounded-full gap-3">
      <TickIcon
        width="25"
        height="25"
      />
      <p className="text-white text-[16px]">No LLC Required, No Credit Check.</p>
    </div>
  );
}
