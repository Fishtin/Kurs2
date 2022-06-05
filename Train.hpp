#ifndef COLUMN_HPP
#define COLUMN_HPP

#include "Program.hpp"

class Train
{

private:

	int NumR;
	std::string Mark;
	int next;

public:
	Train();
	~Train();
	
	int getNumR();


	int getnext();


	std::string getMark();


	void setNumR(int NumSR);


	void setnext(int nextS);


	void setMark(std::string MarkS);


	/*void ADD(int number, std::string mark);
	void Dele(int mode);
	~Train();

	bool        getNumberF(int number);
	int			getNumber();
	void        IGOBN();

	std::string getMark();*/
};

#endif
