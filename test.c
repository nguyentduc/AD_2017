// this program is for testing

#include "wave.h"	//double "" must be used 
#include <stdio.h>
#include <math.h>

//this program will open a wave file and display WAV headr info

int main(int argc, char *argv[]){
	FILE *fp;
	WAVHDR myhdr;
	int answer;
	if(argc !=2){
		printf("Usage: %s wav_file\n", argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("Cannot find file %s\n", argv[1]);
		return -1;
	}
	fread(&myhdr, sizeof(myhdr), 1, fp);
	//printID(myhdr.ChunkID);
	//printf("ChunkSize: %d\n", myhdr.ChunkSize);
	//printID(myhdr.Format);
	displayWAVHDR(myhdr);
	fclose(fp);
	printf("Enter 1 to generate a test tone, 0 to end: \n");
	scanf("%d", &answer);
	if(answer == 1)testTone (440,5);
}
void displayWAVHDR(WAVHDR hdr){
	double duration;
	printf("Chunk ID: "); printID(hdr.ChunkID);
	printf("Chunk Size: %d\n", hdr.ChunkSize);
	printf("Format: "); printID(hdr.Format);
	printf("Subchunk1id: "); printID(hdr.Subchunk1id);
	printf("Subchunk1Size: %d\n", hdr.Subchunk1Size);
	printf("AudioFormat: %d\n", hdr.AudioFormat);
	printf("NumChannels: %d\n", hdr.NumChannels);
	printf("SampleRate: %d\n", hdr.SampleRate);
	printf("ByteRate: %d\n", hdr.ByteRate);
	printf("BlockAlign: %d\n", hdr.BlockAlign);
	printf("BitsPerSample: %d\n", hdr.BitsPerSample);
	printf("Subchunk2ID: "); printID(hdr.Subchunk2ID);
	printf("Subchunk2Size: %d\n", hdr.Subchunk2Size);
	duration = (double)hdr.Subchunk2Size/hdr.ByteRate;
	printf("Duration: %.3f sec\n", duration);
}

void printID( char id[]){
	int i;
	for(i=0; i<4; i++) putchar(id[i]);
	printf("\n");
}

void fillID(const char *s, char d[]){
	int i;
	for(i=0; i<4; i++) d[i]=*s++;
}


void testTone(int freq, double d){
	FILE *fp;
	int i;
	WAVHDR h;
	short int sample;

	fp= fopen("testtone2.wav", "w");
	fillID("RIFF", h.ChunkID);
	//chunksize will be calculated later
	fillID("WAVE", h.Format);
	fillID("fmt ", h.Subchunk1id);
	h.Subchunk1Size = 16;
	h.AudioFormat = 1;
	h.NumChannels =1;
	h.SampleRate = SAMPLE_RATE;
	h.BitsPerSample = 16;
	h.ByteRate = SAMPLE_RATE * h.NumChannels *(h.BitsPerSample/8);
	h.BlockAlign = h.NumChannels *(h.BitsPerSample/8);
	fillID("data", h.Subchunk2ID);
	h.Subchunk2Size = (int)h.ByteRate *d;
	h.ChunkSize = h.Subchunk2Size +36;
	fwrite(&h, sizeof(h), 1, fp);

	for (i=0; i<d*SAMPLE_RATE; i++){
		sample = 32768 * sin(2*PI*freq*i/SAMPLE_RATE);
		fwrite(&sample, sizeof(sample),1, fp);
	}
	fclose(fp);

}
