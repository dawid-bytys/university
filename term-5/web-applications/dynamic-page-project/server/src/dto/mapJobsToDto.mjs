export function mapJobsToDto(jobs) {
  return jobs.map((job) => ({
    title: job.title,
    description: job.description,
    tags: job.tags,
    locations: job.locations,
    salary: job.salary,
    company: job.company,
    image: job.image,
    benefits: job.benefits,
    createdAt: job.createdAt,
  }));
}
