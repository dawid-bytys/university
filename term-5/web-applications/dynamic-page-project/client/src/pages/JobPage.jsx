import { useParams } from 'react-router-dom';
import { useEffect, useState } from 'react';
import { fetchJob } from '../domain/jobs';

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
    return <p>Loading...</p>;
  }

  return <main>{job.title}</main>;
}
