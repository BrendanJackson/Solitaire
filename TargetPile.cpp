#include "TargetPile.h"

// TargetPile::TargetPile()
// {
//
// }

// DrawPile drawPile, Hand hand, TargetPile targetPile
void TargetPile::displayGame( Pile pile, DrawPile drawPile, Hand hand )
{
  // Draw Variables
  string s; //suit
  int n; // number




  // Get the cards suit
  if (drawPile.getCards().front() < 14)
    s = "♠️";
  else if (drawPile.getCards().front() > 14 && drawPile.getCards().front() < 27)
    s = "♣️";
  else if (drawPile.getCards().front() > 28 && drawPile.getCards().front() < 40)
    s = "♦️";
  else
    s = "♥️";

    // !TODO Refactor face cards
    // Get the cards number
    n = drawPile.getCards().front() % 13;
    if (n == 0)
      n = 13; //handles king exception


  cout << endl;
  cout << " | Draw1 | | Draw2 |            " << " |   ♠️  | " <<  " |   ♣️  | " <<  " |   ♦️  | " <<  " |   ♥️  | " << endl;
  cout << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl;

// suit
  if (n > 1 && n < 11)
    cout  << " |   ?   | |   "<<n<<"   |" ;
  else if( n == 1)
    cout  << " |   ?   | |   A   |" ;
  else if( n == 11)
    cout  << " |   ?   | |   J   |" ;
  else if( n == 12)
    cout  << " |   ?   | |   Q   |" ;
  else
    cout  << " |   ?   | |   K   |" ;

// space
cout << "            " ;
// stack 1,2,3,4
// spades
if(spades.size() != 0 ){
  if (spades.top() > 1 && spades.top() < 11)
    cout  << " |   "<<spades.top()<<"   | " ;
  else if( spades.top() == 1)
    cout  << " |   A   | " ;
  else if( spades.top() == 11)
    cout  << " |   J   | " ;
  else if( spades.top() == 12)
    cout  << " |   Q   | " ;
  else
    cout  << " |   K   | " ;
} else
  cout  << " |   ?   | " ;

// clubs
if(clubs.size() != 0 ){
  if (clubs.top() > 1 && clubs.top() < 11)
    cout  << " |   "<<clubs.top()<<"   |"  ;
  else if( clubs.top() == 1)
    cout  << " |   A   | " ;
  else if( clubs.top() == 11)
    cout  << " |   J   | " ;
  else if( clubs.top() == 12)
    cout  << " |   Q   | " ;
  else
    cout  << " |   K   | " ;
} else
  cout  << " |   ?   | " ;

// diamonds
if(diamonds.size() != 0 ){
  if (diamonds.top() > 1 && diamonds.top() < 11)
    cout  << " |   "<<diamonds.top()<<"    |" ;
  else if( diamonds.top() == 1)
    cout  << " |   A   | " ;
  else if( diamonds.top() == 11)
    cout  << " |   J   | " ;
  else if( diamonds.top() == 12)
    cout  << " |   Q   | " ;
  else
    cout  << " |   K   | " ;
} else
  cout  << " |   ?   | " ;

  // hearts
  if(hearts.size() != 0 ){
    if (hearts.top() > 1 && hearts.top() < 11)
      cout  << " |   "<<hearts.top()<<"   | " ;
    else if( hearts.top() == 1)
      cout  << " |   A   | " ;
    else if( hearts.top() == 11)
      cout  << " |   J   | " ;
    else if( hearts.top() == 12)
      cout  << " |   Q   | " ;
    else
      cout  << " |   K   | " ;
  } else
    cout  << " |   ?   | " ;

 cout << endl;

// suit
  cout << " |   ?   | |   "<<s<<"  |            " << " |   ♠️  | " <<  " |   ♣️  | " <<  " |   ♦️  | " <<  " |   ♥️  | " << endl;

  cout     << " |   ?   | |   "<<n<<"   |";

  // Card Values
  // space
  cout << "            " ;
  // stack 1,2,3,4
  // spades
  if(spades.size() != 0 ){
    if (spades.top() > 1 && spades.top() < 11)
      cout  << " |   "<<spades.top()<<"   | " ;
    else if( spades.top() == 1)
      cout  << " |   A   | " ;
    else if( spades.top() == 11)
      cout  << " |   J   | " ;
    else if( spades.top() == 12)
      cout  << " |   Q   | " ;
    else
      cout  << " |   K   | " ;
  } else
    cout  << " |   ?   | " ;

  // clubs
  if(clubs.size() != 0 ){
    if (clubs.top() > 1 && clubs.top() < 11)
      cout  << " |   "<<clubs.top()<<"   |"  ;
    else if( clubs.top() == 1)
      cout  << " |   A   | " ;
    else if( clubs.top() == 11)
      cout  << " |   J   | " ;
    else if( clubs.top() == 12)
      cout  << " |   Q   | " ;
    else
      cout  << " |   K   | " ;
  } else
    cout  << " |   ?   | " ;

  // diamonds
  if(diamonds.size() != 0 ){
    if (diamonds.top() > 1 && diamonds.top() < 11)
      cout  << " |   "<<diamonds.top()<<"    |" ;
    else if( diamonds.top() == 1)
      cout  << " |   A   | " ;
    else if( diamonds.top() == 11)
      cout  << " |   J   | " ;
    else if( diamonds.top() == 12)
      cout  << " |   Q   | " ;
    else
      cout  << " |   K   | " ;
  } else
    cout  << " |   ?   | " ;

    // hearts
    if(hearts.size() != 0 ){
      if (hearts.top() > 1 && hearts.top() < 11)
        cout  << " |   "<<hearts.top()<<"   | " ;
      else if( hearts.top() == 1)
        cout  << " |   A   | " ;
      else if( hearts.top() == 11)
        cout  << " |   J   | " ;
      else if( hearts.top() == 12)
        cout  << " |   Q   | " ;
      else
        cout  << " |   K   | " ;
    } else
      cout  << " |   ?   | " ;

  // End Card Values

  cout << endl;
  cout     << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl << endl;

  displayHand( hand );


}


