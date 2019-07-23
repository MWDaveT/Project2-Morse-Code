#pragma once
#ifndef MORSETREE_H_
#define MORSETREE_H_


#include<iostream>
#include<fstream>
#include<map>


class MorseTree
{
	struct MCNode
	{
		char data_char;
		MCNode* left_ptr;
		MCNode* right_ptr;
		MCNode() {
			data_char = 0;
			left_ptr = NULL;
			right_ptr = NULL;
		}
	};
	
public:

	MorseTree();

	virtual ~MorseTree();

	void print_tree();

	std::string decode(std::string str);

	void add_char_to_tree(char ch, std::string str);

	char get_char_from_code(std::string str);

	std::string encode_to_morsecode(std::string str, std::map<char, std::string> codeMap);

	std::map<char, std::string> build_code_map(std::string);

	

private:

	MCNode* tree_head;
	std::map<char, std::string> morse_encode_map;

	void print_tree(MCNode* Temp);

	char get_char_from_code(MCNode* Temp, std::string str);

	void add_char_to_tree(MCNode*& Temp, char ch, std::string str);

	

	

};


#endif // !MORSETREE_H_
