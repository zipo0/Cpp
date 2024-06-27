#include <iostream>
#include <ctime>
using namespace std;
struct classmate {
	int age;
	string f, s, t;
	classmate* prev, * next;
};

int DataClear(classmate** first)
{
	classmate *current;
	current = new classmate;
	current = *first;
	while (current->next != NULL)
	{
		current = current->next;
		delete current->prev;
	}
	delete current;
	*first = NULL;
	return 0;
}

int CharacterHelp(char *input)
{
	cout << int(*input)<<endl;
	return 0;
}

int InsertionSort(classmate **first)
{
	

		int age;
		string f, s, t;
		classmate* CurrentMain, * CurrentCheck, * tmp, * small;
		tmp = new classmate;
		small = new classmate;
		for (CurrentMain = *first; CurrentMain != NULL; CurrentMain = CurrentMain->next)
		{
			small = CurrentMain;
			for (CurrentCheck = CurrentMain->next; CurrentCheck != NULL; CurrentCheck = CurrentCheck->next)
			{
				if (CurrentCheck->age < small->age)
				{
					small = CurrentCheck;
				}
			}
			tmp->f = small->f;
			tmp->s = small->s;
			tmp->t = small->t;
			tmp->age = small->age;

			small->f = CurrentMain->f;
			small->s = CurrentMain->s;
			small->t = CurrentMain->t;
			small->age = CurrentMain->age;

			CurrentMain->f = tmp->f;
			CurrentMain->s = tmp->s;
			CurrentMain->t = tmp->t;
			CurrentMain->age = tmp->age;
		}
	

	return 0;
}

void BubbleSort(classmate** first)
{
	unsigned int start_time = clock();
	int age;
	string f, s, t;
	classmate* CurrentMain, * CurrentCheck, * tmp, * small;
	tmp = new classmate;
	int i = 0;
	for (CurrentMain = *first; CurrentMain != NULL; CurrentMain = CurrentMain->next)
		i++;
	for (int a=0; a<i; a++)
	{
		for (CurrentMain=*first; CurrentMain->next != NULL; CurrentMain = CurrentMain->next)
		{
			if (CurrentMain->age > CurrentMain->next->age)
			{
				f = CurrentMain->next->f;
				s = CurrentMain->next->s;
				t = CurrentMain->next->t;
				age = CurrentMain->next->age;
				CurrentMain->next->f = CurrentMain->f;
				CurrentMain->next->s = CurrentMain->s;
				CurrentMain->next->t = CurrentMain->t;
				CurrentMain->next->age = CurrentMain->age;
				CurrentMain->f = f;
				CurrentMain->s = s;
				CurrentMain->t = t;
				CurrentMain->age = age;
			}
		}
	}
	unsigned int end_time = clock();
	cout << endl << "time: " << ((float)end_time - start_time) / CLOCKS_PER_SEC << endl;
}

int auto_add(classmate** first, int NumberOfData)
{
	classmate* current;
	string f, s, t;
	int age;
	for (int i = 1; i <= NumberOfData; i++)
	{
		int max;
		max = 3 + rand() % 7;
		f.resize(max);
		s.resize(max);
		t.resize(max);
		for (int i = 0; i < max; i++)
		{
			f[i] = 'a' + rand() % ('z' - 'a');
			s[i] = 'a' + rand() % ('z' - 'a');
			t[i] = 'a' + rand() % ('z' - 'a');
		}
		age = rand()%19 + 6;
		if (*first == NULL)
		{
			*first = new classmate;
			(*first)->f = f;
			(*first)->s = s;
			(*first)->t = t;
			(*first)->age = age;
			(*first)->next = NULL;
			(*first)->prev = NULL;
		}
		else
		{
			for (current = *first; current->next != NULL; current = current->next)
				;
			current->next = new classmate;
			current->next->prev = current;
			current = current->next;
			current->f = f;
			current->s = s;
			current->t = t;
			current->age = age;
			current->next = NULL;
		}
		
	}
	return 0;
}

int add(classmate **first)
{
	classmate *current;
	string f, s, t;
	int age;
	cin >> f >> s >> t>>age;
	if (*first == NULL)
	{
		*first = new classmate;
		(*first)->f = f;
		(*first)->s = s;
		(*first)->t = t;
		(*first)->age = age;
		(*first)->next = NULL;
		(*first)->prev = NULL;
		return 0;
	}
	else
	{
		for (current = *first; current->next != NULL; current = current->next)
			;
		current->next = new classmate;
		current->next->prev = current;
		current = current->next;
		current->f = f;
		current->s = s;
		current->t = t;
		current->age = age;
		current->next = NULL;
		
		return 0;
	}
}

