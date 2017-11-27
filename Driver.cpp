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

  // Initial game setup
  Pile solitaire;
  DrawPile drawPile( solitaire.getCards() );
  Hand hand( solitaire.getCards() );

  // Start the game
  solitaire.bootstrap();



  cout << endl;
}


/*
  // Deck Order: foreach cards as card (sorta)
  for( int card : solitaire.getCards() )
    cout << "\ncard: " << card;

  // Draw Pile
  cout << "\ndrawPile.size " << drawPile.getCards().size();

  // Hand Piles
  cout << "\nhand1.size " << hand.getHand1().size();
  cout << "\nhand2.size " << hand.getHand2().size();
  cout << "\nhand3.size " << hand.getHand3().size();
  cout << "\nhand4.size " << hand.getHand4().size();
  cout << "\nhand5.size " << hand.getHand5().size();
  cout << "\nhand6.size " << hand.getHand6().size();
  cout << "\nhand7.size " << hand.getHand7().size();
*/
