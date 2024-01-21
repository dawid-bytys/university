export async function fetchJobs() {
  const response = await fetch('http://localhost:3000/api/jobs');

  if (!response.ok) {
    throw new Error(response.statusText);
  }

  return response.json();
}
