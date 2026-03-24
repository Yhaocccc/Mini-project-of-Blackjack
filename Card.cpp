#include "Card.h"
#include <iostream>
using namespace std;

Card::Card() {
	card = 0.0;
	suit = 0;
	rank = 0;
}

Card::Card(double Card) {
	card = Card;
	suit = (int)(Card * 10) % 10;
	rank = (int)Card;
}

void Card::setCard(double newCard) {
	card = newCard;
}
//將值存入 card

double Card::getCard() const {
	return card;
}
//回傳 card

string Card::getSuit() const {
	return Suit[suit - 1];
}
//回傳花色

string Card::getRank() const {
	return Rank[rank - 1];
}
//回傳大小

void Card::print() {
	cout << getSuit() << " " << getRank();
}
//使用 getSuit() 及 getRank() 印出資料
