export async function fetchJobs() {
  const response = await fetch('http://localhost:3000/api/jobs');

  if (!response.ok) {
    throw new Error(response.statusText);
  }

  return response.json();
}

export async function fetchJob(id) {
  const response = await fetch(`http://localhost:3000/api/jobs/${id}`);

  if (!response.ok) {
    throw new Error(response.statusText);
  }

  return response.json();
}

export async function addJob(job) {
  const response = await fetch('http://localhost:3000/api/jobs', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(job),
  });

  if (!response.ok) {
    throw new Error(response.statusText);
  }

  return response.json();
}
