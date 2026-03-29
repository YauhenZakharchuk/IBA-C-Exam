#include <stdio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Struct.h"

void print(Person* employee, int size) {
	int i;
	cout << setw(5) << "ID"
		<< setw(25) << "ФИО работника"
		<< setw(15) << "Должность"
		<< setw(8) << "Часы"
		<< setw(10) << "Ставка"
		<< setw(12) << "Зарплата" << endl;
	for (i = 0; i < EMPLOYEES; i++) {
		cout << setw(5) << employee[i].id
			<< setw(25) << employee[i].name
			<< setw(15) << employee[i].job
			<< setw(8) << employee[i].hours
			<< setw(10) << employee[i].salHours
			<< setw(12) << employee[i].salary << endl;
	}
}