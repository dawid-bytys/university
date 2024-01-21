import { createBrowserRouter, RouterProvider } from 'react-router-dom';
import { HomePage } from './pages/HomePage';
import { AddJobPage } from './pages/AddJobPage';
import { Layout } from './components/Layout';
import { JobPage } from './pages/JobPage';

const router = createBrowserRouter([
  {
    element: <Layout />,
    children: [
      {
        path: '/',
        element: <HomePage />,
      },
      {
        path: '/add-job',
        element: <AddJobPage />,
      },
      {
        path: '/jobs/:id',
        element: <JobPage />,
      },
    ],
  },
]);

export function App() {
  return <RouterProvider router={router} />;
}
