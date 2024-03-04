#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include<setjmp.h>

using namespace std;

string dealCard();
bool checkDuplicate(string hand[], string aCard);
void dealHand(string hand[]);
void convertToInt(string hand[], int numHand[2][5]);
string findWinner(string hand[]);
void money();
int p1sum=100000,p2sum=100000,x,y;
int p1betontable,p2betontable;
jmp_buf p1j,p2j,p1win,p2win;

int main()
{
// Generate new random numbers each time the program is run
srand(time(NULL));

// Creates an option menu
int option = 0;
 p1betontable=0;p2betontable=0;
bool stop = false;

while(stop != true)
     {
      cout << "*********" << endl;
     cout << "POKER" << endl;
     cout << "*********" << endl << endl;
     cout << "1. Play" << endl;
     cout << "2. Exit" << endl << endl;
     cout << "Choose your option: ";
     cin >> option;

     if(option != 2) {
   
      string hand[9] = {"", "","","","","","","",""};
      dealHand(hand);
      // Deal 2 cards to the player
      cout<<"Player 1 hands :         player two hands :"<<endl;
      cout<<hand[0]<<"          "<<hand[2]<<endl;
      cout<<hand[1]<<"          "<<hand[3]<<endl;
    if(setjmp(p1j)){
      longjmp(p1win,1);
    }
    if(setjmp(p2j)){
      longjmp(p2win,1);
    }
    else{
    money();
    }
    cout<<setw(4)<<"CARDS ON TABLE "<<endl;
    cout<<hand[4]<<"   "<<hand[5]<<"   "<<hand[6]<<endl;
    if(setjmp(p1j)){
      longjmp(p1win,1);
    }
    if(setjmp(p2j)){
      longjmp(p2win,1);
    }
    else{
     money();
    }
     cout<<setw(4)<<"CARDS ON TABLE "<<endl;
     cout<<hand[4]<<"   "<<hand[5]<<"   "<<hand[6]<<"   "<<hand[7]<<endl;
     if(setjmp(p1j)){
      longjmp(p1win,1);
    }
    if(setjmp(p2j)){
      longjmp(p2win,1);
    }
    else{
     money();
    }
     cout<<setw(4)<<"CARDS ON TABLE "<<endl;
     cout<<"  "<<hand[4]<<"       "<<hand[5]<<"     "<<hand[6]<<"     "<<hand[7]<<"     "<<hand[8]<<endl;
      if(setjmp(p1j)){
     longjmp(p1win,1);
    }
      if(setjmp(p2j)){
         longjmp(p2win,1);
    }
    else{
     money();
    }
    int m,n,o,p,q;
    cout<<"Player 1  ,choose your 5 cards  :"<<endl;
    cout<<"0)  "<<hand[0]<<"1)  "<<hand[1]<<"4)  "<<hand[4]<<"5)       "<<hand[5]<<"6)     "<<hand[6]<<"7)     "<<hand[7]<<"8)     "<<hand[8]<<endl;
    cin>>m>>n>>o>>p>>q;
    string hand1[5]= {hand[m],hand[n],hand[o],hand[p],hand[q] };
    cout<<"Player 2  ,choose your 5 cards  :"<<endl;
    cout<<"2)  "<<hand[2]<<"3)  "<<hand[3]<<"4)  "<<hand[4]<<"5)       "<<hand[5]<<"6)     "<<hand[6]<<"7)     "<<hand[7]<<"8)     "<<hand[8]<<endl;
    cin>>m>>n>>o>>p>>q;
    string hand2[5]= {hand[m],hand[n],hand[o],hand[p],hand[q] };
     string p1rank,p2rank;
     p1rank=findWinner(hand1);
     p2rank=findWinner(hand2);
     if(p1rank.length()>p2rank.length()){
     cout<<"Player 1 wins with  "<<p1rank<<"  against player 2's "<<p2rank<<endl;
     p1sum+=(p1betontable+p2betontable);
    }
    if (p1rank.length()<p2rank.length())
    {
     cout<<"Player 2 wins with  "<<p2rank<<"  against player 1's "<<p1rank<<endl;
     p2sum+=(p1betontable+p2betontable);
    }
    else{
      m=p1rank[0];
      n=p2rank[0];
      if(m>n){
        cout<<"Player 1 wins with  "<<p1rank<<"  against player 2's "<<p2rank<<endl;
        p1sum+=(p1betontable+p2betontable);
      }
      if(m<n){
        cout<<"Player 2 wins with  "<<p2rank<<"  against player 1's "<<p1rank<<endl;
        p2sum+=(p1betontable+p2betontable);
      }
      else{
        m=p1rank[1];
      n=p2rank[1];
      if(m>n){
        cout<<"Player 1 wins with  "<<p1rank<<"  against player 2's "<<p2rank<<endl;
        p1sum+=(p1betontable+p2betontable);
      }
      if(m<n){
        cout<<"Player 2 wins with  "<<p2rank<<"  against player 1's "<<p1rank<<endl;
        p2sum+=(p1betontable+p2betontable);
      }
      }
    }
    if(setjmp(p1win)){
     p1sum+=(p1betontable+p2betontable);
    
     goto end;
    }
    if(setjmp(p2win)){
    p2sum+=(p1betontable+p2betontable);
    }

   end:
   cout<<"this round is finished !!!"<<endl;
   cout<<"player 1 wallet :   "<<p1sum<<endl;
   cout<<"player 2 wallet :   "<<p2sum<<endl;
   cout<<endl;
// Pause program
   cin.ignore(256, '\n');
   cout << endl << "Hit return   to continue...";
   cin.get();
   system("CLS");
    
   } else {
   stop = true;
   }
   return 0;
    }
}
// Returns a card from the deck
    string dealCard()
   {
   string card;

   int aSuit = (rand() % (4)) + 1;
   int aCard = (rand() % (13)) + 1;

   string face;

   switch(aSuit)
   {
   case 1: face = " of Hearts"; break;
   case 2: face = " of Spades"; break;
   case 3: face = " of Diamonds"; break;
   case 4: face = " of Clubs"; break;
   }

   string value;

   switch(aCard)
   {
   case 1: value = "Ace"; break;
   case 2: value = "2"; break;
   case 3: value = "3"; break;
   case 4: value = "4"; break;
   case 5: value = "5"; break;
   case 6: value = "6"; break;
   case 7: value = "7"; break;
   case 8: value = "8"; break;
   case 9: value = "9"; break;
   case 10: value = "10"; break;
   case 11: value = "Jack"; break;
   case 12: value = "Queen"; break;
   case 13: value = "King"; break;
   }

   card = (value + face);

   return card;
   }

