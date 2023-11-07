
#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;


int car_score=0;

int drop_count=0;
int pick_up[3]={0};


int red_car_x=155;
int red_car_y=560;

int black_car_x=455;
int black_car_y=610;

int xVar = 5;  // Gobal Variables
int yVar = 710; // Used in Draing Car

int random_1;
int random_2;

int p_1_x=310;
int p_1_y=705;
int p_2_x=465;
int p_2_y=110;
int p_3_x=665;
int p_3_y=460;

int drop_1_x;
int drop_1_y;
int drop_2_x;
int drop_2_y;
int drop_3_x;
int drop_3_y;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
// File Handling
void fileWriting()
{
	ofstream ofile;
	ofile.open ("Score.txt");
	ofile << car_score << endl;
	ofile.close();
}


int xI = 400, yI = 400;

void drawCar() {
	DrawSquare(xI, yI, 20, colors[WHITE]);
	glutPostRedisplay();
}

void move_black_car()
{
	if(black_car_x>=455 && black_car_x<705 && black_car_y==610)
	{
		black_car_x+=10;
	}
	else if(black_car_x==705 && black_car_y>=570 && black_car_y<=610)
	{
		black_car_y-=10;
	}
	else if(black_car_x>455 && black_car_x<=705 && black_car_y==560)
	{
		black_car_x-=10;
	}
	else if(black_car_x==455 && black_car_y>=560 && black_car_y<=610)
	{
		black_car_y+=10;
	}
}


//bool flag = true;
void moveCar() {

	if(red_car_x>=155 && red_car_x<=200 && red_car_y==560)
	{
		red_car_x+=10;
	}
	else if(red_car_x==205 && red_car_y>=220 && red_car_y<=560)
	{
		red_car_y-=10;
	}
	else if(red_car_x<=205 && red_car_x>155 && red_car_y==210)
	{
		red_car_x-=10;
	}
	else if(red_car_x==155 && red_car_y>=210 && red_car_y<=560)
	{
		red_car_y+=10;
	}
}

void show_passenger(int a, int b)
{
	DrawLine( a , b ,  a, b+30 , 10 , colors[WHITE] );
	DrawLine( a-2 , b+25 ,  a-2 , b+45 , 25 , colors[DEEP_SKY_BLUE] );
	DrawLine( a+10 , b+20 ,  a ,b+10 , 5 , colors[GREEN_YELLOW] );
}

void show_drop_off(int a, int b)
{
	DrawSquare(a, b, 40, colors[RED]);
}

// DrawLine( 310 , 705 ,  310 ,735 , 10 , colors[WHITE] );
// DrawLine( 308 , 730 ,  308 ,750 , 25 , colors[DEEP_SKY_BLUE] );
// DrawLine( 320 , 725 ,  310 ,715 , 5 , colors[GREEN_YELLOW] );

/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	// DrawSquare(400, 20, 40, colors[RED]);
	//
	// //Green Square
	// DrawSquare( 250 , 250 ,20,colors[GREEN]);
	//
	// //Display Score
	 DrawString( 100, 800, "Score= " +std::to_string(car_score), colors[MISTY_ROSE]);
	//

if(car_score < -10)
{
	DrawString( 700, 800, "Game Over", colors[MISTY_ROSE]);
	fileWriting();
}


	// //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	int xAxis = 0;
	int y1Axis = 0;
	int y2Axis = 750;
	int width = 5;
	int trd = 0;
	for (int i = 1; i <21; i++)  // For Vertical Lines
	{
		DrawLine( xAxis , y1Axis ,  xAxis ,y2Axis , width , colors[BLACK] );
		//trd+=50;
		xAxis+=50;
	}

	int x1_Axis = 0;
	int y1_Axis = 750;
	int lenght = 952;   // Ending point
	int height = 5;

	for ( int i = 1; i < 21; i++)  // For Horizontal Lines
	{
		DrawRectangle( x1_Axis, y1_Axis, lenght , height, colors[BLACK] );
		y1_Axis-=50;
	}

	int x_Axis = xVar;;
	int y_Axis = yVar;
	int car_width=10;
	int car_height=7;
	float car_radius=3.5;
	float *color= colors[HOT_PINK];
