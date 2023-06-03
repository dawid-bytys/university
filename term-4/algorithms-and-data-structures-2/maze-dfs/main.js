const canvas = document.getElementById("maze-canvas");
const generateBtn = document.getElementById("generate-btn");
const ctx = canvas.getContext("2d");
let size = 35;
let cellSize = canvas.width / size;

const generateMaze = () => {
  size = parseInt(document.getElementById("size").value);
  cellSize = canvas.width / size;
  let maze = createMaze(size);
  drawMaze(maze);
};

const createEmptyMaze = (size) => {
  const maze = new Array(size)
    .fill(null)
    .map(() => new Array(size).fill(false));
  return maze;
};

const isValid = (x, y, size) => {
  return x >= 0 && x < size && y >= 0 && y < size;
};

const createMaze = (size) => {
  const maze = createEmptyMaze(size);
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
  maze[start[0]][start[1]] = true;

  while (stack.length > 0) {
    const current = stack.pop();
    let neighbors = [];

    for (const [dx, dy] of directions) {
      const x = current[0] + 2 * dx;
      const y = current[1] + 2 * dy;
      if (isValid(x, y, size) && !maze[x][y]) {
        neighbors.push([x, y, dx, dy]);
      }
    }

    if (neighbors.length > 0) {
      stack.push(current);
      const [nextX, nextY, dx, dy] =
        neighbors[Math.floor(Math.random() * neighbors.length)];
      maze[current[0] + dx][current[1] + dy] = true;
      maze[nextX][nextY] = true;
      stack.push([nextX, nextY]);
    }
  }

  return maze;
};

const drawMaze = (maze) => {
  ctx.fillStyle = "#fff";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = "#000";
  for (let x = 0; x < size; ++x) {
    for (let y = 0; y < size; ++y) {
      if (!maze[x][y]) {
        ctx.fillRect(x * cellSize, y * cellSize, cellSize, cellSize);
      }
    }
  }
};

generateMaze();
generateBtn.addEventListener("click", generateMaze);
