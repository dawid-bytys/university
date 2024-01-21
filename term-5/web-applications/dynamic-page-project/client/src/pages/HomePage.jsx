import { useEffect } from 'react';
import { GoogleMap } from '../components/GoogleMap';
import { HomeMain } from '../components/HomeMain';
import { fetchJobs } from '../domain/jobs';
import { useState } from 'react';

export function HomePage() {
  const [jobs, setJobs] = useState(null);

  useEffect(() => {
    async function performFetching() {
      const jobs = await fetchJobs();
      const filteredJobs = jobs.filter((job) => job.locations.includes('Warsaw'));
      setJobs(filteredJobs);
    }

    performFetching();
  }, []);

  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <HomeMain jobs={jobs} />
      <aside className="hidden xl:flex xl:w-1/2 shadow">
        <GoogleMap />
      </aside>
    </div>
  );
}
