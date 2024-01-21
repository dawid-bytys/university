export function mapJobsToDto(jobs) {
  return jobs.map((job) => ({
    id: job.id,
    title: job.title,
    tags: job.tags,
    locations: job.locations,
    salary: job.salary,
    company: job.company,
    image: job.image,
    createdAt: job.createdAt,
  }));
}
