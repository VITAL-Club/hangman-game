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
     
   - Function needed:
      - Display menu (Quynh)*
      - Draw hangman<br/>
      -> Input: the number of guesses left(int)<br/>
         Process: print man<br/>
         Output: drawing
      - Display the word(void):<br/>
      -> Input: the current word(char *) & the incorrect guess( char*)<br/>
         Process: <br/>
         Output: Display the word and incorrect guess<br/>
      - Choose a random word to be in the game(char[]) (Frank)* <br/>
      -> Input: Import word bank<br/>
         Process: randomize to select a word<br/>
         Output: Return the selected word<br/>
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
