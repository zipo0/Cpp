#include <conio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib> 
#include <ctime>
using namespace std;
void main (void)
{
	int first=1,sec=1,tmp=0,i=2,vvod;
	char c;
	SetConsoleOutputCP(1251);
	cout << "1 - узнать число по номеру Фибонааччи\n2 - узнать номер по числу Фибонааччи\n";
	c = _getch();
	switch (c)
	{
	case '1':
		cout << "введите номер числа\n";
		cin >> vvod;
		if (vvod < 3)
		{
			cout << "ответ : 1";
			return;
		}
		while (i < vvod)
		{
			 tmp = first + sec;
			//tmp = 2
			 first = sec;
			sec = tmp;
			 i++;
		}
		cout << "ответ : " << tmp;
		break;
	case '2':
		cout << "введите число\n";
		cin >> vvod;
		if (vvod <= 2)
		{
			cout << "ответ : 1";
			return;
		}
		while (tmp < vvod)
		{
			tmp = first + sec;
			//tmp = 2
			first = sec;
			sec = tmp;
			i++;
		}
		if (tmp > vvod)
			cout << "это число не является числом Фибонааччи\n";
		else
		cout << "ответ : " << i;
	}
}