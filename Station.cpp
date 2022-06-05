#include "Station.hpp"
#include "Program.hpp"

Station::Station()
{
	array[0].setnext(0);
	array[0].setNumR(NULL);
	array[0].setMark(NULL);
	for (int i = 1; i < 10; i++)
		array[i].setnext(-1);
}

Station::Station(int number)
{
	this->number = number;
	this->next = nullptr;
	this->prev = nullptr;
}

Station::~Station()
{
	//delete (first);
}

Station* Station::getPrev() 
{
	return prev;
}

Station* Station::getNext()
{
	return next;
}

void Station::setNext(Station* _next)
{
	this->next=_next;
}
void Station::setPrev(Station* _prev)
{
	this->prev = _prev;
}

int Station::getNumber()
{
	return number;
}

bool Station::isEmpty()
{
	if (array[0].getnext() == 0)
	{
		return true;
	}
	return false;
}

bool Station::add(int number, std::string fuel)
{
	if (getFreePos() == -999) 
	{
		return false;
	}

	if (array[0].getnext() == 0)
	{
		array[0].setnext(getFreePos());
	}
	array[getFreePos()].setNumR(number);
	array[getFreePos()].setMark(fuel);
	array[getFreePos()].setnext(0);
	return true;
}

bool Station::del(int _number)
{
	if (array[0].getnext() == 0)
	{
		return false;
	}
	/*for (int i = 0; i < 10; i++) 
	{
		if (array[i].getNumR()==_number) 
		{
			int tmp = array[0].getnext();
			int j;
			while (tmp != 0)
			{
				if (array[tmp].getNumR() == _number)
				{
					j = tmp;
					break;
				}
				tmp = array[tmp].getnext();
			}

			array[j].setnext(array[i].getnext());
			array[i].setnext(-1);
			array[i].setNumR(NULL);
			array[i].setMark(NULL);
		}

	}*/
	int tmp = array[0].getnext();
	int tmp_prev;
	int i;
	int j;
	while (tmp != 0)
	{
		if (array[tmp].getNumR() == _number)
		{
			i= tmp_prev;
			break;
		}
		tmp_prev = tmp;
		tmp = array[tmp].getnext();
	}
	j = array[i].getnext();
	array[i].setnext(array[j].getnext());
	array[j].setnext(-1);
	array[j].setNumR(NULL);
	array[j].setMark(NULL);
	/*
	if (!isEmpty())
	{
		first->Dele(mode);
		return true;
	}
	return false;*/
}

int Station::getFreePos() 
{
	for (int i = 0; i < 10; i++)
		if (array[i].getnext() == -1)
		{
			return i;
		}
	return (-999);
}

bool Station::find(int _number)
{
	int tmp = array[0].getnext();

	while (tmp != 0)
	{
		if (array[tmp].getNumR() == _number)
		{
			return true;
		}
		tmp = array[tmp].getnext();
	}

	return false;
}

void Station::show()
{
	/*int temp;
	Train* current = first;
	while (true) 
	{
		temp = current->getNumber();
		if (temp < 0)
		{
			current->getMark();
			break;
		}
		if (current != first) 
			std::cout << "|" << std::setw(16) << "|";

		std::cout << std::setw(13) << temp
			<< std::setw(8) << " " << std::setw(10) << current->getMark()<<std::endl << "|" << std::setw(16) << "|";
	}*/
	//int Current = 0;
	int tr = array[0].getnext();
	/*while (Current != 0) 
	{
		//print();
		tr = tr.getNext();
	}*/
	do
	{
		if (tr != 0)
			std::cout << "|" << std::setw(16) << "|";

		std::cout << std::setw(13) << array[tr].getNumR()
			<< std::setw(8) << " " << std::setw(10) << array[tr].getMark() << std::endl << "|" << std::setw(16) << "|";
		tr = array[tr].getnext();
	} while (tr != 0);
	/*Current = array[0].Next;
	while(Current != 0)
		print(array[Current].getInfo);
	Current = array[Current].next;*/
}

void Station::setNumber(int number)
{
	this->number = number;
}

std::string Station::getString()
{
	int temp;
	std::string str = "";
	if (!isEmpty())
	{
		int current =array[0].getnext();
		do
		{
			if (current==0)
			{
				break;
			}
			std::stringstream ss;
			temp = array[current].getNumR();
			str += " ";
			ss << temp;
			str += ss.str();
			str += " ";
			str += array[current].getMark();
			current = array[current].getnext();
		}while (true);
	}
	return str;
}