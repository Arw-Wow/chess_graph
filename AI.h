#pragma once

#include "header.h"

class Pis {
public:
	int x;
	int y;

public:
	Pis(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	// Pis() : x(0), y(0);
	Pis(const Pis & other) : x(other.x), y(other.y) {}
};

class AI : public Board {
public:
	AI(int rr, int ll, int gg) : Board(rr, ll, gg) {
		scoreMap = new int* [this->getR()];
		for (int i = 0; i < getR(); i++) {
			scoreMap[i] = new int[this->getL()];
		}
	}
	~AI() {
		for (int i = 0; i < getR(); i++)
			delete[] scoreMap[i];
	}

	// ���㵱ǰ���ֵ
	void calculate(Pis pis) {
		int blackNum = 1;
		int whiteNum = 1;
		int emptyNum = 0;


		// �ֱ�����ĸ�ά�ȣ��˸�����ķ�ֵ
		for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {
				// ÿ��ά������������ѭ���Ĵμ����ĸ�ά�ȼ��ɼ�����˸������ֵ
				// if (x == 0 && y != -1)	continue;

				// �������Ӽ���
				blackNum = 1;
				whiteNum = 1;
				emptyNum = 0;

			//�ȼ���õ�Ϊ����
				// blackNum++;

				// �����������
				for (int i = 1; i <= 4; i++) {
					int curX = pis.x + x * i;
					int curY = pis.y + y * i;

					// �ж���û�г��磬����Ļ�������ֹ����
					if (curX >= 0 && curX < getR() && curY >= 0 && curY < getL()) {
						if (Bod(curX, curY) == 1) {
							blackNum++;
						}
						else if (Bod(curX, curY) == 0) {
							emptyNum++;
							break;
						}
						else	// ��ǰλ��Ϊ����
							break;
					}
					else // ���߽�
						break;
				}

				// �����������
				for (int i = 1; i <= 4; i++) {
					int curX = pis.x - x * i;
					int curY = pis.y - y * i;

					// �ж���û�г��磬����Ļ�������ֹ����
					if (curX >= 0 && curX < getR() && curY >= 0 && curY < getL()) {
						if (Bod(curX, curY) == 1) {
							blackNum++;
						}
						else if (Bod(curX, curY) == 0) {
							emptyNum++;
							break;
						}
						else
							break;
					}
					else
						break;
				}

				// �����ά�ȷ�ֵ
				if (blackNum == 2) {
					scoreMap[pis.x][pis.y] += 10;
				}
				else if (blackNum == 3) {
					if (emptyNum == 1)
						scoreMap[pis.x][pis.y] += 30;
					else if (emptyNum == 2)
						scoreMap[pis.x][pis.y] += 40;
				}
				else if (blackNum == 4) {
					if (emptyNum == 1)
						scoreMap[pis.x][pis.y] += 60;
					else if (emptyNum == 2)
						scoreMap[pis.x][pis.y] += 200;
				}
				else if (blackNum == 5) {
					scoreMap[pis.x][pis.y] += 20000;
				}

			// �ټ���õ�Ϊ����
				// whiteNum++;
				emptyNum = 0;

				// �����������
				for (int i = 1; i <= 4; i++) {
					int curX = pis.x + x * i;
					int curY = pis.y + y * i;

					// �ж���û�г��磬����Ļ�������ֹ����
					if (curX >= 0 && curX < getR() && curY >= 0 && curY < getL()) {
						if (Bod(curX, curY) == -1) {
							whiteNum++;
						}
						else if (Bod(curX, curY) == 0) {
							emptyNum++;
							break;
						}
						else	// ��ǰλ��Ϊ����
							break;
					}
					else // ���߽�
						break;
				}

				// �����������
				for (int i = 1; i <= 4; i++) {
					int curX = pis.x - x * i;
					int curY = pis.y - y * i;

					// �ж���û�г��磬����Ļ�������ֹ����
					if (curX >= 0 && curX < getR() && curY >= 0 && curY < getL()) {
						if (Bod(curX, curY) == -1) {
							whiteNum++;
							break;
						}
						else if (Bod(curX, curY) == 0) {
							emptyNum++;
							break;
						}
						else
							break;
					}
					else
						break;
				}

				// �����ά�ȷ�ֵ
				if (whiteNum == 2) {
					scoreMap[pis.x][pis.y] += 10;
				}
				else if (whiteNum == 3) {
					if (emptyNum == 1)
						scoreMap[pis.x][pis.y] += 25;
					else if (emptyNum == 2)
						scoreMap[pis.x][pis.y] += 50;
				}
				else if (whiteNum == 4) {
					if (emptyNum == 1)
						scoreMap[pis.x][pis.y] += 55;
					else if (emptyNum == 2)
						scoreMap[pis.x][pis.y] += 10000;
				}
				else if (whiteNum == 5) {
					scoreMap[pis.x][pis.y] += 30000;
				}

			}
		}
		return;
	}

