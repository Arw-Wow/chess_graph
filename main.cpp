#include "BOARD.h"
#include "AI.h"
using namespace std;

int main() {
	int rr, ll, gg;
	int mode = 1;
	
	cout << "���������̴�С��" << endl;
	cout << "�У�";	cin >> rr;	rr -= 1;
	cout << "�У�";	cin >> ll;	ll -= 1;
	cout << "������ʤ��������������";	cin >> gg;
	while (gg <= 0) {
		cout << "ʤ�������������Ƿ������������룺" << endl;
		cin >> gg;
	}
	cout << endl;
	
	cout << "��ѡ�񱳾�ͼƬ�������Ӧ���֣���" << endl;
	cout << "1. ����A��   2.������   3.��ͨ��è   4.�������˽�   5.����" << endl;
	cout << "6.��������   7.������   8.�������   9.ɳ̲	10.ɽ������" << endl;
	cout << "11.Сè   12.���ǿ�   13.�̻�    14.��������   15.֩����" << endl;
		
	int bk;	cin >> bk;
	cout << endl;

	if (gg == 5) {
		cout << "��ѡ��ģʽ��" << endl;
		cout << "1��˫�˶�ս   2���˻���ս" << endl;
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
