#pragma once
#include<vector>
#include<iostream>

using std::pair;
using std::vector;
typedef enum{up = 0, down, left, right} diret;

class Snake{
public:
	Snake(int x, int y);
	void eat_squar(int x, int y);
	void paint_snake(vector<vector<char>>& map);
	pair<int, int>  produce_snake();
	bool move();
	bool check(pair<int, int>& t);
	void change_dir(char ch);
	bool is_eat() ;
	void set_squar(pair<int, int> t);

private:
	size_t m_snake_size;
	vector<pair<int, int>> m_snake;
	diret m_dir;
	int width, length;
	bool m_iseat;
	pair<int, int> m_squar;

};