// Returns true when a given cards already exists within the hand
   bool checkDuplicate(string hand[], string aCard)
  {
    bool duplicate = false;

    for(int i = 0; i < 9; i++) {
     if(hand[i] == aCard)
      duplicate = true;
    }
     return duplicate;
   }

// Deals  random cards to player
    void dealHand(string hand[])
  {
   for(int i = 0; i < 9; i++) {
   string j = dealCard();
   if(checkDuplicate(hand, j) == true)
   i--;
   else
   hand[i] = j;
   }
   }

// Translates hand into an integer array
   void convertToInt(string hand[], int numHand[2][5])
   {
     stringstream stream;

     for(int i = 0; i < 5; i++) {
     if(hand[i].substr(0, 2) == "10") {
     numHand[0][i] = 10;
     } else if(hand[i].substr(0, 1) == "A") {
     numHand[0][i] = 1;
     } else if(hand[i].substr(0, 1) == "J") {
     numHand[0][i] = 11;
     } else if(hand[i].substr(0, 1) == "Q") {
     numHand[0][i] = 12;
     } else if(hand[i].substr(0, 1) == "K") {
     numHand[0][i] = 13;
     } else {
     stream << hand[i].substr(0, 1);
     stream >> numHand[0][i];
     stream.str("");
     stream.clear();
     }
     }

     enum {HEARTS, SPADES, DIAMONDS, CLUBS};

     for(int i = 0; i < 5; i++) {
     if(hand[i].find("Hearts") != -1) {
     numHand[1][i] = HEARTS;
     } else if(hand[i].find("Spades") != -1) {
     numHand[1][i] = SPADES;
     } else if(hand[i].find("Diamonds") != -1) {
     numHand[1][i] = DIAMONDS;
     } else {
     numHand[1][i] = CLUBS;
     }
     }
     }

