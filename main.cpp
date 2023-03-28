/** 
* @file main.cpp
* @brief Главный модуль base85.
*/
#include "base85.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	string input_string;
	string vote;
	string exit;
	try
	{
		cout << "Input string" << endl;
		cin >> input_string;
		
		
		Base85 q(input_string);
		
		cout << "Inpute mode\n1.Code\n2.Decode\nANY.Exit" << endl;
		cin >> vote;
		
		if (vote == "1"){
			q.coder();
		}else if (vote == "2"){
			q.decoder();
		}else
			cout << "exit..." << endl;
		cin >> exit;
			
	}catch (const base85_error & e){
		std::cerr << e.what() << std::endl;
		cin >> exit;
	}
}