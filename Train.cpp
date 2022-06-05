#include "Train.hpp"
#include "Program.hpp"

Train::Train() 
{
	NumR= 0;
	Mark = "";
	next = -1;
}

Train::~Train()
{
}

int Train::getNumR()
{
	return NumR;
}

int Train::getnext()
{
	return next;
}

std::string Train::getMark()
{
	return Mark;
}

void Train::setNumR(int NumSR)
{
	NumR = NumSR;
}

void Train::setnext(int nextS)
{
	next = nextS;
}

void Train::setMark(std::string MarkS)
{
	Mark = MarkS;
}
/*
void Train::ADD(int _number, std::string _mark)
{
	if (number[iter] == NULL)
	{
		std::cout << "Массив переполнен";
		/*this->number[0] = number;
		this->Mark[0] = mark;
		iter++;
	}
	else
	{
		for (int i = 0; i < iter; i++)
		{
  			if (number[i] == NULL)
			{
				number[i] = _number;
				Mark[i] = _mark;
			}
		}

		/*int* _tempN = new int[iter];
		std::string* _tempF = new std::string[iter];
		for (int i = 0; i < iter-1; i++)
		{
			_tempN[i] = this->number[i];
			_tempF[i] = this->Mark[i];
		}
		for (int i = 0; i < iter-1; i++)
		{
			this->number[i] = NULL;
			this->Mark[i] = "";
		}
		delete[] this->number;
		delete[] this->Mark;

		this->number = new int[iter];
		this->Mark = new std::string[iter];
		
		for (int i = 0; i < iter - 1; i++)
		{
			this->number[i] = _tempN[i];
			this->Mark[i] = _tempF[i];
		}
		delete[] _tempN;
		delete[] _tempF;
		this->number[iter-1] = number;
		this->Mark[iter - 1] = mark;
		iter++;
	}
}
void Train::Dele(int mode)
{
	if (mode == 0) 
	{
		
		int* _tempN = new int[iter - 1];
		std::string* _tempF = new std::string[iter-1];
		for (int i = 1; i < iter - 1; i++)
		{
			_tempN[i-1] = this->number[i];
			_tempF[i-1] = this->Mark[i];
		}
		for (int i = 0; i < iter - 1; i++)
		{
			this->number[i] = NULL;
			this->Mark[i] = "";
		}

		delete[] this->number;
		delete[] this->Mark;

		iter--;
		this->number = new int[iter];
		this->Mark = new std::string[iter];

		for (int i = 0; i < iter - 1; i++)
		{
			this->number[i] = _tempN[i];
			this->Mark[i] = _tempF[i];
		}
		delete[] _tempN;
		delete[] _tempF;
	}
	else
	{
		int* _tempN = new int[iter - 1];
		std::string* _tempF = new std::string[iter - 1];
		for (int i = 0; i < iter - 2; i++)
		{
			_tempN[i] = this->number[i];
			_tempF[i] = this->Mark[i];
		}
		for (int i = 0; i < iter - 1; i++)
		{
			this->number[i] = NULL;
			this->Mark[i] = "";
		}
		delete[] this->number;
		delete[] this->Mark;

		iter--;
		this->number = new int[iter];
		this->Mark = new std::string[iter];

		for (int i = 0; i < iter - 1; i++)
		{
			this->number[i] = _tempN[i];
			this->Mark[i] = _tempF[i];
		}
		delete[] _tempN;
		delete[] _tempF;
	}
}*/


/*
bool Train::getNumberF(int number)
{
	for (int i = 0; i < iter-1; i++)
	{
		if (this->number[i] == number) 
		{
			return true;
		}
	}
	return false;
}

int Train::getNumber()
{
	if (iG == iter-1) 
	{
		iG = 0;
		if (number[iG] == NULL) 
		{
			return -1;
		}
		return ((-1)*number[iter-2]);
	}
	iG++;
	return number[iG-1];
}

void Train::IGOBN()
{
	iG = 0;
}

std::string Train::getMark()
{
	if (iGF == iter-1)
	{
		iGF = 0;
		if (Mark[iGF] == "")
		{
			return "";
		}
		return Mark[iter - 2];
	}
	iGF++;
	return Mark[iG - 1];
}
*/