/*
  Warnings:

  - Added the required column `employment` to the `Jobs` table without a default value. This is not possible if the table is not empty.
  - Added the required column `operatingMode` to the `Jobs` table without a default value. This is not possible if the table is not empty.
  - Added the required column `typeOfWork` to the `Jobs` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "Jobs" ADD COLUMN     "employment" TEXT NOT NULL,
ADD COLUMN     "operatingMode" TEXT NOT NULL,
ADD COLUMN     "typeOfWork" TEXT NOT NULL;
