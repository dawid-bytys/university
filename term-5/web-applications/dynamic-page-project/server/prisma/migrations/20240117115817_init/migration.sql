-- CreateTable
CREATE TABLE "Job" (
    "id" TEXT NOT NULL,
    "title" TEXT NOT NULL,
    "description" TEXT NOT NULL,
    "tags" TEXT[],
    "requirements" TEXT[],
    "benefits" TEXT[],
    "image" TEXT NOT NULL,
    "salary" INTEGER NOT NULL,
    "company" TEXT NOT NULL,
    "location" TEXT NOT NULL,

    CONSTRAINT "Job_pkey" PRIMARY KEY ("id")
);
