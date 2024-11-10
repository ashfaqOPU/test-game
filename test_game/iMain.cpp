# include "iGraphics.h"

#include<string>
int layer_speed1=-4;
int count=0;
int screenWidth=620, screenHeight=360;
int x = 300, y = 300, r = 20;
bool idle=1;

char girl[10][14]={"charex\\0.bmp", "charex\\1.bmp", "charex\\2.bmp", "charex\\3.bmp", "charex\\4.bmp", "charex\\5.bmp", "charex\\6.bmp", "charex\\7.bmp", "charex\\8.bmp", "charex\\9.bmp"};
char girlrun[9][14]={"charex\\8.bmp", "charex\\9.bmp", "charex\\10.bmp", "charex\\11.bmp", "charex\\12.bmp", "charex\\13.bmp", "charex\\14.bmp", "charex\\15.bmp", "charex\\16.bmp"};
char backmain1[10][20]={"output1\\part_1.bmp","output1\\part_2.bmp","output1\\part_3.bmp","output1\\part_4.bmp","output1\\part_5.bmp","output1\\part_6.bmp","output1\\part_7.bmp","output1\\part_8.bmp","output1\\part_9.bmp","output1\\part_10.bmp"};
int gi=0;
/*
	function iDraw() is called again and again by the system.

	*/
struct background{
	int x;
	int y;
};
background layer1[10];
void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(20, 200, 200);
	iShowBMP(0,0,"1.bmp");
	for (int i = 0; i < 10; i++) {
   		iShowBMP(layer1[i].x, layer1[i].y, backmain1[i]);
	}
	if(idle){
	iShowBMP2(screenWidth/2-50,screenHeight/2-80,girl[gi],0);
	}
	else{
	iShowBMP2(screenWidth/2-50,screenHeight/2-80,girlrun[gi],0);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	if(key=='s'){
		count=!count;
		if(!count)
			layer_speed1=0;
		else {
			layer_speed1=-4;
		}
		idle=!idle;
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}
void setAll(){
	int sum=0;
	for (int i = 0; i < 10; i++) {
    	layer1[i].y = 0;
    	layer1[i].x = sum;
	 	sum += 62;
	}
}
void change(){
	if(idle){
		gi++;
		if(gi>7){
			gi=0;
		}
	}
	else{
		gi++;
		if(gi>6){
			gi=0;
		}
	}
	for (int i = 0; i < 10; i++) {
    	layer1[i].x -= layer_speed1;
   		 if (layer1[i].x > screenWidth) {
        	layer1[i].x = 0;
    	}
	}
}



int main() {
    setAll();
    if (idle) {
        PlaySound("song.wav", NULL, SND_LOOP | SND_ASYNC);
    }
    iSetTimer(100, change);
    iInitialize(screenWidth, screenHeight, "demo");
    return 0;
}
