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
  system("clear");
  // main loop control variable
  int selection;
  vector<int> pseudoStack;

  // Initial game setup.
  // !TODO: Set constructors as virtual, there are 3 instances of the game running

  Pile solitaire;
  solitaire.createDeck();
  DrawPile drawPile( solitaire.getCards() );
  Hand hand;
  hand.fillHand( solitaire.getCards() );
  TargetPile targetPile;

  // Welcome message
  cout << "\nWelcome to Klondike's solitaire!";


  // I want to loop back until the user selection is equal to 5
  do{
    targetPile.displayGame(drawPile);
    targetPile.displayHand( hand.getHands() );
    // Start the game
    selection = solitaire.bootstrap();

    switch (selection){
      // 1: To Draw a card
      case 1 :
        drawPile.drawCard();
        break;
      // 2: To move the draw card
      case 2 :
        solitaire.displayDrawMenu();

        int targetHand;
        cin >> targetHand;

        // sends you back to the menu
        if (targetHand == 8)
          break;

        // initial validation
        while (targetHand < 0 || targetHand > 8){
          cout << "\ninvalid input, enter a number 0-8.\n";
          cin >> targetHand;
        }

        // cout << "\nDraw card is: " << drawPile.getFace( drawPile.getCards().front() );
        int drawCard;
        drawCard = drawPile.getFace( drawPile.getCards().front() );

        // sends draw card to targetPiles
        if(targetHand == 0){
          bool pop = false;
          pop = targetPile.moveToTarget( drawCard );

          if (pop == true){
            drawPile.popCard();
          }

          break;
        }

        hand.getHands().clear();
        hand.getHands()[targetHand-1].push_front( drawCard );
        break;

      // 3: To select one of the hand cards
      case 3 :
        hand.displayHandMenu();
        int handNumber;
        int targetHandNumber; //clears old result
        int popAmount; // amount to be removed from vector after move is completed
        bool moveable;

        pseudoStack.clear();


        cin >> handNumber;

        // initial validation
        while (handNumber < 1 || handNumber > 8){
          cout << "\ninvalid input, enter a number 1-8.\n";
          system("clear");
          cin >> handNumber;
        }

        // sends  card to targetPiles
        if(handNumber == 8)
          break;



        pseudoStack = hand.checkHand( handNumber );
        if (pseudoStack.size() == 0){
          cout << "\nThis hand is empty, try something else";
          break;
        }

        cout << "\nHow many cards would you like to move?";
        pseudoStack = hand.selectCards( pseudoStack );
        popAmount = pseudoStack.size();


        targetPile.displayHand( hand.getHands() );

        cout << "\nWhich hand would you like to move your selected card(s) to?";
        // Get Target Hand
        hand.displayHandMenu();

        cin >> targetHandNumber;

        // initial validation
        while (
          (targetHandNumber < 1 || targetHandNumber > 8)
          || (targetHandNumber == handNumber)
        ){

          if (targetHandNumber < 1 || targetHandNumber > 8){
            cout << "\ninvalid input, enter a number 1-8.\n";
            hand.displayHandMenu();
            cin >> targetHandNumber;
          }

          if (targetHandNumber == handNumber){
            cout << "\nYou cannot move your hand to the same hand, please select another hand.\n";
            hand.displayHandMenu();
            cin >> targetHandNumber;
          }

        }

        // sends  card to targetPiles
        if( targetHandNumber == 8 )
          break;
        // End Get Target Hand

        moveable = hand.checkTargetHand( targetHandNumber, pseudoStack );

        // moves pseudoStack ontop of TargetHand
        if (moveable == true){
          hand.moveHands( targetHandNumber, pseudoStack );
          cout << "\nHands moveds";
        }

        // use popAmount here
        hand.popCards( handNumber, popAmount );
        pseudoStack.clear();

        break;
      // 4: to quit
      case 4 :
        break;


    }

    // if all piles == 13 , selection = 4, You win Message!
    // selection = targetPile.gameOver();
  }while(selection != 4);

  // Exit Message
  cout << "\nThanks for playing!";
  system("clear");
} // End main


/*
  // Deck Order: foreach cards as card (sorta)
  for( int card : solitaire.getCards() )
    cout << "\ncard: " << card;
deque<int> getHand7();
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
