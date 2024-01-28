export function mapJobsToDto(jobs) {
  return jobs
    .map((job) => ({
      id: job.id,
      title: job.title,
      tags: job.tags,
      location: job.location,
      seniority: job.seniority,
      salary: job.salary,
      company: job.company,
      image: job.image,
      createdAt: job.createdAt,
    }))
    .sort((a, b) => b.createdAt - a.createdAt);
}
