#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printcard(int,int *,int *);
void shuffle_array(int *, int *, int);
void swap(int *, int *);
void color_red();
void color_def();
int check_score(int *, int *, int *, int *);
int straight_flush(int *, int *, int *);
int straight(int *);
int flush(int *);
int four_of_kind(int *);
int three_of_kind(int *);
int pair(int *);
int high_cahrd(int *);
void printscore(int *);
int comper_opponent_score(int *, int *);
void bubble_sort(int *array, int size);
void bit(int *,int *);

void main() {
	srand(time(NULL));
	int i;
	int deck_num[52] = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13 };
	int deck_sing[52] = { 1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4 ,1,2,3,4 ,1,2,3,4 ,1,2,3,4 ,1,2,3,4 };
	int *player_score;
	int *opponent_score;
	int win=0;
	int money = 1000;
	int jackpot = 0;
	
	while (money!=0)
	{
		shuffle_array(deck_num, deck_sing, 52);
		int flop_card_num[5] = { deck_num[0],deck_num[1],deck_num[2],deck_num[3],deck_num[4] };
		int flop_card_sing[5] = { deck_sing[0],deck_sing[1],deck_sing[2],deck_sing[3],deck_sing[4] };
		int hand_card_num[2] = { deck_num[5], deck_num[6] };
		int hand_card_sing[2] = { deck_sing[5], deck_sing[6] };
		int opponent_card_num[2] = { deck_num[7], deck_num[8] };
		int opponent_card_sing[2] = { deck_sing[7], deck_sing[8] };
		for (i = 0; i <= 5; i++)
		{
			system("cls");
			printcard(i, flop_card_num, flop_card_sing);
			printcard(2, hand_card_num, hand_card_sing);
			printf("money:%d$     jackpot:%d$\n", money, jackpot);
			bit(&money,&jackpot);
			if (i == 0) i += 2;
			if (money ==0)
			{
				i = 5;
			}
		}
		system("cls");
		printcard(2, opponent_card_num, opponent_card_sing);
		printcard(5, flop_card_num, flop_card_sing);
		printcard(2, hand_card_num, hand_card_sing);
		
		player_score = check_score(flop_card_num, flop_card_sing, hand_card_num, hand_card_sing);
		opponent_score = check_score(flop_card_num, flop_card_sing, opponent_card_num, opponent_card_sing);
		win = comper_opponent_score(player_score, opponent_score);
		if (win == 1)
		{
			printf("you win with ");
			printscore(player_score);
			printf("agens ");
			printscore(opponent_score);
			money += jackpot;
			jackpot = 0;
		}
		else if (win == -1)
		{
			printf("you lose with ");
			printscore(player_score);
			printf("for ");
			printscore(opponent_score);
			jackpot = 0;
		}
		else
		{
			printf("no winer");
			money += jackpot/2;
			jackpot = 0;
		}
		printf("\n");
		system("pause");
	}
	printf("    GAME OVER");
}

void printcard(int num_of_cards, int *num, int *sing) {
	int i;
	char number;
	int over_flow = 0;
	if (num_of_cards > 23)
	{
		over_flow = num_of_cards - 23;
		num_of_cards = 23;
	}
	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		printf("%c%c%c%c%c", 218, 196, 196, 196, 191);
		color_def();

	}

	printf("\n");

	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		printf("%c%c  %c", 179, sing[i] + 2, 179);
		color_def();
	}

	printf("\n");

	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		printf("%c   %c", 179, 179);
		color_def();
	}
	printf("\n");
	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		if (num[i] == 13) number = 'K';
		else if (num[i] == 12) number = 'Q';
		else if (num[i] == 11) number = 'J';
		else if (num[i] == 1) number = 'A';
		else
		{
			number = num[i] + '0';
		}
		if (num[i] == 10) printf("%c 10%c", 179, 179);
		else
		{
			printf("%c %c %c", 179, number, 179);
		}
		color_def();

	}

	printf("\n");
	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		printf("%c   %c", 179, 179);
		color_def();
	}
	printf("\n");
	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		printf("%c  %c%c", 179, sing[i] + 2, 179);
		color_def();
	}
	printf("\n");
	for (i = 0; i < num_of_cards; i++)
	{
		if (sing[i] < 3) color_red();
		printf("%c%c%c%c%c", 192, 196, 196, 196, 217);
		color_def();
	}
	printf("\n");
	if (over_flow != 0)
	{
		printcard(over_flow, num + 23, sing + 23);

	}
}

