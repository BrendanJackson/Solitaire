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
#include "DrawPile.h"
#include "Hand.h"
#include "TargetPile.h"


int main()
{
  cout << endl;
  // main loop control variable
  int selection;
  int cardValue;
  // Initial game setup.
  // !TODO: Set constructors as virtual, there are 3 instances of the game running

  Pile solitaire;
  DrawPile drawPile( solitaire.getCards() );
  Hand hand( solitaire.getCards() );
  TargetPile targetPile;

  // Welcome message
  cout << "\nWelcome to Klondike's solitaire!";


  // I want to loop back until the user selection is equal to 5
  do{
    targetPile.displayGame(solitaire, drawPile, hand);
    // Start the game
    selection = solitaire.bootstrap();
    switch (selection){
      // 1: To Draw a card
      case 1 : cout << "1 was selected";
        drawPile.drawCard();
        break;
      // 2: To move the draw card
      case 2 : cout << "2 was selected";
        solitaire.displayHandMenu();
        int handNumber;
        cin >> handNumber;

        // initial validation
        while (handNumber < 1 || handNumber > 8){
          cout << "\ninvalid input, enter a number 1-8.\n";
          system("clear");
          cin >> handNumber;
        }
        cardValue = drawPile.getCardValue( hand, handNumber );
        // Game logic validation
        while(
          // Prevent user from moving anything but a king to an empty hand
          ( drawPile.getCards().front() != 13 && drawPile.getHand( hand, handNumber ).size() == 0 )
          ||// Prevent user from moving any card but "1 less" than the 1st visible card on the hand
          ( drawPile.getCards().front() != cardValue -1 )
        ) {
          if ( drawPile.getCards().front() != 13 && drawPile.getHand( hand, handNumber ).size() == 0 ){

            cout << "\n Invalid move, you can only move a king to an empty hand, please try another action\n";
            solitaire.displayHandMenu();
            system("clear");
            cin >> handNumber;

          } else {

            cout << "\n You can only put a card on top of a card that is 1 higher, please try another action\n";
            solitaire.displayHandMenu();
            system("clear");
            cin >> handNumber;

          }

        }


        if (handNumber == 8)
          break;

        drawPile.moveCard( drawPile.getHand( hand, handNumber ) );
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

  // Exit Message
  cout << "\nThanks for playing!";
  cout << endl;
} // End main


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

/*
cout << "\nDeque Test";
cout << "\nhand.getHand1().size(): " << hand.getHand7().size();
cout << "\nindex 0: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size()];
cout << "\nindex 1: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 1];
cout << "\nindex 2: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 2];
cout << "\nindex 3: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 3];
cout << "\nindex 4: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 4];
cout << "\nindex 5: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 5];
cout << "\nindex 6: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 6];
cout << endl;
exit(0);
*/
