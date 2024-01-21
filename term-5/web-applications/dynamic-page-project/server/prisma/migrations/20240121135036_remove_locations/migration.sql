/*
  Warnings:

  - You are about to drop the column `locationId` on the `Jobs` table. All the data in the column will be lost.
  - You are about to drop the `Locations` table. If the table is not empty, all the data it contains will be lost.
  - Added the required column `location` to the `Jobs` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "Jobs" DROP CONSTRAINT "Jobs_locationId_fkey";

-- AlterTable
ALTER TABLE "Jobs" DROP COLUMN "locationId",
ADD COLUMN     "location" JSONB NOT NULL;

-- DropTable
DROP TABLE "Locations";