// Evaluate whether there is a winner in the hand
    string findWinner(string hand[])
  {
    string result = "high";

    bool straightFlush = false;
    bool fourOfAKind = false;
    bool fullHouse = false;
    bool flush = false;
    bool straight = false;
    bool threeOfAKind = false;
    bool twoPair = false;
    bool onePair = false;
    int a,b;
    enum {
    PAIR = 1,
    TWO_PAIR,
    THREE_OF_A_KIND,
    FULL_HOUSE,
     FOUR_OF_A_KIND = 6
     };

    int cards[2][5];
    convertToInt(hand, cards);
   b=cards[0][0];
// Looks for a pair, two pair, three of a kind,
// full house and four of a kind.
     vector<int> winners(0);
     for(int i = 0; i < 4; i++) {
     for(int j = i; j < 4; j++) {
     if(cards[0][i] == cards[0][j + 1]){
     winners.push_back(cards[0][i]);
        a= cards[0][i];}
     }
     }
     if(winners.size() == FOUR_OF_A_KIND)
     fourOfAKind = true;
     else if(winners.size() == FULL_HOUSE)
     fullHouse = true;
     else if(winners.size() == THREE_OF_A_KIND)
     threeOfAKind = true;
     else if(winners.size() == TWO_PAIR)
     twoPair = true;
     else if(winners.size() == PAIR)
     onePair = true;

    // Looks for a straight
     vector<int> orderCards(0);
     for(int i = 0; i < 5; i++)
     orderCards.push_back(cards[0][i]);
    // Bubble sort algorithm
     bool swapped = true;
     int j = 0;
     int tmp;
     while(swapped) {
     swapped = false;
     j++;
     for(int i = 0; i < (orderCards.size() - j); i++) {
     if(orderCards[i] > orderCards[i + 1]) {
     tmp = orderCards[i];
     orderCards[i] = orderCards[i + 1];
     orderCards[i + 1] = tmp;
     swapped = true;
     }
     }
     }
     int checkStraight = orderCards.back();
     while(checkStraight != orderCards.front()) {
     checkStraight--;
     }
     if(checkStraight == (orderCards.back() - (orderCards.size() - 1))) {
     straight = true;
     } else if((orderCards[0] == 1) &&
     (orderCards[1] == 10) &&
     (orderCards[2] == 11) &&
     (orderCards[3] == 12) &&
     (orderCards[4] == 13)) {
     straight = true;
     }

    // Looks for a flush
     for(int i = 0; i < 4; i++) {
     if(cards[1][i] == cards[1][i + 1]) {
      flush = true;
     } else {
     flush = false;
     break;
     }
     }

    // Looks for a straight flush
     if((straight == true) && (flush == true))
      straightFlush = true;
           
           for(int i=1 ;i<5;i++){
           if((cards[0][i]) > (b))
           b=cards[0][i];
           }
           stringstream ss,sy;
           string g,max;
           ss<<a;
           ss>>g;
           sy<<b;
           sy>>max;
     if(straightFlush == true)
     result = max +"0 a Straight Flush!                     ";
     else if(fourOfAKind == true)
     result = g + max + " a Four Of A Kind!            ";
     else if(fullHouse == true)
     result =max + "0  a Full House!             ";
     else if(flush == true)
     result = max + "0 a Flush!                ";
     else if(straight == true)
     result =max+ " a Straight!               ";
     else if(threeOfAKind == true)
     result = g + max +"a Three Of A Kind!";
     else if(twoPair == true)
     result = g + max +" Two Pairs!";
     else if(onePair == true)
     result = g + max + "a Pair!";

     return result;
    }
   void money(){
    int c1,c2;
    do{
    cout<<"1.CHECK 2.CALL 3.RAISE 4.ALL IN 5.FOLD "<<endl<<"player 1 choice :"<<endl;
    cin>>c1;
    switch(c1){
        case(1):x=0;break;
        case(2):
        if(c2==3||c2==4){
        x=y;
        goto stepi;
        break;
        }
        else{
            cout<<"amount :"<<endl;
             cin>>x;
        break;   
        }
        
        case(3):
        cout<<"amount :"<<endl;
         cin>>x;
        break;
        case(4):
        x=p1sum;break;
        case(5):
        longjmp(p1j,1);
         break;
    }
    cout<<"1.CHECK 2.CALL 3.RAISE 4.ALL IN 5.FOLD "<<endl;
    cout<<"player 2 choice "<<endl;
    cin>>c2;
    switch(c2){
        case(1):y=0;break;
        case(2):
        if(c1==2||c1==3||c1==4){
            y=x;
            break;
        }
        else{
            cout<<"amount :"<<endl;
             cin>>y;
        break;   
        }
        
        case(3):
        cout<<"amount :"<<endl;
         cin>>y;
        break;
        case(4):
        y=p2sum;   
        break;
        case(5):
        longjmp(p2j,1);
        break;
         
    }
   
    
     }while((c2==3)||(c1==1 && c2==2));
     stepi:
      p1betontable +=x;
         p1sum-=x;
      p2betontable +=y;
         p2sum-=y;
     cout<<"MONEY ON TABLE :    "<<(p1betontable+p2betontable)<<endl;
     cout<<"player 1 wallet :   "<<p1sum<<endl;
     cout<<"player 2 wallet :   "<<p2sum<<endl;

    }