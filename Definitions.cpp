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




#include "Declarations.h"

/*=Pile
******************/
// Creates 52 shuffled cards, 1-13 == "♠️", 14-26 == "♣️", 27-39 == "♦️", 40-52 == "♥️"
Pile::Pile()
{

  cout << "\nWelcome to Klondike's solitaire!";

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
       << "\n4: To reset the game"
       << "\n5: to quit"
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
       << "\n 8: Draw another card";

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
       << "\n 8: Draw another card";

}

void Pile::displayGame()
{
  string s; //suit
  if (Pile::getCards().front() < 14)
    s = "♠️";
  else if (Pile::getCards().front() > 14 && Pile::getCards().front() < 27)
    s = "♣️";
  else if (Pile::getCards().front() > 28 && Pile::getCards().front() < 40)
    s = "♦️";
  else
    s = "♥️";

  // !TODO Refactor face cards
  int n = Pile::getCards().front() % 13;

  cout << endl;
  cout << " |       | |       |            " << " |   ♠️  | " <<  " |   ♣️  | " <<  " |   ♦️  | " <<  " |   ♥️  | " << endl;
  cout << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl
       << " |   ?   | |   "<<n<<"   |            " << " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " << endl
       << " |   ?   | |   "<<s<<"  |            " << " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " << endl
       << " |   ?   | |   "<<n<<"   |            " << " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " << endl
       << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl << endl;

  cout << " |   1   |" << " |   2   | " <<  " |   3   | " <<  " |   4   | " <<  " |   5   | " <<  " |   6   | " <<  " |   7   | " << endl;
  cout << " +-------+" << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl
       << " |  num  |" << " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " << endl
       << " |  num  |" << " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " << endl
       << " |  num  |" << " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " <<  " |  num  | " << endl
       << " +-------+" << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl;

}

/*=DrawPile
************/
DrawPile::DrawPile(vector<int> visitingCards)
{

  for(int i = 0;i < 24; i++)
    cards.push( visitingCards[i] );

}

queue<int> DrawPile::getCards()
{
  return cards;
}

void DrawPile::DrawCard()
{

  cout << "\ncards.front(): " << cards.front() << " cards.back(): " << cards.back()
       << " Pushing front card to back";
  cards.push( cards.front() );
  cout << "\ncards.back(): " << cards.back() << " Popping front card off the list!";

  cards.pop();
  cout << "\ncards.front(): " << cards.front() << " cards.back(): " << cards.back();

}

/*=TargetPile
************/
// TargetPile::TargetPile()
// {
//
// }
/*=Hand
************/
Hand::Hand(vector<int> visitingCards)
{
  // refactor
  // hand1{24}, hand2{25,26}, hand3{27, 28, 29}, hand4{30, 31, 32, 33},
  // hand5{34, 35, 36, 37, 38}, hand6{39, 40, 41, 42, 43, 44},
  // hand7{45, 46, 47, 48, 49, 50, 51}
  hand1.push_back( visitingCards[24] );

  hand2.push_back( visitingCards[25] );
  hand2.push_back( visitingCards[26] );

  hand3.push_back( visitingCards[27] );
  hand3.push_back( visitingCards[28] );
  hand3.push_back( visitingCards[29] );

  hand4.push_back( visitingCards[30] );
  hand4.push_back( visitingCards[31] );
  hand4.push_back( visitingCards[32] );
  hand4.push_back( visitingCards[33] );

  hand5.push_back( visitingCards[34] );
  hand5.push_back( visitingCards[35] );
  hand5.push_back( visitingCards[36] );
  hand5.push_back( visitingCards[37] );
  hand5.push_back( visitingCards[38] );

  hand6.push_back( visitingCards[39] );
  hand6.push_back( visitingCards[40] );
  hand6.push_back( visitingCards[41] );
  hand6.push_back( visitingCards[42] );
  hand6.push_back( visitingCards[43] );
  hand6.push_back( visitingCards[44] );

  hand7.push_back( visitingCards[45] );
  hand7.push_back( visitingCards[46] );
  hand7.push_back( visitingCards[47] );
  hand7.push_back( visitingCards[48] );
  hand7.push_back( visitingCards[49] );
  hand7.push_back( visitingCards[50] );
  hand7.push_back( visitingCards[51] );

}

deque<int> Hand::getHand1()
{
  return hand1;
}

deque<int> Hand::getHand2()
{
  return hand2;
}

deque<int> Hand::getHand3()
{
  return hand3;
}

deque<int> Hand::getHand4()
{
  return hand4;
}

deque<int> Hand::getHand5()
{
  return hand5;
}

deque<int> Hand::getHand6()
{
  return hand6;
}

deque<int> Hand::getHand7()
{
  return hand7;
}
