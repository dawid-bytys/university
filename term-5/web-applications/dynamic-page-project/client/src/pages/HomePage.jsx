import { GoogleMap } from '../components/GoogleMap';
import { HomeMain } from '../components/HomeMain';

export function HomePage() {
  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <HomeMain />
      <aside className="hidden xl:flex basis-1/2 shadow">
        <GoogleMap />
      </aside>
    </div>
  );
}
