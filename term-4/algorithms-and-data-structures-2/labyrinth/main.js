document.addEventListener("DOMContentLoaded", () => {
  const canvas = document.getElementById("labyrinth-canvas");
  const generateBtn = document.getElementById("generate-btn");
  const ctx = canvas.getContext("2d");
  let size = 35;
  let cellSize = canvas.width / size;

  const generateLabyrinth = () => {
    size = parseInt(document.getElementById("size").value);
    cellSize = canvas.width / size;
    let labyrinth = createLabyrinth(size);
    drawLabyrinth(labyrinth);
  };

  const createEmptyLabyrinth = (size) => {
    const labyrinth = new Array(size)
      .fill(null)
      .map(() => new Array(size).fill(false));
    return labyrinth;
  };

  const isValid = (x, y, size) => {
    return x >= 0 && x < size && y >= 0 && y < size;
  };

  const createLabyrinth = (size) => {
    const labyrinth = createEmptyLabyrinth(size);
    const stack = [];
    const directions = [
      [0, 1],
      [1, 0],
      [0, -1],
      [-1, 0],
    ];
    const start = [
      Math.floor(Math.random() * size),
      Math.floor(Math.random() * size),
    ];

    stack.push(start);
    labyrinth[start[0]][start[1]] = true;

    while (stack.length > 0) {
      const current = stack.pop();
      let neighbors = [];

      for (const [dx, dy] of directions) {
        const x = current[0] + 2 * dx;
        const y = current[1] + 2 * dy;
        if (isValid(x, y, size) && !labyrinth[x][y]) {
          neighbors.push([x, y, dx, dy]);
        }
      }

      if (neighbors.length > 0) {
        stack.push(current);
        const [nextX, nextY, dx, dy] =
          neighbors[Math.floor(Math.random() * neighbors.length)];
        labyrinth[current[0] + dx][current[1] + dy] = true;
        labyrinth[nextX][nextY] = true;
        stack.push([nextX, nextY]);
      }
    }

    return labyrinth;
  };

  const drawLabyrinth = (labyrinth) => {
    ctx.fillStyle = "#fff";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    ctx.fillStyle = "#000";
    for (let x = 0; x < size; ++x) {
      for (let y = 0; y < size; ++y) {
        if (!labyrinth[x][y]) {
          ctx.fillRect(x * cellSize, y * cellSize, cellSize, cellSize);
        }
      }
    }
  };

  generateLabyrinth();
  generateBtn.addEventListener("click", generateLabyrinth);
});
