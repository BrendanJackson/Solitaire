
/*
|--------------------------------------------------------------------------
| Pile
|--------------------------------------------------------------------------
| aggregate like data into container classes where it makes sense to do it,
| because it's It's generally easier to pass around an object than a bunch of parameters.
| Keep everything as close to its source as possible because it is generally easier,
| to have a function inside the object that does work on its members and returns,
| a result than to expose the members and have someone else do the work.
|
| Note that "easier" may not be in the immediate "Get 'er done!" sense,
| but instead in the inevitable "Debug and maintain" sense.
| If you track a bug to a member variable and only the class can
| interact with the member variable, the area you have to search for the
| bug is restricted to that one class.
|
| In short, keep the card class as it is, pass around its instantiated object to other classes and dont ever give the other objects there data.
| 1) Create a vector of 52 integer 1-52
| 2) randomize the 52 integers
| 3) Pass 24 integers to a queue called the draw pile
| 4) Pass the remaining integers to 7 different pseudo stack vectors,
| the 1st gets 1 integer, the 2nd gets 2 integers, ... ending with the 7th.
| 5) all of the integers, with the exception of the 1st integer per data structure,
| will not be considered visible.
| 6) Each pile must function as the solitaire game will.
| 7) Some type of menu must be implemented to pass the data around.
| "♥️"
| "♦️"
| "♣️"
| "♠️"
| Each data structure will need to be updated, and also update the "displayGame" method
| in theory, I should be able to do everything the same way I've been doing it
| but on a grander scale. Parent > methods > Child > methods > main?
| What if my parent method needs child data though?
| Or can I just make new methods for the children, passing in data from the other objects?
*/

#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
// contains rand( ) and srand( ) for random number generation
#include <cstdlib>
// contains definitions of time functions
#include <chrono>
#include <random>       // std::default_random_engine
#include <stack>
#include <iomanip>

using namespace std;

class Pile
{
protected:
    vector<int> cards;

public:
  Pile();

  vector<int> getCards();
  void shuffleDeck();

  int bootstrap();

  int displayGameMenu();
  void displayDrawMenu();
  void displayHandMenu();

// DrawPile drawPile, Hand hand, TargetPile targetPile
  void displayGame();

};

#endif
