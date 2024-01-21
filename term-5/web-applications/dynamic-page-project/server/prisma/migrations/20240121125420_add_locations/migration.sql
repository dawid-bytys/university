/*
  Warnings:

  - You are about to drop the column `lat` on the `Locations` table. All the data in the column will be lost.
  - Added the required column `lt` to the `Locations` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "Locations" DROP COLUMN "lat",
ADD COLUMN     "lt" DOUBLE PRECISION NOT NULL;
