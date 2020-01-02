#include "pch.h"


DataBase::DataBase() :
	capacity(5), used(0)
{
	this->data = new Product[this->capacity];
}

DataBase::DataBase(const DataBase& other):
	capacity(other.capacity), used(other.used)
{
	data = new Product[this->capacity];
	std::copy(other.data, other.data + used, data);
}

DataBase::~DataBase()
{
	delete[] this->data;
	this->data = nullptr;
}

void DataBase::operator=(const DataBase& other)
{
	if (this == &other)
	{
		return;
	}
	delete[] data;
	this->capacity = other.capacity;
	this->used = other.used;
	this->data = new Product[this->capacity];
	std::copy(other.data, other.data + this->used, this->data);
}

void DataBase::make_bigger()
{
	Product* tmp;
	tmp = new Product[this->capacity + 5];
	std::copy(this->data, this->data + this->used, tmp);
	delete[] this->data;
	this->data = tmp;
	this->capacity += 5;

	delete[] tmp;
	tmp = nullptr;
}

void DataBase::search(std::string name)
{
	int num_found = 0;
	for (int i = 0; i < this->used; i++)
	{
		if (this->data[i].getName() == name)
		{
			std::cout << "Product found!" << std::endl;
			this->data[i].output(std::cout);
			num_found++;
		}
	}
	if (num_found == 0)
	{
		std::cout << "No product by that name!" << std::endl;
	}
}

void DataBase::search_id(int id)
{
	int num_found = 0;
	for (int i = 0; i < this->used; i++)
	{
		if (this->data[i].getIdNumber() == id)
		{
			std::cout << "Product found!" << std::endl;
			this->data[i].output(std::cout);
			num_found++;
		}
	}
	if (num_found == 0)
	{
		std::cout << "No product by that id!" << std::endl;
	}
}

void DataBase::add(const Product& new_product)
{
	if (this->used >= this->capacity-1)
	{
		this->make_bigger();
	}
	this->data[this->used] = new_product;
	this->used++;
}

void DataBase::display_all()
{
	for (int i = 0; i < this->used; i++)
	{
		this->data[i].output(std::cout);
		
	}
}


void DataBase::remove(std::string name)
{
	for (int i = 0; i < this->used; i++)
	{
		if (this->data[i].getName() == name)
		{
			this->used--;
			data[i] = data[this->used];
		}
	}
}

void DataBase::save(std::ostream& outs)
{
	this->sort_name();
	for (int i = 0; i < this->used; i++)
	{
		this->data[i].output(outs);
	}
}

void DataBase::load(std::istream& ins)
{
	Product tmp;
	while (ins >> tmp)
	{
		if (this->used >= this->capacity)
		{
			this->make_bigger();
		}
		this->data[used] = tmp;
		this->used++;
	}
}

void DataBase::sort_name()
{
	bool done = false;
	Product tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (data[i].getName() > data[i + 1].getName())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}

void DataBase::sort_price()
{
	bool done = false;
	Product tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (data[i].getPrice() > data[i + 1].getPrice())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}