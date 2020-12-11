#include <stdio.h>
#include <stdlib.h>

int inpot(int *,int,int);
void printboard(int *, int, int, int *);
int check(int *, int, int, int *);
void fill(int *,int);
void shuffle(int *, int);
void win();

int TURN_NUM = 1;

void main() {
	int guess_1, guess_2;
	int width = 1, height = 1;
	int size=100;
	int scoring = 0;
	int * board, *exposed;
	printf("you need to enter to \"width\" or \"height\" even number !!\n");
	while (size % 2 == 1 || size > 60)
	{
		printf("Select the width of the board:");
		scanf("%d", &width);
		printf("Select the height of the board:");
		scanf("%d", &height);
		size = width * height;
	}
	board = (int*)calloc(size, sizeof(int));
	fill(board, size);
	shuffle(board, size);
	exposed= (int*)calloc(size, sizeof(int));
	printboard(board, -1, -1, exposed, width, height);
	while (scoring != size)
	{
		guess_1 = inpot(exposed, -1, size,1);
		guess_2 = inpot(exposed, guess_1, size,2);
		system("cls");
		printboard(board, guess_1, guess_2, exposed, width, height);
		scoring += check(board, guess_1, guess_2, exposed);
	}
	void free(void *board);
	void free(void *exposed);
	win();
}

void printboard(int *board, int guess_1, int guess_2, int *exposed, int width, int height) {
	int i;
	int j;
	int s = 0;
	for (j = 0; j < height; j++)
	{
		for (i = 0; i < width; i++) {
			if (s == guess_1 || s == guess_2 || exposed[s] == 1) {
				printf(" %c ", board[s]);
			}
			else
			{
				printf(" %c ", 219);
			}
			s++;
		}
		printf("\n");
		s -= width;
		for (i = 0; i < width; i++) {
			if (s < 9) {
				printf(" %d ", s+1);
			}
			else
			{
				printf(" %d", s+1);
			}
			s++;
		}
		printf("\n\n");
	}
}

int inpot(int *exposed,int guess_1,int size,int num) {
	printf("#%d guess: ", num);
	int guess_2;
	guess_1++;
	scanf("%d", &guess_2);
	while (guess_2 < 1 || guess_2 > size || guess_2 == guess_1 || exposed[guess_2 - 1] == 1) {
		if (guess_2 < 1 || guess_2 > size) {
			printf("there is no card at this number on the board\n");
		}
		if (exposed[guess_2 - 1] == 1) {
			printf("You've already guessed this location\n");
		}
		if (guess_2 == guess_1) {
			printf("That was your first guess");
		}
		printf("you have to enter a guess again\n");
		printf("#%d guess: ", num);
		scanf("%d", &guess_2);
	}
	return guess_2 - 1;
}

int check(int *board, int guess_1, int guess_2, int *exposed) {
	if (board[guess_1] == board[guess_2]) {
		exposed[guess_1] = exposed[guess_2] = 1;
		board[guess_1] = board[guess_2] = 0;
		printf("%c", 7);
		return 2;
	}
	return 0;
}

void fill(int *board, int size) {
	int i;
	size /= 2;
	for (i = 0; i < size; i++) {
		board[i * 2] = board[i * 2 + 1] = i + 224;
	}
}


void shuffle(int *array, int size)
{
	int i;
	for (i = 0; i < size - 1; i++)
	{
		int j = i + rand() / (RAND_MAX / (size- i) + 1);
		int temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}
}
void win() {
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	printf("%c                                         %c\n", 186, 186);
	printf("%c %c   %c   %c%c   %c  %c    %c     %c  %c  %c   %c  %c\n", 186, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 186);
	printf("%c %c   %c  %c  %c  %c  %c    %c     %c     %c%c  %c  %c\n", 186, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 186);
	printf("%c  %c %c   %c  %c  %c  %c     %c %c %c   %c  %c %c %c  %c\n", 186, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 186);
	printf("%c   %c    %c  %c  %c  %c     %c %c %c   %c  %c  %c%c  %c\n", 186, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 186);
	printf("%c   %c     %c%c    %c%c       %c %c    %c  %c   %c  %c\n", 186, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 186);
	printf("%c                                         %c\n", 186, 186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}