	// �������е��ֵ
	void all_calculate() {
		for (int i = 0; i < getR(); i++) {
			for (int j = 0; j < getL(); j++) {
				if (Bod(i, j) != 0)	continue;

				calculate(Pis(i, j));
			}
		}
	}

	// �ҵ�����ֵ��
	Pis find_pis_down() {
		all_calculate();

		Pis max_pis;
		int max_score = -1;
		for (int i = 0; i < getR(); i++) {
			for (int j = 0; j < getL(); j++) {
				if (Bod(i, j) != 0)	continue;

				if (scoreMap[i][j] > max_score) {
					max_pis.x = i;
					max_pis.y = j;
					max_score = scoreMap[i][j];
				}
			}
		}
		return max_pis;
	}

	void clear_map() {
		for (int i = 0; i < getR(); i++) {
			for (int j = 0; j < getL(); j++) {
				scoreMap[i][j] = 0;
			}
		}
	}

	// ����
	void AiGo() {
		clear_map();
		Pis pis = find_pis_down();

		Sleep(1100);

		setlinecolor(BLACK);
		setfillcolor(WHITE);
		solidcircle(pis.y * 25, pis.x * 25, 10);
		circle(pis.y * 25, pis.x * 25, 10);

		Bod(pis.x, pis.y, -1);//Ĭ��AIΪ����-1
	}

	bool PlayerGo() {
		MOUSEMSG m;
		
		BEGIN:
		m = GetMouseMsg();
		int a = 0, b = 0;

		for (int i = 0; i < getL(); i++) {
			for (int j = 0; j < getR(); j++) {
				if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12) {
					b = i;
					a = j;
					goto NEXT;
				}
			}
		}
		goto BEGIN;

		NEXT:
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (Bod(a, b) != 0) {
				TCHAR str1[] = _T("�����Ѿ��������ˣ�������ѡ��");
				TCHAR str2[] = _T("��ʾ");
				MessageBox(NULL, str1, str2, MB_OK);
				return false;
			}
			setlinecolor(WHITE);
			setfillcolor(BLACK);
			solidcircle(b * 25, a * 25, 10);
			circle(b * 25, a * 25, 10);
			Bod(a, b, 1);
		}
		else
			return false;

		return true;
	}

	void play_chess() {
		while (1) {
			while (!PlayerGo()) {}
			if (this->judge(1))
				break;

			AiGo();
			
			// test();
			// test2();
			
			if (this->judge(0))
				break;
		}
	}
	
	// ����÷�
	// void test() {
	//	for (int i = 0; i < getR(); i++) {
	//		for (int j = 0; j < getL(); j++) {
	//			cout << scoreMap[i][j] << '\t';
	//		}
	//		cout << endl;
	//	}
	// }

	// �������
	// void test2() {
	//	for (int i = 0; i < getR(); i++) {
	//		for (int j = 0; j < getL(); j++) {
	//			cout << Bod(i, j) << '\t';
	//		}
	//		cout << endl;
	//	}
	// }


private:
	int** scoreMap;

};