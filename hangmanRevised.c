// Here's my iteration of the Hangman code. My approach to this is to
// count the amount of correct letters contained in the word.
// If you feel this code needs to be corrected, don't hesitate
// to do so.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fileLoader.h"
#define HANGED 6

#ifdef WIN32
  #define CLS system("cls")
#else
  #define CLS system("clear")
#endif

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
	system("pause");
	return;
}


typedef struct Dictionary
{
  unsigned int words;
  char** wordList;
} Dictionary;

/*
  Returns a blank dictionary with space for `size` number of words.
 */
Dictionary* newDictionary(unsigned int size)
{
  Dictionary* dict = malloc(sizeof(Dictionary));
  dict->words = size;
  dict->wordList = malloc(size * sizeof(char*));

  return dict;
}

/*
  Cleans up a dictionary by freeing all relevant pointers.
 */
void freeDictionary(Dictionary* dict)
{
  unsigned int i;
  for (i = 0; i < dict->words; i++)
    free(dict->wordList[i]);

  free(dict->wordList);

  free(dict);

  return;
}

/*
  Given a file name, returns the contents of the file as one long string.
  If the file cannot be read for any reason, returns a null pointer instead.
 */
char* readRaw(const char* filePath)
{
  FILE* input = fopen(filePath, "rb");
  char* fileContents = NULL;

  if (input)
  {
    // Move to the end of the file, figure out the length, then move back.
    fseek(input, 0, SEEK_END);
    int fileLength = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Use the length to properly allocate a pointer with sufficient space
    // for both the string and the terminating null.
    fileContents = calloc(fileLength + 1, sizeof(char));
    fread(fileContents, sizeof(char), fileLength, input);

    fclose(input);
  }

  return fileContents;
}

/*
  Takes a string and splits it into smaller strings. The delimiter used is " \n\r".

  Frees the input string when complete!
 */
Dictionary* splitWords(char* str)
{
  unsigned int numberOfWords = 1;
  char* tmp;

  for (tmp = str; *tmp; tmp++)
    if (*tmp == '\n')
      numberOfWords++;

  Dictionary* dict = newDictionary(numberOfWords);
  char* mutable = str;
  unsigned int currentWord = 0;
  char* token;

  for (token = strtok(mutable, " \n\r"); token; token = strtok(NULL, " \n\r"))
  {
    dict->wordList[currentWord] = calloc(1, strlen(token) + 1);
    strcpy(dict->wordList[currentWord], token);
    currentWord++;
  }

  // In this specific code, the string won't be needed again. Remove this line to keep it.
  free(str);

  return dict;
}

/*
  Pulls a random word from a given dictionary.

  Frees the dictionary when complete!
 */
char* dictionaryRandomWord(Dictionary* dict)
{
  unsigned int word = rand() % dict->words;

  char* chosenWord = calloc(1, strlen(dict->wordList[word]) + 1);
  strcpy(chosenWord, dict->wordList[word]);

  // Also in this code, the dictionary won't be needed again. Remove this line to keep it.
  freeDictionary(dict);

  return chosenWord;
}

/*
  Loads a random word from wordList.txt
 */
char* getRandomWord()
{
  return dictionaryRandomWord(splitWords(readRaw("wordList.txt")));
}

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
  srand(time(NULL));

  // char *stringGuess = "guess";
  char *stringGuess = getRandomWord();
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

  displayMenu();


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

  // Display right word
  printf("Correct word: ");
  displayString(stringGuess, guessLen);

  // Free memory from the guessed string
  printf("GAME OVER\n");

  // Free both the correct / wrong strings.
  free(stringRight);
  free(stringWrong);

  return 0;
}
