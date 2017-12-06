#include "TargetPile.h"

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
    if( clubs.empty() && card == 1){
        clubs.push(card);
        pop = true;
    } else if ( clubs.empty() && card != 1 )
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
    if( diamonds.empty() && card == 1){
        diamonds.push(card);
        pop = true;
    } else if ( diamonds.empty() && card != 1 )
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
    if( hearts.empty() && card == 1){
      hearts.push(card);
      pop = true;

    } else if ( hearts.empty() && card != 1 )
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
  checkFace(n);
  cout << endl;
  cout << " | Draw1 | | Draw2 |            " << " |   ♠️  | " <<  " |   ♣️  | " <<  " |   ♦️  | " <<  " |   ♥️  | " << endl;
  cout << " +-------+ +-------+            " << " +-------+ " <<  " +-------+ " <<  " +-------+ " <<  " +-------+ " << endl;

// suit

  cout  << " |   ?   | |   ";
  checkFace( n );
  cout << "   |" ;

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

  // face
  cout  << " |   ?   | |   ";
  checkFace( n );
  cout << "   |" ;

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


  // displayHand( hand.getHands() );


}


void TargetPile::displayHand( vector< deque<int> > hands )
{
  cout << " |   1   | |   2   |  |   3   |  |   4   |  |   5   |  |   6   |  |   7   | " << endl;
  cout << " +-------+ +-------+  +-------+  +-------+  +-------+  +-------+  +-------+ " << endl;



  int maxSize = 0;
  cout << endl;
  // display hands in columns
  for (int i = 0; i < hands.size(); i++) {
    maxSize = hands[i].size();
    cout << "["<<i<<"]Size:" << maxSize << "  ";

  }

  size_t n = max_element( hands.begin(), hands.end(),
    [](  const deque<int> &x, const deque<int> &y )
      {
        return x.size() < y.size();
      }
  )->size();
cout << endl;
  for ( size_t i = 0; i < n; i++)
  {
    for ( size_t j = 0; j < hands.size(); j++ )
    {
        cout << setw( 8 );
        if ( i < hands[j].size() )
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

int TargetPile::gameOver()
{

  if (
    (spades.top() == 13)
    && (clubs.top() == 26)
    && (diamonds.top() == 39)
    && (hearts.top() == 52)
  )
    return 4;

  return 0;

}
