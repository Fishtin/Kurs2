# ifndef STATION_HPP
# define STATION_HPP

#include "Program.hpp"
#include "Train.hpp"

class Station
{
private:
	int number;
	Station* prev, * next;
	Train array[10];
public:
	Station();
	Station(int number);
	~Station();
	
	Station* getPrev();
	Station* getNext();

	void setNext(Station* _next);
	void setPrev(Station* _prev);

	int getNumber();
	bool isEmpty();
	bool add(int number, std::string mark);
	bool del(int mode);
	int getFreePos();

	bool find(int number);
	void show();
	void setNumber(int number);
	std::string getString();
};

#endif