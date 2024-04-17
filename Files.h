#include"Catcafe.h"
#include<string>
#include<iostream>
#include<fstream>
#include<string>
#pragma once

class Files
{
public:
	static void create_data(Catcafe** arr, int* n);
	static void write_data(Catcafe* arr, int n, const  std::string name);
	static void read_file(Catcafe** arr, int* n, const  std::string name);
	static void found_elem(Catcafe* arr, int n, const  int found_index);
	static void print_data(Catcafe* arr,int n);
	static void add_elem(Catcafe** arr, int* n);
	static void delete_elem(Catcafe** arr, int* n, const int del_ind);
	static void update_elem(Catcafe** arr, int n, const int found_index, const int update_ind);
};

