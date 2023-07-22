//By N1ne_
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc!=2)
	{
		printf("operation not specified!\n");
		printf("-h = helping\n");
		exit(1);
	}
	if(!strcmp(argv[1], "-h"))
	{
		printf("-s = start npaint\n");
		printf("-c = list of brushes\n");
	}
	if(!strcmp(argv[1], "-c"))
	{
		printf("0 = '#'; 1 = '@'; 2 = '_'; 3 = ' '; 4 = clear\n");
		printf("ESC = exit from npaint\n");
	}
	if(!strcmp(argv[1], "-s"))
	{
		int x = 0,y = 3;
		int a;
		char sym = '#';
		initscr();
		keypad(stdscr, 1);
		noecho();
		printw("NPaint 1.0\n");
		//printw("__________________________________________________________________________________________\n");
		
		do
		{
			mvaddch(y,x,sym);
			a = getch();
			if(a == KEY_UP) y--;
			if(a == KEY_DOWN) y++;
			if(a == KEY_LEFT) x--;
			if(a == KEY_RIGHT) x++;
			if(a == '0') sym = '#'; 
			if(a == '1') sym = '@';
			if(a == '2') sym = '_'; 
			if(a == '3') sym = ' ';
			if(a == '4')
			{
				system("clear");
				x = 0;
				y = 3;
			}
		} while (a != 27);

		endwin();
	}

	return 0;
}
