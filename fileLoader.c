#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  for (unsigned int i = 0; i < dict->words; i++)
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
  
  for (char* tmp = str; *tmp; tmp++)
    if (*tmp == '\n')
      numberOfWords++;

  Dictionary* dict = newDictionary(numberOfWords);
  char* mutable = str;
  unsigned int currentWord = 0;
  
  for (char* token = strtok(mutable, " \n\r"); token; token = strtok(NULL, " \n\r"))
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

