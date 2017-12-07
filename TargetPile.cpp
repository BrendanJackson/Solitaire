#include "TargetPile.h"

void TargetPile::displayStacks()
{
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
    else if( spades.top() == 13)
      cout  << " |   K   | " ;
    else
      cout << " ERROR ";
  } else
    cout  << " |   ?   | " ;

  // clubs
  if(clubs.size() != 0 ){

    if (clubs.top() >= 15 && clubs.top() <= 23)
      cout  << " |   "<<clubs.top()<<"   |"  ;
    else if( clubs.top() == 14)
      cout  << " |   A   | " ;
    else if( clubs.top() == 24)
      cout  << " |   J   | " ;
    else if( clubs.top() == 25)
      cout  << " |   Q   | " ;
    else if( clubs.top() == 26)
      cout  << " |   K   | " ;
    else
      cout << " ERROR ";

  } else
    cout  << " |   ?   | " ;

  // diamonds
  if(diamonds.size() != 0 ){

    if (diamonds.top() >= 28 && diamonds.top() <= 36)
      cout  << " |   "<<diamonds.top()<<"    |" ;
    else if( diamonds.top() == 27)
      cout  << " |   A   | " ;
    else if( diamonds.top() == 37)
      cout  << " |   J   | " ;
    else if( diamonds.top() == 38)
      cout  << " |   Q   | " ;
    else if( diamonds.top() == 39)
      cout  << " |   K   | " ;
    else
        cout << " ERROR ";

  } else
    cout  << " |   ?   | " ;

    // hearts
    if(hearts.size() != 0 ){

      if (hearts.top() >= 41 && hearts.top() <= 48 )
        cout  << " |   "<<hearts.top()<<"   | " ;
      else if( hearts.top() == 40)
        cout  << " |   A   | " ;
      else if( hearts.top() == 50)
        cout  << " |   J   | " ;
      else if( hearts.top() == 51)
        cout  << " |   Q   | " ;
      else if( hearts.top() == 52)
        cout  << " |   K   | " ;
      else
        cout << " ERROR ";

    } else
      cout  << " |   ?   | " ;

   cout << endl;

}

bool TargetPile::moveToTarget(int card)
{
  cout << "\nMoving to target pile";
  bool pop = false;
  // Data Validation for cards
  if (card >= 1 && card <= 13){

    // Makes Ace the 1st card in the stack always
    if( spades.empty() && card == 1){
      spades.push(card);
      pop = true;

    } else if ( spades.empty() && card != 1 )
      cout << "\nThe first card must be an Ace";
    // Makes All cards after the Ace has been entered follow face
    else if ( spades.top() == card - 1){
      spades.push(card);
      pop = true;

    }
    else {
      cout << "\nYou can only place a card that is 1 value higher than the previous card here";
    }

  } else if (card >= 14 && card <= 26){

    // Makes Ace the 1st card in the stack always
    if( clubs.empty() && card == 14){
        clubs.push(card);
        pop = true;
    } else if ( clubs.empty() && card != 14 )
      cout << "\nThe first card must be an Ace";
    // Makes All cards after the Ace has been entered follow face
    else if ( clubs.top() == card - 1){
      clubs.push(card);
      pop = true;
    } else {
      cout << "\nYou can only place a card that is 1 value higher than the previous card here";
    }

  } else if (card >= 27 && card <= 39){

    // Makes Ace the 1st card in the stack always
    if( diamonds.empty() && card == 27){
        diamonds.push(card);
        pop = true;
    } else if ( diamonds.empty() && card != 27 )
      cout << "\nThe first card must be an Ace";
    // Makes All cards after the Ace has been entered follow face
    else if ( diamonds.top() == card - 1){
      diamonds.push(card);
      pop = true;
    } else {
      cout << "\nYou can only place a card that is 1 value higher than the previous card here";
    }

  } else if (card >= 40 && card <= 52){

    // Makes Ace the 1st card in the stack always
    if( hearts.empty() && card == 40){
      hearts.push(card);
      pop = true;

    } else if ( hearts.empty() && card != 40 )
      cout << "\nThe first card must be an Ace";
    // Makes All cards after the Ace has been entered follow face
    else if ( hearts.top() == card - 1){
      hearts.push(card);
      pop = true;
    } else {
      cout << "\nYou can only place a card that is 1 value higher than the previous card here";
    }

  } else
    cout << "\nTargetPile ERROR";


  return pop;
}


