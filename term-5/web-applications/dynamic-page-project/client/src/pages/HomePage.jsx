import { useState } from 'react';
import { GoogleMap } from '../components/GoogleMap';
import { JobOffer } from '../components/JobOffer';
import { Link } from 'react-router-dom';
import { Results } from '../components/Results';
import { Settings } from '../components/Settings';
import { Loading } from '../components/Loading';
import { useFetch } from '../hooks/useFetch';
import { ServerDown } from '../components/ServerDown';

export function HomePage() {
  const [filters, setFilters] = useState({
    city: 'All cities',
    search: '',
  });
  const { state, data } = useFetch({
    method: 'GET',
    url: 'http://localhost:3000/api/jobs',
    filters,
  });

  function handleFiltersChange(e) {
    setFilters({
      ...filters,
      [e.target.name]: e.target.value,
    });
  }

  if (state === 'loading') {
    return <Loading />;
  }

  if (state === 'error') {
    return <ServerDown />;
  }

  return (
    <div className="flex flex-row p-5 sm:p-10 gap-10 overflow-hidden">
      <main className="flex flex-col xl:w-1/2 gap-5">
        <Settings handleFiltersChange={handleFiltersChange} />
        <Results
          count={data.length}
          city={filters.city !== 'All cities' ? filters.city : null}
        />
        <section className="flex flex-1 flex-col gap-5 overflow-auto no-scrollbar">
          {data.map((job) => (
            <Link
              to={`/jobs/${job.id}`}
              key={job.id}
            >
              <JobOffer {...job} />
            </Link>
          ))}
        </section>
      </main>
      <aside className="hidden w-1/2 2xl:block shadow">
        <GoogleMap jobs={data} />
      </aside>
    </div>
  );
}
