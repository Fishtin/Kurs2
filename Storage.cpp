#include "Storage.hpp"
#include "Program.hpp"

Storage::Storage(std::string address) {
	this->address = address;
};

bool Storage::InputData(Company* comp)
{
	std::string name, fuel;
	int number, number1;
	char buffer[100];
	char* f;

	std::ifstream file(address);

	if (!file.is_open()) return false;
	file.getline(buffer, 100);
	if (buffer != " ")
	{
		name = buffer;
		comp->setName(name);
	}
	else
	{
		std::cout << "Файл пуст\n";
		return false;
	}
	while (!file.eof())
	{
		file.getline(buffer, 100);
		f = strtok(buffer, " ");
		if (f == NULL) 
			continue;
		number = atoi(f);
		comp->add(number, 0);
		f = strtok(NULL, " ");
		while (f)
		{
			number1 = atoi(f);
			f = strtok(NULL, " ");
			fuel = f;
			comp->addL(number, 0, number1, fuel);
			f = strtok(NULL, " ");
		}
	}
	file.close();
	return true;
}

bool Storage::OutputData(Company* comp)
{
	std::ofstream file(address);
	if (!file.is_open())
		return false;
	file << comp->getName() + '\n' + comp->getString();
	file.close();
	return true;
}

Storage::~Storage() {};