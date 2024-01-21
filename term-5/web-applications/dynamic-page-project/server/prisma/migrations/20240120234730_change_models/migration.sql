/*
  Warnings:

  - You are about to drop the `Job` table. If the table is not empty, all the data it contains will be lost.

*/
-- DropTable
DROP TABLE "Job";

-- CreateTable
CREATE TABLE "Jobs" (
    "id" TEXT NOT NULL,
    "title" TEXT NOT NULL,
    "description" TEXT NOT NULL,
    "tags" TEXT[],
    "requirements" TEXT[],
    "benefits" TEXT[],
    "image" TEXT NOT NULL,
    "salary" TEXT NOT NULL,
    "company" TEXT NOT NULL,
    "locations" TEXT[],
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT "Jobs_pkey" PRIMARY KEY ("id")
);
