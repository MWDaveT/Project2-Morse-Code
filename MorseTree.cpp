#include "MorseTree.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

MorseTree::MorseTree()
{	
	tree_head = NULL;	
}

void MorseTree::add_char_to_tree(Node*& temp, char c, std::string str)
{
	if (temp == NULL)
	{
		temp = new MorseTree::Node();
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


char MorseTree::get_char_from_code(MorseTree::Node* temp, std::string str)
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

void MorseTree::print_tree(Node* temp)
{
	//MorseTree::print_tree(Node* Temp);
	std::cout << "Testing" << std::endl;

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