#include "MorseTree.h"
#include<iostream>
#include<fstream>

int main() {

	std::string str, str1;
	MorseTree MSTree;
	std::fstream MorseCode;
	MorseCode.open("morse.txt");
	while (MorseCode >> str)
	{
		MorseCode >> str1;
		MSTree.add_char_to_tree(str[0], str1);
	}
	MSTree.print_tree();

	MSTree.decode("--. --- .--. .... . .-. ...");

	return 0;
}