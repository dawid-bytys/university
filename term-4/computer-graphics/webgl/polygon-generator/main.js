document.addEventListener("DOMContentLoaded", () => {
  const verticesCount = document.getElementById("vertices-count");
  const radius = document.getElementById("radius");
  const generateBtn = document.getElementById("generate-btn");
  const canvas = document.getElementById("canvas");

  const createRegularPolygonVertices = (verticesCount, radius) => {
    const vertices = [];
    const angle = (2 * Math.PI) / verticesCount;
    for (let i = 0; i < verticesCount; ++i) {
      vertices.push(radius * Math.cos(i * angle));
      vertices.push(radius * Math.sin(i * angle));
    }
    return vertices;
  };

  let vertices = createRegularPolygonVertices(
    parseInt(verticesCount.value),
    parseFloat(radius.value)
  );

  const resizeCanvas = () => {
    canvas.width = 500;
    canvas.height = 500;
  };

  resizeCanvas();

  const gl = canvas.getContext("webgl");
  if (!gl) {
    throw new Error("WebGL not supported");
  }

  const vertexShaderSource = `
      attribute vec2 a_position;
      void main() {
        gl_Position = vec4(a_position, 0, 1);
      }
    `;

  const fragmentShaderSource = `
      precision mediump float;
      void main() {
        gl_FragColor = vec4(1, 0, 0, 1);
      }
    `;

  const createShader = (gl, type, source) => {
    const shader = gl.createShader(type);
    gl.shaderSource(shader, source);
    gl.compileShader(shader);
    return shader;
  };

  const vertexShader = createShader(gl, gl.VERTEX_SHADER, vertexShaderSource);
  const fragmentShader = createShader(
    gl,
    gl.FRAGMENT_SHADER,
    fragmentShaderSource
  );

  const program = gl.createProgram();
  gl.attachShader(program, vertexShader);
  gl.attachShader(program, fragmentShader);
  gl.linkProgram(program);

  const positionAttributeLocation = gl.getAttribLocation(program, "a_position");
  const positionBuffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);

  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

  gl.viewport(0, 0, canvas.width, canvas.height);
  gl.clearColor(1, 1, 1, 1);
  gl.clear(gl.COLOR_BUFFER_BIT);

  gl.useProgram(program);
  gl.enableVertexAttribArray(positionAttributeLocation);
  gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);
  gl.vertexAttribPointer(positionAttributeLocation, 2, gl.FLOAT, false, 0, 0);

  gl.drawArrays(gl.TRIANGLE_FAN, 0, vertices.length / 2);

  generateBtn.addEventListener("click", () => {
    vertices = createRegularPolygonVertices(
      parseInt(verticesCount.value),
      parseFloat(radius.value)
    );
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);
    gl.drawArrays(gl.TRIANGLE_FAN, 0, vertices.length / 2);
  });
});
