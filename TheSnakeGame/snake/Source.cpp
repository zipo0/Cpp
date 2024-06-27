
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib> 
#include <ctime>
using namespace std;
#define MAXX 50
#define MAXY 25
void printmypole(char** pole)
{

	int i, q;
	string print = "";
	for (i = 0; i < MAXY; i++)
	{
		for (q = 0; q < MAXX; q++)
		{
			print += pole[i][q];
		}
		print += "|\n";
	}
	cout << print;
	/*int i=0, b=0;
	while (i <= 19)
	{
		while (b <= 19)
		{
			cout << pole[i+b*19];
			b = b + 1; 
		}
		cout << "\n";
		i = i + 1;
	}*/
}
void init (int* x, int* y)
{
	*x = rand() % MAXX;
	while(*x%2==0)
		*x = rand() % MAXX;
	*y = rand() % MAXY;

}
void main(void) {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	char GameSpace[MAXX][MAXY], UserInput;
	string gameover = "`¶¶¶¶````¶¶¶¶```¶¶```¶¶`¶¶¶¶¶\n¶¶``````¶¶``¶¶``¶¶¶`¶¶¶`¶¶\n¶¶`¶¶¶``¶¶¶¶¶¶``¶¶`¶`¶¶`¶¶¶¶\n¶¶``¶¶``¶¶``¶¶``¶¶```¶¶`¶¶\n`¶¶¶¶```¶¶``¶¶``¶¶```¶¶`¶¶¶¶¶\n                    \n`¶¶¶¶```¶¶``¶¶``¶¶¶¶¶```¶¶¶¶¶\n¶¶``¶¶``¶¶``¶¶``¶¶``````¶¶``¶¶\n¶¶``¶¶``¶¶``¶¶``¶¶¶¶````¶¶¶¶¶\n¶¶``¶¶```¶¶¶¶```¶¶``````¶¶``¶¶\n`¶¶¶¶`````¶¶````¶¶¶¶¶```¶¶``¶¶";
	int i,b,User_x=MAXX/2,User_y=MAXY/2, FoodY, FoodX, score, deathcount=-1, drugsX=-1, drugsY=-1, goldcoinX=-1, goldcoinY=-1, silvercoinX=-1, silvercoinY=-1, DifficultyLevel=0;
	bool poisoned = false, MedicineExist=false, goldcoin = false, silvercoin = false, on = true;
	string Ranks[16] = {"НЕТ РАНГА","PROSPECT I","PROSPECT II","PROSPECT III","PROSPECT ELITE","CHALLENGER I","CHALLENGER II","CHALLENGER III","CHALLENGER ELIE","RISIG STAR","SHOOTING STAR","ALL-STAR","SUPERSTAR","CHAMPION","SUPER CHAMPION","GRAND CHAMPION"};
	string login;
	string menu;
	string print;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	srand(time(NULL));
	i = 0;
	score = 0;
	menu = "\n##     ## ######## ##    ## ##     ## \n###   ### ##       ###   ## ##     ## \n#### #### ##       ####  ## ##     ## \n## ### ## ######   ## ## ## ##     ## \n##     ## ##       ##  #### ##     ## \n##     ## ##       ##   ### ##     ## \n##     ## ######## ##    ##  #######  ";



	system("color 70");
	while (on)
	{
		cout << menu;
		cout << "MENU\n1 - создать аккаунт\n2 - уровни\n3 - играть\n ";

		UserInput = _getch();
		switch (UserInput)
		{
		case '1':
			cout << "введите свое имя : ";
			cin >> login;
			cout << "добро пожаловать " << login << " , теперь вы можете играть.\n";
			break;
		case '2':
			if (login == "")
				cout << "создайте аккаунт чтобы играть\n";
			else
			{
				cout << "выберете уровень сложности для аккаунта " << login << ": \n 1 - салага\n 2 - новичок\n 3 - любитель\n 4 - профессионал\n 5 - легенда\n";

				UserInput = _getch();
				switch (UserInput)
				{
				case '1':
					DifficultyLevel = -5;
					break;
				case '2':
					DifficultyLevel = 0;
					break;
				case '3':
					DifficultyLevel = 5;
					break;
				case '4':
					DifficultyLevel = 10;
					break;
				case '5':
					DifficultyLevel = 20;
					break;

				}
			}
			break;
		case '3':
			if (login == "")
				cout << "создайте аккаунт чтобы играть\n";
			else
			{
				while (i < MAXY)
				{
					b = 0;
					while (b < MAXX)
					{
						GameSpace[b][i] = ' ';
						b = b + 1;


					}
					i = i + 1;
				}
				init(&FoodX, &FoodY);
				while (deathcount != 0)

				{
					i = 0;
					print = "";
					while (i < MAXY)
					{
						b = 0;
						while (b < MAXX)
						{
							if (b == User_x && i == User_y)
							{
								print+= '#';
								if (User_x == FoodX && User_y == FoodY)
								{
									init(&FoodX, &FoodY);
									score = score + 1;
									if (poisoned)
										deathcount = deathcount + MAXX / 3;
									if (rand() % 100 >= 90 - DifficultyLevel && !poisoned)
									{
										deathcount = MAXX / 2;
										poisoned = true;
									}
									if (rand() % 100 >= 98)
									{
										//создаем золотую монету
										init(&goldcoinX, &goldcoinY);
										goldcoin = true;
									}
									if (rand() % 100 >= 75)

									{
										//создаем silver coin
										init(&silvercoinX, &silvercoinY);
										silvercoin = true;

									}

								}
								//тут проверка - если существует ликарство/золотая монета и мы на него наступили, то вылечились
								if (User_x == drugsX && User_y == drugsY && MedicineExist)
								{
									score = score + 10;
									poisoned = false;
									MedicineExist = false;
								}
								if (User_x == goldcoinX && User_y == goldcoinY && goldcoin)
								{

									score = score + 100;
									goldcoin = false;
								}
								if (User_x == silvercoinX && User_y == silvercoinY && silvercoin)
								{
									score = score + 50;
									silvercoin = false;
								}
							}
							else
							{
								if (b == FoodX && i == FoodY)
									print+= '@';
								else //тут вывод лекарства на экран
									if (b == drugsX && i == drugsY && MedicineExist)
										print+="!";
									else
										if (b == silvercoinX && i == silvercoinY && silvercoin)
											print += "+";
										else //тут вывод золотой монеты на экран
											if (b == goldcoinX && i == goldcoinY && goldcoin)
												print += "$";
											else
												print += GameSpace[b][i];
							}
							b = b + 1;
						}
						print += "|";
						if (i == 0)
						{
							print += " твой ранг : " ;
							print += Ranks[(score / 200) % 16];
						}
						if (i == 2)
							print += "  $ - золотая монета : +100 очков";
						if (i == 3)
							print += "  + - серебряная монета : +50 очков";
						if (i == 4)
							print += "  ! - лекарство : +здоровье & +10 очков";
						if (i == 5)
							print += "  @ - яблоко : +1 очко";
						print += "\n";
						i = i + 1;
					}
					system("cls");
					cout << print;
					for (i = 0; i < MAXX; i++)
						cout << '=';
					cout << User_x << " " << User_y << "\n";
					cout << score << " - your score \n";
					if (poisoned)

						cout << "вы были отравлены!\n" << "Ходов до смерти" << " " << deathcount-- << "\n";
					if (rand() % 1000 >= 799 + DifficultyLevel * 10 && poisoned)
					{
						//создаем лекарство
						init(&drugsX, &drugsY);
						MedicineExist = true;
					}
					UserInput = _getch();

					if (UserInput == 'd' || UserInput == 'D' || UserInput == 'в' || UserInput == 'В' || UserInput == 77)
						User_x = (User_x + 2) % MAXX;
					if (UserInput == 'w' || UserInput == 'W' || UserInput == 'ц' || UserInput == 'Ц' || UserInput == 72)
					{
						User_y = User_y - 1;
						if (User_y < 0)
							User_y = MAXY + User_y;

					}
					if (UserInput == 'a' || UserInput == 'A' || UserInput == 'ф' || UserInput == 'Ф' || UserInput == 75)
					{
						User_x = User_x - 2;
						if (User_x < 0)
							User_x = MAXX + User_x;



					}
					if (UserInput == 's' || UserInput == 'S' || UserInput == 'ы' || UserInput == 'Ы' || UserInput == 80)
						User_y = (User_y + 1) % MAXY;

//					system("cls");
				}
				while (true)
				{
					cout << gameover << '\n';
					cout << "ваши баллы : " << score << "\n";
					cout << "ваш ранг : " << Ranks[(score / 200)%16]; 
					_getch();
					system("cls");
				}
				break;
			}
		default:
			cout << "unkown operator\n";
			}
	}
}