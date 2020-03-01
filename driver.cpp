#include "Board.h"
using namespace std;

int main() {
	vector<vector<int>> board(9, vector<int>(9, 0));
	size_t board_place = 0;
	size_t column_place = 0;
	int board_num;
	char waste;
	for (size_t i = 0; i < 11; ++i) {
		if (i == 3 || i == 7) {
			for (size_t j = 0; j < 11; ++j) {
				cin >> waste;
			}
		}
		else {
			for (size_t k = 0; k < 11; ++k) {
				if (k == 3 || k == 7) cin >> waste;
				else {
					cin >> board_num;
					board[board_place][column_place] = board_num;
					column_place++;
				}
			}
			column_place = 0;
			board_place++;
		}
	}
	Board b(board);
	b.solve();
	return 0;
}