/* !TODO rm https://www.daniweb.com/programming/software-development/threads/438882/help-with-a-deck-of-cards-program
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


int main()
{
  cout << endl;
  Pile solitaire;
  DrawPile drawPile( solitaire.getCards() );
  Hand hand( solitaire.getCards() );

  // foreach cards as card (sorta)
  for( int card : solitaire.getCards() )
    cout << "\ncard: " << card;

  cout << "\ndrawPile.front " << drawPile.getCards().front();

  cout << "\nhand1.getCards " << hand.getHand1().front();
  cout << "\nhand2.getCards " << hand.getHand2().front();
  cout << "\nhand3.getCards " << hand.getHand3().front();
  cout << "\nhand4.getCards " << hand.getHand4().front();
  cout << "\nhand5.getCards " << hand.getHand5().front();
  cout << "\nhand6.getCards " << hand.getHand6().front();
  cout << "\nhand7.getCards " << hand.getHand7().front();

  cout << endl;
}