void color_red() {
	printf("\033[0;31m");
}

void color_def() {
	printf("\033[0m");
}

void swap(int *num_1, int *num_2) {
	int tamp;
	tamp = *num_1;
	*num_1 = *num_2;
	*num_2 = tamp;
}

void shuffle_array(int *array_1, int *array_2, int size)
{
	int i;
	int randindx;
	for (i = 0; i < size - 1; i++)
	{
		randindx = (rand() % size);
		swap(array_1 + i, array_1 + randindx);
		swap(array_2 + i, array_2 + randindx);
	}
}

int check_score(int *flop_num, int *flop_sing, int *hand_num, int *hand_sing) {
	int i, cards = 7;
	int total_num[7] = { hand_num[0],hand_num[1] , flop_num[0],flop_num[1],flop_num[2],flop_num[3],flop_num[4]};
	int total_sing[7] = { hand_sing[0],hand_sing[1] ,flop_sing[0],flop_sing[1],flop_sing[2],flop_sing[3],flop_sing[4]};
	int count_num[14] = { 0 };
	int count_sing[4] = { 0 };
	// score[10] = { 0 };
	int *score = (int *)calloc(12, sizeof(int));

	for ( i = 0; i < cards; i++)
	{
		count_num[total_num[i] - 1]++;
	}
	count_num[13] = count_num[0];
	for (i = 0; i < cards; i++)
	{
		count_sing[total_sing[i] - 1]++;
	}
	score[1] = four_of_kind(count_num);
	score[4] = flush(count_sing, hand_sing, hand_num);
	score[5] = straight(count_num);
	score[6] = three_of_kind(count_num);
	pair(count_num, score);
	score[9] = high_cahrd(count_num);
	if (score[6] != 0 && score[8] != 0) {
		score[2] = score[6];
		score[3] = score[8];
	}
	if (score[5] != 0 && score[4] != 0)
	{
		score[0] = straight_flush(count_sing, total_sing, total_num, cards);
	}
	bubble_sort(total_num, cards);
	score[10] = total_num[4];
	score[11] = total_num[3];
	//printscore(score);
	return score;
}

int straight_flush(int *count_sing,int *total_sing,int *total_num,int cards) {
	int count_num[14] = { 0 };
	int i;
	int j;
	for (i = 0; i < 4; i++)
	{
		if (count_sing[i] >= 5) {
			for ( j = 0; j < cards; j++)
			{
				if (total_sing[j] == i + 1) {
					count_num[total_num[j] - 1]++;
				}
			}
			count_num[13] = count_num[0];
			return straight(count_num);
		}
	}
	return 0;
}

int straight(int *count_num) {
	int sum = 0, max = 0,max_index;
	int i;
	for ( i = 0; i < 14; i++)
	{
		if (count_num[i] > 0) {
			sum++;
			if (sum > max) {
				max = sum;
				max_index = i;
			}
		}
		else
		{
			sum = 0;
		}
			
	}
	if (max >= 5)
	{
		return max_index - 3;
	}
	return 0;
}

int flush(int *count_sing,int *hand_sing,int *hand_num) {
	int i;

	for ( i = 0; i < 4; i++)
	{
		if (count_sing[i] >= 5) {
			if (hand_sing[0] == i + 1 && hand_sing[1] == i + 1) {
					if (hand_num[0] > hand_num[1]) {
						return hand_num[0];
					}
					else
					{
						return hand_num[1];
					}
				}
				if (hand_sing[0] == i + 1)
				{
				
					return hand_num[0];
				}
				if (hand_sing[1] == i + 1)
				{
					return hand_num[1];
				}
			return 1;
		}
	}
	return 0;
}

