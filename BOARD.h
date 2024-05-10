#pragma once

#include <iostream>
#include <graphics.h>

using namespace std;

class Board {
	//��ʼΪ0����������Ϊ1��-1��
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

	int getR() const {
		return r;
	}

	int getL() const {
		return l;
	}

	int getG() const {
		return goal;
	}

	// �������̸ô�������״̬
	int Bod(int i, int j) {
		return bod[i][j];
	}

	// �ı����̸ô�������״̬
	void Bod(int i, int j, int pis) {
		bod[i][j] = pis;
	}

	// �ж��Ƿ�ֳ���ʤ��
	bool judge(int flag) {
		bool jdg = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				// ����ÿһ�����ж�
				int sum = 0;
				// ��
				// sum = 0;
				for (int k = 0; k < goal && j + k < l; k++)
					sum += bod[i][j + k];
				if (abs(sum) == goal) {
					jdg = true;
					goto END;
				}

				// ��
				sum = 0;
				for (int k = 0; k < goal && i + k < r; k++)
					sum += bod[i + k][j];
				if (abs(sum) == goal) {
					jdg = true;
					goto END;
				}
				// ��б
				sum = 0;
				for (int k = 0; k < goal && i + k < r && j + k < l; k++)
					sum += bod[i + k][j + k];
				if (abs(sum) == goal) {
					jdg = true;
					goto END;
				}

				// ��б
				sum = 0;
				for (int k = 0; k < goal && i + k < r && j - k >= 0; k++)
					sum += bod[i + k][j - k];
				if (abs(sum) == goal) {
					jdg = true;
					goto END;
				}
			}
		}
	END:
		if (jdg == true) {
			if (flag % 2 == 0) {
				MessageBox(NULL, _T("���2�����壩ʤ����"), _T("��Ϸ����"), MB_OK);
			}
			else {
				MessageBox(NULL, _T("���1�����壩ʤ����"), _T("��Ϸ����"), MB_OK);
			}
		}
		
		return jdg;
	}

	void init_chess(int bk) {
		initgraph(25 * l + 100, 25 * r, 1);
		// setbkcolor(RGB(0, 178, 238));
		// cleardevice();
		
		switch (bk) {
		case 1: loadimage(0, "res/����A��.jpg", 25 * l + 100, 25 * r);	break;
		case 2: loadimage(0, "res/������.jpg", 25 * l + 100, 25 * r);	break;
		case 3: loadimage(0, "res/��ͨ��è.jpg", 25 * l + 100, 25 * r); 	break;
		case 4: loadimage(0, "res/�������˽�.jpg", 25 * l + 100, 25 * r);	break;
		case 5: loadimage(0, "res/����.jpg", 25 * l + 100, 25 * r);		break;
		case 6: loadimage(0, "res/��������.jpg", 25 * l + 100, 25 * r);	break;
		case 7: loadimage(0, "res/������.jpg", 25 * l + 100, 25 * r);	break;
		case 8: loadimage(0, "res/�������.jpg", 25 * l + 100, 25 * r);	break;
		case 9: loadimage(0, "res/ɳ̲.jpg", 25 * l + 100, 25 * r);		break;
		case 10: loadimage(0, "res/ɽ������.jpg", 25 * l + 100, 25 * r);	break;
		case 11: loadimage(0, "res/Сè.jpg", 25 * l + 100, 25 * r);		break;
		case 12: loadimage(0, "res/�ǿ�.jpg", 25 * l + 100, 25 * r);		break;
		case 13: loadimage(0, "res/�̻�.jpg", 25 * l + 100, 25 * r);		break;
		case 14: loadimage(0, "res/��������.jpg", 25 * l + 100, 25 * r);	break;
		case 15: loadimage(0, "res/֩����.jpg", 25 * l + 100, 25 * r);	break;
		}
		
		// IMAGE img;
		// loadimage(&img, "res/Black.bmp");
		// putimage(0, 0, &img);

		setlinecolor(BLACK);
		for (int i = 0; i < 25 * r; i += 25) {
			line(0, i, 25 * (l - 1), i);
		}
		for (int i = 0; i < 25 * l; i += 25) {
			line(i, 0, i, 25 * (r - 1));
		}

		TCHAR s1[] = _T("���1������");
		TCHAR s2[] = _T("���2������");
		outtextxy(25 * l + 10, 6 * r, s1);
		outtextxy(25 * l + 10, 16 * r, s2);
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
					TCHAR str1[] = _T("�����Ѿ��������ˣ�������ѡ��");
					TCHAR str2[] = _T("��ʾ");
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

			if (this->judge(flag))
				break;
		}
	}
	
private:
	int r;
	int l;
	int** bod;
	int goal;
};
