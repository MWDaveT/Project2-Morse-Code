#pragma once
#ifndef MORSETREE_H_
#define MORSETREE_H_


#include<iostream>
#include<fstream>
#include<map>

/** General class for Morse Code Project */
class MorseTree
{
	/** Structure for nodes of BST for Morse Code */
	struct MCNode
	{
		char data_char;
		MCNode* left_ptr;
		MCNode* right_ptr;
		/** Initialization of node for morsecode tree */
		MCNode() {
			data_char = 0;
			left_ptr = NULL;
			right_ptr = NULL;
		}
	};
	
public:
	/**Public map that is used to encode to morse code */
	std::map<char, std::string> build_code_map(std::string);
	
	/**Constructor for MorseTree */
	MorseTree();
	
	/**Destructor to prevent warnings */
	virtual ~MorseTree();
	
	/**Function to allow printing of MorseTree */
	void print_tree();

	/**Public funtion to decode morse code
	@parma take input morse string to be decopded */
	std::string decode(std::string str);
	
	/**Function to add charter to Morsecode tree
	@parma - char to be inserted into tree
	@parma - string that is morse code to determine location of char insertions
	*/
	void add_char_to_tree(char ch, std::string str);
	
	/**Function to return char from code given
	@parma - string that is morse code
	@returns the char given the morse string inputted
	*/
	char get_char_from_code(std::string str);
	
	/**Function to return the morse code given the string to encode
	@parma - string is the input string to encode
	@parma - map is the map used to convert char to morse code
	@returns the encode string
	*/
	std::string encode_to_morsecode(std::string str, std::map<char, std::string> codeMap);

	

	

private:
	/** head of morse tree */
	MCNode* tree_head;
	
	
	std::map<char, std::string> morse_encode_map;
	
	/**Private print function for tree
	@parma - MCNode which is head of tree
	keeps the head of MSTree private
	*/
	void print_tree(MCNode* Temp);

	/**Private get char function for tree
	@parma - MCNode which is head of tree
	keeps the head of MSTree private
	*/
	char get_char_from_code(MCNode* Temp, std::string str);

	/**Private add char function for tree
	@parma - MCNode which is head of tree
	keeps the head of MSTree private
	*/
	void add_char_to_tree(MCNode*& Temp, char ch, std::string str);



};


#endif // !MORSETREE_H_