//_________________________________________________- For Drawing Car______________________________________
	DrawRoundRect(x_Axis + car_width, y_Axis + car_height, car_width*2, car_height*3, color, car_radius/2);
	DrawRoundRect(x_Axis,y_Axis,car_width,car_height,color,car_radius); // bottom left tyre
	DrawRoundRect(x_Axis + car_width*3, y_Axis ,car_height,car_height,color,car_radius);

	int car_2_x=red_car_x;
	int car_2_y=red_car_y;
	color=colors[RED];
	DrawRoundRect(car_2_x + car_width, car_2_y + car_height, car_width*2, car_height*3, color, car_radius/2);
	DrawRoundRect(car_2_x,car_2_y,car_width,car_height,color,car_radius); // bottom left tyre
	DrawRoundRect(car_2_x + car_width*3, car_2_y ,car_height,car_height,color,car_radius);

	if(drop_count>=2)
	{
		int car_3_x=black_car_x;
		int car_3_y=black_car_y;
		color=colors[BLACK];
		DrawRoundRect(car_3_x + car_width, car_3_y + car_height, car_width*2, car_height*3, color, car_radius/2);
		DrawRoundRect(car_3_x,car_3_y,car_width,car_height,color,car_radius); // bottom left tyre
		DrawRoundRect(car_3_x + car_width*3, car_3_y ,car_height,car_height,color,car_radius);
	}
//_______________________________________________________________________________________________________

// _________________________________________ For Drawing obstacles________________________________

int x__Axis = 102;
int y__Axis = 650;
int w = 50;
int h = 12;
float *c = colors[BLACK];
for (int i = 0; i < 500; i++)  // Left most Vertical
 {
	DrawRectangle( x__Axis, y__Axis, w ,h ,  c);
	y__Axis-=1;
	if(y__Axis == 105)
	 break;
}
// ______________________________________________________________________________

int x__axis = 246;
int y__axis = 52;
int wi = 12;
int he = 50;
float *co = colors[BLACK];
for (int i = 0; i < 820; i++)  // Bottom_Horizontal
 {
	DrawRectangle( x__axis, y__axis, wi ,he ,  co);
	x__axis+=1;
	if(x__axis == 837)
	 break;
}
// __________________________________________________________________________________


int x_axis = 852;
int y_axis = 639;
int wid = 50;
int hei = 12;
float *col = colors[BLACK];
for (int i = 0; i < 600; i++)  // Right most T-Shape (Vertical-side)
 {
	DrawRectangle( x_axis, y_axis, wid ,hei ,  col);
	y_axis-=1;
	if(y_axis == 200)
	 break;
}

int x___axis = 646;
int y___axis = 402;
int widt = 12;
int heig = 50;
float *colo = colors[BLACK];
for (int i = 0; i < 820; i++)  // Right most T-Shape (Horizontal-side)
 {
	DrawRectangle( x___axis, y___axis, widt ,heig ,  colo);
	x___axis+=1;
	if(x___axis == 837)
	 break;
}
//___________________________________________________________________________________________
int x___Axis = 302;
int y___Axis = 547;
int _width = 50;
int _height = 12;
float *_color = colors[BLACK];
for (int i = 0; i < 600; i++)  // Between (Vertical)
 {
	DrawRectangle( x___Axis, y___Axis, _width ,_height ,  _color);
	y___Axis-=1;
	if(y___Axis == 250)
	 break;
}
//___________________________________________________________________________________

int xaxis = 300;
int yaxis = 654;
int _wid = 12;
int _heigh = 50;
float *_colo = colors[BLACK];
for (int i = 0; i < 820; i++)  // Upper Horizontal
 {
	DrawRectangle( xaxis, yaxis, _wid ,_heigh ,  _colo);
	xaxis+=1;
	if(xaxis == 737)
	 break;
}

