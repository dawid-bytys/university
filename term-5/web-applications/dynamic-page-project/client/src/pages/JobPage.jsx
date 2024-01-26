import { useParams } from 'react-router-dom';
import { Loading } from '../components/Loading';
import { GoogleMap } from '../components/GoogleMap';
import { JobOffer } from '../components/JobOffer';
import { useFetch } from '../hooks/useFetch';

export function JobPage() {
  const { id } = useParams();
  const { data, state, error } = useFetch({
    method: 'GET',
    url: `http://localhost:3000/api/jobs/${id}`,
  });

  if (state === 'loading') {
    return <Loading />;
  }

  if (state === 'error') {
    return <p>Error: {error.message}</p>;
  }

  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <main className="flex-1 xl:w-1/2 flex flex-col gap-16">
        <section className="flex flex-row gap-10">
          <JobOffer
            {...data}
            isSingleOffer={true}
          />
        </section>
        <section className="flex flex-col gap-5">
          <h2 className="text-3xl font-semibold">Description</h2>
          <p className="text-lg text-justify">{data.description}</p>
        </section>
        <section className="flex flex-col gap-5">
          <h2 className="text-3xl font-semibold">Requirements</h2>
          <ol className="list-disc list-inside">
            {data.requirements.map((requirement) => (
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
            {data.benefits.map((benefit) => (
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
          jobs={[data]}
          zoom={12}
          position={{
            lat: data.location.lat,
            lng: data.location.lng,
          }}
          isSingleOffer={true}
        />
      </aside>
    </div>
  );
}
