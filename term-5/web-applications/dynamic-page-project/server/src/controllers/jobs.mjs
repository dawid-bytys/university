import { getJobs, addJob, getJobById } from '../database/jobs.mjs';
import { mapJobsToDto } from '../dto/mapJobsToDto.mjs';
import { mapJobToDto } from '../dto/mapJobToDto.mjs';

export async function getJobsController(req, res) {
  const { city } = req.query;
  const jobs = await getJobs(city);
  return res.json(mapJobsToDto(jobs));
}

export async function addJobController(req, res) {
  await addJob(req.body);
  return res.status(201).json({
    message: 'Your job listing has been successfully added!',
  });
}

export async function getSingleJobController(req, res) {
  const { id } = req.params;
  const job = await getJobById(id);
  return res.json(mapJobToDto(job));
}
