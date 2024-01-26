import { useState, useEffect } from 'react';

export function useFetch(options) {
  const { url, method, body, filters } = options;
  const [fetchingState, setFetchingState] = useState({
    state: 'loading',
    data: null,
    error: null,
  });

  useEffect(() => {
    async function fetchData() {
      try {
        console.log(`${url}?` + new URLSearchParams(filters).toString());
        const response = await fetch(`${url}?` + new URLSearchParams(filters).toString(), {
          method,
          body: JSON.stringify(body),
        });

        if (!response.ok) {
          throw new Error(response.statusText);
        }

        const data = await response.json();
        setFetchingState({ state: 'success', data, error: null });
      } catch (error) {
        setFetchingState({ state: 'error', data: null, error });
      }
    }

    fetchData();
  }, [url, method, body, filters]);

  return fetchingState;
}
