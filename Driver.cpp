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
  // main loop control variable
  int selection;
  // Initial game setup
  Pile solitaire;
  DrawPile drawPile( solitaire.getCards() );
  Hand hand( solitaire.getCards() );

  // I want to loop back until the user selection is equal to 5
  do{
    // Start the game
    selection = solitaire.bootstrap();
    switch (selection){
      // 1: To Draw a card
      case 1 : cout << "1 was selected";
        drawPile.DrawCard();
        break;
      // 2: To move the draw card
      case 2 : cout << "2 was selected";
        break;
      // 3: To select one of the hand cards
      case 3 : cout << "3 was selected";
        break;
      // 4: To reset the game
      case 4 : cout << "4 was selected";
        break;
      // 5: to quit
      case 5 : cout << "5 was selected";
        break;
    }
  }while(selection != 5);

  cout << "\nThanks for playing!";
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
