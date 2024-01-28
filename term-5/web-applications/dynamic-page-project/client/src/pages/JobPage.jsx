import { useParams } from 'react-router-dom';
import { Loading } from '../components/Loading';
import { GoogleMap } from '../components/GoogleMap';
import { JobOffer } from '../components/JobOffer';
import { useFetch } from '../hooks/useFetch';
import { ServerDown } from '../components/ServerDown';
import workSvg from '../assets/svg/work.svg';
import starSvg from '../assets/svg/star.svg';
import checklistSvg from '../assets/svg/checklist.svg';
import locationSvg from '../assets/svg/location-outline.svg';

export function JobPage() {
  const { id } = useParams();
  const { data, state } = useFetch({
    method: 'GET',
    url: `http://localhost:3000/api/jobs/${id}`,
  });

  if (state === 'loading') {
    return <Loading />;
  }

  if (state === 'error') {
    return <ServerDown />;
  }

  return (
    <div className="flex flex-1 flex-row p-5 sm:p-10 gap-10">
      <main className="flex-1 xl:w-1/2 flex flex-col gap-16">
        <section>
          <div className="flex flex-col rounded-xl border-2 border-neutral-200 p-5 gap-5">
            <JobOffer
              {...data}
              isSingleOffer={true}
            />
            <div className="grid grid-cols-2 gap-5 lg:grid-cols-4 border-t-2 border-neutral-200 pt-5">
              <div className="flex flex-col gap-3">
                <div className="flex items-center justify-center">
                  <img
                    src={workSvg}
                    alt="work"
                    className="w-10 h-10"
                  />
                </div>
                <div>
                  <p className="text-neutral-400 text-center">Type of work</p>
                  <p className="font-medium text-center">{data.typeOfWork}</p>
                </div>
              </div>
              <div className="flex flex-col gap-3">
                <div className="flex items-center justify-center">
                  <img
                    src={starSvg}
                    alt="type of work"
                    className="w-10 h-10"
                  />
                </div>
                <div>
                  <p className="text-neutral-400 text-center">Seniority</p>
                  <p className="font-medium text-center">{data.seniority}</p>
                </div>
              </div>
              <div className="flex flex-col gap-3">
                <div className="flex items-center justify-center">
                  <img
                    src={checklistSvg}
                    alt="employment"
                    className="w-10 h-10"
                  />
                </div>
                <div>
                  <p className="text-neutral-400 text-center">Employment type</p>
                  <p className="font-medium text-center">{data.employment}</p>
                </div>
              </div>
              <div className="flex flex-col gap-3">
                <div className="flex items-center justify-center">
                  <img
                    src={locationSvg}
                    alt="operating mode"
                    className="w-10 h-10"
                  />
                </div>
                <div>
                  <p className="text-neutral-400 text-center">Operating mode</p>
                  <p className="font-medium text-center">{data.operatingMode}</p>
                </div>
              </div>
            </div>
          </div>
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
        {/*<GoogleMap
          jobs={[data]}
          zoom={12}
          position={{
            lat: data.location.lat,
            lng: data.location.lng,
          }}
          isSingleOffer={true}
        />*/}
      </aside>
    </div>
  );
}
