import { useState } from 'react';
import { GoogleMap } from '../components/GoogleMap';
import { JobOffer } from '../components/JobOffer';
import { Link } from 'react-router-dom';
import { Results } from '../components/Results';
import { Settings } from '../components/Settings';
import { Loading } from '../components/Loading';
import { useFetch } from '../hooks/useFetch';

export function HomePage() {
  const [filters, setFilters] = useState({
    location: '',
    tags: [],
  });
  const { state, data, error } = useFetch({
    method: 'GET',
    url: 'http://localhost:3000/api/jobs',
    filters,
  });

  if (state === 'loading') {
    return <Loading />;
  }

  if (state === 'error') {
    return <p>Error: {error.message}</p>;
  }

  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <main className="flex-1 xl:w-1/2 flex flex-col gap-5">
        <Settings />
        <Results count={data.length} />
        <section className="flex flex-1 flex-col gap-5">
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
      <aside className="hidden xl:flex xl:w-1/2 shadow">{/*<GoogleMap jobs={jobs} />*/}</aside>
    </div>
  );
}
