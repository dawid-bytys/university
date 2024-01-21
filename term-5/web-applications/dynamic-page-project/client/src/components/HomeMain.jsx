import { Settings } from './Settings';
import { Results } from './Results';
import { JobOffer } from './JobOffer';

export function HomeMain({ jobs }) {
  if (!jobs) {
    return <p>Loading...</p>;
  }

  return (
    <main className="flex-1 xl:w-1/2 flex flex-col gap-5">
      <Settings />
      <Results
        count={jobs.length}
        city="Warsaw"
      />
      <section className="flex flex-1 flex-col gap-5">
        {jobs.map((job, index) => (
          <JobOffer
            key={index}
            {...job}
          />
        ))}
      </section>
    </main>
  );
}
