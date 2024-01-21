import { getJobs, addJob } from '../database/jobs.mjs';
import { mapJobsToDto } from '../dto/mapJobsToDto.mjs';

export async function getJobsController(_req, res) {
  const jobs = await getJobs();
  return res.json(mapJobsToDto(jobs));
}

export async function addJobController(req, res) {
  await addJob(req.body);
  return res.status(201).json({
    message: 'Your job listing has been successfully added!',
  });
}
