// Here's my iteration of the Hangman code. My approach to this is to
// count the amount of correct letters contained in the word.
// If you feel this code needs to be corrected, don't hesitate
// to do so.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *string = "guess";
  char input, letter;
  char alphabet[26];
  // i is the for loop, guessLen is for the length of the actual word
  // alphabetLetters is the length of the incorrect array
  // correctGuess is to equal the guess length of the word.
  // correctLetters is the amount of times a correct letter is found,
  // which will be added to correctGuess after going through the word.
  int i, guessLen, alphabetLetters = 0, correctGuess = 0, correctLetters = 0;

  guessLen = strlen(string);

  while (correctLetters <= guessLen)
  {
    printf("\n%d out of %d found\n", correctLetters, guessLen);
    printf("Please input a character: ");
    scanf("%c", &input);
    // This is to remove the extra newline from scanf
    getchar();
    printf("Guess: %c\n", input);

    // If the input is correct, and is not a blank character
    // we move on to the next letter.
    // Otherwise, we put the word in an array of incorrect letters
    for (i = 0; i < guessLen; i++)
    {
      // If the letter is correct, we increment the correct letter by one
      // If not, we put it inside the alphabet array
      if (input == string[i])
      {
        printf("Right letter\n");
        correctGuess++;
      }

      // If there are correct letters found in the word,
      // we update the countLetters variable.
      if (correctGuess != 0)
        correctLetters += correctGuess;
      else
      {
        // Otherwise, we put the incorrect letter into the
        // alphabet array.
        for (i = 0; i < alphabetLetters; i++)
        {
          if (alphabet[i] == input)
          {
            printf("Letter %c is already taken\n", input);
            alphabet[alphabetLetters] = input;
            alphabetLetters++;
          }
        }
      }

    }
  }

  printf("End of program");

  return 0;
}
