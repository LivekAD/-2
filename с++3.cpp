//Варіант 20. Завд: З клавіатури вводиться назва моделі маніпулятора
//мишка, час напрацювання на відмову та середній час
//експлуатації на день, а у файл виводиться назва
//моделі маніпулятора мишка, час напрацювання на
//відмову та середній час експлуатації на день та
//кількість днів життя мишки

#include <iostream>
#include <istream>
#include <locale>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string line;
	setlocale(LC_ALL, "Rus");
	int n = 256;
	char* Mos = new char[n];
	int vrem, sredn, res, k=6;
	cout << "Для записи введите 1, для чтения 2 - ";
	cin >> k;
	if (k == 2)
	{
		std::ifstream ifile("res.txt"); // окрываем файл для чтения
		if (ifile.is_open())
		{
			while (getline(ifile, line))
			{
				cout << line << endl;
			}
		}
		ifile.close();
	}
	if (k == 1)
	{
		ofstream ifile("res.txt", std::ios_base::in | std::ios_base::app);

		if (!ifile)
		{
			cout << "Файл не відкритий.\n";
			return -1;
		}

		cout << "Введите наименование - "; cin >> Mos;
		cout << "Введите время работы на отказ(нажатий) - "; cin >> vrem;
		cout << "Введите среднее врямя работы в день(нажатий) - "; cin >> sredn;

		res = vrem / sredn;

		ifile << "Наименование - " << Mos << ", количество нажатий на отказ - " << vrem << ", среднее количество нажатий в день - " << sredn << ", приблизительное количество дней работы - " << res << endl;
		ifile.close();

		cout << "У Вас мишка проработает приблизительно - " << res << " дней после покупки" << endl;

		delete[] Mos;
	}
}