/**
 * @file base85.cpp
 */
#include "base85.h"
#include <cstring>
/**
* @brief Конструктор
* @param input_string - вводимая строка которая будет зашифрован/дешифрован
* @throw base85_error, если произошла ошибка.
*/
Base85::Base85(string input_string)
{
	if(input_string.empty())
		throw base85_error("String is empty");
	
	this->len = input_string.length() + 1;
	strcpy(this->str, input_string.c_str());
}
/**
* @brief Кодирование
* @throw base85_error, если произошла ошибка.
*/
void Base85::coder()
{
	string output("");
	int a = len, b = a * 8 / 6;
	if (a * 8 % 6 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 8];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++) {
		for (int k = 1; k < 9; k++) {
			buff[j] = (str[i - 1] >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	for (int l = 0; l < b; l++) {
		q[l] = 0;
		for (int i = 0; i < 6; i++) {
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += alfabet[(unsigned int)q[l]];
	}
	
	std::cout << output << endl;
}
/**
* @brief Декодирование
* @throw base85_error, если произошла ошибка.
*/
void Base85::decoder()
{
	string output("");
	int a = len, b = a * 6 / 8;
	if (a * 6 % 8 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 6];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++) {
		for (int k = 1; k < 7; k++) {
			for (int l = 0; l < 85; l++)
				if (str[i - 1] == alfabet[l])
					buff[j] = (l >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	for (int l = 0; l < b; l++) {
		q[l] = 0;
		for (int i = 0; i < 8; i++) {
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += q[l];
	}
	
	std::cout << output << endl;
}
