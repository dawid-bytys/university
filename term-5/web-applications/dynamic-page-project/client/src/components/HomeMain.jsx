import { Settings } from './Settings';
import { Results } from './Results';
import { JobOffer } from './JobOffer';

const jobs = [
  {
    image:
      'https://www.microsoft.com/pl-pl/microsoft-365/blog/wp-content/uploads/sites/50/2022/06/cropped-microsoft_logo_element.png',
    company: 'Microsoft',
    title: 'Sr. Backend Developer',
    locations: ['Warsaw', 'Cracow'],
    tags: ['Backend', 'Node.js', 'Express.js', 'MongoDB'],
    salary: {
      from: 10000,
      to: 15000,
      currency: 'PLN',
    },
    createdAt: new Date(),
  },
  {
    image: 'https://www.edigitalagency.com.au/wp-content/uploads/apple-logo-png-black.png',
    company: 'Apple',
    title: 'Sr. Frontend Developer',
    locations: ['Warsaw', 'Remote'],
    tags: ['Frontend', 'React', 'Redux', 'TypeScript'],
    salary: {
      from: 10000,
      to: 15000,
      currency: 'PLN',
    },
    createdAt: new Date(),
  },
];

export function HomeMain() {
  return (
    <main className="flex-1 basis-1/2 flex flex-col gap-5">
      <Settings />
      <Results
        count={5}
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
