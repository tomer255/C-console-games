#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rotate(int *, int);
void shuffle_array(int *array, int size);
void printboard(int *);
void wright(int *);
void switch_line(int *,int,int);
void switch_row(int *,int,int);
void shuffle(int *);
void swap(int *, int *);
void del(int *, int);
int difficulty();
void fill_line(int *, int*, int);
void fill_board(int *, int*);
int generate(int *);
int check_if_correct(int *);
int check_line(int *, int);
int check_row(int *, int);
int check_sqer(int *, int);

void main() {
	srand(time(NULL));
	int board[81] = { 0 };
	int play = 1;
	while (play)
	{
		generate(board);
		while (check_if_correct(board))
		{
			system("cls");
			printboard(board);
			wright(board);
		}
		system("cls");
		printboard(board);
		printf("you win!!!\none more game?\n1-yes\n2-no\n");
		scanf("%d", &play);
		play = play % 2;
	}
}

void shuffle_array(int *array, int size)
{
	int i;
	for (i = 0; i < size - 1; i++)
	{
		swap(array+i, array+(rand()% size));
	}
}
void printboard(int *board) {
	int i, j,k;
	int s = 0;
	printf("    A   B   C   D   E   F   G   H   I\n");
	printf("  %c", 201);
	for (i = 0; i < 8; i++) {
		if (i == 2 || i == 5) {
			printf("%c%c%c%c", 205, 205, 205, 203);
		}
		else
		{
			printf("%c%c%c%c", 205, 205, 205, 209);
		}
		
	}
	printf("%c%c%c%c\n", 205, 205, 205, 187);
	for (i = 0; i < 9; i++) {
		printf("%d ", i + 1);
		for (j = 0; j < 9; j++)
		{
			if (j == 0 || j == 3 || j == 6) {
				printf("%c", 186);
			}
			else
			{
				printf("%c", 179);
			}
			for ( k = 0; k < 1; k++)
			{
				if (board[s] != 0) {
					printf(" %d ", board[s]);
				}
				else
				{
					printf("   ");
				}
				s++;
			}
		}
		printf("%c\n", 186);
		if (i != 8) {
			if(i == 2 || i == 5)
			printf("  %c", 204);
			else
			{
				printf("  %c", 199);
			}
			for (j = 0; j < 8; j++) {
				if (i == 2 || i == 5) {
					if (j == 2 || j == 5) {
						printf("%c%c%c%c", 205, 205, 205, 206);
					}
					else
					{
						printf("%c%c%c%c", 205, 205, 205, 216);
					}
				}
				else
				{
					if (j == 2 || j== 5) {
						printf("%c%c%c%c", 196, 196, 196, 215);
					}
					else
					{
						printf("%c%c%c%c", 196, 196, 196, 197);
					}
				}
			}
			if (i == 2 || i == 5) {
				printf("%c%c%c%c\n", 205, 205, 205, 185);
			}
			else
			{
				printf("%c%c%c%c\n", 196, 196, 196, 182);
			}
		}
	}
	printf("  %c", 200);
	for (i = 0; i < 8; i++) {
		if (i == 2 | i == 5) {
			printf("%c%c%c%c", 205, 205, 205, 202);
		}
		else
		{
			printf("%c%c%c%c", 205, 205, 205, 207);
		}
	}
	printf("%c%c%c%c\n", 205, 205, 205, 188);
}
void rotate(int *array, int num) {
	int i;
	int j;
	for ( j = 0; j < num; j++)
	{
		for (i = 0; i < 8; i++) {
			swap(array + i, array + i + 1);
		}
	}
}
void wright(int *board) {
	char letter=0;
	int num=0;
	int spot=0;
	int value=0;
	rewind(stdin);
	printf("Enter a letter of the spot: ");
	scanf("%c", &letter);
	if (letter >= 'a' && letter <= 'z') {
		letter -= 32;
	}
	
	printf("Enter a number of the spot: ");
	scanf("%d", &num);
	spot = (num - 1) * 9 + (letter - 64);
	printf("Enter the number you want to insert: ");
	scanf("%d", &value);
	if (letter >= 'A' && letter <= 'Z' && num >= 1 && num <= 9 && value >= 0 && value <= 9) {
		board[spot - 1] = value;
	}
	else
	{
		printf("\nERROR:Invalid input\n");
		rewind(stdin);
		system("pause>nul");
	}
}
void swap(int *num_1, int *num_2) {
	int tamp;
	tamp = *num_1;
	*num_1 = *num_2;
	*num_2 = tamp;
}
void switch_line(int *board,int line_1,int line_2) {
	int i;
	if (line_1 != line_2) {
		for (i = 0; i < 9; i++)
		{
			swap(board + (line_1 - 1) * 9 + i, board + (line_2 - 1) * 9 + i);
		}
	}
}
void switch_row(int *board,int row_1,int row_2) {
	int i;
	if (row_1 != row_2) {
		for (i = 0; i < 73; i += 9)
		{
			swap(board + row_1 + i - 1, board + row_2 + i - 1);
		}
	}
}
void shuffle(int *board) {
	int i;
	int j;
	for (j = 0; j < 5; j++)
	{
		for (i = 1; i < 10; i++) {
			if (i < 4) {
				switch_line(board, i, (rand() % 3) + 1);
				switch_row(board, i, (rand() % 3) + 1);
			}
			if (i > 3 && i < 7) {
				switch_line(board, i, (rand() % 3) + 4);
				switch_row(board, i, (rand() % 3) + 4);
			}
			if (i > 6) {
				switch_line(board, i, (rand() % 3) + 7);
				switch_row(board, i, (rand() % 3) + 7);
			}
		}
	}
}
void del(int *board, int n) {
	int i;
	for ( i = 0; i < n; i++)
	{
		board[rand() % 81] = 0;
	}
}
int difficulty() {
	int dif = 0;
	system("cls");
	printf("Select a difficulty level:\n1-very easy\n2-easy\n3-normal\n4-hard\n5-veryvhard\n");
	scanf("%d", &dif);
	switch (dif)
	{
	case 1:
		return 20;
		break;
	case 2:
		return 40;
		break;
	case 3:
		return 60;
		break;
	case 4:
		return 80;
		break;
	case 5:
		return 100;
		break;
	default:
		return 0;
		break;
	}
}
void fill_line(int *board,int *seed, int line) {
	int i;
	line = (line -1) * 9;
	for ( i = 0; i < 9; i++)
	{
		board[line + i] = seed[i];
	}
}
void fill_board(int *board, int *seed) {
	fill_line(board, seed, 1);
	rotate(seed, 3);
	fill_line(board, seed, 2);
	rotate(seed, 3);
	fill_line(board, seed, 3);
	rotate(seed, 1);
	fill_line(board, seed, 4);
	rotate(seed, 3);
	fill_line(board, seed, 5);	
	rotate(seed, 3);
	fill_line(board, seed, 6);
	rotate(seed, 1);
	fill_line(board, seed, 7);
	rotate(seed, 3);
	fill_line(board, seed, 8);
	rotate(seed, 3);
	fill_line(board, seed, 9);
}
int generate(int *board) {
	int seed[9] = { 1,2,3,4,5,6,7,8,9 };
	shuffle_array(seed, 9);
	fill_board(board, seed);
	shuffle(board);
	del(board, difficulty());
}
int check_if_correct (int *board) {
	int i;
	for ( i = 1; i <= 9; i++)
	{
		if (check_line(board, i) == 1) {
			return 1;
		}
	}
	for (i = 1; i <= 9; i++)
	{
		if (check_row(board, i) == 1) {
			return 1;
		}
	}
	for ( i = 1; i <= 9; i++)
	{
		if (check_sqer(board, i) == 1) {
			return 1;
		}
	}
	return 0;
}
int check_line(int *board,int line) {
	int i;
	int num;
	int check[9] = { 0 };
	for ( i = 0; i < 9; i++)
	{
		num = board[(line-1)*9+i] - 1;
		if (num != -1) {
			check[num] = 1;
		}
		
	}
	for ( i = 0; i < 9; i++)
	{
		if (check[i] == 0) {
			return 1;
		}
	}
	return 0;
}
int check_row(int *board, int row) {
	int i;
	int num;
	int check[9] = { 0 };
	row -= 1;
	for (i = 0; i < 9; i++)
	{
		num = board[row + i*9] - 1;
		if (num != -1) {
			check[num] = 1;
		}
	}
	for (i = 0; i < 9; i++)
	{
		if (check[i] == 0) {
			return 1;
		}
	}
	return 0;
}
int check_sqer(int *board,int sqer) {
	int i;
	int j;
	int num = ((sqer - 1) * 3) % 9;
	int check[9] = { 0 };
	if (sqer > 3)
	{
		num += 27;
	}
	if (sqer > 6)
	{
		num += 27;
	}
	for ( j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (board[num] != 0) {
				check[board[num] - 1] = 1;
			}
			num++;
		}
		num += 6;
	}
	for (i = 0; i < 9; i++)
	{
		if (check[i] == 0) {
			return 1;
		}
	}
	return 0;
}