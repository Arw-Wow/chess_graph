#include "header.h"

void print_and_set_and_get_mode(int & rr, int & ll, int & gg, int & mode) {
	// wchar_t input[10];
	// char input[1000] = { 0 };
	
	// LPTSTR input;
	// InputBox(input, 7, _T("���������̴�С (��,�У�eg: 20,20)"));

	// ��inputת��Ϊ����
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
	cout << "���������̴�С��" << endl;
	cout << "�У�";	cin >> rr;	rr -= 1;
	cout << "�У�";	cin >> ll;	ll -= 1;
	cout << "������ʤ��������������";	cin >> gg;
	while (gg <= 0) {
		cout << "ʤ�������������Ƿ������������룺" << endl;
		cin >> gg;
	}
	cout << endl;

	if (gg == 5) {
		cout << "��ѡ��ģʽ��" << endl;
		cout << "1��˫�˶�ս   2���˻���ս" << endl;
		cin >> mode;
	}
}

int set_background() {
	int row = 3;	// ����
	int col = 5;	// ����
	int width = 100;	// ��ť���
	int height = 80;	// ��ť�߶�
	int rowSpace = 70;	// ��ť�м��
	int colSpace = 80;	// ��ť�м��
	int headSpace = 100;	// ͷ�����մ�С

	initgraph(col * width + (col - 1) * colSpace, row * height + (row - 1) * rowSpace + headSpace);
	// setbkcolor(RGB(192, 192, 192));	// �������óɻ�ɫ
	// cleardevice();
	loadimage(0, "res/ѡ�����.jpg", col * width + (col - 1) * colSpace, row * height + (row - 1) * rowSpace + headSpace);

	settextcolor(BLACK);
	setbkmode(TRANSPARENT);	// text�������ɫ����Ϊ͸����Ĭ�����ɫΪ����ɫ��
	outtextxy((col * width + (col - 1) * colSpace) / 3, headSpace / 3, _T("��ѡ�񱳾�ͼƬ��"));

	// Button button[3][5];
	Button** button = new Button * [3];
	for (int i = 0; i < 3; i++) {
		button[i] = new Button[5];
	}
	
	LPCTSTR bk_str[15] = {
		"����A��", "������", "��ͨ��è", "�������˽�", "����",
		"��������", "������", "�������", "ɳ̲", "ɽ������",
		"Сè", "���ǿ�", "�̻�", "��������", "֩����",
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

	// cout << "��ѡ�񱳾�ͼƬ�������Ӧ���֣���" << endl;
	// cout << "1. ����A��   2.������   3.��ͨ��è   4.�������˽�   5.����" << endl;
	// cout << "6.��������   7.������   8.�������   9.ɳ̲	10.ɽ������" << endl;
	// cout << "11.Сè   12.���ǿ�   13.�̻�    14.��������   15.֩����" << endl;

	closegraph();
	return bk;
}
