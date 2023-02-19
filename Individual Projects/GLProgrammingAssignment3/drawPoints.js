//Kirk McBrayer
//cs435628
window.onload = function init() {
  var canvas = document.getElementById("gl-canvas");
  gl  = canvas.getContext('webgl2');

  gl.clearColor (0.9, 0.9, 0.9, 1.0); 

  var program = initShaders(gl, "vertex-shader", "fragment-shader");
  gl.useProgram(program);

  var vertices = [ -0.5, -0.5, 0.0, 0.5, -0.5, 0.0, 0.0, 0.5, 0.0 ];

  var vertex_buffer = gl.createBuffer();
  gl.bindBuffer (gl.ARRAY_BUFFER, vertex_buffer);
  gl.bufferData (gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

  var positionLoc = gl.getAttribLocation(program, "aPosition");
  gl.vertexAttribPointer (positionLoc, 3, gl.FLOAT, false, 0, 0);
  gl.enableVertexAttribArray (positionLoc);
 
  render();
};

/* Use gl.POINTS to display vertices as points and gl.LINE_LOOP 
to draw a triangle outline. */

function render() {
  gl.clear (gl.COLOR_BUFFER_BIT);
  gl.drawArrays (gl.POINTS, 0, 3);
  gl.drawArrays (gl.LINE_LOOP, 0, 3);
}