// -------------- Car__Hiting__For Left Most Obstacle--------------------------
if(xVar==65 && yVar>=120 && yVar<=660)  // For Left side of Left most obstacles________________________________
{
	xVar=5;    // Assigning Random Values
	yVar=500;
	car_score-=4;
}

if(xVar==145 && yVar>=130 && yVar<=660) // For Right side of Left most obstacles____
{
	xVar=5;    // Assigning Random Values
	yVar=500;
	car_score-=4;
}


if(yVar==660 && xVar>=65 && xVar<=145) // For Upper side of Left most obstacles____
{
	xVar=5;
	yVar=500;
	car_score-=4;
}

if(yVar==120 && xVar>=65 && xVar<=135) // For Lower side of Left most obstacles____
{
	xVar=5;
	yVar=500;
	car_score-=4;
}
// -------------------CLOSING_____(Car__Hiting__For Left Most Obstacle)--------------------------------

   // ----- For In_Between__Obstacle
if(xVar==265 && yVar>=230 && yVar<=550)  // For Left side of In_Between obstacles________________________________
{
	xVar=205;    // Assigning Random Values
	yVar=410;
	car_score-=4;
}
if(xVar==345 && yVar>=230 && yVar<=560)  // For Right side of Left most obstacles________________________________
{
	xVar=205;    // Assigning Random Values
	yVar=410;
	car_score-=4;
}

if(yVar==560 && xVar>=265 && xVar<=345) // For Upper side of Left most obstacles____
{
	xVar=205;    // Assigning Random Values
	yVar=410;
	car_score-=4;
}

if(yVar==220 && xVar>=265 && xVar<=335) // For Lower side of Left most obstacles____
{
	xVar=205;    // Assigning Random Values
	yVar=410;
	car_score-=4;
}
// ____________ CLOSING_____ IN-Between Obstacle

// ______________ Upper Obstacle---------------------------------

if(xVar==265 && yVar>=620 && yVar<=700)
{  // For Left side of UPPER OBSTACLE________________________________
	xVar=205;    // Assigning Random Values
	yVar=660;
	car_score-=4;
}
if(xVar==745 && yVar>=620 && yVar<=700)  // For Right side of UPPER OBSTACLE________________________________
{
	xVar=205;    // Assigning Random Values
	yVar=660;
	car_score-=4;
}

if(yVar==700 && xVar>=265 && xVar<=745) // For Upper side of UPPER OBSTACLE____
{
	xVar=205;    // Assigning Random Values
	yVar=660;
	car_score-=4;
}

if(yVar==620 && xVar>=265 && xVar<=745) // For Lower side of UPPER OBSTACLE ____
{
	xVar=205;    // Assigning Random Values
	yVar=660;
	car_score-=4;
}
// ----- CLOSING ____________ UPPER OBSTACLE___________________

// ----------------------------- BOTTOM_OBSTACLE --------------------------
if(xVar==215 && yVar>=50 && yVar<=100)  // For Left side of BOttom OBSTACLE________________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
	car_score-=4;
}
if(xVar==845 && yVar>=50 && yVar<=100)  // For Right side of BOttom OBSTACLE________________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
	car_score-=4;
}

if(yVar==100 && xVar>=215 && xVar<=845) // For Upper side of BOttom OBSTACLE____
{
	xVar=155;    // Assigning Random Values
	yVar=60;
	car_score-=4;
}

if(yVar==20 && xVar>=215 && xVar<=845) // For Lower side of BOttom OBSTACLE ____
{
	xVar=155;    // Assigning Random Values
	yVar=60;
	car_score-=4;
}
// CLOSING __ BOttom__________________________________________
//----------------------------------------------------------------------------
// -----------------T-Shaped------------------
    // Vertical side of T-Shaped
if(xVar==815 && yVar>=200 && yVar<=650)  // For Left side of In_Between obstacles________________________________
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}
if(xVar==895 && yVar>=200 && yVar<=660)  // For Right side of Left most obstacles________________________________
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}

if(yVar==650 && xVar>=815 && xVar<=895) // For Upper side of Left most obstacles____
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}

