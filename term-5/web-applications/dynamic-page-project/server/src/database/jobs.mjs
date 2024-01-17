import { prisma } from './prisma.mjs';

export async function getJobs() {
  return await prisma.job.findMany();
}

export async function addJob(job) {
  return await prisma.job.create({ data: job });
}
