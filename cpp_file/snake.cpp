#include "snake.h" 
using std::make_pair; 
Snake::Snake(int x, int y) { 
	width = x;
	length = y;
	m_snake.push_back(produce_snake());
	m_snake_size = 1;
	m_dir = right;

}

void Snake::eat_squar(int x, int y) {
// nothing
}

void Snake::paint_snake(vector<vector<char>>& map) {
	//paint the snake in map
	for (int i = 0; i < m_snake.size(); i++) {
		map[m_snake[i].first][m_snake[i].second] = '#';
	}
		map[m_snake[0].first][m_snake[0].second] = '@';

}

pair<int, int > Snake::produce_snake() {
	//product a snake by random
	int x = rand() %  width + 1;
	int y = rand() % length + 1;
	return make_pair(x, y);

}

bool Snake::move() {
	pair<int, int> t = m_snake[0];
	if (check(t)) {
		if (m_iseat) {
			//eat a squart, add the length of snake
			m_snake.insert(m_snake.begin(), m_squar);
		}
		else {
			//else move one step
			for (int i = m_snake.size() - 1; i >= 1; i --) 
				m_snake[i] = m_snake[i - 1];
			m_snake[0] = t;
		}
		return true;
	}
	return  false;
}
bool Snake::check(pair<int, int>& t) {

	switch (m_dir) {
	case up:   t.first++;	break;
	case down: t.first--;	break;
	case left: t.second--;	break;
	case right:t.second++;	break;
	}
	//std::cout << t.first << "  " << t.second << std::endl;
	if (t == m_squar) m_iseat = true;
	//check whether meet the map

	if (t.first == 0 || t.first == width - 1) return false;
	if (t.second == 0 || t.second == length - 1) return false;
	//check whether meet itself
	for (int i = 1; i < m_snake.size(); i++) {
		if (t == m_snake[i]) return false;
	}
	return true;
}

void Snake::change_dir(char ch) {
	switch (ch) {
	case'w': m_dir = down;  break;
	case'a': m_dir = left;  break;
	case's': m_dir = up;    break;
	case'd': m_dir = right; break;

	}
}

//get flag of eat
bool Snake::is_eat() { 
	bool ret = m_iseat;
	m_iseat = false;
	return ret;
}

void Snake::set_squar(pair<int, int> t) {
	m_squar = t;
}