#include "DrawPile.h"

DrawPile::DrawPile(vector<int> visitingCards)
{

  for(int i = 0;i < 24; i++)
    cards.push( visitingCards[i] );

}

queue<int> DrawPile::getCards()
{
  return cards;
}

void DrawPile::drawCard()
{

  cout << "\ncards.front(): " << cards.front() << " cards.back(): " << cards.back()
       << " Pushing front card to back";
  cards.push( cards.front() );
  cout << "\ncards.back(): " << cards.back() << " Popping front card off the list!";

  cards.pop();
  cout << "\ncards.front(): " << cards.front() << " cards.back(): " << cards.back();

}

int DrawPile::getCardValue( Hand handObject, int handNumber )
{
// !TODO: duplication needs removed
  deque<int> handChoice;

  switch (handNumber){

    case 1:
      handChoice = handObject.getHand1();
      break;

    case 2:
      handChoice = handObject.getHand2();
      break;

    case 3:
      handChoice = handObject.getHand3();
      break;

    case 4:
      handChoice = handObject.getHand4();
      break;

    case 5:
      handChoice = handObject.getHand5();
      break;

    case 6:
      handChoice = handObject.getHand6();
      break;

    case 7:
      handChoice = handObject.getHand7();
      break;
  }

  // !TODO: terrible name
  int number = handChoice.front() % 13;
  if (number == 0)
    number = 13;

  return number;

}

deque<int> DrawPile::getHand( Hand handObject, int handNumber )
{

  deque<int> handChoice;
  switch (handNumber){

    case 1:
      handChoice = handObject.getHand1();
      break;

    case 2:
      handChoice = handObject.getHand2();
      break;

    case 3:
      handChoice = handObject.getHand3();
      break;

    case 4:
      handChoice = handObject.getHand4();
      break;

    case 5:
      handChoice = handObject.getHand5();
      break;

    case 6:
      handChoice = handObject.getHand6();
      break;

    case 7:
      handChoice = handObject.getHand7();
      break;
  }


  return handChoice;
}

void DrawPile::moveCard( deque<int> hand )
{
  // cout << "\n\nhand.front()" << hand.front()
  //      << "\nhand.back()" << hand.back()
  //      << "\nhand.size()" << hand.size();

  hand.push_front( cards.front() );

  // cout << "\n\nhand.front()" << hand.front()
  //      << "\nhand.back()" << hand.back()
  //      << "\nhand.size()" << hand.size();

  // cout << "\n\ncards.size(): " << cards.size()
  //      << "\ncards.front(): " << cards.front()
  //      << endl;

  cards.pop();

  // cout << "\n\ncards.size(): " << cards.size()
  //      << "\ncards.front(): " << cards.front()
  //      << endl;
}
