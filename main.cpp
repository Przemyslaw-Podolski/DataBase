#include "pch.h"

int menu();

int main()
{
	DataBase dataBase_i;
	Product product_i;
	std::string fileName;
	std::cout << "Enter the name of the file: ";
	std::getline(std::cin, fileName);
	fileName += ".txt";
	std::ifstream fin(fileName.c_str());//Conversion due to file name can only be c_str

	if (!fin.fail())
	{
		dataBase_i.load(fin);
		fin.close();
		int choice = 0;

		while (choice != 8)
		{
			choice = menu();
			switch (choice)
			{
			case 1:
			{
				std::cin >> product_i;
				dataBase_i.add(product_i);
				break;
			}
			case 2:
			{
				system("cls");
				std::string name;
				std::cout << "Enter the product name: ";
				if (std::cin.peek() == '\n') std::cin.ignore();
				std::getline(std::cin, name);
				dataBase_i.search(name);
				break;
			}
			case 3:
			{
				system("cls");
				int id;
				std::cout << "Enter ID number: ";
				std::cin >> id;
				dataBase_i.search_id(id);
				break;
			}
			case 4:
			{
				system("cls");
				std::cout << "All products in database!" << std::endl;
				dataBase_i.display_all();
				break;
			}
			case 5:
			{
				system("cls");
				std::string name;
				std::cout << "Enter the product name: ";
				if (std::cin.peek() == '\n') std::cin.ignore();
				std::getline(std::cin, name);
				dataBase_i.remove(name);
				break;
			}
			case 6:
			{
				dataBase_i.sort_name();
			}
			case 7:
			{
				dataBase_i.sort_price();
			}
			case 8:
			{
				break;
			}
			default:
			{
				system("cls");
				std::cout << "NOT A VALID INPUT" << std::endl;
				break;
			}
			}
		}

		std::ofstream fout(fileName.c_str());
		if (!fout.fail())
		{
			dataBase_i.save(fout);
		}
		else
		{
			std::cout << "File could not open!" << std::endl;
		}
		fout.close();
		std::cout << "Thank you for using DataBase." << std::endl;
	}
	else 
	{
		std::cout << "File does not exist, creating new file." << std::endl;
		std::ofstream newFile(fileName.c_str());
		newFile.close();
		main();
	}

		return 0;
}

int menu()
{
	int choice;
	std::cout << "1. Add new product." << std::endl;
	std::cout << "2. Search for product by name." << std::endl;
	std::cout << "3. Search for product by ID number." << std::endl;
	std::cout << "4. Display all current products." << std::endl;
	std::cout << "5. Remove product from database." << std::endl;
	std::cout << "6. Sort products by name." << std::endl;
	std::cout << "7. Sort products by price." << std::endl;
	std::cout << "8. Quit." << std::endl;
	std::cin >> choice;
	return choice;
}
