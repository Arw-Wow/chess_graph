#include "BOARD.h"

using namespace std;

int main() {
	int rr, ll, gg;
	
	cout << "���������̴�С��" << endl;
	cout << "�У�";	cin >> rr;
	cout << "�У�";	cin >> ll;
	cout << "������ʤ��������������";	cin >> gg;
	while (gg <= 0) {
		cout << "ʤ�������������Ƿ������������룺" << endl;
		cin >> gg;
	}
	cout << endl;

	Board board(rr, ll, gg);

	board.init_chess();
	board.play_chess();

}
