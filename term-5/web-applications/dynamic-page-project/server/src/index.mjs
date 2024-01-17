import { createServer } from './server.mjs';

function main() {
  const app = createServer();

  app.listen(3000, () => {
    console.log('Server listening on port 3000');
  });
}

main();
