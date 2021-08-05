
var canvas;
var canvasContext;
var ballX = 50;
var ballY = 50;
var ballSpeedX = 10;
var ballSpeedY = 4;

var player1Score = 0;
var player2Score = 0;
const WINNING_SCORE = 3;

var showingWinScreen = false;

var paddle1Y = 250;
var paddle2Y = 250;
const PADDLE_HEIGHT = 100;
const PADDLE_THICKNESS = 10;
//const means that the above values remain constant in all of the code//
//Changing it above, changes it everywhere//


//below is also used to make the mouse move//
function calculateMousePos(evt) {
	var rect = canvas.getBoundingClientRect();
	var root = document.documentElement;
	var mouseX = evt.clientX - rect.left - root.scrollLeft;
	var mouseY = evt.clientY - rect.top - root.scrollTop;
	return {
		x:mouseX,
		y:mouseY
	};
}

window.onload = function() {
	canvas = document.getElementById('gameCanvas');
	canvasContext = canvas.getContext('2d');

//below code determines how the ball moves//
	var framesPerSecond = 30;
	setInterval(function() {
			moveEverything();
			drawEverything();
		}, 1000/framesPerSecond);


//below code is to make our mouse move the left paddle//
	canvas.addEventListener('mousemove',
		function(evt) {
			var mousePos = calculateMousePos(evt);
			paddle1Y = mousePos.y - (PADDLE_HEIGHT/2);
		});
}

//code below detrmines when the game becomes reset//
function ballReset() {
  if(player1Score >= WINNING_SCORE ||
	   player2Score >= WINNING_SCORE ) {
           player1Score = 0;
					 player2Score =0;
					 showingWinScreen = true;

		 }

	ballSpeedX = -ballSpeedX;
	ballX = canvas.width/2;
	ballY = canvas.height/2;
}

//function computerMovement makes the right paddle so that it can hit the ball//
function computerMovement (){
	       var paddle2YCenter = paddle2Y + (PADDLE_HEIGHT/2);
	       if(paddle2Y < ballY-35) {
					     paddle2Y += 5;
						} else if(paddle2YCenter < ballY +35){
							paddle2Y -= 5;
						}
}


//code below tells the computer how to move the ball//
function moveEverything() {
	     if (showingWinScreen){
				      return;
			 }
         computerMovement ();

	ballX += ballSpeedX;
	ballY +=  ballSpeedY;

	if(ballX < 0) {
		   if(ballY > paddle1Y &&
				  ballY < paddle1Y+PADDLE_HEIGHT) {
						   ballSpeedX = -ballSpeedX;

							 var deltaY = ballY
							         -(paddle1Y+PADDLE_HEIGHT/2);
									ballSpeedY = deltaY *0.25;

				} else {
					     player2Score ++; //MUST BE BEFORE BALL RESET //
		           ballReset();
						  }
	}
	if(ballX > canvas.width) {
		if(ballY > paddle2Y &&
			 ballY < paddle2Y+PADDLE_HEIGHT) {
						ballSpeedX = -ballSpeedX;

//the deltaY stuff belows determines the speed of the ball depending on //
//where the ball hits the paddle //
						var deltaY = ballY
										-(paddle2Y+PADDLE_HEIGHT/2);
							 ballSpeedY = deltaY *0.35;

			 } else {
				    player1Score ++; //MUST BE BEFORE BALL RESET //
						ballReset();
					 }
		}


	if(ballY < 0) {
		ballSpeedY = -ballSpeedY;
	}
	if(ballY > canvas.height) {
		ballSpeedY = -ballSpeedY;
	}
}


//function drawEverything draws all the shapes that we need in the game//
function drawEverything() {
	// next line blanks out the screen with black
	colorRect(0,0,canvas.width,canvas.height,'black');

	if(showingWinScreen) {
		    canvasContext.fillStyle = 'white';
		    canvasContext.fillText("Click to continue", 100, 100);
		    return;
	      }

	// this is the left player paddle
	colorRect(0,paddle1Y,PADDLE_THICKNESS,PADDLE_HEIGHT,'white');

	// this is the right player paddle
	colorRect(canvas.width -PADDLE_THICKNESS,paddle2Y,PADDLE_THICKNESS,PADDLE_HEIGHT,'white');

	// next line draws the ball
	colorCircle(ballX, ballY, 10, 'white');

	canvasContext.fillText(player1Score, 100, 100);
	canvasContext.fillText(player2Score, canvas.width -100,100);
}

function colorCircle(centerX, centerY, radius, drawColor) {
	canvasContext.fillStyle = drawColor;
	canvasContext.beginPath();
	canvasContext.arc(centerX, centerY, radius, 0,Math.PI*2,true);
	canvasContext.fill();
}

function colorRect(leftX,topY, width,height, drawColor) {
	canvasContext.fillStyle = drawColor;
	canvasContext.fillRect(leftX,topY, width,height);}
