/****************************************************************

Console I/O library
By My Space Services Copyright 2019

This library contains many functions similar to the conio library
provided in Borland Turbo C . Also it contains the function defined
by My Space Services .

This library was created and tested on UBUNTU 9.10 . The main purpose
of creating this library is to help people migrating their programs
based on the CONIO libray of Turbo C to GNU C .

The function here in are based on the specifications of
terminfo feature of Linux based OS . so output may be differ or
not as expected , please consider checking terminfo settings of
your terminal .

you can contact us team(at)my-space(dot)co(dot)in

****************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<termios.h>	// Library general terminal interface that is provided to control asynchronous communications ports.
#include<unistd.h>
#include<fcntl.h>
#include<stdarg.h>
#include<string.h>

// Primary color constants
#define BLACK 0
#define RED 1
#define GREEN 2
#define BROWN 3
#define BLUE 4
#define PURPLE 5
#define MAGENTA 5
#define CYAN 6
#define LIGHTGRAY 7
// Secondary color constants
#define DARKGRAY 10
#define LIGHTRED 11
#define LIGHTGREEN 12
#define YELLOW 13
#define LIGHTBLUE 14
#define LIGHTPURPLE 15
#define LIGHTMAGENTA 15
#define LIGHTCYAN 16
#define WHITE 17

//__BEGIN_NAMESPACE_STD
short int PRIMARYBIT;	// Sets wheather the color is primary or secondary
short int TEXTCOLOR;	// Font color holder
short int BGPRIMARYBIT;	// Sets wheather the color is primary or secondary for background preventing conflict
short int TEXTBGCOLOR;	// Background color holder

int KEY;
typedef struct termios TERMIO;
void textcolor(short color){
	if(color>7){
		PRIMARYBIT=1;
		TEXTCOLOR=30+(color%10);
	} else {
		PRIMARYBIT=0;
		TEXTCOLOR=30+color;
	}
}
void textbackground(short color){
	if(color>7){
		BGPRIMARYBIT=1;
		TEXTBGCOLOR=40+(color%10);
	} else {
		BGPRIMARYBIT=0;
		TEXTBGCOLOR=40+color;
	}
}

void setFontColor(){
	printf("%c[%d;%dm", 0x1B,PRIMARYBIT,TEXTCOLOR);
}
void setBackgroundColor(){
	printf("%c[%d;%dm", 0x1B,BGPRIMARYBIT,TEXTBGCOLOR);
}
void resetFontColor(){
	if(strcmp(getenv("TERM"),"linux")==0)
		printf("%c[1;37m", 0x1B);
	else
		printf("%c[0;30m", 0x1B);
}
void resetBackgroundColor(){
	if(strcmp(getenv("TERM"),"linux")==0)
		printf("%c[0;40m", 0x1B);
	else
		printf("%c[0;49m", 0x1B);
}

void cprintf(const char *FormatString, ...) {
	va_list ArgList;
	setBackgroundColor();
	setFontColor();
	
	va_start(ArgList,FormatString);
	vprintf(FormatString,ArgList);
	va_end(ArgList);
	resetFontColor();
	resetBackgroundColor();
}

void cputs(const char *inputString) {
	setBackgroundColor();
	setFontColor();
	puts(inputString);
	resetFontColor();
	resetBackgroundColor();
}

void cscanf(const char *FormatString, ...) {
	va_list ArgList;
	setBackgroundColor();
	setFontColor();
	va_start(ArgList,FormatString);
	vscanf(FormatString,ArgList);
	va_end(ArgList);
	resetFontColor();
	resetBackgroundColor();
}

int gotoxy(int x, int y) {

/*** Described in man terminfo as vpa=\E[%p1%dd ***
*
*	Vertical position absolute
*
**************************************************/

	printf("%c[%dd", 0x1B,y);

/*** Described in man terminfo as vpa=\E[%p1%dd ***
*
*	Horinzontal position absolute
*
**************************************************/

	printf("%c[%dG", 0x1B,x);
	return 0;
}

void clrscr(){
	system("clear");
}

int getch( ) {
  TERMIO oldt,newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );		// Setting backup of present terminal mode , Line Buffering mode
  newt = oldt;					// Copying settings in new structure;
  newt.c_lflag &= ~( ICANON | ECHO );		// Sets the terminal into non-canonical mode, thus disabling line buffering
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );	// Applying changes
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );	// Restoring terminal from backup, thus enabling line buffering
  return ch;
}



int getche( ) {
  TERMIO oldt,newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );		// Setting backup of present terminal mode , Line Buffering mode
  newt = oldt;					// Copying settings in new structure;
  newt.c_lflag &= ~( ICANON );		// Sets the terminal into non-canonical mode, thus disabling line buffering
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );	// Applying changes
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );	// Restoring terminal from backup, thus enabling line buffering
  return ch;
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch= getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

// void randomize(){
// 	srand( (unsigned int)time( NULL ) );
// }
//__END_NAMESPACE_STD
