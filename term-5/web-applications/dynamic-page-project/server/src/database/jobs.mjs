import { prisma } from './prisma.mjs';

export async function getJobs(filters) {
  const { city, search } = filters;

  if (city === 'All cities' && search === '') {
    return prisma.jobs.findMany();
  }

  return prisma.jobs.findMany({
    where: {
      AND: [
        {
          location: {
            path: ['city'],
            string_contains: city === 'All cities' ? '' : city,
          },
        },
        {
          title: {
            contains: search,
            mode: 'insensitive',
          },
        },
      ],
    },
  });
}

export async function addJob(job) {
  await prisma.jobs.create({ data: job });
}

export async function getJobById(id) {
  return prisma.jobs.findUnique({ where: { id } });
}
