# hangman-game
This is a hangman game coded in C
                                              
                                              FLOW CHART
                                              
                                              
   _______________             __________________________            ____________________________        
  | Program start | --------> | Pick a word using random | -------> | Display # of char with "_"  
   ----------------             --------------------------            ---------------------------
                                                                          /
                                                                        /
                                                                      /
                                                                  ________________
                                                                 | Guess the word |
                                                                  ----------------
                                                                 /              \
                                                         loop   /                \     loop
                                                               /                  \
                                                         _______________        ________________
                                                        | Correct guess |      | Incorrect guess |  
                                                         ---------------        -----------------
                                                         /                        |            \
                                                        /                         |             \
                                                 _______________             ____________        _____________________________
                                                | Update letter |           | Update the |      | Check for # of guesses left |
                                                 ---------------            |  hangman   |       -----------------------------
                                                    /                        ------------          /                   |
                                                   /                                              /                    |
      __________                         _______________________                            ______________         __________________
     | Display  |  <------------------- | Check if word is done |                          | If lives > 0 |       | If no lives left | 
     |win screen|                        -----------------------                           | -1 from lives|       | show "game over" |
      ----------                                                                            --------------          -----------------    
      Functions needed:
      - Display menu (Quynh)*
      - Draw hangman
      -> Input: the number of guesses left(int)
         Process: print man
         Output: dawing
      - Display the word(void):
      -> Input: the current word(char *) & the incorrect guess( char*)
         Process: 
         Output: Display the word and incorrect guess
      - Display "Game over" screen( void)
      - Choose a random word to be in the game(char[]) (Frank)*
      -> Input: Import word bank
         Process: randomize to select a word
         Output: Return the selected word
    *: call dibs
    
  - Function to check if the letter is in the word
  
  #include<stdbool.h>
  
  #include<string.h>
  
  bool checkChar( const char* answer, char* current, char guess)
  {
    bool found = false;
    for(int it =0; i < strlen(answer); i++)
    {
    
     if(answer[i] == guess){
      found= true;
      current[i] = guess;
      }
     }
     return found;
     }
