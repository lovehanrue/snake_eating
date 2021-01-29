#include <iostream>
#include<windows.h>
#include<conio.h>

#include "snake_menu.h"

using std::cout;
using std::endl;
using std::make_pair;
Snake_menu::Snake_menu(int x, int y) {
	vector<char>* temp;  // init the map
	for (int i = 0; i < x; i++) {
		temp = new vector<char>;
		for (int j = 0; j < y ; j++) {
			if (i == 0 || j == 0) {
				temp->push_back('*');
				continue;
			}
			if (i == x - 1 || j == y - 1) {
				temp->push_back('*');
				continue;
			}
			temp->push_back(' ');
		}
		m_map.push_back(*temp);
	}
	length = y;
	width = x;
	// init the member
	m_squar = nullptr;
	m_snake = nullptr;
	test();
}
Snake_menu::~Snake_menu() {
	for (int i = 0; i < m_map.size(); i++) delete &m_map[i];
	delete m_squar;
	delete m_snake;
}
void Snake_menu::paint_map() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			if (i == 0 || j == 0) {
				m_map[i][j] = '*';
				continue;
			}
			if (i == width - 1 || j == length - 1) {
				m_map[i][j] == '*';
				continue;
			}
			m_map[i][j] = ' ';
		}
	}
	m_map[m_squar->get_x()][m_squar->get_y()] = '#';
	m_snake->paint_snake(m_map);

}

void Snake_menu::show_map() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++)
			cout << m_map[i][j];
		cout << endl;
	}
}

void Snake_menu::test() {
	if (m_squar != nullptr) delete m_squar;
	if (m_snake != nullptr) delete m_snake;
	m_squar = new Squar(width, length);
	m_snake = new Snake(width, length);
	m_snake->set_squar(make_pair(m_squar->get_x(), m_squar->get_y()));
	while (true) {
		paint_map();   
		show_map();
		//m_squar->product_one();	
		if (_kbhit()) { //get the key    w is up, a is left, s is down, d is right
			char ch = _getch();
			m_snake->change_dir(ch);
		}

		if (!m_snake->move()){ // judge whether meet the map
			restart_game();
		}	

		if (m_snake->is_eat()) { // judge whether has ate the squart
			m_squar->product_one();
			m_snake->set_squar(make_pair(m_squar->get_x(), m_squar->get_y()));
		}
		Sleep(600);
		system("cls");
	}
}
void Snake_menu::restart_game() {
	system("cls");
	cout << "game over" << endl;
	Sleep(2000);
	cout << " 1 : restart" << endl;
	cout << " 2 : exit" << endl;
	int number;
	while (true) {
		std::cin >> number;
		if (number == 1)test();
		else if (number == 2) exit(0);
		else {
			cout << "please input corrected number" << endl;
		}

	}

}