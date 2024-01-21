import { useEffect, useState } from 'react';
import { GoogleMap } from '../components/GoogleMap';
import { JobOffer } from '../components/JobOffer';
import { Link } from 'react-router-dom';
import { Results } from '../components/Results';
import { Settings } from '../components/Settings';
import { fetchJobs } from '../domain/jobs';
import { Loading } from '../components/Loading';

export function HomePage() {
  const [jobs, setJobs] = useState(null);

  useEffect(() => {
    async function performFetching() {
      const jobs = await fetchJobs();
      setJobs(jobs);
    }

    performFetching();
  }, []);

  if (!jobs) {
    return <Loading />;
  }

  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <main className="flex-1 xl:w-1/2 flex flex-col gap-5">
        <Settings />
        <Results count={jobs.length} />
        <section className="flex flex-1 flex-col gap-5">
          {jobs.map((job) => (
            <Link
              to={`/jobs/${job.id}`}
              key={job.id}
            >
              <JobOffer {...job} />
            </Link>
          ))}
        </section>
      </main>
      <aside className="hidden xl:flex xl:w-1/2 shadow">
        <GoogleMap jobs={jobs} />
      </aside>
    </div>
  );
}
