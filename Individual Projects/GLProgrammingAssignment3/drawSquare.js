//Kirk McBrayer
//cs435628
window.onload = function init() {
  var canvas = document.getElementById("gl-canvas");
  gl  = canvas.getContext('webgl2');

  gl.clearColor (0.9, 0.9, 0.9, 1.0); 

  var program = initShaders(gl, "vertex-shader", "fragment-shader");
  gl.useProgram(program);

  	 var vertices = [-0.5,-0.5,0.0, 0.5,-0.5,0.0, 0.5,0.5,0.0, -0.5,0.5,0.0];
     var colors = [0,0,0, 1,0,0, 0,1,0, 0,0,1];

/* Use the following color array          
var colors = [0,0,0, 1,0,0, 0,1,0, 0, 0, 1]; */


var color_buffer = gl.createBuffer();
gl.bindBuffer (gl.ARRAY_BUFFER, color_buffer);
gl.bufferData (gl.ARRAY_BUFFER, new Float32Array(colors), gl.STATIC_DRAW);
var colorLoc = gl.getAttribLocation (program, "aColor");
gl.vertexAttribPointer (colorLoc, 3, gl.FLOAT, false, 0, 0);
gl.enableVertexAttribArray (colorLoc);

/* Here, you create buffer object and store color data 
as done above for vextex dat*/
var vertex_buffer = gl.createBuffer();
gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);
gl.bindBuffer(gl.ARRAY_BUFFER, null);

         gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
         var positionLoc = gl.getAttribLocation (program, "aPosition");
         gl.vertexAttribPointer (positionLoc, 3, gl.FLOAT, false, 0, 0);
  	 gl.enableVertexAttribArray (positionLoc);

/* Here, you bind the color buffer as variable "aColor"  
as done above for variable "aPosition */

  render();
};

/* Use gl.TRIANGLE_FAN to draw a square */

function render() {
  gl.clear (gl.COLOR_BUFFER_BIT);
  gl.drawArrays (gl.TRIANGLE_FAN, 0, 4);
}

