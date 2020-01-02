#pragma once
#include "pch.h"


class Product
{
public:
	Product();
	Product(std::string, int, int, int, float);
	std::string getName();
	int getIdNumber();
	int getQuantity();
	int getMaxQuantity();
	float getPrice();
	void output(std::ostream&);
	void input(std::istream&);

private:
	std::string m_name;
	int m_idNumber;
	int m_quantity;
	int m_maxQuantity;
	float m_price;
};


std::ostream& operator <<(std::ostream&, Product&);
std::istream& operator >>(std::istream&, Product&);

