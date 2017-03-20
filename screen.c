#include "screen.h"
#include <stdio.h>

void setFGcolor(int fg){
	printf("\033[%d;1m", fg);
	fflush(stdout);
}

void resetcolor(void){
	printf("\033[0m");
	fflush(stdout);
}

void gotoXY( int row, int col){
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

void clearscreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void displayBar(double rms, int col){
	int i;
	for(i=0; i<rms/100; i++){
	//for(i=30; i>0; i--){
		gotoXY(i+2, col);//start form 
		
#ifndef UNICODE
		printf("*");
#else
		printf("%s", BAR);
#endif
	}
	fflush(stdout);
}
