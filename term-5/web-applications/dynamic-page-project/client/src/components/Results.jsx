export function Results({ count, city }) {
  return (
    <div>
      <h2 className="flex flex-row gap-2 items-center text-xl font-semibold">
        <span>{count} Results</span>
        <span className="text-[#CFD6E0]">in Poland, {city}</span>
      </h2>
    </div>
  );
}
