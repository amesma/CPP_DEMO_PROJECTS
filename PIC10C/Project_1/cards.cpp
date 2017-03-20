
#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

/* 
You might or might not need these two extra libraries 

*/
std::ostream& operator<<(std::ostream& os, const Card& card);
std::ostream& operator<<(std::ostream& os, const Player& player);
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
	os << card.get_spanish_rank() << " de " << card.get_spanish_suit() << "    ("<< card.get_english_rank() << " of " << card.get_english_suit() << ")";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	std::vector <Card*>::const_iterator cards;
	const Player *point_play = &player;
	if (!(player.card_hand.empty()))
	{
		for (cards = player.card_hand.begin(); cards != player.card_hand.end(); ++cards)
		{
			if (*cards != nullptr)
				os << "\t" << *(*cards) << "\n";
		}
		if (point_play->get_total() != 0)
		{
			std::cout << std::endl;
			std::cout << point_play->get_name() << " total is " << point_play->get_total() << ".";
		}
	}
	else
	{
		os << "There are no cards.";
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
		*iter = 0;
	}
	card_hand.clear();
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

	Player *point_play = &player;

	while (!(point_play->bust()) && point_play->hit())
	{
		deal(player);
		std::cout << point_play->whose_cards() << std::endl;
		std::cout << player << std::endl;
		if (point_play->bust())
		{
			point_play->bust_state();
		}
	}

}
// Implemente the member functions of the Hand class here.
Player::Player(){
}

Player::~Player() {

}
std::string Player::whose_cards() const {
	return "";
}

std::string GameUser::whose_cards() const {
	return "Your cards: ";
}

std::string Dealer::whose_cards() const {
	return "Dealer's cards: ";
}

std::string Player::get_name() const {
	return name;
}
std::string GameUser::get_name() const {
	return name;
}
std::string Dealer::get_name() const {
	return name;
}

float GameUser::current_amount() const{
	return money;
}

bool Player::hit() {

	std::cout << "Do you want another card? (Y/N) ";
	char response = '0';
	while (response != 'y' || response != 'Y' || response != 'N' || response == 'n')
	{
		std::cin >> response;
	}
	return (response == 'y' || response == 'Y');
	//should bet and also add new card
}
bool Player::bust() const {
	return(get_total() > 7.5);
}

void Player::bust_state(){

	std::cout << "Too bad. You lost.";
	std::cout << std::endl;
}

GameUser::GameUser() {

	money = 100;
	bet = 0;
	n_game = true;
	name = "Your";

}
void GameUser::win_bet() {
	money += bet;
}
void GameUser::lose_bet() {
	money -= bet;
}
int GameUser::ret_bet() const {
	return bet;
}
GameUser::~GameUser() {

}
bool GameUser::hit(){

	char rspd;
	std::cout << "Do you want another card? (Y/N) ";
	std::cin >> rspd;
	return (rspd == 'Y' || rspd == 'y');
}

void GameUser::win() {
	win_bet();
	std::cout << "You win $" << bet << ".";
	std::cout << std::endl;
	reset(true);
	win_count++;
}
void GameUser::tie() const {
	std::cout << "Nobody wins!";
}
int GameUser::return_win() const{
	return win_count;
}

void GameUser::enter_bet(int new_bet) {
	bet = new_bet;
}

void GameUser::bust_state() {
	lose_bet();
	std::cout << "Too bad. You lost " << ret_bet() << " dollars.";
	reset(true);
	std::cout << std::endl;
}

void GameUser::reset(bool truth) {
	n_game = truth;
}

bool GameUser::new_game() const {
	return n_game;
}

