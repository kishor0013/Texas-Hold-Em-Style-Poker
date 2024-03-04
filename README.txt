Texas Hold’em   poker is a thrilling card game played with a standard deck of 52 cards. The game revolves around strategic decision-making, psychology, and a dash of luck. Here’s how it works:

Starting the Game:
1.Each player receives two private cards (known as “hole cards”).
2.Five community cards are dealt face-up on the table.
Hand Rankings:
The goal is to create the best possible five-card hand using your hole cards and the community cards.
Let’s explore the hand rankings from highest to lowest:
Royal Flush: A, K, Q, J, and 10, all of the same suit. It’s the ultimate hand!
Straight Flush: Any straight with all cards of the same suit (e.g., 9♥ 8♥ 7♥ 6♥ 5♥).
Four-of-a-Kind (Quads): Four cards of the same rank (e.g., J♦ J♣ J♠ J♥ K♦).
Full House: Three cards of one rank and two cards of another (e.g., A♥ A♣ A♦ 9♠ 9♣).
Flush: Five cards of the same suit (e.g., A♠ J♠ 8♠ 4♠ 3♠).
Straight: Five consecutive cards (not necessarily of the same suit, e.g., 9♥ 8♠ 7♣ 6♦ 5♣).
Three-of-a-Kind (Trips): Three cards of the same rank (e.g., 7♠ 7♦ 7♣ K♦ Q♣).
Two Pair: Two sets of pairs (e.g., 9♣ 9♦ 6♣ 6♠ Q♥).
One Pair: Two cards of the same rank (e.g., A♦ A♥ K♠ 9♦ 4♥).
High Card: When no other hand is made, the highest card in your hand (e.g., A♠ J♦ 8♣ 6♠ 2♥).
Example Hand:
Imagine you have K♥ 9♥, and the community cards are K♠-T♣-T♦-4♠-2♣.
Your final hand would be K♥ K♠ T♣ T♦ 9♥, which is Two Pair (Kings and Tens) with a Nine kicker.
This program tries to replicate above.  The initial goals for this project that I had in my mind are:
1.	Cross platform library, supports all compilers
2.	Clean, good quality code, consistent formatting  
3.	Unit test everything
4.	Optimize for speed and size

A simple walkthrough of my functions:
I tried to break down my problem into as many simple functions as possible.
Main function – it starts the game and runs until one of the players exits.
                                 It gives 2 cards to each player and 5 cards on table and evaluates
                                  the winner using several functions.
Deal card () – it does the job of generating 9 random cards ,2 for each player and 5 on table for both           players use.
Check duplicate () -it cjhecks whether the randomly generated card is a duplicate of previously generated card.
Deal hand () -it deals the cards generated to players as hands and on table.
Find winner ()-it takes the 5 cards as input from the players and find their hand ranks.         
                            It also returns the ranks in the form of string such that the higher order rank has 
                             Higher length .it uses some other functions.
Convert to int () -it converts the hand provided to it into 2-D array of integers for finding
                                the hand ranks.
Money () – it performs the task related with calling ,raising  of money between each rounds .

it also provides the option to do rounds of game each time clearing the screen after a round.
