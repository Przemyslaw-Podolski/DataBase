
#include "pch.h"


	Product::Product() :
	m_idNumber(0), m_quantity(0), m_maxQuantity(0), m_price(0) {};

	Product::Product(std::string name, int idNumber, int Quantity, int maxQuantity, float price) :
	m_name(name), m_idNumber(idNumber), m_quantity(Quantity), m_maxQuantity(maxQuantity), m_price(price) {};

	std::string Product::getName()
	{
		return this->m_name;
	};

	int Product::getIdNumber()
	{
		return this->m_idNumber;
	};

	int Product::getQuantity()
	{
		return this->m_quantity;
	};

	int Product::getMaxQuantity()
	{
		return this->m_maxQuantity;
	};

	float Product::getPrice()
	{
		return this-> m_price;
	};

	void Product::output(std::ostream& outs)
	{
		if (&outs == &std::cout)
		{
			outs << "Name: " << this->m_name << std::endl;
			outs << "Id number: " << this->m_idNumber << std::endl;
			outs << "Quantity: " << this->m_quantity << std::endl;
			outs << "Maximum quantity: " << this->m_maxQuantity << std::endl;
			outs << "Price : " << this->m_price << std::endl;
		}
		else
		{
			outs << this->m_name << std::endl;
			outs << this->m_idNumber << std::endl;
			outs << this->m_quantity << std::endl;
			outs << this->m_maxQuantity << std::endl;
			outs << this->m_price << std::endl;
		}

	}

	void Product::input(std::istream& ins) 
	{
		if (&ins == &std::cin)
		{
			if (ins.peek() == '\n')
				ins.ignore();
			std::cout << "Name: ";
			getline(ins, this->m_name);

			std::cout << "\nEnter Id Number: ";
			ins >> this->m_idNumber;
			std::cout << "\nEnter Quantity: ";
			ins >> this->m_quantity;
			std::cout << "\nEnter Maximum quantity: ";
			ins >> this->m_maxQuantity;
			std::cout << "\nEnter Price: ";
			ins >> this->m_price;
		}
		else
		{
			if (ins.peek() == '\n')
				ins.ignore();
			getline(ins, this->m_name);

			ins >> this->m_idNumber;
			ins >> this->m_quantity;
			ins >> this->m_maxQuantity;
			ins >> this->m_price;
		}
	}

	std::ostream& operator <<(std::ostream& outs, Product& tmp)
	{
		tmp.output(outs);
		return outs;
	}

	std::istream& operator >>(std::istream& ins, Product& tmp)
	{
		tmp.input(ins);
		return ins;
	}