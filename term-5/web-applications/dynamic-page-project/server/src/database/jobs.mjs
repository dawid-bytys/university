import { prisma } from './prisma.mjs';

export async function getJobs() {
  return await prisma.jobs.findMany();
}

export async function addJob(job) {
  return await prisma.jobs.create({ data: job });
}
