# ifndef COMPANY_HPP
# define COMPANY_HPP

#include "Program.hpp"
#include "Station.hpp"

class Company
{
private:
	std::string name;
	Station* state;
	
public:

	Company();
	Company(std::string name);
	~Company();

	bool isEmpty();
	bool add(int number, int mode);
	bool del(int number, int mode);
	bool find(int number, int mode);
	bool addL(int number, int mode, int number1, std::string mark);
	bool delL(int number, int mode);
	bool findL(int number, int mode, int number1);
	void show(int mode);
	void setName(std::string name);
	std::string getString();
	std::string getName();
	void setState(Station* state);
};

#endif