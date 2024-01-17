import express from 'express';
import { jobsRouter } from './jobs.mjs';

export const router = express.Router();

router.use('/api/jobs', jobsRouter);
