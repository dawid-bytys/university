export function mapJobToDto(job) {
  return {
    title: job.title,
    description: job.description,
    tags: job.tags,
    location: job.location,
    salary: job.salary,
    seniority: job.seniority,
    employment: job.employment,
    operatingMode: job.operatingMode,
    typeOfWork: job.typeOfWork,
    company: job.company,
    benefits: job.benefits,
    requirements: job.requirements,
    image: job.image,
    createdAt: job.createdAt,
  };
}
