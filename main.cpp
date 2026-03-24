#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
	Deck poker; //建立一個Deck裡面要有52張牌
	Card* player = new Card[5]; //建立玩家的卡組
	Card* dealer = new Card[5]; //建立莊家的卡組

	poker.sortCard(); //52 張牌做排序（由小排到大）
	poker.Shuffle(); //洗牌

	int i = 0, j = 0;//i代表玩家的張數 j代表莊家的張數

	for (i = 0; i < 2; i++, j++) {
		poker.distributeForPlayer(player, i);
		poker.distributeForDealer(dealer, j);
	}// 輪流發牌，共發兩張

	int choice = 0; //決定所有的A 是要變成11 還是1 初始為0

	cout << "玩家手中的牌："; poker.showOriginal(player);//顯示玩家手中的牌

	if (poker.checkHaveA(player, i) == 1) {
		cout << "請問您要將手上的A 轉變為11 還是1呢？ 轉變為11 請輸入1 反之輸入0" << endl;
		cin >> choice;
	}//確認初始值的A 是要變成11 還是1

	cout << "以及你目前的總點數為：" << poker.calculatePoker(player, i, choice) << endl;
	cout << "---------------輸入任意值進行下一步---------------" << endl;
	char a;
	cin >> a;
	cout << "--------------------------------------------------" << endl;

	cout << "請問你是否需要加牌呢？" << endl << endl; cout << "需要加牌 輸入1 不需要加牌 輸入0" << endl;

	int num;//是否需要加牌的變數
	cin >> num;

	cout << "--------------------------------------------------" << endl;

	while (num == 1 || num == 0) {
		if (num == 1) {
				poker.distributeForPlayer(player, i); i++;
				cout << "玩家目前手中的牌：";
				poker.showLater(player, i);
				cout << "以及你的總點數為：" << poker.calculatePoker(player, i, choice) << endl;
				if (i == 5) {
					cout << "--------------------------------------------------" << endl;
					cout << "遊戲結束 過五關！！！";
					break;
				}//過五關的判斷
				if (poker.calculatePoker(player, i, choice) <= 21) {
					if (poker.checkHaveA(player, i) == 1) {
						cout << "請問您要將手上的A 轉變為11 還是1呢？ 轉變為11 請輸入1 反之輸入0" << endl;
						cin >> choice;
					}//如果牌堆裡面有A
					cout << "請問你是否需要繼續加牌呢？" << endl;
					cout << "--------------------------------------------------" << endl;
					cin >> num;
				}//判斷是否大於21點
				else {
					cout << "--------------------------------------------------" << endl;
					cout << "遊戲結束 太可惜啦！莊家獲勝 不要哭" << endl;
					break;
				}
				
		}

		if(num == 0) {
			cout << "莊家手中的牌："; poker.showOriginal(dealer);
			while (poker.calculatePoker(dealer, j, 1) < 17) {
				poker.distributeForDealer(dealer, j); j++;
			}//判斷莊家是否小於17點

			poker.showLater(dealer, j);
			cout << "莊家的總點數為：" << poker.calculatePoker(dealer, j, 1) << endl;

			if (poker.calculatePoker(dealer, j, 1) > 21) {
				cout << "--------------------------------------------------" << endl;
				cout << "遊戲結束 玩家獲勝！！！";
			}//莊家是否大於21點
			else {
				cout << "玩家與莊家最後的對決 準備好就輸入任意值" << endl;
				cin >> a;
				cout << "--------------------------------------------------" << endl;
				if (poker.calculatePoker(dealer, j, 1) > poker.calculatePoker(player, i, choice))
					cout << "遊戲結束 太可惜啦！莊家獲勝 不要哭";
				else if (poker.calculatePoker(dealer, j, 1) == poker.calculatePoker(player, i, choice))
					cout << "遊戲結束 雙方平手 下次加油";
				else
					cout << "遊戲結束 玩家獲勝！！！";
				cout  << endl << "--------------------------------------------------" << endl;
			}
			break;

		}
	}
	
	return 0;
}
