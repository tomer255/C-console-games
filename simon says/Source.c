#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void print_block(int, int, char);
void block(int,int);
int get_move();

#define BLOCK_W 8
#define BLOCK_H 5
#define LOC_X 10
#define LOC_Y 20
#define SPEED 500
#define BLOCKS 8 //(betwen 1 to 8)

void main() {
	int color;
	int scoor = 0;
	int array[100] = { 0 };
	int i;
	srand(time(NULL));
	for ( i = 0; i <= BLOCKS; i++)
	{
		block(i, 0);
	}
	while (1)
	{
		array[scoor] = (rand() % BLOCKS) + 1;
		for ( i = 0; i < scoor; i++)
		{
			block(array[i], 1);
			Beep((array[i]*100)+200, SPEED);
			block(array[i], 0);
		}
		for ( i = 0; i < scoor; i++)
		{
			color = 0;
			while (color < 1 || color > BLOCKS)
			{
				color = get_move();
			}
			block(color, 1);
			Beep((color * 100) + 200, SPEED);
			block(color, 0);
			if (array[i]!=color)
			{
				printf("\033[%d;%dH GAME OVER your score is: %d", LOC_X+ (BLOCK_H*2) + 1, LOC_Y, scoor);
				return 0;
			}
		}
		scoor++;
	}
}

void print_block(int x, int y, char c) {
	int i, j;
	for (i = 0; i < BLOCK_H; i++)
	{
		printf("\033[%d;%dH", x + i, y);
		for (j = 0; j < BLOCK_W; j++)
		{
			printf("%c", c);
		}
	}
}

void block(int color, int on) {
	printf("\033[%d;%dm", 1 - on, 30 + (color%8));
	char c = 176 + (on * 43);
	switch (color)
	{
	case 1: print_block(LOC_X - BLOCK_H, LOC_Y, c); break;
	case 2: print_block(LOC_X, LOC_Y - BLOCK_W, c); break;
	case 3: print_block(LOC_X, LOC_Y + BLOCK_W, c); break;
	case 4: print_block(LOC_X + BLOCK_H, LOC_Y, c); break;
	case 5: print_block(LOC_X + BLOCK_H, LOC_Y+ BLOCK_W, c); break;
	case 6: print_block(LOC_X - BLOCK_H, LOC_Y + BLOCK_W, c); break;
	case 7: print_block(LOC_X + BLOCK_H, LOC_Y - BLOCK_W, c); break;
	case 8: print_block(LOC_X - BLOCK_H, LOC_Y - BLOCK_W, c); break;
	default:
		break;
	}
	printf("\033[0m");
}

int get_move() {
	switch (getch())
	{
		case 'w': return 1; //red (up)  (200,85)-(287,165)
		case 'a': return 2; //green (left)
		case 'd': return 3; //yelow (r
		case 'x': return 4; //blue (down)
		case 'c': return 5; // (down left)
		case 'e': return 6; // (up left)
		case 'z': return 7; // (up left)
		case 'q': return 8; // (up left)
		default: return 0;
		break;
	}
}
