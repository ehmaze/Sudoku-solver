#include "Board.h"
using namespace std;

Board::Board(vector<vector<int>> &board_in) :board(board_in) {}

bool Board::possible(uint32_t x, uint32_t y, int n) const {
	if (check_col(y, n) && check_row(x, n) && check_box(x, y, n)) return true;
	return false;
}
bool Board::check_row(std::uint32_t row, int n)const {
	for (uint32_t i = 0; i < 9; ++i) {
		if (board[row][i] == n) return false;
	}
	return true;
}


bool Board::check_col(std::uint32_t col, int n) const {
	for (uint32_t i = 0; i < 9; ++i) {
		if (board[i][col] == n) return false;
	}
	return true;
}


bool Board::check_box(std::uint32_t row, uint32_t col, int n)const {
	uint32_t row_ = box_start(get_box(row, col)).first;
	uint32_t col_ = box_start(get_box(row, col)).second;
	for (uint32_t i= row_; i < row_ + 3; ++i) {
		for (uint32_t j = col_; j < col_ + 3; ++j) {
			if (board[i][j] == n) return false;
		}
	}
	return true;
}

pair<std::uint32_t, std::uint32_t> Board::box_start(std::uint32_t box)const {
	if (box == 0) return make_pair(0, 0);
	else if (box == 1) return make_pair(0, 3);
	else if (box == 2) return make_pair(0, 6);
	else if (box == 3) return make_pair(3, 0);
	else if (box == 4) return make_pair(3, 3);
	else if (box == 5) return make_pair(3, 6);
	else if (box == 6) return make_pair(6, 0);
	else if (box == 7) return make_pair(6, 3);
	else return make_pair(6, 6);

}
uint32_t Board::get_box(uint32_t row, uint32_t col)const {
	if (row < 3) {
		if (col < 3) return 0;
		else if (col < 6) return 1;
		else return 2;
	}
	else if (row < 6) {
		if (col < 3) return 3;
		else if (col < 6) return 4;
		else return 5;
	}
	else {
		if (col < 3) return 6;
		else if (col < 6) return 7;
		else return 8;
	}
}
void Board::solve() {
	for (uint32_t x = 0; x < 9; ++x) {
		for (uint32_t y = 0; y < 9; ++y) {
			if (board[x][y] == 0) {
				for (int n = 1; n < 10; ++n) {
					if (possible(x, y, n)) {
						board[x][y] = n;
						solve();
						board[x][y] = 0;
					}
				}
				return;	
			}
			if (x == 8 && y == 8) {
				print();
				return;
			}
		}
	}
}
void Board::print() const {
	for (uint32_t i = 0; i < 9; ++i) {
		if (i == 3 || i == 6) {
			cout << "- - - | - - - | - - - \n";
		}
		for (uint32_t j = 0; j < 9; ++j) {
			if (j == 3 || j == 6) cout << "| ";
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "\n\n\n";
}