int counter(classmate current)
{
	unsigned int i, sum=0;
	for (i = 0; current.f[i] != 0; i++)
		;
	sum += i;
	for (i = 0; current.s[i] != 0; i++)
		;
	sum += i;
	for (i = 0; current.t[i] != 0; i++)
		;
	sum += i;
	return sum;
}

int output(classmate **first)
{
	classmate *current;
	int STRINGSIZE=30;
		cout << endl << endl << endl;
		if (*first != NULL)
		{
		cout << " | D A T A :\n";
		for (current = *first; current != NULL; current = current->next)
		{
			
			cout << " |  " << current->f << "  " << current->s << "  " << current->t; 
			int TmpSize = counter(*current);
			for (int i = 0; i < (STRINGSIZE - TmpSize); i++)
				cout << '-';
			cout << "[" << current->age << ']';
			cout << endl;
		}
			cout << " |_";
			cout << endl << endl << endl;
		}
		else
			cout << "\n\n\n         . . . . NO DATA . . . \n\n\n";
	return 0;
}

classmate*  copy(classmate** first, classmate** pfirst)
{
	classmate *current, *pcurrent=NULL;
	*pfirst= new classmate;
	pcurrent = *pfirst;
	for (current = *first; current != NULL; current = current->next)
	{
		pcurrent->age = current->age;
		pcurrent->f = current->f;
		pcurrent->s = current->s;
		pcurrent->t = current->t;

		if (current->next != NULL)
			pcurrent->next = new classmate;
		else
			pcurrent->next = NULL;
		pcurrent = pcurrent->next;
	}
	return *pfirst;
}

int TestSorts(int AmountOfRuns, int a0range, int a1range)
{
	classmate *pfirst=NULL, *dfirst=NULL;
	int AmountOfData;
	for (int i = 0; i < AmountOfRuns; i++)
	{
		AmountOfData = (rand() % a1range - a0range) + a0range;
		
		auto_add(&pfirst, AmountOfData);
		copy(&pfirst, &dfirst);
		output(&pfirst);
		cout << endl << endl;
		output(&dfirst);
	}
	return 0;
}

int menu(classmate **first, char c, char *input, int *NumberOfData)
{
	unsigned int start_time = 0;
	unsigned int end_time = 0;
	switch (c)
	{
	case '1':
		system("cls");
		add(first);
		cout << endl;
		break;
	case '2':
		system("cls");
		cout << "NumberOfData: ";
		cin >> *NumberOfData;

		auto_add(first, *NumberOfData);
		cout << "Done!\n";
		cout << endl;
		break;
	case '3':
		system("cls");
		output(first);
		cout << endl;
		break;
	case '4':
		system("cls");
		break;
	case '5':
		char inputtmp;
		system("cls");
		cout << "1. InsertionSort\n2. BubbleSort\n";
		cin >> inputtmp;
		switch (inputtmp)
		{
		case '1':
			start_time = clock();
			InsertionSort(first);
			end_time = clock();
			cout << endl << "time: " << ((float)end_time - start_time) / CLOCKS_PER_SEC << endl;
			break;
		case '2':
			BubbleSort(first);
			break;
		case '3':

			break;
		}
		
		break;
	case '6':
		int AmountOfRuns, a0range, a1range;
		cout << "Amount Of Runs : ";
		cin >> AmountOfRuns;
		cout << "Set the Range (x , y) : \n------x=";
		cin >> a0range;
		cout << "------y=";
		cin >> a1range;
		TestSorts(AmountOfRuns, a0range, a1range);
		break;
	case '0':
		system("cls");
		DataClear(first);
		cout << endl << "cleared!" << endl << endl;
		break;
	case '7':
		cin >> input;
		CharacterHelp(input);
		cout << endl;
		break;
	}
	return 0;
}

int main()
{
	int NumberOfData;
	setlocale(LC_ALL, "russian");
	classmate* current, *first = NULL, test;
	char c;
	char input;
	while (true)
	{
		cout << "1. Добавить\n2. Генерация массива\n3. Вывод\n4. Удалить\n5. Сортировать\n";
		cout << endl << "0. Clear All Data\n" << endl;
		cin >> c;
		menu(&first, c, &input, &NumberOfData);
	}
}