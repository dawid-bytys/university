import express from 'express';
import { getJobsController, addJobController } from '../controllers/jobs.mjs';

export const jobsRouter = express.Router('/jobs');

jobsRouter.get('/', getJobsController);
jobsRouter.post('/', addJobController);
