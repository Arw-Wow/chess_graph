#pragma once

#include "header.h"

class Button {
public:
	Button() : x1(0), y1(0), x2(0), y2(0), str("无") {}

	Button(int x1, int y1, int x2, int y2, LPCTSTR _str) : x1(x1), y1(y1), x2(x2), y2(y2), str(_str) {
		// str = new TCHAR[strlen(_str) + 1];
		// memcpy(str, _str, strlen(_str) + 1);
	}
	
	Button(const Button& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), str(other.str) {
		// str = new TCHAR[strlen(other.str) + 1];
		// memcpy(str, other.str, strlen(other.str) + 1);
	}

	// ~Button() {}

	bool checkClick(ExMessage & m) {
		if (m.message == WM_LBUTTONDOWN) {
			if (m.x > x1 && m.x < x2 && m.y > y1 && m.y < y2)
				return true;
		}
		return false;
	}
	
	void display() {
		// setlinecolor(BLUE);
		// line(x1, y1, x1, y2);
		// line(x1, y1, x2, y1);
		// line(x1, y2, x2, y2);
		// line(x2, y1, x2, y2);
		setfillcolor(RGB(0, 255, 255)); // 设置button颜色()
		fillrectangle(x1, y1, x2, y2);

		settextcolor(BLACK);
		setbkmode(TRANSPARENT); // text背景填充色设置为透明（默认填充色为背景色）
		outtextxy(x1 + (x2 - x1) / 5, y1 +  (y2 - y1) / 2.5, str);
	}


private:
	LPCTSTR str;
	int x1;
	int y1;
	int x2;
	int y2;
};
