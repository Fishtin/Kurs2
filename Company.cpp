#include "Company.hpp"
#include "Program.hpp"

Company::Company()
{
	name = "";
	this->state = nullptr;
}

Company::Company(std::string name)
{
	this->name = name;
	this->state = nullptr;
}

Company::~Company()
{
	if (!isEmpty())
	{
		Station* current = state->getNext();
		while (current != state)
		{
			Station* temp = current;
			current = current->getNext();
			delete (temp);
		}
		delete (state);
	}
}

bool Company::isEmpty()
{
	return state == nullptr;
}

bool Company::add(int number, int mode)
{
	if (isEmpty()) {
		setState( new Station(number));
		state->setNext(state);
		state->setPrev(state);
		return true;
	}
	if (mode == 0) {
		Station* temp = new Station(number);
		Station* current = state;

		if (current->getNumber() == number)
			return false;

		temp->setNext(current);
		temp->setPrev(current->getPrev());
		current->getPrev()->setNext(temp);
		current->setPrev(temp);
		return true;
	}
	if (mode == 1) {
		Station* temp = new Station(number);
		Station* current = state->getPrev();
		if (current->getNumber() == number)
			return false;
		temp->setPrev(current);
		temp->setNext(current->getNext());
		current->getNext()->setPrev(temp);
		current->setNext(temp);
		state = temp;
		return true;
	}
	return false;
}

bool Company::del(int number, int mode)
{
	bool flag = false;;
	if (!isEmpty()) 
	{
		Station* current = state;
		do 
		{
			if (current->getNumber() == number)
			{
				current->getPrev()->setNext(current->getNext());
				current->getNext()->setPrev(current->getPrev());
				if (current == state && current->getNext() != state) state = current->getNext();
				if (current == state && current->getNext() == state) flag = true;
				delete(current);
				if (flag) 
					state = nullptr;
				return true;
			}
			if (mode == 0) 
				current = current->getNext();
			if (mode == 1) 
				current = current->getPrev();
		} while (current != state);
	}
	return false;
}

bool Company::find(int number, int mode)
{
	if (!isEmpty()) 
	{
		Station* current = state;
		do {
			if (current->getNumber() == number)
				return true;
			if (mode == 0) 
				current = current->getNext();
			if (mode == 1)
				current = current->getPrev();
		} while (current != state);
	}
	return false;
}

bool Company::addL(int number, int mode, int number1, std::string fuel)
{
	if (!isEmpty()) 
	{
		Station* current = state;
		do {
			if (current->getNumber() == number) 
				return current->add(number1, fuel);
			if (mode == 0)
				current = current->getNext();
			if (mode == 1) 
				current = current->getPrev();
		} while (current != state);
	}
	return false;
}

bool Company::delL(int number, int mode)
{
	if (!isEmpty()) 
	{
		Station* current = state;
		do {
			if (current->getNumber() == number)
				return current->del(mode);
			if (mode == 0)
				current = current->getNext();
			if (mode == 1) 
				current = current->getPrev();
		} while (current != state);
	}
	return false;
}

bool Company::findL(int number, int mode, int number1)
{
	if (!isEmpty())
	{
		Station* current = state;
		do {
			if (current->getNumber() == number)
				return current->find(number1);
			if (mode == 0) current = current->getNext();
			if (mode == 1) current = current->getPrev();
		} while (current != state);
	}
	return false;
}

void Company::show(int mode)
{
	if (!isEmpty()) {
		if (mode == 0) {
			Station* current = state;
			do {
				std::cout << "----------------------------------------------------\n";
				std::cout << "|" << std::setw(8) << current->getNumber() << std::setw(8) << "|";
				current->show();
				std::cout << "\n";
				current = current->getNext();
			} while (current != state);
		}
		if (mode == 1) {
			Station* current = state->getPrev();
			do {
				std::cout << "----------------------------------------------------\n";
				std::cout << "|" << std::setw(8) << current->getNumber() << std::setw(8) << "|";
				current->show();
				std::cout << "\n";
				current = current->getPrev();
			} while (current != state->getPrev());
		}
	}
}

void Company::setName(std::string name)
{
	this->name = name;
}

std::string Company::getString()
{
	std::string str = "";
	Station* current = state;
	if (state)
	{
		do {
			std::stringstream ss;
			ss << current->getNumber();
			str += ss.str();
			str += current->getString();
			str += '\n';
			current = current->getNext();
		} while (current != state);
	}
	return str;
}

std::string Company::getName()
{
	return name;
}

void Company::setState(Station* _state)
{ 
	this->state = _state;
}

