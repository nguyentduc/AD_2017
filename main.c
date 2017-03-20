// this program is for testing

#include "wave.h"	//double "" must be used 
#include <stdio.h>
#include <math.h>
#include <signal.h>
#include <sys/wait.h>
#include "screen.h"
#include <stdlib.h>

//this program will open a wave file and display WAV headr info

int main(int argc, char *argv[]){
	FILE *fp;
	WAVHDR myhdr;
	short int sa[SAMPLE_RATE];
	int answer, ret;
	/*if(argc !=2){
		printf("Usage: %s wav_file\n", argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("Cannot find file %s\n", argv[1]);
		return -1;
	}*/
	while(1){
		ret = system("arecord -r16000 -c1 -d1 -f S16_LE -q data.wav");
		clearscreen();	//a fresh screen/second
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT || WTERMSIG(ret)==SIGQUIT))break;
		fp = fopen("data.wav", "r");
		fread(&myhdr, sizeof(myhdr), 1, fp);
		displayWAVHDR(myhdr);
		fread(&sa, sizeof(short int), SAMPLE_RATE, fp);
		displayWAVdata(sa);
		fclose(fp);
	}//endwhile
	printf("Enter 1 to generate a test tone, 0 to end: \n");
	scanf("%d", &answer);
	if(answer == 1)testTone (440,5);

}
