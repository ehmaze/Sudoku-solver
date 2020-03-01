#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <utility>

class Board {
private:
	std::vector<std::vector<int>> board;
public:

	Board(std::vector<std::vector<int>> &board_in);
	
	bool possible(std::uint32_t x, std::uint32_t y, int n)const;
	bool check_row(std::uint32_t row, int n)const;
	bool check_col(std::uint32_t col, int n) const;
	bool check_box(std::uint32_t row, std::uint32_t col, int n)const;
	std::uint32_t get_box(std::uint32_t row, std::uint32_t col)const;
	std::pair<std::uint32_t, std::uint32_t> box_start(std::uint32_t box)const;
	void print()const;
	
	void solve();

};













#endif // !BOARD_H
