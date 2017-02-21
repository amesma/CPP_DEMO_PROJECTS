#include "cards.h"
#include <cstdlib>
#include <iostream>

/* 
You might or might not need these two extra libraries 
#include <iomanip>
#include <algorithm>
*/

/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
	os << card.get_spanish_rank() << " de " << card.get_spanish_suit() << "    (" << card.get_english_rank() << " of " << card.get_english_suit() << ")";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	std::vector <Card*>::const_iterator cards;
	if (!(player.card_hand.empty()))
	{
		for (cards = player.card_hand.begin(); cards != player.card_hand.end(); ++cards)
		{
			os << *(*cards) << "\t";
		}
	}
	return os;
}

float Card::get_value() const {
	if (get_rank() <= 7) {
		return get_rank();
	}
	else
	{
		return 0.5;
	}
}
// Accessor: returns a string with the suit of the card in Spanish 
std::string Card::get_spanish_suit() const { 
   std::string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
std::string Card::get_spanish_rank() const { 
   std::string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}
// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
std::string Card::get_english_suit() const {
   std::string suitName;
   switch (suit) {
      case OROS: 
         suitName = "coins"; 
	 break;
      case COPAS: 
         suitName = "cups"; 
	 break; 
      case ESPADAS: 
         suitName = "swords"; 
	 break;
      case BASTOS: 
         suitName = "clubs"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
std::string Card::get_english_rank() const { 
   std::string rankName;
   switch (rank) {
      case AS:
         rankName = "One"; 
	 break; 
      case DOS: 
         rankName = "Two"; 
	 break; 
      case TRES: 
         rankName = "Three"; 
	 break; 
      case CUATRO: 
         rankName = "Four"; 
	 break; 
      case CINCO: 
         rankName = "Five"; 
	 break; 
      case SEIS: 
         rankName = "Six"; 
	 break; 
      case SIETE: 
         rankName = "Seven"; 
	 break; 
      case SOTA: 
         rankName = "Jack"; 
	 break; 
      case CABALLO: 
         rankName = "Knight"; 
	 break; 
      case REY: 
         rankName = "King"; 
	 break; 
      default: break;
   }
   return rankName;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}

Hand::Hand()
{
	card_hand.reserve(1);
}
Hand::~Hand()
{
	clear();
}
/* *************************************************
   Hand class
   ************************************************* */
void Hand::add(Card* new_card) {
	card_hand.push_back(new_card);
}

float Hand::get_total() const{

	float total = 0;

	if (card_hand.empty() == true)
	{
		return 0;
	}
	
		std::vector<Card*>::const_iterator iter;
		for (iter = card_hand.begin(); iter != card_hand.end(); ++iter)
		{
			total += (*iter)->get_value();
		}
	return total;
}

void Hand::clear()
{
	std::vector<Card*>::iterator iter;
	for (iter = card_hand.begin(); iter != card_hand.end(); ++iter)
	{
		delete *iter;
		*iter = nullptr;
	}
}
Deck::Deck() {
	make_deck();
}

void Deck::make_deck() {
	for (size_t i = 0; i < 52; ++i) {
		add(new Card());
	}
}
Deck::~Deck() {

}
void Deck::deal(Hand& a_hand)
{

	if (card_hand.size() > 1)
	{
		a_hand.add(card_hand.back());
		card_hand.pop_back();
	}
}
void Deck::add_cards(Player& player) {

	while (!(player.bust()) && player.hit())
	{
		deal(player);
		
		if (player.bust())
		{
			player.bust_state();
			std::cout << "true";
		}
	}
}
// Implemente the member functions of the Hand class here.
Player::Player(){
	money = 100;
	bet = 0;
}

Player::~Player() {

}
float Player::current_amount() {
	return money;
}
bool Player::hit() {

	std::cout << "Do you want another card? (Y/N) ";
	char response;
	std::cin >> response;
	return (response == 'y' || response == 'Y');
	//should bet and also add new card
}
bool Player::bust() const {
	return(get_total() > 7.5);
}
void Player::bust_state(){
	std::cout << "Too bad. You lost ";
	std::cout << bet << " dollars.";
	money -= bet;
	std::cout << std::endl;
}

int GameUser::ret_money() const{
	return money;
}

int GameUser::ret_bet() const {
	return bet;
}
GameUser::~GameUser() {

}
bool GameUser::hit(){

	char rspd;
	std::cout << "Do you want to hit? (Y/N) ";
	std::cin >> rspd;
	return (rspd == 'Y');
}

void GameUser::win() {
	std::cout << "You win " << bet;
	money += bet;
	win_count++;
}
void GameUser::tie() const {
	std::cout << "Nobody wins!";
}
int GameUser::return_win() const{
	return win_count;
}

void GameUser::enter_bet(int new_bet)
{
	bet = new_bet;
}
Dealer::Dealer() {

}
Dealer::~Dealer() {

}
bool Dealer::hit(){
	return(get_total() < 5.5);
}
Game::Game() {
	//initialize dealer and user
	deck.make_deck();
}

Game::~Game() {

}

bool Game::no_money() {
	if (user.current_amount() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::play() {

	if (user.ret_bet() == 0)
	{
		int bet;
		std::cout << "You have $" << user.ret_money() << "\t Enter a bet:";
		std::cin >> bet;
		user.enter_bet(bet);
	}

	//deal to player and house
	deck.deal(user);
	deck.deal(dealer);

	std::cout << user << std::endl;

	if (user.get_total() != 0)
	{
		std::cout << "Your total is (" << user.get_total() << ")" << std::endl;
	}

	std::cout << dealer << std::endl;

	if (dealer.get_total() != 0)
	{
		std::cout << "Dealer's total is (" << dealer.get_total() << ")" << std::endl;
	}

	deck.add_cards(user);
	deck.add_cards(dealer);

	if (dealer.bust())
	{
		user.win();
	}
	else
	{
		if (!user.bust())
		{
			if (user.get_total() > dealer.get_total())
			{
				user.win();
			}
			else if (user.get_total() < dealer.get_total())
			{
				user.bust_state();
			}
		}
	}

	//destroys cards
	user.clear();
	dealer.clear();
}
/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.
//4 end state: dealer bust and player doesnt, player bust and dealer doesnt, both bust, both lose
int main() {

	bool game_play = true;
	Game new_game = Game();
	
	while (game_play == true)
	{
		new_game.play();
		if (new_game.no_money() == true)
		{
			game_play = false;
		}
	}
	std::cout << "You have $0. GAME OVER! Come back when you have more money.";
	std::cout << "Bye!";
	return 0;
}