/*
|--------------------------------------------------------------------------
|
|--------------------------------------------------------------------------
|
|
|
|
|
*/

#include "Pile.h"

/*=Pile
******************/
// Creates 52 shuffled cards, 1-13 == "♠️", 14-26 == "♣️", 27-39 == "♦️", 40-52 == "♥️"
void Pile::createDeck()
{

  for(int i = 1;i <= 52; i++)
    cards.push_back(i);


  shuffleDeck();

}

void Pile::shuffleDeck()
{

  mt19937 mt;
  // Creates a time object
  auto current_time = chrono::system_clock::now();
  // gets time since epoch from current time
  auto duration = current_time.time_since_epoch();
  // converts that time to milliseconds
  auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

  // Seed for random, prevents program from using the same # continuously
  mt.seed( millis );


  // shuffles deck
  shuffle( begin( cards ), end( cards ), mt);

}


vector<int> Pile::getCards()
{
  return cards;
}

int Pile::bootstrap()
{

  int selection = displayGameMenu();

  while( selection < 1 || selection > 5 ){
    cout << "\nInvalid input, please choose a number between 1 & 5\n";
    selection = displayGameMenu();
  }

  return selection;

}

int Pile::displayGameMenu()
{

  int menuSelection;

  cout << "\nHere are the menu options, select a number with the corrisponding options"
       << "\n1: To Draw a card"
       << "\n2: To move the draw card"
       << "\n3: To select one of the hand cards"
       << "\n4: to quit"
       << endl;

  cin >> menuSelection;
  return menuSelection;

}

void Pile::displayDrawMenu()
{

  cout << "\nWhich Pile would you like to send your draw card to?"
       << "\nSelect one of the options below"
       << "\n 0: To the target pile"
       << "\n 1: To Hand1"
       << "\n 2: To Hand2"
       << "\n 3: To Hand3"
       << "\n 4: To Hand4"
       << "\n 5: To Hand5"
       << "\n 6: To Hand6"
       << "\n 7: To Hand7"
       << "\n 8: Draw another card"
       << endl;

}

void Pile::displayHandMenu()
{

  cout << "\nWhich hand would you like to select?"
       << "\n 1: Hand1"
       << "\n 2: Hand2"
       << "\n 3: Hand3"
       << "\n 4: Hand4"
       << "\n 5: Hand5"
       << "\n 6: Hand6"
       << "\n 7: Hand7"
       << "\n 8: Go back to the main menu"
       << endl;

}

void Pile::displayTargetHandMenu()
{

  cout << "\nWhich hand would you like to select?"
       << "\n 0: Target Pile"
       << "\n 1: Hand1"
       << "\n 2: Hand2"
       << "\n 3: Hand3"
       << "\n 4: Hand4"
       << "\n 5: Hand5"
       << "\n 6: Hand6"
       << "\n 7: Hand7"
       << "\n 8: Go back to the main menu"
       << endl;

}

int Pile::getFace(int number)
{
  number = number % 13;
  if (number == 0)
    number = 13;

  return number;
}

void Pile::checkFace(int number)
{

  if (number > 1 && number < 11)
    cout << number;
  else if( number == 1)
    cout << "A";
  else if( number == 11)
    cout << "J";
  else if( number == 12)
   cout << "Q";
  else if( number == 13)
   cout << "K";
  else
    cout << "?";

}

string Pile::getSuit(int number)
{

  string suit;
  if (number <= 13)
    suit = "♠️";
  else if (number >= 14 && number <= 26)
    suit = "♣️";
  else if (number >= 27 && number <= 39)
    suit = "♦️";
  else if (number >= 40 && number <= 52)
    suit = "♥️";
  else
    suit = "ERROR";

    return suit;
}
