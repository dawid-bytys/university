/*
  Warnings:

  - You are about to drop the column `locationsId` on the `Jobs` table. All the data in the column will be lost.
  - Added the required column `locationId` to the `Jobs` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "Jobs" DROP CONSTRAINT "Jobs_locationsId_fkey";

-- AlterTable
ALTER TABLE "Jobs" DROP COLUMN "locationsId",
ADD COLUMN     "locationId" TEXT NOT NULL;

-- AddForeignKey
ALTER TABLE "Jobs" ADD CONSTRAINT "Jobs_locationId_fkey" FOREIGN KEY ("locationId") REFERENCES "Locations"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
