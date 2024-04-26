#include "Files.h"
#include "Catcafe.h"

using namespace std;


void Files::create_data(Catcafe** arr, int* n)
{
	cout << "n=";
	cin >> *n;

	if (*n <= 0) {
		cout << "Ошибка: n меньше или равен 0";
		return;
	}
	else {
		*arr = new Catcafe[*n];
		for (int i = 0; i < *n; i++)
		{
			cout << "ID: " << i << endl;
			cin >> (*arr)[i];
		}
	}
}

void Files::write_data(Catcafe* arr, int n, const  std::string name)
{
	ofstream f(name + ".txt");
	if (!f.is_open())
	{
		cout << "Ошибка: файл не найден" << endl;
		return;
	}
	f << n << endl;
	for (int i = 0; i < n; i++)
		f << arr[i].GetName() + " " << arr[i].GetRayting() << " " << arr[i].GetPrice() << endl;
	f.close();
	cout << "База данных успешно сохранена" << endl;
}
void Files::read_file(Catcafe**  arr, int* n, const  std::string name)
{
	ifstream f(name + ".txt");
	if(!f.is_open()) 
	{
		cout << "Ошибка: файл не найден" << endl;
		return;
	}
	f >> *n;
	*arr = new Catcafe[*n];
	string* words = new string[3];
	for (int i = 0; i < *n; i++)
	{
		f >> words[0] >> words[1] >> words[2];
		(*arr)[i].SetName(words[0]);
		(*arr)[i].SetRayting(stof(words[1]));
		(*arr)[i].SetPrice(stof(words[2]));
	}
	f.close();
	cout << "База данных успешно загружена" << endl;
}
void Files::found_elem(Catcafe* arr, int n, const  int index)
{
	string key;
	Catcafe cafe;
	bool flag = false;
	cout << "Укажите имя/число, по которому вы хотите найти элемент: ";
	cin >> key;
	switch (index) {
		case 1:
			for (int i = 0; i < n; i++) {
				if ((arr)[i].GetName() == key)
				{
					cafe = arr[i];
					flag = true;
					break;
				}
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				if ((arr)[i].GetRayting() == stof(key))
				{
					cafe = arr[i];
					flag = true;
					break;
				}
			}
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				if ((arr)[i].GetPrice() == stof(key))
				{
					cafe = arr[i];
					flag = true;
					break;
				}
			}
			break;
	}
	if (flag)
		print_data(new Catcafe[1]{ cafe }, 1);
	else
		cout << "Ошибка: объект не найден" << endl;
}
void Files::print_data(Catcafe* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "ID: " << i << endl;
		cout << arr[i];
	}
}
void Files::add_elem(Catcafe** arr, int* n)
{
	int n2;
	Catcafe* old_arr = *arr;
	Catcafe* add_arr;

	cout << "Введите количество новых элементов: ";
	cin >> n2;

	*arr = new Catcafe[*n + n2];
	add_arr = new Catcafe[n2];

	for (int i = 0; i < n2; i++)
		cin >> add_arr[i];

	for (int i = 0; i < *n; i++)
		(*arr)[i] = old_arr[i];
	for (int i = 0; i < n2; i++)
		(*arr)[*n + i] = add_arr[i];

	*n = *n + n2;

	delete[] old_arr;
	delete[] add_arr;
}
void Files::delete_elem(Catcafe** arr, int* n, const int del_ind)
{
	*n=*n-1;

	Catcafe* old_arr = *arr;
	Catcafe* new_arr = new Catcafe[*n];
	for (int i = 0; i < *n; i++)
	{
		if (i >= del_ind)
			new_arr[i] = old_arr[i + 1];
		else
			new_arr[i] = old_arr[i];
	}
	*arr = new_arr;

	delete[] old_arr;
	delete[] new_arr;
}
void Files::update_elem(Catcafe** arr, int n, const  int elem_index, const int update_ind) {
	string stringField;
	switch (update_ind)
	{
	case 1:
		cout << "Введите новое имя: ";
		cin >> stringField;
		(*arr)[elem_index].SetName(stringField);
		break;
	case 2:
		cout << "Введите новый рейтинг: ";
		cin >> stringField;
		(*arr)[elem_index].SetRayting(stof(stringField));
		break;
	case 3:
		cout << "Введите новую цену за час: ";
		cin >> stringField;
		(*arr)[elem_index].SetPrice(stof(stringField));
		break;
	}
}