void TargetPile::displayHand( Hand hand )
{
  cout << " |   1   | |   2   |  |   3   |  |   4   |  |   5   |  |   6   |  |   7   | " << endl;
  cout << " +-------+ +-------+  +-------+  +-------+  +-------+  +-------+  +-------+ " << endl;
    vector< deque<int> > hands; //vector of type deque<int>
    hands.push_back( hand.getHand1() );
    hands.push_back( hand.getHand2() );
    hands.push_back( hand.getHand3() );
    hands.push_back( hand.getHand4() );
    hands.push_back( hand.getHand5() );
    hands.push_back( hand.getHand6() );
    hands.push_back( hand.getHand7() );

    int maxSize = 0;
    for (int i = 0; i < hands.size(); i++) {
      for (int j = 0; j < hands[i].size(); j++) {
        if ( maxSize < hands[i].size() ) {
          maxSize = hands[i].size();
          cout << "\nnew maxSize: " << maxSize;
        }
      }
    }

    for (int j = 0; j < maxSize; j++) {
      cout << endl;
      for(int i = 0;i < 7;i++){
        cout << setw(10) << fixed;

        if(hands[i][j] == 0)
          cout << " ";
        else if (
          (hands[i][j] > 1 && hands[i][j] < 11) ||
          (hands[i][j] > 14 && hands[i][j] < 24) ||
          (hands[i][j] > 27 && hands[i][j] < 37) ||
          (hands[i][j] > 40 && hands[i][j] < 50)
        ){

          int temp = hands[i][j] % 13;
          if (temp == 0)
            temp = 13;

            cout << temp ;

        }  else
          cout << getCardValue( hands[i][j] ) ;

          // getSuit
          if (hands[i][j] >= 1 && hands[i][j] <= 13)
           cout << spade;
          else if (hands[i][j] >= 14 && hands[i][j] <= 26 )
           cout << club;
          else if (hands[i][j] >= 27 && hands[i][j] <= 39 )
           cout << diamond;
          else if (hands[i][j] >= 40 && hands[i][j] <= 52 )
           cout << heart;
          else
           cout << "  ";


      }
    }



  cout << endl;

}


string TargetPile::getCardValue(int cardNumber)
{
  string showCard;

  cardNumber = cardNumber % 13;
  if (cardNumber == 0)
    cardNumber = 13;

  if(cardNumber != 0 ){
    if( cardNumber == 1)
      showCard =  "A" ;
    else if( cardNumber == 11)
      showCard = "J" ;
    else if( cardNumber == 12)
      showCard = "Q" ;
    else
      showCard = "K" ;
  } else
    showCard = "?" ;

  return showCard;
}
