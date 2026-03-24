#include <iostream>
#include <ctime>
#include "Deck.h"
#include "Card.h"
using namespace std;

int Deck::current_figures = 0;
//紀錄當前發到第幾張牌

Deck::Deck() {
    player = new Card[5];
    dealer = new Card[5];
    poker = createADeck();
}

Deck::Deck(Card* p, Card* d, Card* po) {
    player = p;
    dealer = d;
    poker = po;
}
// 建構子

Card* Deck::createADeck() const {
    Card* cards = new Card[All_Size];
    int index = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            cards[index] = j + (i * 0.1);
            index++;
        }
    }

    return cards;
}
//建立一個有所有撲克牌的陣列，並且回傳它 #小數點表花色、整數表大小

void Deck::sortCard() {
    for (int i = 0; i < 51; i++) {
        int min = i;
        for (int j = i + 1; j < 52; j++) {
            if (poker[j].getCard() < poker[min].getCard())
                min = j;
            for (int m = 0; m < min; m++) {
                if (poker[m].getCard() > poker[min].getCard()) {
                    swapByPointer(&poker[m], &poker[min]);
                }
            }
        }
    }
}
//由小到大排列所有的牌（提示：用 card 的小數去判斷），並且交換卡牌位置使用 swapByPointer()

void Deck::Shuffle() {
    srand(time(0));
    for (int i = 0; i < 52; ++i)
    {
        int j = rand() % 52;
        swapByReference(poker[i], poker[j]);
    }
}
//洗牌

void Deck::distributeForPlayer(Card* player, int paraPlayer) {
    player[paraPlayer] = poker[current_figures];
    current_figures++;
}
//分配卡牌給玩家

void Deck::distributeForDealer(Card* player, int paraDealer) {
    player[paraDealer] = poker[current_figures];
    current_figures++;
}
//分配卡牌給莊家

Card* Deck::getPlayer() const {

    return player;
}
//回傳 玩家的花色跟牌值

Card* Deck::getDealer() const {

    return dealer;
}
//回傳 莊家的花色跟牌值

void Deck::showOriginal(Card* person) {
    for (int i = 0; i < 2; i++) {
        person[i].print();
        cout << " ";
    }
    cout << endl;
}
//會傳入一個 Card* 的參數，印出手上的兩張牌

void Deck::showLater(Card* person, int a) {
    for (int i = 0; i < a; i++) {
        person[i].print();
        cout << " ";
    }
    cout << endl;
}
//顯示手上所有的牌，int一個整數，是用來判斷總共要顯示幾張牌

int Deck::calculatePoker(Card* player, int i, int choice) {
    string index[5];
    int total = 0;
    for (int j = 0; j < i; j++) {
        index[j] = player[j].getRank();

        if (choice == 1 && index[j] == "A")
            total += 11;
        else if (choice == 0 && index[j] == "A")
            total += 1;
        else {
            if (index[j] == "2")
                total += 2;
            else if (index[j] == "3")
                total += 3;
            else if (index[j] == "4")
                total += 4;
            else if (index[j] == "5")
                total += 5;
            else if (index[j] == "6")
                total += 6;
            else if (index[j] == "7")
                total += 7;
            else if (index[j] == "8")
                total += 8;
            else if (index[j] == "9")
                total += 9;
            else if (index[j] == "10" || index[j] == "J" || index[j] == "Q" || index[j] == "K")
                total += 10;
        }
    }
    return total;
}
//計算加總

int Deck::checkHaveA(Card* player, int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (player[i].getRank() == "A") {
            index = 1;
            break;
        }
    }

    return index;
}
//確認是否有A

void Deck::swapByReference(Card& c1, Card& c2) {
    Card tempCard = c2;
    c2 = c1;
    c1 = tempCard;
}
//用參照的方式將參數兩個物件做交換

void Deck::swapByPointer(Card* c1, Card* c2) {
    Card tempCard = *c2;
    *c2 = *c1;
    *c1 = tempCard;
}
//用指標的方式將參數兩個物件做交換
