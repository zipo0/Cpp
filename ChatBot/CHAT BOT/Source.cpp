#include <iostream>
#include <windows.h>
#include <limits>
#include <string>
#include <fstream>
using namespace std;
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()
bool save(string whattosave, string	wheretosave)
{
	ofstream saves(wheretosave, ios::binary | ios::app);
	saves  << whattosave << "\n";
	saves.close();
	return true;
}
string find_answer(string* bot_answer, string* human_input,int *rows, string user_input)
{
	int i;
	for (i = 0; i < *rows; i++)
	{
		if (user_input == human_input[i])
			return bot_answer[i];
    }

	cout << "я еще не знаю отвтета, как бы вы отвтетили?\n";

	getline(cin, bot_answer[i]);
		human_input[i] = user_input;
		*rows = *rows + 1;

	//сохранить базу данных обновлённую
		save(bot_answer[i],"bot_answer.txt");
		save(human_input[i], "human_input.txt");
	return "сохрaнение . . .\n\n\nПривет\n";
	
}
void initinputanswer(string* bot_answer, string* human_input,int* rows)
{
	ifstream fileanswer("bot_answer.txt"),filehuman("human_input.txt");
	bot_answer[0] = "Привет";
	human_input[0] = "привет";
	*rows=*rows+1;
	if (fileanswer.is_open() && filehuman.is_open())
	{
		cout << "читаю базу данных\nbot_answer   human_input\n";
		for (int i = 1;!(fileanswer.eof() || filehuman.eof()); i++)
		{
			fileanswer >> bot_answer[i];
			filehuman >> human_input[i];
			*rows = *rows + 1;
			cout << bot_answer[i] << "   " << human_input[i] << endl;
		}
	}
}
void main(void)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int rows = 0;
	string bot_answer[1000], human_input[1000], buffer;
	bool on = true;
	initinputanswer(bot_answer, human_input, &rows);
	cout << bot_answer[0]<<"\n";
	while (on)
	{
		if (!getline(cin, buffer))
			return;
		cout << find_answer(bot_answer, human_input, &rows, buffer)<<"\n";
		//if (!getline(cin, buffer))
		//	return;
	}
}
