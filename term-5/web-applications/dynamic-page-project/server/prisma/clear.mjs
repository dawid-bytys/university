import { prisma } from '../src/database/prisma.mjs';

async function main() {
  try {
    await prisma.jobs.deleteMany();
  } catch (err) {
    console.error(err);
    process.exit(1);
  } finally {
    await prisma.$disconnect();
    console.log('Clear complete!');
  }
}

main();
