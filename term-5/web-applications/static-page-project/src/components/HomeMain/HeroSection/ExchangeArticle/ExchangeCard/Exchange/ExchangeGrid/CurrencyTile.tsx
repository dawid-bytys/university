interface CurrencyTileProps {
  iconPath: string;
  shortName: string;
  fullName: string;
}

export function CurrencyTile({ iconPath, shortName, fullName }: CurrencyTileProps) {
  return (
    <div className="flex flex-col p-5 justify-between">
      <div className="flex flex-row">
        <div>
          <img
            src={iconPath}
            className="w-8 h-8 rounded-full"
            alt="Currency flag"
          />
        </div>
        <div className="flex items-center justify-center">
          <p className="ml-3 font-poppins-medium text-2xl">{shortName}</p>
        </div>
      </div>
      <div>
        <p>{fullName}</p>
      </div>
    </div>
  );
}
