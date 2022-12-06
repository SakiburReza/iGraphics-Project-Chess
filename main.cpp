#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"

int x=0 ,y =0, l = 0;
int soilder[8][8]={{52,53,54,55,56,54,53,52},
                   {51,51,51,51,51,51,51,51},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {11,11,11,11,11,11,11,11},
                  {12,13,14,15,16,14,13,12}};


int i,j;
char lastKey = 0;
int black_move=1,white_move=1,indicator=0;

void pawn_move()
{
    if(j>=1&&j<2){

      iSetColor(0,255,0);
       iFilledRectangle(i*100,j*100,100,10);
       iFilledRectangle(i*100,j*100,10,100);
       iFilledRectangle(i*100,j*100+90,100,10);
       iFilledRectangle(i*100+90,j*100,10,100);

        iSetColor(0,0,255);
       iFilledRectangle(i*100,(j+1)*100,100,10);
       iFilledRectangle(i*100,  (j+1)*100,10,100);
       iFilledRectangle(i*100,(j+1)*100+90,100,10);
       iFilledRectangle(i*100+90,(j+1)*100,10,100);

        iFilledRectangle(i*100,(j+2)*100,100,10);
       iFilledRectangle(i*100,(j+2)*100,10,100);
       iFilledRectangle(i*100,(j+2)*100+90,100,10);
       iFilledRectangle(i*100+90,(j+2)*100,10,100);
    }
     else if(j>=2){
          iSetColor(0,255,0);
       iFilledRectangle(i*100,j*100,100,10);
       iFilledRectangle(i*100,j*100,10,100);
       iFilledRectangle(i*100,j*100+90,100,10);
       iFilledRectangle(i*100+90,j*100,10,100);

        iSetColor(0,0,255);
       iFilledRectangle(i*100,(j+1)*100,100,10);
       iFilledRectangle(i*100,  (j+1)*100,10,100);
       iFilledRectangle(i*100,(j+1)*100+90,100,10);
       iFilledRectangle(i*100+90,(j+1)*100,10,100);
    }
}

void iDraw()
{

    iClear();
    int p,q;
    int board_colour [8][8];
    for(p=0;p<800;p=p+100){
        for(q=0;q<800;q=q+100){

            if((p/100)%2==0)
            if((q/100)%2==0){ iSetColor(10,10,10);
            iFilledRectangle(p,q,100,100);
            }
           else{
            iSetColor(255,255,255);
            iFilledRectangle(p,q,100,100);
            }

           else if((p/100)%2==1)
            if((q/100)%2==1){
                    iSetColor(10,10,10);
            iFilledRectangle(p,q,100,100);
            }
           else {
                iSetColor(255,255,255);
           iFilledRectangle(p,q,100,100);
            }
        }
    }
    if(indicator){

        pawn_move();
    }

     iShowBMP(i*100+14,j*100+14,"B_Rook_B.BMP");



}

void iMouseMove(int mx, int my) {

}
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(black_move){
            i=mx/100;
            j=my/100;
             printf("%d\n",i);
            indicator=1;
            //black_move=0;

        }
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





        //printf("%c\n",key);
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


int main() {
	//place your own initialization codes here.

	iInitialize(800, 800, "Chess Board");

	return 0;
}

