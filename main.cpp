#include "header.h"

int main() {
	int rr, ll, gg, mode;
	print_and_set_and_get_mode(rr, ll, gg, mode);

	int bk = set_background();
	
	if (mode == 1) {
		Board board(rr, ll, gg);

		board.init_chess(bk);
		board.play_chess();
	}
	else if (mode == 2) {
		AI board(rr, ll, gg);

		board.init_chess(bk);
		board.play_chess();
	}
}
