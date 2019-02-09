#include <stdio.h>
#include <stdlib.h>

void displayMenu(){
	printf("\t\t\t **WELCOME TO HANGMAN**\n");
	printf("\t\t\t **********************\n");
	printf("\t\t\t --------    \t\t Do not get TOO hung up :)\n");
    printf(" Du du DU du du Du\t |      |\n");
    printf("       Du du Du du du... |     (@)\n");
    printf("\t HANGman!!!!     |     /|\\     \t\t\t HANG in there!\n ");
    printf("\t\t\t |      |\n");
    printf("\t\t\t |     / \\     Do not leave him HANGing! \n");
    printf("\t\t    _____|_________\n");
    printf("\t\t   /     |         /|  \t\t Just hanging around!\n");
 	printf("\t\t  /______________ / /\n");
  	printf("\t\t |               | /   \t\t\t\t Hang you for playing!\n");
 	printf("\t\t |______________ |/\n");
	printf("HOW TO PLAY: \n");
	printf("- You are trying to guess a word one letter at a time.\n");
	printf("- Guesses can only be letters (mostly in the English alphabet), because nobody is ready for numbers yet :/ \n");
	printf("- Simply type the letter that you have chosen and press ENTER on the keyboard.\n");
	printf("- When your guess is correct, that letter will be displayed in the blank correspond to its actual position in that word.");
	printf("- When your guess is incorrect, you lose one miss and further completed the hangman :( \n");
	printf("- You have total of 6 MISSES before you hang the man (which means GAME OVER).\n");
	printf("- The numbers of remaining misses that you have left will be displayed on the screen, so no need to keep count.\n");
	printf(" Good luck!\n");
	//Frezze the screen so people could read and play
	printf("Press any key to continue: \n");
	system("pause");
	return;
}


