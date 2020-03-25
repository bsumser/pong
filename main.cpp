#include <iostream> 
#include <vector> 
#include <pthread.h> 
#include <curses.h>
#include <unistd.h>

#define DELAY 50000

using namespace std; 
void *getMove(void *threadid);

int main() 
{
	int next_x = 0, next_y = 0, max_y = 0, max_x = 0; //variables for ball
	int p1X = 0, p1Y = 0, p1MaxY = 0; //variables for player 1 paddle
	int p2X = 0, p2Y = 0, p2MaxY = 0; //variab;es for player 2 paddle
	int p1NextY = 0, p2NextY = 0;
	int direction = 1;
	int height = 1;
	char key;
	int x = 0, y = 0;
	initscr(); //initialize the window
	curs_set(FALSE); //dont display cursor
	noecho(); //dont echo any keypresses
	keypad(stdscr, TRUE); //allow the arrow keys
	getmaxyx(stdscr, max_y, max_x); //get the max boundry of the screen
	nodelay(stdscr,true);
	p1MaxY = max_y;
	p2MaxY = max_y;
	p2X = max_x - 2;
	
	while(1) {
		clear();
		mvprintw(y,x,"o");
		mvprintw(p1Y,p1X,"||");
		mvprintw(p1Y + 1,p1X,"||");
		mvprintw(p2Y,p2X,"||");
		mvprintw(p2Y + 1,p2X,"||");
		refresh();
		usleep(DELAY);
		if (key = getch()) {
			if (key == 's' && p1Y + 2 != p1MaxY) {p1Y++;}
			if (key == 'w' && p1Y > 0) {p1Y--;}
			if (key == 'k' && p2Y + 2 != p2MaxY) {p2Y++;}
			if (key == 'i' && p2Y > 0) {p2Y--;}
		}
		
		next_x = x + direction;
		next_y = y + height;
		if ((next_x >= max_x && next_y == p2Y) || (next_x < 0 && next_y == p1Y))
			{ direction*= -1; }
		else if (next_y >= max_y || next_y < 0) { height *= -1; }
		else { x += direction + 1; y += height; }
	}
	cout << "returning 0" << endl;
	endwin(); //restore terminal settings at close
	return 0; 
}

