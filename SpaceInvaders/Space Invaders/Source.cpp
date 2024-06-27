#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
#define MAXX 25
#define MAXY 50
struct vustrel {
	int vert, horizontal;
	vustrel* next = NULL;
	vustrel* prev = NULL;
};
void putshoot(int x, int y, char** space)
{
space[x][y] = 946;
}
void putplayer(int x, int y, char** space)
{
	space[x][y] = 718;
	space[x-1][y] = 698;
	space[x][y + 1] = 718;
	space[x][y - 1] = 718;
	space[x][y - 2] = 766;
	space[x][y + 2] = 766;
}
void putenemy(int x, int y, char** space)
{
	space[x][y] = 987;
	space[x][y-1] = 991;
	space[x - 1][y - 1] = 988;
	space[x][y + 1] = 991;
	space[x - 1][y + 1] = 988;
	
}

string createstringfromspace(char** space)
{
	string pole="",sdvig="                    |";
	int i = 0, q = 0;
	while (i < MAXX)
	{
		q = 0;
		pole = pole + sdvig;
		while (q < MAXY)
		{
			pole = pole + space[i][q];
			q++;
		}
		pole = pole + "|\n";
		i++;
	}
	pole = pole + sdvig;
	for (i = 0; i < MAXY; i++)
	{
		pole = pole + '_';
	}
	pole= pole+"|\n";

	return pole;
}
void printspace(string pole)
{
	cout << pole;
}
void initspace(char** space)
{
	int i = 0, q = 0;

	while (i < MAXX)
	{
		q = 0;
		while (q < MAXY)
		{
			space[i][q] = ' ';
			q++;
		}
		i++;
	}
}

void ozhidaniepolzovatelia(int*x, int*y, vustrel** shoot, int*xshoot, int*yshoot)
{
	char vvod;
	vvod = _getch();
	if (vvod == ' ' || vvod == 'w' || vvod == 72)
	{
		if (*shoot == NULL)
		{
			*shoot = new vustrel;
			(*shoot)->vert = *x - 2;
			(*shoot)->horizontal = *y;
		}
		else
		{
			vustrel* current=*shoot;
			while (current->next != NULL)
				current = current->next;
			current->next = new vustrel;
			current->next->prev = current;
			current = current->next;
			current->vert = *x - 2;
			current->horizontal = *y;

		}
	}
	if (vvod == 'd' || vvod == 'D' || vvod == 'в' || vvod == 'В' || vvod == 77)
		*y = (*y + 2) % MAXY;
	if (vvod == 'a' || vvod == 'A' || vvod == 'ф' || vvod == 'Ф' || vvod == 75)
	{
		*y = *y - 2;
		if (*y < 0)
			*y = MAXY + *y;
	}
}
void sleep(int sleep)
{
	while (sleep > 0 && !_kbhit())
	{
		Sleep(10);
		sleep -= 10;
	}
}
void deleteshoot(vustrel** shoot)
{

		vustrel* next = (*shoot)->next;
		if(next!=NULL)
		next->prev = (*shoot)->prev;
		delete *shoot;
		if (*shoot!=NULL)
		*shoot = next;
}
void gamestart(char** space)
{
	int xkorabl = MAXX - 1, ykorabl = MAXY / 2, xshoot=0, yshoot=0;
	float  enemyx = 1, enemyy = 1, ev = 0.5;
	bool enemyisalive = true;
	vustrel *vustrel_zero = NULL, **current;
	string pole;
	while (true)
	{
		while (!_kbhit())
		{
			initspace(space);
			putplayer(xkorabl, ykorabl, space);
			current = &vustrel_zero;
			while (*current!=NULL)
			{
				putshoot((*current)->vert, (*current)->horizontal, space);
				(*current)->vert = (*current)->vert - 1;

				//если выстрел долетел до верхней границы поля, то его удаляем
				if ((*current)->vert ==-1)
				{
					 deleteshoot(current);
				}
				else//если координаты выстрела каррент (текущий выстрел) совпадают с областью, где находится противник, то убили противника
				if ((*current)->vert == enemyx && (*current)->horizontal == enemyy)
				{
					enemyisalive = false;
				}
				//конец проверки убийства противника

				// переход к следующему выстрелу и выполнение следующего шага цикла уже для него
				if(*current!=NULL)
				   current = &((*current)->next);
			}
			
			
			if (enemyisalive)
			{
				putenemy((int)enemyx, (int)enemyy, space);
				
				// изменить координаты врага в соответствии с его скоростью движения (ev)
				enemyy = enemyy + ev;

				// если достигли края поля, то меняем скорость противника на противоположную
				if (enemyy >= MAXY - 2)
					ev = -0.5;
				else
					if (enemyy <= 1)
						ev = 0.5;
			}
			if (enemyisalive == false)
			{
				enemyx = 1;
				enemyy = 1;
				enemyisalive=true;
			}
			
			pole = createstringfromspace(space);
			system("cls");
			printspace(pole);
			sleep(100);
		}
		ozhidaniepolzovatelia(&xkorabl, &ykorabl, &vustrel_zero, &xshoot, &yshoot);
		
	}
}
void main(void)
{	
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	system("mode con cols=94 lines=27");
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	int i = 0;
	char** space;
	space = new char* [MAXX];
	while (i < MAXX)
	{
		space[i] = new char[MAXY];
		i++;
	}
	gamestart(space);
}

