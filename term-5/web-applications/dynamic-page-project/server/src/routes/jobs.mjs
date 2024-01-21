import express from 'express';
import {
  getJobsController,
  addJobController,
  getSingleJobController,
} from '../controllers/jobs.mjs';

export const jobsRouter = express.Router('/jobs');

jobsRouter.get('/', getJobsController);
jobsRouter.get('/:id', getSingleJobController);
jobsRouter.post('/', addJobController);
