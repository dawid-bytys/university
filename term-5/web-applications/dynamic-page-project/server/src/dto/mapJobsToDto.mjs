export function mapJobsToDto(jobs) {
  return jobs.map((job) => ({
    id: job.id,
    title: job.title,
    tags: job.tags,
    location: job.location,
    salary: job.salary,
    company: job.company,
    image: job.image,
    createdAt: job.createdAt,
  }));
}
