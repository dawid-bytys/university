import { BrowserRouter, Routes, Route } from 'react-router-dom';
import { Home } from '@/pages/Home';

export function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route
          index
          element={<Home />}
        />
      </Routes>
    </BrowserRouter>
  );
}
