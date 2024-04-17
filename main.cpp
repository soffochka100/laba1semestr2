#include"Files.h"
#include"Catcafe.h"
#include<iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main()
{
	system("chcp 1251");

	int n = 1;
	int stop = 0;
	int id;
	int field_index;
	Catcafe* arr=new Catcafe[n];
	string fileName;
	char key = ' ';
	char key2 = ' ';
	while (stop == 0) {
		cout << "Выберите действие"
				"\n1 - создать новую базу данных"
				"\n2 - сохранить текущую базу данных в файл"
				"\n3 - вывести текущую базу данных"
				"\n4 - прочитать базу данных из файла"
				"\n5 - найти элемент в текущей базе данных"
				"\n6 - добавить новые элементы в базу данных"
				"\n7 - удалить элемент из базы данных"
				"\n8 - изменить элемент по айди в текущей базе данных"
				"\nвведите любой символ для того чтобы остановить программу"
				"\nввод: ";
		cin >> key;
		switch (key) {
			case '1':
				Files::create_data(&arr,&n);
				break;
			case '2':
				cout << "Введите имя файла(без расширения): ";
				cin >> fileName;
				Files::write_data(arr, n, fileName);
				break;
			case '3':
				Files::print_data(arr,n);
				break;
			case '4':
				cout << "Введите имя файла(без расширения): ";
				cin >> fileName;
				Files::read_file(&arr, &n, fileName);
				break;
			case '5':
				cout << "Выберите поле, по которому хотите найти элемент"
						"\n1-имя"
						"\n2-рейтинг"
						"\n3-цена за час"
						"\nввод: ";
				cin >> key2;
				Files::found_elem(arr, n, atoi(&key2));
				break;
			case '6':
				Files::add_elem(&arr, &n);
				break;
			case '7':
				cout << "Введите айди элемента: ";
				cin >> id;
				Files::delete_elem(&arr, &n, id);
				break;
			case '8':
				cout << "Введите айди элемента: ";
				cin >> id;
				cout << "Введите номер поля обьекта, который вы хотите изменить"
						"\n1-имя"
						"\n2-рейтинг"
						"\n3-цена за час"
						"\nввод: ";
				cin >> field_index;
				Files::update_elem(&arr, n, id, field_index);
				break;
			default:
				stop = 1;
		}
	}
	return 0;
}
