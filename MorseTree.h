#pragma once
#ifndef MORSETREE_H_
#define MORSETREE_H_


#include<iostream>
#include<fstream>
class MorseTree
{
	struct Node
	{
		char data_char;
		Node* left_ptr;
		Node* right_ptr;
		Node() {
			data_char = 0;
			left_ptr = NULL;
			right_ptr = NULL;
		}
	};
	
public:

	MorseTree();

	virtual ~MorseTree();

	void print_tree();

	void decode(std::string str);

	void add_char_to_tree(char ch, std::string str);

	char get_char_from_code(std::string str);

private:

	Node* tree_head;

	void print_tree(Node* Temp);

	char get_char_from_code(Node* Temp, std::string str);

	void add_char_to_tree(Node*& Temp, char ch, std::string str);
};


#endif // !MORSETREE_H_
