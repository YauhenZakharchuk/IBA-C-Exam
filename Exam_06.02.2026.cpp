#include <stdio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Struct.h"

void print(Person* employee, int size);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person employee[EMPLOYEES];
	int choice1;
	int i, j, temp, tempID, tempHours;
	string tempName, tempJob;
	float tempSalHours, tempSalary;
	
	do {
		printf("Выберите действие: \n");
		printf("1. Ввод данных !!!первоначальное действие!!!\n");
		printf("2. Изменение данных\n");
		printf("3. Удаление данных\n");
		printf("4. Сортировка данных\n");
		printf("5. Выход\n");
		scanf_s(" %d", &choice1);
		switch (choice1) {
		case (1): {
			for (int i = 0; i < EMPLOYEES; i++) {
				cout << "Введите ФИО сотрудника № " << i + 1 << endl;
				getline(cin >> ws, employee[i].name);
				cout << "Введите должность сотрудника" << endl;
				getline(cin >> ws, employee[i].job);
				cout << "Введите его ID (целое число):" << endl;
				cin >> employee[i].id;
				cout << "Введите его часовую ставку с двумя знаками после запятой:" << endl;
				cin >> employee[i].salHours;
				cout << "Введите количество отработанных часов (целое):" << endl;
				cin >> employee[i].hours;
				employee[i].salary = employee[i].salHours * (float)employee[i].hours;
				cin.ignore(1000, '\n');
			}
			print(employee, EMPLOYEES);
			break;
		}
		case (2): {
			printf("Введите ID сотрудника для изменения данных:\n");
			scanf_s(" %d", &temp);
			for (i = 0; i < EMPLOYEES; i++) {
				if (employee[i].id == temp) {
					printf("Введите его новую часовую ставку с двумя знаками после запятой:\n");
					cin >> employee[i].salHours;
					printf("Введите количество отработанных часов (целое):\n");
					cin >> employee[i].hours;
					employee[i].salary = employee[i].salHours * (float)employee[i].hours;
					print(employee, EMPLOYEES);
				}
			}
			break;
		}
		case (3): {
			printf("Введите ID сотрудника для удаления его данных:\n");
			scanf_s(" %d", &temp);
			for (i = 0; i < EMPLOYEES; i++) {
				if (employee[i].id == temp) {
					employee[i].id = 0;
					employee[i].name = "\0";
					employee[i].job = "\0";
					employee[i].salHours = 0.00;
					employee[i].hours = 0;
					employee[i].salary = employee[i].salHours * (float)employee[i].hours;
					print(employee, EMPLOYEES);
				}
			}
			break;
		}
		case (4): {
			for (i = (EMPLOYEES - 1); i >= 0; i--) {
				//вложенный цикл проходит от нулевого элемента до последнего, находит с
				//помощью if самое "тяжелое" значение, сравнивая соседние пары элементов, и опускает
				//его в последнюю ячейку массива
				for (j = 0; j < i; j++) {
					if (employee[j].salary < employee[j + 1].salary) {

						tempID = employee[j + 1].id;
						employee[j + 1].id = employee[j].id;
						employee[j].id = tempID;

						tempHours = employee[j + 1].hours;
						employee[j + 1].hours = employee[j].hours;
						employee[j].hours = tempHours;

						tempName = employee[j + 1].name;
						employee[j + 1].name = employee[j].name;
						employee[j].name = tempName;

						tempJob = employee[j + 1].job;
						employee[j + 1].job = employee[j].job;
						employee[j].job = tempJob;

						tempSalHours = employee[j + 1].salHours;
						employee[j + 1].salHours = employee[j].salHours;
						employee[j].salHours = tempSalHours;

						tempSalary = employee[j + 1].salary;
						employee[j + 1].salary = employee[j].salary;
						employee[j].salary = tempSalary;
					}
				}
			}
			print(employee, EMPLOYEES);
			break;
		}
		case (5):exit(1);
		default:
			printf("Menu item \n%d does not exist.\n", choice1);
			printf("Try again.\n");
			break;
		}
	} while ((choice1 < 6) || (choice1 > 0));

}

