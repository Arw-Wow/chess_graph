#include "BOARD.h"

using namespace std;

int main() {
	int rr, ll, gg;
	
	cout << "请输入棋盘大小：" << endl;
	cout << "行：";	cin >> rr;
	cout << "列：";	cin >> ll;
	cout << "请输入胜利所需棋子数：";	cin >> gg;
	while (gg <= 0) {
		cout << "胜利所需棋子数非法！请重新输入：" << endl;
		cin >> gg;
	}
	cout << endl;

	Board board(rr, ll, gg);

	board.init_chess();
	board.play_chess();

}
