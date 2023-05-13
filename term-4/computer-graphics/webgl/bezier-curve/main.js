function main() {
  const canvas = document.getElementById("canvas");
  const gl = canvas.getContext("webgl");

  if (!gl) {
    alert(
      "Unable to initialize WebGL. Your browser or machine may not support it."
    );
    return;
  }

  canvasResize(gl, 1000, 1000);

  const vertexShaderSource = `
    attribute vec2 a_position;
    void main() {
      gl_Position = vec4(a_position, 0, 1);
    }
  `;

  const fragmentShaderSource = `
    precision mediump float;
    void main() {
      gl_FragColor = vec4(0, 0, 1, 1);
    }
  `;

  const program = initShaderProgram(
    gl,
    vertexShaderSource,
    fragmentShaderSource
  );

  gl.useProgram(program);

  const points = [];

  canvas.addEventListener("click", (e) => {
    const rect = e.target.getBoundingClientRect();
    const [x, y] = canvasToWebglCoordinates(
      canvas,
      e.clientX - rect.left,
      e.clientY - rect.top
    );

    const vertices = [x, y];

    for (let i = 0; i <= 360; i += 0.1) {
      const rad = (i * Math.PI) / 180;
      vertices.push(x + 0.05 * Math.cos(rad));
      vertices.push(y + 0.05 * Math.sin(rad));
    }

    points.push(vertices);

    for (let i = 0; i < points.length; ++i) {
      const buffer = gl.createBuffer();
      gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
      gl.bufferData(
        gl.ARRAY_BUFFER,
        new Float32Array(points[i]),
        gl.STATIC_DRAW
      );

      const position = gl.getAttribLocation(program, "a_position");
      gl.enableVertexAttribArray(position);
      gl.vertexAttribPointer(position, 2, gl.FLOAT, false, 0, 0);
      gl.drawArrays(gl.TRIANGLE_FAN, 0, points[i].length / 2);
    }

    if (points.length > 1) {
      const vertices = [];

      for (let i = 0; i <= 1; i += 0.01) {
        const [x, y] = deCasteljau(points, i);
        vertices.push(x);
        vertices.push(y);
      }

      const buffer = gl.createBuffer();
      gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
      gl.bufferData(
        gl.ARRAY_BUFFER,
        new Float32Array(vertices),
        gl.STATIC_DRAW
      );

      const position = gl.getAttribLocation(program, "a_position");
      gl.enableVertexAttribArray(position);
      gl.vertexAttribPointer(position, 2, gl.FLOAT, false, 0, 0);
      gl.drawArrays(gl.LINE_STRIP, 0, vertices.length / 2);
    }
  });
}

function canvasResize(gl, width, height) {
  canvas.width = width;
  canvas.height = height;
  gl.viewport(0, 0, canvas.width, canvas.height);
}

function drawCircle(gl, canvas, program, x, y, radius) {
  const [glX, glY] = canvasToWebglCoordinates(canvas, x, y);
  const vertices = [glX, glY];

  for (let i = 0; i <= 360; i += 0.01) {
    const rad = (i * Math.PI) / 180;
    vertices.push(glX + radius * Math.cos(rad));
    vertices.push(glY + radius * Math.sin(rad));
  }

  const buffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

  const position = gl.getAttribLocation(program, "a_position");
  gl.enableVertexAttribArray(position);
  gl.vertexAttribPointer(position, 2, gl.FLOAT, false, 0, 0);
  gl.drawArrays(gl.TRIANGLE_FAN, 0, vertices.length / 2);
}

function initShaderProgram(gl, vertexShaderSource, fragmentShaderSource) {
  const vertexShader = loadShader(gl, gl.VERTEX_SHADER, vertexShaderSource);
  const fragmentShader = loadShader(
    gl,
    gl.FRAGMENT_SHADER,
    fragmentShaderSource
  );

  const program = gl.createProgram();
  gl.attachShader(program, vertexShader);
  gl.attachShader(program, fragmentShader);
  gl.linkProgram(program);

  if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
    alert(
      "Unable to initialize the shader program: " +
        gl.getProgramInfoLog(program)
    );
    return null;
  }

  return program;
}

function loadShader(gl, type, source) {
  const shader = gl.createShader(type);
  gl.shaderSource(shader, source);
  gl.compileShader(shader);

  if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
    alert(
      "Failed to compile shader: " + gl.getShaderInfoLog(shader) + "\n" + source
    );
    gl.deleteShader(shader);
    return null;
  }

  return shader;
}

function canvasToWebglCoordinates(canvas, x, y) {
  const glX = (2.0 * x) / canvas.width - 1;
  const glY = 1 - (2.0 * y) / canvas.height;
  return [glX, glY];
}

function deCasteljau(points, t) {
  if (points.length === 1) {
    return points[0];
  }

  const newPoints = [];

  for (let i = 0; i < points.length - 1; ++i) {
    const x = (1 - t) * points[i][0] + t * points[i + 1][0];
    const y = (1 - t) * points[i][1] + t * points[i + 1][1];
    newPoints.push([x, y]);
  }

  return deCasteljau(newPoints, t);
}

document.addEventListener("DOMContentLoaded", main);
