#pragma once

class Squar {
public:
	Squar(int width, int lenght);
	void product_one(); // product a squar
	int get_x() const;
	int get_y() const;

private:
	int x, y;
	int m_wid, m_len;
};