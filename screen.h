//include the function prototypes for screen manipulation
enum COLOR{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define UNICODE
#define BAR "\u2590"		//display a bar

//function prototypes
void setFGcolor(int fg);
void resetcolor(void);
void gotoXY(int row, int col);
void displayBar( double rms, int col); 
