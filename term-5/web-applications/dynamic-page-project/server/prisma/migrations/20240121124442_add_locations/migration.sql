/*
  Warnings:

  - You are about to drop the column `locations` on the `Jobs` table. All the data in the column will be lost.
  - Added the required column `locationsId` to the `Jobs` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "Jobs" DROP COLUMN "locations",
ADD COLUMN     "locationsId" TEXT NOT NULL;

-- CreateTable
CREATE TABLE "Locations" (
    "id" TEXT NOT NULL,
    "city" TEXT NOT NULL,
    "lat" DOUBLE PRECISION NOT NULL,
    "lng" DOUBLE PRECISION NOT NULL,

    CONSTRAINT "Locations_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "Jobs" ADD CONSTRAINT "Jobs_locationsId_fkey" FOREIGN KEY ("locationsId") REFERENCES "Locations"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
