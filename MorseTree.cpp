#include "MorseTree.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

MorseTree::MorseTree()
{	
	tree_head = NULL;	
}

void MorseTree::add_char_to_tree(MCNode*& temp, char c, std::string str)
{
	if (temp == NULL)
	{
		temp = new MorseTree::MCNode();
	}
	if (str.size() == 0)
	{
		temp->data_char = c;
	}
	else
	{
		if (str[0] == '.')
			MorseTree::add_char_to_tree(temp->left_ptr, c, str.substr(1));
		else
			MorseTree::add_char_to_tree(temp->right_ptr, c, str.substr(1));
	}
}

void MorseTree::add_char_to_tree(char c, std::string str)
{
	MorseTree::add_char_to_tree(tree_head, c, str);
}

char MorseTree::get_char_from_code(std::string str)
{
	return MorseTree::get_char_from_code(tree_head, str);
}


char MorseTree::get_char_from_code(MorseTree::MCNode* temp, std::string str)
{
	if (temp->data_char != 0 && str.size() == 0)
	{	
		return temp->data_char;
	}
	else
	{
		if (str[0] == '.')
			return MorseTree::get_char_from_code(temp->left_ptr, str.substr(1));
		else
			return MorseTree::get_char_from_code(temp->right_ptr, str.substr(1));
	}
}

MorseTree::~MorseTree() {}

void MorseTree::print_tree()
{
	MorseTree::print_tree(tree_head);
}

void MorseTree::print_tree(MorseTree::MCNode* temp)
{
	if (temp != NULL)
	{
		MorseTree::print_tree(temp->left_ptr);
		std::cout << "The Char is: " << temp->data_char << std::endl;
		MorseTree::print_tree(temp->right_ptr);
	}
}

void MorseTree::decode(std::string str)
{
	std::string code_alpha;
	std::string decode_message = "";
	std::istringstream iss(str);
	while (iss >> code_alpha)
	{
		decode_message += MorseTree::get_char_from_code(code_alpha);
	}
	std::cout << decode_message << std::endl;
			
}

std::map<char, std::string> MorseTree::build_code_map(std::string filename)
{
	char letter;
	std::string code;
	std::map<char, std::string> codeMap;


	std::fstream MorseCode;
	MorseCode.open(filename);
	while (MorseCode >> letter >> code)
	{
		codeMap[letter] = code;
	}

	return codeMap;
}

std::string encode_to_morsecode(std::string str)
{
	std::map<char, std::string> codeMap;
	codeMap = MorseTree::build_code_map("morse.txt");

	
}