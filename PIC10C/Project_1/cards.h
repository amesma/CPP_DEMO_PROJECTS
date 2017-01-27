/* *************************************
   Ricardo Salazar, February 26, 2015

   Interface of a simple Card class
   ************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

   /*
   The values for this type start at 0 and increase by one 
   afterwards until they get to SIETE. 
   The rank reported by the function Card::get_rank() below is 
   the value listed here plus one.
   E.g: 
   The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
   The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
   */
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Card {
   public: 
      // Constructor assigns random rank & suit to card.
      Card();
      
      // Accessors 
      string get_spanish_suit() const;
      string get_spanish_rank() const; 

      /* 
         These are the only functions you'll need to code 
         for this class. See the implementations of the two 
	 functions above to get an idea of how to proceed.
      */
      string get_english_suit() const;
      string get_english_rank() const; 

	  //should have return value

      // Converts card rank to number.
      // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
      int get_rank() const;
	  float get_value() const;

      // Compare rank of two cards. E.g: Eight<Jack is true.
      // Assume Ace is always 1. 
      // Useful if you want to sort the cards.
      bool operator < (Card card2) const;

private:
      suit_t suit;
      rank_t rank;
};


class Hand {
   public:
      // A vector of Cards
	   Hand();
	   void add(Card* new_card);
	   void add_card();
	   float get_total() const;
	   void clear();
      // You decide what functions you'll need...

	   //memory management
	   ~Hand() {
		   for (auto& x : card_hand)
			   delete x;
	   }

   private:
	   vector<Card*> card_hand;
      // You decide what fields you'll need...
};


class Player {
   public:
	   Player();// Constructor.
      //    Assigns initial amount of money
	   Player(int m) { money = m; };
	   virtual bool hit() const;
	   virtual bool bust() const;
	//   float current_amount();
      // You decide what functions you'll need...
	   virtual ~Player();
   private:
      int money;
      // You decide what extra fields (if any) you'll need...
};

class Game {

public:
	Game();
	void play();

private:

};

class Dealer:public Player {

};

class GameUser :public Player {

};
#endif