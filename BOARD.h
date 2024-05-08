#pragma once

#include <iostream>
#include <graphics.h>

using namespace std;

class Board {
	//初始为0，两个棋子为1和-1；
public:
	Board(int rr, int ll, int gg) : r(rr), l(ll), goal(gg) {
		bod = new int* [r];
		for (int i = 0; i < r; i++) {
			bod[i] = new int[l];
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				bod[i][j] = 0;
			}
		}
	}

	~Board() {
		for (int i = 0; i < r; i++) {
			delete[] bod[i];
		}
		// delete[] bod;
	}

	// int getR() const {
	//	return r;
	// }

	// int getL() const {
	//	return l;
	// }

	// int getG() const {
	//	return goal;
	// }

	bool judge() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				// 对于每一点来判断
				int sum = 0;
				// 横
				// sum = 0;
				for (int k = 0; k < goal && j + k < l; k++)
					sum += bod[i][j + k];
				if (abs(sum) == goal)
					return true;

				// 竖
				sum = 0;
				for (int k = 0; k < goal && i + k < r; k++)
					sum += bod[i + k][j];
				if (abs(sum) == goal)
					return true;

				// 左斜
				sum = 0;
				for (int k = 0; k < goal && i + k < r && j + k < l; k++)
					sum += bod[i + k][j + k];
				if (abs(sum) == goal)
					return true;

				// 右斜
				sum = 0;
				for (int k = 0; k < goal && i + k < r && j - k >= 0; k++)
					sum += bod[i + k][j - k];
				if (abs(sum) == goal)
					return true;
			}
		}
		return false;
	}

	void init_chess() {
		initgraph(25 * l + 100, 25 * r);
		setbkcolor(RGB(0, 178, 238));
		cleardevice();

		setlinecolor(BLACK);
		for (int i = 0; i <= 25 * r; i += 25) {
			line(0, i, 25 * l, i);
		}
		for (int i = 0; i <= 25 * l; i += 25) {
			line(i, 0, i, 25 * r);
		}

		TCHAR s1[] = _T("玩家1：黑棋");
		TCHAR s2[] = _T("玩家2：白棋");
		outtextxy(25 * l + 10, 7 * r, s1);
		outtextxy(25 * l + 10, 18 * r, s2);
	}

	void play_chess() {
		MOUSEMSG m;
		int a = 0, b = 0;

		int flag = 0;

		while (1) {
			m = GetMouseMsg();

			for (int i = 0; i < l; i++) {
				for (int j = 0; j < r; j++) {
					if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12) {
						b = i;
						a = j;
					}
				}
			}

			if (m.uMsg == WM_LBUTTONDOWN) {
				if (bod[a][b] != 0) {
					TCHAR str1[] = _T("这里已经有棋子了，请重新选择");
					TCHAR str2[] = _T("提示");
					MessageBox(NULL, str1, str2, MB_OK);
					continue;
				}
				if (flag % 2 == 0) {
					setfillcolor(BLACK);
					solidcircle(b * 25, a * 25, 10);
					bod[a][b] = 1;
				}
				else {
					setfillcolor(WHITE);
					solidcircle(b * 25, a * 25, 10);
					bod[a][b] = -1;
				}
				flag++;
			}

			if (this->judge()) {
				TCHAR str3[] = _T("玩家1（黑棋）胜利！");
				TCHAR str4[] = _T("玩家2（白棋）胜利！");
				TCHAR str5[] = _T("游戏结束");
				if (flag % 2 == 0) {
					MessageBox(NULL, str4, str5, MB_OK);
					return;
				}
				else {
					MessageBox(NULL, str3, str5, MB_OK);
					return;
				}
			}
		}
	}
	int r;
	int l;
	int** bod;
	int goal;


};
