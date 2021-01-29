#include<time.h>
#include<stdlib.h>
#include "squar.h"
Squar::Squar(int width, int length) {
	m_wid = width;
	m_len = length;
	product_one();
}
void Squar::product_one() {
	do {
		x = rand() % m_wid;
	} while (x == 0 || x == m_wid - 1);
	do {
		y = rand() % m_wid;
	} while (y == 0 || y == m_wid - 1);
}

int Squar::get_x()const {
	return this->x;
}
int Squar::get_y()const {
	return this->y;
}