#include<iostream>
#include<fstream>
#include "Grammar.h"

int main()
{
	Grammar grammar;
	std::ifstream fin("intput.txt");
	if (!fin.is_open())
	{
		std::cerr << "Eroare la deschiderea fisierului!" << std::endl;
		return 1;
	}
	fin >> grammar;
	int mata;



}