#include "BOARD.h"
#include "AI.h"
using namespace std;

int main() {
	int rr, ll, gg;
	int mode = 1;
	
	cout << "请输入棋盘大小：" << endl;
	cout << "行：";	cin >> rr;	rr -= 1;
	cout << "列：";	cin >> ll;	ll -= 1;
	cout << "请输入胜利所需棋子数：";	cin >> gg;
	while (gg <= 0) {
		cout << "胜利所需棋子数非法！请重新输入：" << endl;
		cin >> gg;
	}
	cout << endl;
	
	cout << "请选择背景图片（输入对应数字）：" << endl;
	cout << "1. 哆啦A梦   2.海贼王   3.卡通熊猫   4.浪漫情人节   5.落日" << endl;
	cout << "6.鸣人佐助   7.塞尔比   8.赛博朋克   9.沙滩	10.山川河流" << endl;
	cout << "11.小猫   12.璀璨星空   13.烟花    14.宇宙星球   15.蜘蛛侠" << endl;
		
	int bk;	cin >> bk;
	cout << endl;

	if (gg == 5) {
		cout << "请选择模式：" << endl;
		cout << "1：双人对战   2：人机对战" << endl;
		cin >> mode;
	}
	if (mode == 1) {
		Board board(rr, ll, gg);

		board.init_chess(bk);
		board.play_chess();
	}
	else if (mode == 2) {
		AI board(rr, ll, gg);

		board.init_chess(bk);
		board.Play_chess();
	}
}
