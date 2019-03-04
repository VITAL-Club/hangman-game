// Here's my iteration of the Hangman code. My approach to this is to
// count the amount of correct letters contained in the word.
// If you feel this code needs to be corrected, don't hesitate
// to do so.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void displayString(char* current, int stringLength)
{
  int i;

  for (i = 0; i < stringLength; i++)
  {
    // If there is no element, make the thing blank
    if (current[i] == 0)
    {
      printf("_");
    }
    //Otherwise, place the letter into the string
    else
    {
      printf("%c", current[i]);
    }
    // Include a space between each letter
    printf(" ");
  }

  // Have a new line for the string
  printf("\n");
}

// Displaying the hanging body
void displayBody(int correctLetters)
{
  switch(correctLetters)
  {
    case 1:
      printf("  O\n");
      break;
    case 2:
      printf("  O\n");
      printf("  |\n");
      break;
    case 3:
      printf("  O\n");
      printf(" /|\n");
      break;
    case 4:
      printf("  O\n");
      printf(" /|\\\n");
      break;
    case 5:
      printf("  O\n");
      printf(" /|\\\n");
      printf(" /\n");
      break;
    case 6:
      printf("  o\n");
      printf(" /|\\\n");
      printf(" /\\\n");
      break;
    default:
      return;
  }
}

// The searching prototype that Frank made. I made it into an int
// function to count the variable incase it was found once.
int checkChar(const char* answer, char* current, char guess)
{
  int found = 0;
  int i;
  int length = strlen(answer);

  for (i = 0; i < length; i++)
  {
    if (answer[i] == guess)
    {
      found++;
      current[i] = guess;
    }
  }

  return found;
}

int main(void)
{
  // This is the
  char *stringGuess = "guess";
  char *stringRight;
  char input, letter;
  char alphabet[26];
  // i is the for loop, guessLen is for the length of the actual word
  // alphabetLetters is the length of the incorrect array
  // correctGuess is to equal the guess length of the word.
  // correctLetters is the amount of times a correct letter is found,
  // which will be added to correctGuess after going through the word.
  int i, guessLen, alphabetLetters = 0, correctGuess = 0, correctLetters = 0;
  int wrongGuess = 0, lives = 6;
  printf("Welcome to Hangman\n");

  guessLen = strlen(stringGuess);
  // Dynamically Allocate the word to fit the thing itself.
  stringRight = malloc(sizeof(char) * (guessLen + 1));

  while (correctLetters < guessLen)
  {
    // Display the string
    displayString(stringRight, guessLen);
    printf("Please input a character: ");
    scanf("%c", &input);
    // This is to remove the extra newline from scanf
    getchar();

    // Increment letter if it a letter is found;
    alphabetLetters = checkChar(stringGuess, stringRight, input);

    // If there are no letters found from the guessed character,
    // we increment the wrongGuess variable.
    if (alphabetLetters != 0)
    {
      correctLetters += alphabetLetters;
    }
    else
    {
      printf("Wrong Letter\n");
      wrongGuess++;
      displayBody(wrongGuess);

      // If the amount of lives and the amount of wrong guesses equal
      // zero, we end the loop and immediately give the GAME OVER screen
      if (lives - wrongGuess != 0)
        printf("Lives left: %d\n", lives - wrongGuess);
      else
        break;
    }
  }

  // Free memory from the guessed string
  printf("GAME OVER\n");
  free(stringRight);

  return 0;
}
