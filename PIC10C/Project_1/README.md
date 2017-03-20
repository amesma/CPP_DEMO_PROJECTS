README FILE

This project will implement a Spanish version of Blackjack, known as "Siete y medio", or 7 and a half.

Classes: Cards, Hand, Player.

Files: cards.h

cards.cpp

siete_y_medio.cpp

Your assignment is to write a single-player version of the card game known as 'siete y medio' (seven and a half), which is very similar in nature to the casino game of Blackjack (also known as 21). The goal of the game is to get cards whose total value comes the closest to 71/2 without going over it. Getting a card total over 71/2 is called "busting". 

When a player makes a bet against the dealer. There are 4 possible outcomes:

The player comes closer to 71/2 than the dealer or the dealer busts but the player did not bust. 
In this case the player wins the round and the player's money increases by the amount that was bet.
The dealer comes closer to 71/2 than the player, or the player busts.
In this case the player loses the round and the player's money decreases by the amount that was bet.
Both, the player and dealer bust.
In this case the player loses the round and the player's money decreases by the amount that was bet. 
This is called house advantage. 
Both the player and the dealer have the same total and  they do not bust.
In this case a tie is declared and no money is exchanged.

From the Spanish playing cards entry of wikipedia: 
"The traditional Spanish baraja is an old deck that was brought over by the Moors to Spain during the 14th century. The cards are still called naipes after the nā'ib cards found in the Mamluk deck... 

Smaller decks have 40 cards and lack ranks 8, 9 and comodines (jokers). The four suits are bastos (clubs), oros (literally "golds", that is, golden coins), copas (cups) and espadas (swords). The four suits are thought to represent the four social classes of the Middle Ages. The suit of coins represents the merchants, the clubs represents the peasants, the cups represent the church and the swords represent the military.

The three face cards of each suit have pictures similar to the jack, queen, and king in the French deck, and rank identically. They are the sota, which is similar to the jack/knave and generally depicts a page or squire, the caballo (knight, literally "horse"), and the rey (king) respectively.

At each round of play the player places a bet. After that, the player and the dealer each draw one card from the deck.The player is then repeatedly asked if another card is wanted. The player can continue to draw cards while the total is less than 71/2. After the player's turn is over, the dealer's cards are shown. The dealer's play is always the same: the dealer continues to draw cards only if the total is less than 51/2.

The value of every card doesn't always agree with the rank of the card. The values are listed in the following table:
Cards in 'siete y medio'
Name:	   As   	  Dos  	  Tres  	 Cuatro 	 Cinco 	  Seis  	 Siete 	  Sota  	Caballo	  Rey  
Rank:	1	2	3	4	5	6	7	10	11	12
Value: 	1	2	3	4	5	6	7	1/2	1/2	1/2

For this assignment, assume the player starts with 100 pesos (or dollars) and the game ends when the player is down to 0 or when the dealer loses 900. Also, it is a good idea to add input validation and prevent the user from betting an amount bigger than the one the player actually has.



Test cases:
1.Enter N first.
Program should quit.
2. Enter Y three times.
No matter what cards are, should either restart game when you lose, or keep going.
3. Enter letter other than Y or N.
Should have no effect until you enter Y or N.
4. Enter number when asked to enter Y or N. This should only loop when it is not the user's first time being asked that.
Should have no effect until you enter Y or N.

Known bugs: Code does not produce log file or show you cards one at a time, only all the cards a user has at once.

Code structured based on: http://hawkee.com/snippet/7632/
