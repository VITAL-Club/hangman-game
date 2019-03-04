// Here's my iteration of the Hangman code. My approach to this is to
// count the amount of correct letters contained in the word.
// If you feel this code needs to be corrected, don't hesitate
// to do so.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define HANGED 7

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

}

// The searching prototype that Frank made
bool checkChar(const char* answer, char* current, char guess)
{
  bool found = false;
  int i;
  int length = strlen(answer);

  for (i = 0; i < length; i++)
  {
    if (answer[i] == guess)
    {
      found = true;
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
  printf("Welcome to hangman\n");

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
    printf("Guess: %c\n", input);

    if (checkChar(stringGuess, stringRight, input));
    {
      printf("Correct\n");
      correctLetters++;
    }

  }

  // Free memory from the guessed string
  free(stringRight);
  printf("End of program");

  return 0;
}
