import { Settings } from './Settings';
import { Results } from './Results';
import { JobOffer } from './JobOffer';
import { Link } from 'react-router-dom';

export function HomeMain({ jobs }) {
  if (!jobs) {
    return <p>Loading...</p>;
  }

  return (
    <main className="flex-1 xl:w-1/2 flex flex-col gap-5">
      <Settings />
      <Results count={jobs.length} />
      <section className="flex flex-1 flex-col gap-5">
        {jobs.map((job) => (
          <Link
            to={`/jobs/${job.id}`}
            key={job.id}
          >
            <JobOffer
              image={job.image}
              company={job.company}
              title={job.title}
              locations={job.locations}
              tags={job.tags}
              salary={job.salary}
              createdAt={job.createdAt}
            />
          </Link>
        ))}
      </section>
    </main>
  );
}
