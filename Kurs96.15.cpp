#include "Program.hpp"
#include "Company.hpp"
#include "Train.hpp"
#include "Storage.hpp"

Company* comp = NULL;
Storage file("text.txt");

int failure() {
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n' || a<0))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите: ";
	}
	return a;
}

void Add()
{
	int number, mode = 0;
	std::cout << "Введите номер Депо: ";
	number = failure();
	if (!comp->isEmpty()) {
		std::cout << "Проход по списку прямой(0)/обратный(1):";
		mode = failure();
	}
	if (comp->add(number, mode))
		std::cout << "Добавление успешно!\n";
	else
		std::cout << "Не добавлено!\n";
}
void AddL()
{
	int number, number1, mode;
	std::string mark;
	std::cout << "Введите номер Депо: ";
	number = failure();
	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	std::cout << "Введите Рег.номер : ";
	number1 = failure();
	std::cout << "Введите марку : ";
	std::cin >> mark;
	if (comp->addL(number, mode, number1, mark))
		std::cout << "Добавление успешно!\n";
	else
		std::cout << "Не добавлено!\n";
}
void Del()
{
	int number, mode;
	std::cout << "Введите номер Депо: ";
	number = failure();
	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (comp->del(number, mode))
		std::cout << "Удаление успешно!\n";
	else
		std::cout << "Не удалено!\n";
}
void DelL()
{
	int number, mode;
	std::cout << "Введите номер Депо, в которой требуется удалить Рег.номер: ";
	number = failure();
	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (comp->delL(number, mode))
		std::cout << "Удаление успешно!\n";
	else
		std::cout << "Не удалено!\n";
}
void Find()
{
	int number, mode;
	std::cout << "Введите номер Депо: ";
	number = failure();
	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (comp->find(number, mode))
		std::cout << "Депо найдена!\n";
	else
		std::cout << "Депо не найдена!";
}
void FindL()
{
	int number, mode, number1;
	std::cout << "Введите номер Депо: ";
	number = failure();
	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	std::cout << "Введите Рег.номер : ";
	number1 = failure();
	if (comp->findL(number, mode, number1))
		std::cout << "Рег.номер найдена!\n";
	else
		std::cout << "Рег.номер не найдена!\n";

}
void Show()
{
	{
		int mode;
		std::cout << "\nПроход по списку прямой(0)/обратный(1):";
		mode = failure();
		system("cls");
		std::cout << "\n----------------------------------------------------\n";
		std::cout << "|        Железная дорога '" << comp->getName() << "'";
		std::cout << "\n----------------------------------------------------";
		std::cout << "\n|     Номер     |" << "         Номер     |      Марка          ";
		std::cout << "\n|      депо     |" << "         рег       |\n";
		comp->show(mode);
		std::cout << "----------------------------------------------------\n";
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	comp = new Company();
	while (true) {
		Show();
		std::cout << "\n Выберите действие:\n";
		std::cout << " 1. Добавить Депо\n";
		std::cout << " 2. Добавить Рег.Номер\n";
		std::cout << " 3. Удалить Депо\n";
		std::cout << " 4. Удалить Рег.Номер\n";
		std::cout << " 5. Найти Депо\n";
		std::cout << " 6. Найти Рег.Номер\n";
		std::cout << " 7. Переименовать ЖД\n";
		std::cout << " 8. Удалить ЖД и создать пустую\n";
		std::cout << " 9. Загрузить ЖД из файла\n";
		std::cout << " 10. Выгрузить ЖД в файл\n";
		std::cout << " 0. Выход\n";
		n = failure();
		if (n == 1)
			Add();
		else if (n == 2)
			AddL();
		else if (n == 3)
			Del();
		else if (n == 4)
			DelL();
		else if (n == 5)
			Find();
		else if (n == 6)
			FindL();
		else if (n == 7)
		{
			std::string newName;
			std::cout << "Введите название бензиновой компании: ";
			std::cin >> newName;
			comp->setName(newName);
		}
		else if (n == 8)
		{
			delete(comp);
			comp = new Company();
		}
		else if (n == 9)
		{
			delete(comp);
			comp = new Company();
			if (file.InputData(comp)) std::cout << "Загрузка успешна!";
			else
			{
				std::cout << "Ошибка!";
				delete(comp);
				comp = new Company();
			}
		}
		else if (n == 10)
		{
			if (comp != NULL)
			{
				if (file.OutputData(comp))
					std::cout << "Выгрузка успешна!";
				else
					std::cout << "Ошибка";
			}
			else
				std::cout << "Ошибка!";
		}
		else if (n == 0)
		{
			delete(comp);
			break;
		}
	}
}
