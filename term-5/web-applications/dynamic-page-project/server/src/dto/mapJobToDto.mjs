export function mapJobToDto(job) {
  return {
    title: job.title,
    description: job.description,
    tags: job.tags,
    locations: job.locations,
    salary: job.salary,
    company: job.company,
    benefits: job.benefits,
    requirements: job.requirements,
    image: job.image,
    createdAt: job.createdAt,
  };
}
