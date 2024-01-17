import express from 'express';
import cors from 'cors';
import { router } from './routes/index.mjs';
import { errorMiddleware } from './middlewares/errorMiddleware.mjs';

export function createServer() {
  const app = express();

  app.use(express.json());
  app.use(cors());
  app.use(errorMiddleware);
  app.use(router);

  return app;
}
