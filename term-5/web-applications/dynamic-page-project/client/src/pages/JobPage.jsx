import { useParams } from 'react-router-dom';
import { useEffect, useState } from 'react';
import { fetchJob } from '../domain/jobs';
import { Loading } from '../components/Loading';
import { GoogleMap } from '../components/GoogleMap';
import { JobOffer } from '../components/JobOffer';

export function JobPage() {
  const { id } = useParams();
  const [job, setJob] = useState(null);

  useEffect(() => {
    async function performFetching() {
      const job = await fetchJob(id);
      setJob(job);
    }

    performFetching();
  }, [id]);

  if (!job) {
    return <Loading />;
  }

  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <main className="flex-1 xl:w-1/2 flex flex-col gap-16">
        <section className="flex flex-row gap-10">
          <JobOffer
            {...job}
            isSingleOffer={true}
          />
        </section>
        <section className="flex flex-col gap-5">
          <h2 className="text-3xl font-semibold">Description</h2>
          <p className="text-lg text-justify">{job.description}</p>
        </section>
        <section className="flex flex-col gap-5">
          <h2 className="text-3xl font-semibold">Requirements</h2>
          <ol className="list-disc list-inside">
            {job.requirements.map((requirement) => (
              <li
                key={requirement}
                className="text-lg text-justify"
              >
                {requirement}
              </li>
            ))}
          </ol>
        </section>
        <section className="flex flex-col gap-5">
          <h2 className="text-3xl font-semibold">Benefits</h2>
          <ol className="list-disc list-inside">
            {job.benefits.map((benefit) => (
              <li
                key={benefit}
                className="text-lg text-justify"
              >
                {benefit}
              </li>
            ))}
          </ol>
        </section>
      </main>
      <aside className="hidden xl:flex xl:w-1/2 shadow">
        <GoogleMap
          jobs={[job]}
          zoom={12}
          position={{
            lat: job.location.lat,
            lng: job.location.lng,
          }}
          isSingleOffer={true}
        />
      </aside>
    </div>
  );
}
