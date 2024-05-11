#include "header.h"

void print_and_set_and_get_mode(int & rr, int & ll, int & gg, int & mode) {
	// wchar_t input[10];
	// char input[1000] = { 0 };
	
	// LPTSTR input;
	// InputBox(input, 7, _T("请输入棋盘大小 (行,列，eg: 20,20)"));

	// 将input转换为数字
	// int i = 0;
	// int r = 0, l = 0;
	// while (input[i++] != ',') {
	//	r = r * 10 + input[i] - '0';
	// }
	// while (input[i++] != '\0') {
	//	l = l * 10 + input[i] - '0';
	// }

	// rr = r - 1;
	// ll = l - 1;

	mode = 1;
	cout << "请输入棋盘大小：" << endl;
	cout << "行：";	cin >> rr;	rr -= 1;
	cout << "列：";	cin >> ll;	ll -= 1;
	cout << "请输入胜利所需棋子数：";	cin >> gg;
	while (gg <= 0) {
		cout << "胜利所需棋子数非法！请重新输入：" << endl;
		cin >> gg;
	}
	cout << endl;

	if (gg == 5) {
		cout << "请选择模式：" << endl;
		cout << "1：双人对战   2：人机对战" << endl;
		cin >> mode;
	}
}

int set_background() {
	int row = 3;	// 行数
	int col = 5;	// 列数
	int width = 100;	// 按钮宽度
	int height = 80;	// 按钮高度
	int rowSpace = 70;	// 按钮行间距
	int colSpace = 80;	// 按钮列间距
	int headSpace = 100;	// 头部留空大小

	initgraph(col * width + (col - 1) * colSpace, row * height + (row - 1) * rowSpace + headSpace);
	// setbkcolor(RGB(192, 192, 192));	// 背景设置成灰色
	// cleardevice();
	loadimage(0, "res/选择界面.jpg", col * width + (col - 1) * colSpace, row * height + (row - 1) * rowSpace + headSpace);

	settextcolor(BLACK);
	setbkmode(TRANSPARENT);	// text背景填充色设置为透明（默认填充色为背景色）
	outtextxy((col * width + (col - 1) * colSpace) / 3, headSpace / 3, _T("请选择背景图片："));

	// Button button[3][5];
	Button** button = new Button * [3];
	for (int i = 0; i < 3; i++) {
		button[i] = new Button[5];
	}
	
	LPCTSTR bk_str[15] = {
		"哆啦A梦", "海贼王", "卡通熊猫", "浪漫情人节", "落日",
		"鸣人佐助", "塞尔比", "赛博朋克", "沙滩", "山川河流",
		"小猫", "璀璨星空", "烟花", "宇宙星球", "蜘蛛侠",
	};
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			button[i][j] = Button(
							j * (width + colSpace),
							headSpace + i * (colSpace + rowSpace),
							j * (width + colSpace) + width,
							headSpace + i * (height + rowSpace) + height,
							bk_str[i * col + j]);
			button[i][j].display();
		}
	}
	
	int chose_row = 0;
	int chose_col = 0;

	while (1) {
		ExMessage m;
		m = getmessage(EX_MOUSE);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (button[i][j].checkClick(m)) {
					chose_row = i;
					chose_col = j;
					goto NEXT;
				}
			}
		}
	}

	NEXT:
	int bk = chose_row * col + chose_col + 1;

	// cout << "请选择背景图片（输入对应数字）：" << endl;
	// cout << "1. 哆啦A梦   2.海贼王   3.卡通熊猫   4.浪漫情人节   5.落日" << endl;
	// cout << "6.鸣人佐助   7.塞尔比   8.赛博朋克   9.沙滩	10.山川河流" << endl;
	// cout << "11.小猫   12.璀璨星空   13.烟花    14.宇宙星球   15.蜘蛛侠" << endl;

	closegraph();
	return bk;
}
