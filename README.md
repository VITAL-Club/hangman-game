# hangman-game
This is a hangman game coded in C
                                              FLOW CHART
   _______________             __________________________            ____________________________        
  | Program start | --------> | Pick a word using random | -------> | Display # of char with "_"|
  ----------------             --------------------------            ----------------------------
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