// DrawPile drawPile, Hand hand, TargetPile targetPile
void TargetPile::displayGame( DrawPile drawPile )
{
  // Draw Variables
  string s; //suit
  int n; // number


  s = getSuit( drawPile.getCards().front() );
  n = getFace( drawPile.getCards().front() );
  // checkFace(n);
  cout << endl;
  cout << " | Draw1 | | Draw2 |            " << " |   ♠️  | " <<  " |   ♣️  | " <<  " |   ♦️  | " <<  " |   ♥️  | " << endl;
  cout << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl;

// suit

  cout  << " |   ?   | |   ";
  checkFace( n );
  cout << "   |" ;

// space
cout << "            " ;

displayStacks();
// suit
  cout << " |   ?   | |   "<<s<<"  |            " << " |   ♠️  | " <<  " |   ♣️  | " <<  " |   ♦️  | " <<  " |   ♥️  | " << endl;

  // face
  cout  << " |   ?   | |   ";
  checkFace( n );
  cout << "   |" ;

  // Card Values
  // space
  cout << "            " ;

  displayStacks();

  cout     << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl << endl;


}


void TargetPile::displayHand( vector< deque<int> > hands )
{
  cout << "    | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |   | 7 | " << endl;
  cout << "    +---+   +---+   +---+   +---+   +---+   +---+   +---+ " << endl;
  cout << endl;

  // check for hidden values
  getHidden();


  size_t n = max_element( hands.begin(), hands.end(),
    [](  const deque<int> &x, const deque<int> &y )
      {
        return x.size() < y.size();
      }
  )->size();

  for ( size_t i = 0; i < n; i++)
  {
    for ( size_t j = 0; j < hands.size(); j++ )
    {
        if ( ( hands[i].size() == hidden[i].size() ) && ( hidden[i].size() != 1 ) ){
          hidden[i].pop_back();
          cout << i << "size: "<< hidden[i].size();
        }


        // cout << "\nhands[i].size(): " << hands[i].size()
        //      << " hidden[i].size(): " << hidden[i].size();

        if ( ( hands[i].size() == hidden[i].size() ) && ( hidden[i].size() == 1 ) ){
          hidden[i][j] = 0;
          // cout << "\nhidden remove hidden status, hidden[i][j]: " << hidden[i][j];
        }


        cout << setw( 8 );

        if( hidden[j][i] == 1 ) // hidden[][] == true{ cout ???}
        {
          cout << setw(8) << fixed << right << "???";

        }
        else if ( i < hands[j].size() )
        {
          cout << setw(6) << fixed << right;
          checkFace(getFace(hands[j][i]));
          cout << getSuit(hands[j][i]);
        }
        else
        {
            cout << "";
        }
    }

    cout << endl;
  }
    // end display hands in columns

  cout << endl;

}


stack <int> TargetPile::getSpades()
{
  return spades;
}
stack <int> TargetPile::getClubs()
{
  return clubs;
}
stack <int> TargetPile::getDiamonds()
{
  return diamonds;
}
stack <int> TargetPile::getHearts()
{
  return hearts;
}

// int TargetPile::gameOver()
// {
//
//   if (
//     (spades.top() == 13)
//     && (clubs.top() == 26)
//     && (diamonds.top() == 39)
//     && (hearts.top() == 52)
//   ){
//     return 4;
//   } else {
//     return 0;
//   }
//
//
// }


vector < vector <bool> > & TargetPile::getHidden()
{

  hidden.push_back( hidden1 );
  hidden.push_back( hidden2 );
  hidden.push_back( hidden3 );
  hidden.push_back( hidden4 );
  hidden.push_back( hidden5 );
  hidden.push_back( hidden6 );
  hidden.push_back( hidden7 );

  return hidden;

}
