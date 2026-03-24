#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {

public:
    static const int All_Size = 52; //表示撲克牌數
    static int current_figures; //紀錄當前發到第幾張牌

    Deck(); //建構子 
    Deck(Card* p, Card* d, Card* po); //建構子
    Card* createADeck() const; //建立一個有所有撲克牌的陣列
    void sortCard(); //由小到大排列所有的牌，並且交換卡牌位置使用 swapByPointer()
    void Shuffle(); //洗牌
    void distributeForPlayer(Card*, int); //分配卡牌給玩家
    void distributeForDealer(Card*, int); //分配卡牌給電腦
    Card* getPlayer() const; //回傳 玩家的花色跟牌值
    Card* getDealer() const; //回傳 莊家的花色跟牌值
    void showOriginal(Card*); //會傳入一個 Card* 的參數，印出手上的兩張牌
    void showLater(Card*, int); //顯示手上所有的牌，int一個整數，是用來判斷總共要顯示幾張牌
    int calculatePoker(Card*, int, int); //計算加總
    int checkHaveA(Card*, int); //確認是否有A

    void swapByReference(Card&, Card&); //用參照的方式將參數兩個物件做交換
    void swapByPointer(Card*, Card*); //用指標的方式將參數兩個物件做交換

private:
    Card* player = new Card[5]; //用來存放玩家手牌的指標
    Card* dealer = new Card[5]; //用來存放莊家手牌的指標
    Card* poker; //用來存放所有卡牌的指標
};
#endif // !1