if(yVar==170 && xVar>=825 && xVar<=895) // For Lower side of Left most obstacles____
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}
//---------------------------------------------------------------

// -----------------Horizontal Side of T-Shaped------------------------------

if(xVar==615 && yVar>=400 && yVar<=450)  // For Left side of Horizontal Side of T-Shape OBSTACLE________________________________
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}

if(yVar==450 && xVar>=615 && xVar<=815) // For Upper side ofHorizontal Side of T-Shape OBSTACLE____
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}

if(yVar==380 && xVar>=615 && xVar<=815) // For Lower side of Horizontal Side of T-Shape OBSTACLE ____
{
	xVar=755;    // Assigning Random Values
	yVar=560;
	car_score-=4;
}




//----------------------------- Closing Obstacles ---------------------------------------------

// ----------------------Creating Passenger---------------------------- // x = 305 y = 700
if(pick_up[0]==0)
{
	show_passenger(p_1_x,p_1_y);
	//show_passenger(465,110);
}
if(pick_up[1]==0)
{
	show_passenger(p_2_x,p_2_y);
}
if(pick_up[2]==0)
{
	show_passenger(p_3_x,p_3_y);
}
if(pick_up[0]==1)
{
	show_drop_off(drop_1_x, drop_1_y);
}
if(pick_up[1]==1)
{
	show_drop_off(drop_2_x, drop_2_y);
}
if(pick_up[2]==1)
{
	show_drop_off(drop_3_x, drop_3_y);
}

				  // Upper Passenger
		// DrawLine( 310 , 705 ,  310 ,735 , 10 , colors[WHITE] );
		// DrawLine( 308 , 730 ,  308 ,750 , 25 , colors[DEEP_SKY_BLUE] );
	 	// DrawLine( 320 , 725 ,  310 ,715 , 5 , colors[GREEN_YELLOW] );

//  -------------Right Passemger on (T-Shape)
	// 	DrawLine( 695 , 450 ,  695 , 480 , 10 , colors[WHITE] );
	// 	DrawLine( 693 , 475 ,  693 , 495 , 25 , colors[DEEP_SKY_BLUE] );
	// 	DrawLine( 705 , 470 ,  695 , 460 , 5 , colors[GREEN_YELLOW] );
 //
 // // ----- Bottom Passenmger-----------------
 // DrawLine(  485, 102 ,  485 ,132 , 10 , colors[WHITE] );
 // DrawLine( 483 , 127 ,  483 ,147 , 25 , colors[DEEP_SKY_BLUE] );
 // DrawLine( 495 , 122 ,  485 ,112 , 5 , colors[GREEN_YELLOW] );

// --------------- Drawing Tree -----------------------
   // Upper Tree___________
DrawLine(  535, 703 ,  535 ,733 , 10 , colors[BROWN] );
DrawRoundRect(522 ,733 , 25 , 20 ,colors[GREEN], 4);

// Tree on T-Shaped
DrawLine(  795,    453 ,  795 ,483 , 10 , colors[BROWN] );
DrawRoundRect(782 ,483 ,  25 , 20 ,colors[GREEN], 4);

// ----------- Bottom Right
DrawLine(  655, 103 ,  655 ,133 , 10 , colors[BROWN] );
DrawRoundRect(640 ,133 , 25 , 20 ,colors[GREEN], 4);

// --------- Bottom Left------------
DrawLine(  275, 103 ,  275 ,133 , 10 , colors[BROWN] );
DrawRoundRect(262 ,133 , 25 , 20 ,colors[GREEN], 4);

// -------------------------------------------------------------------------------------
//      -------- Hiting For Upper Tree-----------
if(xVar==545 && yVar>=700 && yVar<=750)  // Hiting For Upper Tree______________________________
{
	xVar=205;    // Assigning Random Values
	yVar=660;
}

if(xVar==485 && yVar>=700 && yVar<=750)  //Hiting For Upper Tree________________________________
{
	xVar=205;    // Assigning Random Values
	yVar=660;
}
if(yVar==750 && xVar>=485 && xVar<=545)  // Hiting For Upper Tree_______________________________
{
	xVar=205;    // Assigning Random Values
	yVar=660;
}
//____________________________________________________________________________________
//------------------------ Hiting For Bottom Right Tree-----------
if(xVar==605 && yVar>=100 && yVar<=150)  // Hiting For Upper Tree______________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
}

