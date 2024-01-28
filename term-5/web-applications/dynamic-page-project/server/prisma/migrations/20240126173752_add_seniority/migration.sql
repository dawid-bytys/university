/*
  Warnings:

  - Added the required column `seniority` to the `Jobs` table without a default value. This is not possible if the table is not empty.
  - Changed the type of `salary` on the `Jobs` table. No cast exists, the column would be dropped and recreated, which cannot be done if there is data, since the column is required.

*/
-- AlterTable
ALTER TABLE "Jobs" ADD COLUMN     "seniority" TEXT NOT NULL,
DROP COLUMN "salary",
ADD COLUMN     "salary" JSONB NOT NULL;
