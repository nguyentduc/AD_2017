// this header contains wave header information as a struct
// it also contains necessary constant definitions and functions
// prototypes used in this project

typedef struct {
	char ChunkID[4];
	int ChunkSize;
	char Format[4];
	char Subchunk1id[4];
	int Subchunk1Size;
	short int AudioFormat;
	short int NumChannels;
	int SampleRate;
	int ByteRate;
	short int BlockAlign;
	short int BitsPerSample;
	char Subchunk2ID[4];
	int Subchunk2Size;		//data size
}WAVHDR;		//Wave header
//#define DEBUG 
#define SAMPLE_RATE 16000
#define PI 3.14

//function prototypes
void displayWAVHDR(WAVHDR hdr);
void printID(char *);
void testTone(int freq, double duration);
void fillID(const char *, char []);
void displayWAVdata(short int []);