if(yVar==150 && xVar>=605 && xVar<=665)  //Hiting For Bottom Right Tree________________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
}
if(xVar==665 && yVar>=100 && yVar<=150)  // Hiting For  Bottom Right Tree_______________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
}
// ---------------------------------------------------------------------------------------
//225  150 --------------Bottom Left Tree Hitting-------------------------------------------------------------------------

if(xVar==225 && yVar>=100 && yVar<=150)  // Hiting For Bottom Left Tree______________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
}

if(yVar==150 && xVar>=225 && xVar<=275)  //Hiting For Bottom Left Tree________________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
}
if(xVar==285 && yVar>=100 && yVar<=150)  // Hiting For Bottom Left Tree_______________________________
{
	xVar=155;    // Assigning Random Values
	yVar=60;
}

// -----------------------------------Tree on T-Shaped____________________

if(xVar==745 && yVar>=450 && yVar<=500)  // Hiting For Bottom Left Tree______________________________
{
	xVar=755;    // Assigning Random Values
	yVar=560;
}

if(yVar==500 && xVar>=745 && xVar<=805)  //Hiting For Bottom Left Tree________________________________
{
	xVar=755;    // Assigning Random Values
	yVar=560;;
}
//--------------------------------- Cloding Hittinfg Tree on T-Shaped

		// DrawLine( 310 , 705 ,  310 ,735 , 10 , colors[WHITE] );
	//	DrawSquare(310, 740, 5,colors[WHITE]);

	//	DrawCircle(302,737,5,colors[RED]);
	//	DrawCircle(50,670,10,colors[RED]);

	// }





	// DrawLine( 0yyyy , 0 ,  0 , 850 , 10 , colors[BLACK] );
	// DrawLine( 50 , 0 ,  50 , 850 , 2 , colors[BLACK] );
	// DrawLine( 140 , 0 ,  140 , 850 , 2 , colors[BLACK] );
	// DrawLine( 210 , 0 ,  210 , 850 , 2 , colors[BLACK] );
	// DrawLine( 280 , 0 ,  280 , 850 , 2 , colors[BLACK] );
	// DrawLine( 350 , 0 ,  350 , 850 , 2 , colors[BLACK] );
	// DrawLine( 420 , 0 ,  420 , 850 , 2 , colors[BLACK] );
	// DrawLine( 490 , 0 ,  490 , 850 , 2 , colors[BLACK] );
	// DrawLine( 560 , 0 ,  560 , 850 , 2 , colors[BLACK] );
	// DrawLine( 630 , 0 ,  630 , 850 , 2 , colors[BLACK] );
	// DrawLine( 700 , 0 ,  700 , 850 , 2 , colors[BLACK] );
	// DrawLine( 770 , 0 ,  770 , 850 , 2 , colors[BLACK] );
	// DrawLine( 840 , 0 ,  840 , 850 , 2 , colors[BLACK] );
	// DrawLine( 910 , 0 ,  910 , 850 , 2 , colors[BLACK] );
	// DrawLine( 990 , 0 ,  990 , 850 , 2 , colors[BLACK] );
	//DrawLine( 1060 , 0 ,  700 , 850 , 2 , colors[BLACK] );


	//
	// DrawCircle(50,670,10,colors[RED]);
	// DrawCircle(70,670,10,colors[RED]);
	// DrawCircle(90,670,10,colors[RED]);
	// DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	// DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);
	// DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	// DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	// DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	//
	// drawCar();gyylutMouseFunc(MouglutMouseFunc(MouseClicked);
	// glutPassiveMotionFunc(MouseMoved); // Mouse
	// glutMotionFunc(MousePressedAndMoved); // MouseseClicked);
	// glutPassiveMotionFunc(MouseMoved); // Mouse
	// glutMotionFunc(MousePressedAndMoved); // Mouse

	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	// show_passenger(a_axis, b_axis);
	// glutPostRedisplay();
	  // Moving Car___
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
				if(xVar>5)
				{
					xVar -= 10;
					cout << " X-Axis is: " << xVar << endl;
					cout << "Y-Axis is: " << yVar << endl;
				}
		// what to do when left key is pressed...
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
				if(xVar<905)
				{
					xVar += 10;
					cout << " X-Axis is: " << xVar << endl;
					cout << "Y-Axis is: " << yVar << endl;
				}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
				if(yVar<=710)
				{
					yVar += 10;
					cout << " X-Axis is: " << xVar << endl;
					cout << "Y-Axis is: " << yVar << endl;
				}

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
				if(yVar>10)
				{
					yVar -= 10;
					cout << " X-Axis is: " << xVar << endl;
					cout << "Y-Axis is: " << yVar << endl;
				}

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

