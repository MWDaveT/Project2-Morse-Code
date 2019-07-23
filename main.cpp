#include "MorseTree.h"
#include<iostream>
#include<fstream>
#include<map>

int main() {

	std::string str, str1, str2;
	MorseTree MSTree;
	std::fstream MorseCode;
	MorseCode.open("morse.txt");
	while (MorseCode >> str)
	{
		MorseCode >> str1;
		MSTree.add_char_to_tree(str[0], str1);
	}
	MorseCode.close();
	//MSTree.print_tree();
	str2 = "dog";
	std::cout << MSTree.decode("--. --- .--. .... . .-. ...") << std::endl;
	std::map<char, std::string> codeMap = MSTree.build_code_map("morse.txt");
	std::cout << MSTree.encode_to_morsecode(str2, codeMap) << std::endl;
	
	return 0;
}