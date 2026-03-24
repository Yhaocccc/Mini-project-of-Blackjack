#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>
using namespace std;

class Card {
public:
    Card();
    Card(double);
    void setCard(double); //將值存入 card
    double getCard() const; //回傳 card
    string getSuit() const; //回傳花色
    string getRank() const; //回傳大小
    void print(); //使用 getSuit() 及 getRank() 印出資料

private:
    vector<string> Suit = { "Club", "Diamond", "Heart", "Spade" };
    vector<string> Rank = { "A", "2", "3", "4", "5", "6", "7",
                          "8", "9", "10", "J", "Q", "K" };
    int suit; //花色，用數字作區分
    int rank; //大小，用數字作區分
    double card;//整張卡，包含大小及花色。以小數點做表示，整數部分為大小，小數部分為花色(ex. 7.1 代表[梅花7])
};
#endif
