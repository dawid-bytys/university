export function mapJobToDto(job) {
  return {
    title: job.title,
    description: job.description,
    tags: job.tags,
    location: job.location,
    salary: job.salary,
    company: job.company,
    benefits: job.benefits,
    requirements: job.requirements,
    image: job.image,
    createdAt: job.createdAt,
  };
}
