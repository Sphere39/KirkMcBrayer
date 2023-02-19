function setup() {
  createCanvas(500, 1500);
}

function draw() {
  //Example 1
  background(0, 255, 0);
  fill(255, 255, 255)
  stroke(0, 0, 0)
  strokeWeight(1)
  ellipse(100, 100, 100, 100)
  rect(300, 50, 100, 100)
  //Example 2
  noStroke()
  fill(255, 255, 255)
  rect(0, 250, 500, 500)
  fill(255, 0, 0, 100)
  ellipse(250, 450, 200, 200)
  fill(0, 255, 0, 100)
  ellipse(300, 550, 200, 200)
  fill(0, 0, 255, 100)
  ellipse(200, 550, 200, 200)
  //Example 3
  fill(0, 0, 0)
  rect(0, 750, 500, 250)
  fill(255, 255, 0)
  arc(150, 875, 100, 100, 5*PI/4, 3*PI/4)
  fill(255, 0, 0)
  ellipse(350, 875, 100, 100)
  rect(300, 875, 100, 50)
  fill(255, 255, 255)
  ellipse(325, 875, 25, 25)
  ellipse(375, 875, 25, 25)
  fill(0, 0, 255)
  ellipse(325, 875, 15, 15)
  ellipse(375, 875, 15, 15)
  //Example 4
  fill(0, 0, 255)
  rect(0, 1000, 500, 500)
  fill(0, 200, 0)
  strokeWeight(5)
  stroke(255, 255, 255)
  ellipse(250, 1250, 200, 200)
  fill(255, 0, 0)
  beginShape();
  vertex(250,1150)
  vertex(225,1220)
  vertex(165,1220)
  vertex(210,1255)
  vertex(190,1325)
  vertex(250,1290)
  vertex(310,1325)
  vertex(290,1255)
  vertex(335,1220)
  vertex(275,1220)
  endShape(CLOSE);
}

