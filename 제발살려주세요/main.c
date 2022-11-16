#include "Çì´õ.h"

int main() {
	srand(time(NULL));

	printf("Initializing the board.\n");
	printf("=============================\n");
	printf("******** BLUE MARBLE ********\n");
	printf("=============================\n");
	while (1) {
		print_status(player_y, player_x, player_complete, computer_y, computer_x, computer_complete);
		print_menu();
		get_dice_face();
		printf("Moving %d spaces\n", dice);
		move();
		if (computer_complete == 3) {
			printf("Sorry, you lose");
			return 0;
		}
		else if (player_complete == 3) {
			printf("Congratulation! You won!");
			return 0;
		}
	}
	return 0;
}