bool Is_passenger_1_near()
{
	if(xVar>=255 && xVar<=265 && yVar==710)
	{
		return true;
	}
	return false;
}

bool Is_passenger_2_near()
{
	if(xVar>=405 && xVar<=415 && yVar==110)
	{
		return true;
	}
	return false;
}

bool Is_passenger_3_near()
{
	if(xVar>=605 && xVar<=615 && yVar==460)
	{
		return true;
	}
	return false;
}

bool Is_dropoof_1_near()
{
	if(xVar>=855 && xVar<=905 && yVar>=50 && yVar<=150)
	{
		return true;
	}
	return false;
}

bool Is_dropoof_2_near()
{
	if(xVar>=55 && xVar<=135 && yVar>=660 && yVar<=700)
	{
		return true;
	}
	return false;
}

bool Is_dropoof_3_near()
{
	if(xVar>=505 && xVar<=555 && yVar>=10 && yVar<=50)
	{
		return true;
	}
	return false;
}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if(key==32 && Is_passenger_1_near())
	{
		pick_up[0]=1;
	}
	if(key==32 && Is_passenger_2_near())
	{
		pick_up[1]=1;
	}
	if(key==32 && Is_passenger_3_near())
	{
		pick_up[2]=1;
	}

	if(key==32 && Is_dropoof_1_near())
	{
		pick_up[0]=0;
		p_1_x=drop_1_x;  //Replacing randomize destination to Passenger
		p_1_y=drop_1_y;
		drop_count++;
		car_score+=10;
	}
	if(key==32 && Is_dropoof_2_near())
	{
		pick_up[1]=0;
		p_2_x=drop_2_x;
		p_2_y=drop_2_y;
		drop_count++;
		car_score+=10;
	}
	if(key==32 && Is_dropoof_3_near())
	{
		pick_up[2]=0;
		p_3_x=drop_3_x;
		p_3_y=drop_3_y;
		drop_count++;
		car_score+=10;
	}

	// if(key=='T' || key=='t')
	// {
	// 	pick_up[0]=0;
	// 	pick_up[1] = 0;
	// 	pick_up[2] = 0;
	// }

	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveCar();
	if(drop_count>=2)
	{
			move_black_car();
	}
	glutPostRedisplay();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(5000.0/FPS, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	// File Handling



		drop_1_x=GetRandInRange(855,905);
		drop_1_y=GetRandInRange(50,150);
		cout << "Random x-axis= " << drop_1_x << endl;
		cout << "Random y-axis= " << drop_1_y << endl;

		drop_2_x=GetRandInRange(55,135);
		drop_2_y=GetRandInRange(660,700);
		drop_3_x=GetRandInRange(505,555);
		drop_3_y=GetRandInRange(10,50);
		// random_1=GetRandInRange(0,50);
		// random_2=GetRandInRange(0,750);
		// cout << "Random x-axis= " << random_1 << endl;
		// cout << "Random y-axis= " << random_2 << endl;

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0/FPS, Timer, 0);

	// glutMouseFunc(MouseClicked);
	// glutPassiveMotionFunc(MouseMoved); // Mouse
	// glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
