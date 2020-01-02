#pragma once
#include "pch.h"

class DataBase
{
public:
	DataBase();
	~DataBase();
	DataBase(const DataBase&); //Copying constructor
	void operator=(const DataBase&);  //Copying operator
	void search(std::string); //Search by name - show output
	void search_id(int); //Search by id - show output
	void add(const Product&); //If full use make_bigger(), add product
	void display_all();
	void remove(std::string); //Remove product by name
	void save(std::ostream& outs); //Save to file
	void load(std::istream& ins); //Load from file
	void sort_name();
	void sort_price();

private:
	void make_bigger(); //Create bigger table of products
	int capacity;
	Product *data;
	int used;

};