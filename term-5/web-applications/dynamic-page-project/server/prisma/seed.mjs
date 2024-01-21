import { prisma } from '../src/database/prisma.mjs';
import { jobs } from '../src/mocks/jobs.mjs';

async function main() {
  try {
    await prisma.jobs.createMany({
      data: jobs,
    });
  } catch (err) {
    console.error(err);
    process.exit(1);
  } finally {
    await prisma.$disconnect();
    console.log('Seeding complete!');
  }
}

main();
