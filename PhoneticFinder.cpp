#include "PhoneticFinder.hpp"

namespace phonetic {

	// Finds a word in text, even if the word is written with misspellings,
	// The function returns the word as it is written in the text.
	// An exception will be thrown - if there is wrong input (empty text/word) or if the word isn't 
	// in the text.
	
	std::string find(const std::string text,const std::string word) {

		if(text.length() == 0 || word.length() == 0 || word == " ")
			throw std::runtime_error("invalid input");

		std::string ans = "";
		bool flag = true;  //flag that represents if the word is matching so far
		size_t pos = 0;  //position of word 
	    
		for(size_t i = 0; i < text.length(); i++) {
			
			// if new word found
			if(!flag && (text.at(i-1) == ' ' || text.at(i-1) == '\n'))
				flag = true;

			if(flag){

				if(letterCheck(word.at(pos), text.at(i))) {
					pos++; 
					ans += text.at(i);
				} else {
					pos = 0;
					ans = "";
					flag = false;
				}
			
				// if found matching word and the text ends or the next char is ' ' or '\n'  
				// return ans else continue searching
				if(pos == word.length() && ((i+1 < text.length() 
										  && (text.at(i+1) == ' ' || text.at(i+1) == '\n'))
										  || i+1 == text.length()))
					return ans; 
				else if(pos == word.length()) {
						pos = 0;
						ans = "";
						flag = false;
				}
			}				  
		}
		throw std::runtime_error("Did not find the word " + word + " in the text");
	}

	// This boolean function helps us check if two letters are similar 
	// (according to the assigment instructions).
	// it returns true if they are similar, false else 

	bool letterCheck(char l1, char l2){

		if(l1 == 'v' || l1 == 'V' || l1 == 'w' || l1 == 'W') {
			if(l2 == 'v' || l2 == 'V' || l2 == 'w' || l2 == 'W')
				return true;
			else
				return false;
		}
		else if(l1 == 'b' || l1 == 'B' || l1 == 'f' || l1 == 'F' || l1 == 'p' || l1 == 'P') {
			if(l2 == 'b' || l2 == 'B' || l2 == 'f' || l2 == 'F' || l2 == 'p' || l2 == 'P')
				return true; 
			else 
				return false;
		}
		else if(l1 == 'g' || l1 == 'G' || l1 == 'j' || l1 == 'J') {
			if(l2 == 'g' || l2 == 'G' || l2 == 'j' || l2 == 'J') 
				return true; 
			else
				return false;
		}
		else if(l1 == 'c' || l1 == 'C' || l1 == 'k' || l1 == 'K' || l1 == 'q' || l1 == 'Q') {
			if(l2 == 'c' || l2 == 'C' || l2 == 'k' || l2 == 'K' || l2 == 'q' || l2 == 'Q') 
				return true; 
			else 
				return false;
		}
		else if(l1 == 's' || l1 == 'S' || l1 == 'z' || l1 == 'Z') {
			if(l2 == 's' || l2 == 'S' || l2 == 'z' || l2 == 'Z') 
				return true; 
			else 
				return false;
		}
		else if(l1 == 'd' || l1 == 'D' || l1 == 't' || l1 == 'T') {
			if(l2 == 'd' || l2 == 'D' || l2 == 't' || l2 == 'T')
				return true; 
			else
				return false;
		}
		else if(l1 == 'o' || l1 == 'O' || l1 == 'u' || l1 == 'U') {
			if(l2 == 'o' || l2 == 'O' || l2 == 'u' || l2 == 'U') 
				return true; 
			else
				return false;
		}
		else if(l1 == 'i' || l1 == 'I' || l1 == 'y' || l1 == 'Y') {
			if(l2 == 'i' || l2 == 'I' || l2 == 'y' || l2 == 'Y') 
				return true; 
			else 
				return false;
		}
		else if((char)tolower(l1) == (char)tolower(l2)) 
			return true;

		else
			return false;
	}	
}

			