int four_of_kind(int *count_num) {
	int i;
	for ( i = 14; i > 0; i--)
	{
		if (count_num[i] == 4) {
			return i+1;
		}
	}
	return 0;
}

int three_of_kind(int *count_num) {
	int i;
	for (i = 14; i > 0; i--)
	{
		if (count_num[i] == 3) {
			return i+1;
		}
	}
	return 0;
}

int pair(int *count_num, int *score) {
	int i;
	for (i = 14; i > 0; i--)
	{
		if (count_num[i] == 2) {
			if (score[8] != 0)
			{
				score[7] = score[8];
				score[8] = i + 1;
				return;
			}
			score[8] = i + 1;
		}
	}
	return 0;
}

int high_cahrd(int *count_num) {
	int i;
	for ( i = 13; i > 0; i--)
	{
		if (count_num[i] != 0) return i + 1;
	}
}

void bubble_sort(int *array, int size) {
	int i, j;
	for (j = 0; j < 4; j++)
	{
		for (i = size - 1; i > j; i--)
		{
			if (array[i] < array[i - 1]) {
				swap(array + i, array + i - 1);
			}
		}
	}

}

void printscore(int *score) {
	int i;
	char dsply[10] = { 0 };
	for ( i = 0; i <10 ; i++)
	{
		if (score[i] >= 2 && score[i] <= 9) dsply[i] = score[i] + '0';
		if (score[i] == 1 || score[i] == 14) dsply[i] = 'A';
		if (score[i] == 11) dsply[i] = 'J';
		if (score[i] == 12) dsply[i] = 'Q';
		if (score[i] == 13) dsply[i] = 'K';
	}

	if (score[0] == 10) printf("RUIaL Flush");
	else if (score[0] != 0) printf("Straight Flush: %c ", dsply[0]);
	else if (score[0] == 10) printf("Straight Flush: 10 ");
	else if (score[1] != 0) printf("Four of kind: %c ", dsply[1]);
	else if (score[1] == 10) printf("Four of kind: 10 ");
	else if (score[2] != 0) {
		printf("Full house: ");
		if (dsply[2] == 10) printf("10");
		else printf("%c ", dsply[2]);
		if (dsply[3] == 10) printf("10");
		else printf("%c ", dsply[3]);
	}
	else if (score[4] == 10) printf("Flush: 10 ");
	else if (score[4] != 0) printf("Flush: %c ", dsply[4]);
	else if (score[5] == 10) printf("Straight: 10 ");
	else if (score[5] != 0) printf("Straight: %c ", dsply[5]);
	else if (score[6] == 10) printf("Three of kind: 10 ");
	else if (score[6] != 0) printf("Three of kind: %c ", dsply[6]);
	else if (score[7] != 0) { 
		printf("Two pair: ");
		if (dsply[7] == 10)printf("10");
		else printf("%c ", dsply[7]);
		if (dsply[8] == 10)printf("10");
		else printf("%c ", dsply[8]);
	}
	else if (score[8] == 10) printf("One pair: 10 ");
	else if (score[8] != 0) printf("One pair: %c ", dsply[8]);
	else if (score[9] == 10) printf("High cahrd: 10 ");
	else if (score[9] != 0) printf("High cahrd: %c ", dsply[9]);
}

int comper_opponent_score(int *player, int *opponent) {
	int i;
	for ( i = 0; i < 12; i++)
	{
		if (player[i]> opponent[i])
		{
			return 1;
		}
		if (opponent[i] > player[i])
		{
			return -1;
		}
	}
	return 0;
}

void bit(int *money, int *jackpot){
	int ch,bit=-1;
	if (*money != 0) {
		printf("1-cahek\n2-bit\n");
		scanf("%d", &ch);
		if (ch != 1) {

			printf("enter your bit:");
			while (bit < 0 || bit > *money)
			{
				rewind(stdin);
				scanf("%d", &bit);
			}
			*money -= bit;
			*jackpot += bit * 2;
		}
	}
	else
	{
		system("pause");
	}


}