Dealer::Dealer() {
	name = "Dealer's";
}
Dealer::~Dealer() {

}
bool Dealer::hit(){
	return(get_total() < 5.5);
}
void Dealer::bust_state() {
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

	GameUser *point_user = &user;

	if (point_user->new_game() == true)
	{
		int bet;
		std::cout << "You have $" << point_user->current_amount() << ".\t Enter a bet: ";
		std::cin >> bet;
		point_user->enter_bet(bet);
	}

	//deal to player and house
	deck.deal(user);
	deck.deal(dealer);


	std::cout << "Your cards: " << std::endl;
	std::cout << user << std::endl;
	deck.add_cards(user);
	//should show cards and hit, if no hit or if lose: show dealer!!! and then lose state;

	std::cout << dealer << std::endl;
	deck.add_cards(dealer);

	
	if (dealer.bust())
	{
		std::cout << std::endl;
		if (!point_user->bust()) {
			point_user->win();
		}
	}
	else
	{
		if (!point_user->bust())
		{
			if (point_user->get_total() > dealer.get_total())
			{
				point_user->win();
			}
			else if (point_user->get_total() < dealer.get_total())
			{
				point_user->bust_state();
				
			}
		}
		else {
			point_user->bust_state();
		}
	}

	//destroys cards
	point_user->clear();
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
	std::cout << std::endl;
	std::cout << "You have $0. GAME OVER! Come back when you have more money.";
	std::cout << "Bye!";
	return 0;
=======
#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

/*
You might or might not need these two extra libraries

*/
std::ostream& operator<<(std::ostream& os, const Card& card);
std::ostream& operator<<(std::ostream& os, const Player& player);
/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
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
	const Player *point_play = &player;
	if (!(player.card_hand.empty()))
	{
		for (cards = player.card_hand.begin(); cards != player.card_hand.end(); ++cards)
		{
			if (*cards != nullptr)
				os << "\t" << *(*cards) << "\n";
		}
		if (point_play->get_total() != 0)
		{
			std::cout << std::endl;
			std::cout << point_play->get_name() << " total is " << point_play->get_total() << ".";
		}
	}
	else
	{
		os << "There are no cards.";
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
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

Hand::Hand()
{
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

float Hand::get_total() const {

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
		*iter = 0;
	}
	card_hand.clear();
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

	Player *point_play = &player;

	while (!(point_play->bust()) && point_play->hit())
	{
		deal(player);
		std::cout << point_play->whose_cards() << std::endl;
		std::cout << player << std::endl;
		if (point_play->bust())
		{
			point_play->bust_state();
		}
	}

}
// Implemente the member functions of the Hand class here.
Player::Player() {
}

Player::~Player() {

}
std::string Player::whose_cards() const {
	return "";
}

std::string GameUser::whose_cards() const {
	return "Your cards: ";
}

std::string Dealer::whose_cards() const {
	return "Dealer's cards: ";
}

std::string Player::get_name() const {
	return name;
}
std::string GameUser::get_name() const {
	return name;
}
std::string Dealer::get_name() const {
	return name;
}

float GameUser::current_amount() const {
	return money;
}

bool Player::hit() {

	std::cout << "Do you want another card? (Y/N) ";
	char response = '0';
	while (response != 'y' || response != 'Y' || response != 'N' || response == 'n')
	{
		std::cin >> response;
	}
	return (response == 'y' || response == 'Y');
	//should bet and also add new card
}
bool Player::bust() const {
	return(get_total() > 7.5);
}

void Player::bust_state() {

	lose_bet();
	std::cout << "Too bad. You lost.";
	std::cout << std::endl;
}

GameUser::GameUser() {

	money = 100;
	bet = 0;
	n_game = true;
	name = "Your";

}
void GameUser::win_bet() {
	money += bet;
}
void GameUser::lose_bet() {
	money -= bet;
}
int GameUser::ret_bet() const {
	return bet;
}
GameUser::~GameUser() {

}
bool GameUser::hit() {

	char rspd;
	std::cout << "Do you want another card? (Y/N) ";
	std::cin >> rspd;
	return (rspd == 'Y' || rspd == 'y');
}

void GameUser::win() {
	win_bet();
	std::cout << "You win $" << bet << ".";
	std::cout << std::endl;
	reset(true);
	win_count++;
}
void GameUser::tie() const {
	std::cout << "Nobody wins!";
}
int GameUser::return_win() const {
	return win_count;
}

void GameUser::enter_bet(int new_bet) {
	bet = new_bet;
}

void GameUser::bust_state() {
	lose_bet();
	std::cout << "Too bad. You lost " << ret_bet() << " dollars.";
	reset(true);
	std::cout << std::endl;
}

void GameUser::reset(bool truth) {
	n_game = truth;
}

bool GameUser::new_game() const {
	return n_game;
}

Dealer::Dealer() {
	name = "Dealer's";
}
Dealer::~Dealer() {

}
bool Dealer::hit() {
	return(get_total() < 5.5);
}
void Dealer::bust_state() {
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

	GameUser *point_user = &user;

	if (point_user->new_game() == true)
	{
		int bet;
		std::cout << "You have $" << point_user->current_amount() << ".\t Enter a bet: ";
		std::cin >> bet;
		point_user->enter_bet(bet);
	}

	//deal to player and house
	deck.deal(user);
	deck.deal(dealer);


	std::cout << "Your cards: " << std::endl;
	std::cout << user << std::endl;
	deck.add_cards(user);
	//should show cards and hit, if no hit or if lose: show dealer!!! and then lose state;

	std::cout << dealer << std::endl;
	deck.add_cards(dealer);


	if (dealer.bust())
	{
		std::cout << std::endl;
		if (!point_user->bust()) {
			point_user->win();
		}
	}
	else
	{
		if (!point_user->bust())
		{
			if (point_user->get_total() > dealer.get_total())
			{
				point_user->win();
			}
			else if (point_user->get_total() < dealer.get_total())
			{
				point_user->bust_state();

			}
		}
		else {
			point_user->bust_state();
		}
	}

	//destroys cards
	point_user->clear();
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
	std::cout << std::endl;
	std::cout << "You have $0. GAME OVER! Come back when you have more money.";
	std::cout << "Bye!";
	return 0;
}