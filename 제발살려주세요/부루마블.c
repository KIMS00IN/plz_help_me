#include "Çì´õ.h"

int player_x = 0;
int player_y = 0;
int player_complete = 0;

int computer_x = 0;
int computer_y = 0;
int computer_complete = 0;

int player_turn = TRUE;

int strength = 0;

int dice = 0;

void print_status(int player_x, int player_y, int player_complete,
	int computer_x, int computer_y, int computer_complete) {
	printf("Player ==================\n");
	printf("- position: (y: %d, x: %d)\n", player_y, player_x);
	printf("- complete: %d\n", player_complete);
	printf("Computer =================\n");
	printf("- position: (y: %d, x: %d)\n", computer_y, computer_x);
	printf("- complete: %d\n", computer_complete);
	printf("=========================\n");
}

void print_menu() {
	if (player_turn) {
		printf("It's your turn.\n");
		printf("Let's roll the dice\n");
		printf("Throwing strength ( 1 ~ 3 )> ");
		scanf_s("%d", &strength);
	}
	else {
		printf("It's computer's turn.\n");
		printf("Let's roll the dice.\n");
		strength = rand() % 3 + 1;
	}
}

void get_dice_face() {
	int dice_sum = 0;
	for (int i = 0; i < strength; i++) {
		dice_sum += rand() % 6 + 1;
	}
	dice = dice_sum / strength;
}

void move() {
	if (player_turn) {
		while (dice--) {
			if (player_y == 0 && player_x < 9) player_x++;
			else if (player_y == 9 && player_x > 0) player_x--;
			else if (player_x == 0 && player_y > 0) player_y--;
			else if (player_x == 9 && player_y < 9) player_y++;
			if (player_y == 0 && player_x == 0) player_complete++;
		}
		player_turn = FALSE;
	}
	else {
		while (dice--) {
			if (computer_y == 0 && computer_x < 9) computer_x++;
			else if (computer_y == 9 && computer_x > 0) computer_x--;
			else if (computer_x == 0 && computer_y > 0) computer_y--;
			else if (computer_x == 9 && computer_y < 9) computer_y++;
			if (computer_y == 0 && computer_x == 0) computer_complete++;
		}
		player_turn = TRUE;
	}
}