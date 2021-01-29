#pragma once
#include <vector>
#include "squar.h"
#include "snake.h"

#define  MAP_X_INDEX_SIZE  20
#define  MAP_Y_INDEX_SIZE  80
using std::vector;

class Snake_menu {
public:
	Snake_menu(int x = MAP_X_INDEX_SIZE, int y = MAP_Y_INDEX_SIZE);
	~Snake_menu();
	void test();
	void show_map();
	void paint_map();
	void restart_game();

private:
	vector<vector<char>> m_map;
	Squar* m_squar;
	Snake* m_snake;
	int length, width;
};