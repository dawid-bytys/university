import { prisma } from './prisma.mjs';

export async function getJobs(city) {
  if (!city) {
    return prisma.jobs.findMany();
  }

  return prisma.jobs.findMany({
    where: {
      locations: {
        has: city,
      },
    },
  });
}

export async function addJob(job) {
  await prisma.jobs.create({ data: job });
}

export async function getJobById(id) {
  return prisma.jobs.findUnique({ where: { id } });
}
