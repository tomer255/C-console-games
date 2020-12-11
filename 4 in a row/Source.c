#include <stdio.h>
#include <Windows.h>

void printbourd(int *, int, int);
int get_move(int *, int, int);
int animation(int*, int);
int cahek_win(int *, int, int);
int chak_jaison(int *, int, int, int, int);

#define WHID 8
#define HITE 8
#define SPEED 50

void main() {
	int i;
	int player = 1;
	int move;
	int bourd[WHID][HITE] = {0};
	int winer = 0;
	for (i = 0; i < WHID*HITE; i++)
	{
		system("cls");
		printbourd(bourd, WHID, HITE);
		move=get_move(bourd, WHID, player);
		winer = animation(bourd, move);

		if (winer != 0) {
			printf("player %d win!!!\n", player);
			system("pause");
			return;
		}

		if (player == 1) player++;
		else if (player == 2) player--;
	}
}

void printbourd(int bourd[WHID][HITE], int whid, int hite) {
	int i = 0, j;
	int s = 0;
	printf(" ");
	if (hite >= 10 && i < 10) printf(" ");
	for (i = 0; i < whid; i++)
	{
		if (i < 10) printf(" ");
		printf("  %d", i+1);
	}
	printf("\n");
	if (hite >= 10) printf(" ");
	printf("  %c", 201);
	for (i = 0; i < whid - 1; i++) {
		printf("%c%c%c%c", 205, 205, 205, 203);
	}
	printf("%c%c%c%c\n", 205, 205, 205, 187);
	for (i = 0; i < hite; i++) {
		if (hite >= 10 && i < 9) printf(" ");
		printf("%d ", i + 1);
		for (j = 0; j < whid; j++)
		{
			if (bourd[j][i] != 0) {
				printf("%c", 186);
				if (bourd[j][i] == 1) printf("\033[0;31m %c \033[0m", 219);
				if (bourd[j][i] == 2) printf("\033[0;34m %c \033[0m", 219);
			}
			else
			{
				printf("%c   ", 186);
			}
			s++;
		}
		printf("%c\n", 186);
		if (hite >= 10 ) printf(" ");
		if (i != hite - 1) {
			printf("  %c", 204);
			for (j = 0; j < whid - 1; j++) {
				printf("%c%c%c%c", 205, 205, 205, 206);
			}
			printf("%c%c%c%c\n", 205, 205, 205, 185);
		}
	}
	printf("  %c", 200);
	for (i = 0; i < whid - 1; i++) {
		printf("%c%c%c%c", 205, 205, 205, 202);
	}
	printf("%c%c%c%c\n", 205, 205, 205, 188);
}

int get_move(int bourd[WHID][HITE], int whid, int player) {
	int move;
	printf("enter your move:");
	scanf("%d", &move);
	move -= 1;
	while (move < 0 || move > whid - 1 || bourd[move][0]!=0)
	{
		printf("invalv move\n");
		scanf("%d", &move);
		move -= 1;
	}
	bourd[move][0] = player;
	return move;
}

int animation(int bourd[WHID][HITE],int move) {
	int i = 0;
	while (bourd[move][i + 1] == 0 && i < HITE-1)
	{
		system("cls");
		bourd[move][i + 1] = bourd[move][i];
		bourd[move][i] = 0;
		i++;
		printbourd(bourd, WHID, HITE);
		Sleep(SPEED);
	}
	return cahek_win(bourd, move, i);
}

int cahek_win(int bourd[WHID][HITE], int row, int line) {
	if (chak_jaison(bourd, row, line, +1, 0) + chak_jaison(bourd, row, line, -1, 0) + 1 == 4) return 1;
	if (chak_jaison(bourd, row, line, 0, +1) + 1 == 4) return 1;
	if (chak_jaison(bourd, row, line, +1, +1) + chak_jaison(bourd, row, line, -1, -1) + 1==4)return 1;
	if (chak_jaison(bourd, row, line, -1, +1) + chak_jaison(bourd, row, line, +1, -1) + 1==4)return 1;
	return 0;
}

int chak_jaison(int bourd[WHID][HITE], int row, int line, int row_d, int line_d) {
	if (row + row_d>= WHID || line + line_d>= HITE)
		return 0;
	if (bourd[row+ row_d][line+ line_d]== bourd[row][line])
		return chak_jaison(bourd, row + row_d, line + line_d, row_d, line_d) + 1;
	else
		return 0;
}