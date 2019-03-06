// Here's my iteration of the Hangman code. My approach to this is to
// count the amount of correct letters contained in the word.
// If you feel this code needs to be corrected, don't hesitate
// to do so.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define HANGED 6

#ifdef WIN32
  #define CLS system("cls")
#else
  #define CLS system("clear")
#endif

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
  printf("\t\t\t\t\t\tBody: ");
  switch(correctLetters)
  {
    case 1:
      printf("\t\t  O\n");
      break;
    case 2:
      printf("\t\t  O\n");
      printf("\t\t\t\t\t\t\t\t  |\n");
      break;
    case 3:
      printf("\t\t  O\n");
      printf("\t\t\t\t\t\t\t\t /|\n");
      break;
    case 4:
      printf("\t\t  O\n");
      printf("\t\t\t\t\t\t\t\t /|\\\n");
      break;
    case 5:
      printf("\t\t  O\n");
      printf("\t\t\t\t\t\t\t\t /|\\\n");
      printf("\t\t\t\t\t\t\t\t /\n");
      break;
    case 6:
      printf("\t\t  O\n");
      printf("\t\t\t\t\t\t\t\t /|\\\n");
      printf("\t\t\t\t\t\t\t\t /\\\n");
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

// Printing the wrong character array
void wrongLetterDisplay(char *wrong)
{
  int i;
  int length = strlen(wrong);

  for (i = 0; i < length; i++)
  {
    printf("%c", wrong[i]);
    printf(" ");
  }
  printf("\n");
}

// Inserting the wrong letter into the wrong letter array.
void wrongLetterFunction(char *wrong, char input)
{
  int i;

  for (i = 0; i < HANGED; i++)
  {
    if (input == wrong[i])
      break;
    else
    {
      wrong[strlen(wrong)] = input;
      break;
    }
  }
}

// Make a boolean function to make sure that the
// letter guess is not contained in the wrong letter array.
bool checkWrongLetter(char *wrong, char input)
{
  bool check = false;
  int i = 0;

  for (i = 0; i < HANGED; i++)
  {
    if (wrong[i] == input)
    {
      check = true;
    }
  }

  return check;
}

int main(void)
{
  // This is the
  char *stringGuess = "guess";
  char *stringRight;
  char input, letter;
  // "Alphabet" is the wrong array.
  char *stringWrong;
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
  stringWrong = calloc(sizeof(char), HANGED + 1);

  while (correctLetters < guessLen)
  {
    CLS;
    // display the wrong letter array after each input
    wrongLetterDisplay(stringWrong);
    // Display the string
    displayString(stringRight, guessLen);
    printf("Please input a character: ");
    input = tolower(getchar());
    // This is to remove the extra newline from scanf
    // 10 is a newline.
    while (getchar() != 10);

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
      printf("Sorry, Wrong Letter. Please try again.\n");

      // Checking to see if the input is already in the wrong character array.
      // If not, we increment the wrongGuess variable and add the character into the array.
      if (!checkWrongLetter(stringWrong, input))
      {
        wrongGuess++;
        wrongLetterFunction(stringWrong, input);
      }

      displayBody(wrongGuess);

      // If the amount of lives and the amount of wrong guesses equal
      // zero, we end the loop and immediately give the GAME OVER screen
      if (lives - wrongGuess != 0)
        printf("Lives left: %d\n", lives - wrongGuess);
      else
        break;


      getchar();
      while(getchar() != 10);
    }
  }
  displayString(stringRight, guessLen);

  // Free memory from the guessed string
  printf("GAME OVER\n");
  
  // Free both the correct / wrong strings.
  free(stringRight);
  free(stringWrong);

  return 0;
}
