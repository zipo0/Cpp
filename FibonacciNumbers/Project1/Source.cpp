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
	cout << "1 - ������ ����� �� ������ ����������\n2 - ������ ����� �� ����� ����������\n";
	c = _getch();
	switch (c)
	{
	case '1':
		cout << "������� ����� �����\n";
		cin >> vvod;
		if (vvod < 3)
		{
			cout << "����� : 1";
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
		cout << "����� : " << tmp;
		break;
	case '2':
		cout << "������� �����\n";
		cin >> vvod;
		if (vvod <= 2)
		{
			cout << "����� : 1";
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
			cout << "��� ����� �� �������� ������ ����������\n";
		else
		cout << "����� : " << i;
	}
}