//Kirk McBrayer
//cs435628
window.onload = function init() {
  var canvas = document.getElementById("gl-canvas");
  gl  = canvas.getContext('webgl2');

  gl.clearColor (0.9, 0.9, 0.9, 1.0); 

  var program = initShaders(gl, "vertex-shader", "fragment-shader");
  gl.useProgram(program);

  var vertices = [ -0.5, -0.5, 0.0, 0.5, -0.5, 0.0, 0.0, 0.5, 0.0 ];

/* Specify translation vector. Establish link and pass the values 
to the vertex shader using gl.getUniformLocation(program, 'uTranslate') 
and gl.uniform functions. */ 
   var tx = 0.5, ty = 0.0, tz = 0.0;
   uTranslate = gl.getUniformLocation(program, 'uTranslate');
   gl.uniform4f(uTranslate, tx, ty, tz, 0.0);

/* Specify scaling matrix. Establish the link and pass the values  
to the vertex shader using gl.getUniformLocation(program, 'uScale') 
and gl.uniform functions. */
var scaleMatrix = new Float32Array([
  0.5, 0.0, 0.0, 0.0,
  0.0, 0.5, 0.0, 0.0,
  0.0, 0.0, 1.0, 0.0,
  0.0, 0.0, 0.0, 1.0
  ]);
  var uScale = gl.getUniformLocation(program, 'uScale');
  gl.uniformMatrix4fv(uScale, false, scaleMatrix);

  var vertex_buffer = gl.createBuffer();
  gl.bindBuffer (gl.ARRAY_BUFFER, vertex_buffer);
  gl.bufferData (gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

  var positionLoc = gl.getAttribLocation(program, "aPosition");
  gl.vertexAttribPointer (positionLoc, 3, gl.FLOAT, false, 0, 0);
  gl.enableVertexAttribArray (positionLoc);


  render();
};

function render() {
  gl.clear (gl.COLOR_BUFFER_BIT);
  gl.drawArrays (gl.TRIANGLES, 0, 3);
}

