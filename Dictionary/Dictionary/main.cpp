#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "dictionary.h"

using namespace std;

void lower(string& s);
string stripPunct(const string& s);
void checkSpelling(ifstream& in, Dictionary& dict);


int main(int argc, char* argv[]) 
{

	Dictionary d("C:\\GitHub\\Dictionary\\Dictionary\\Dictionary\\test.txt");
	//checkSpelling(inf, d);

	//inf.close();

    system("pause");
	return EXIT_SUCCESS;
}

void checkSpelling(ifstream& in, Dictionary& dict) 
{
	int line_number = 0;

	while (in) 
    {
		++line_number;

		string line;
		getline(in, line);

  	    stringstream ss (stringstream::in | stringstream::out);
		ss << line;

		string word;
		while (ss >> word) 
        {
            // TODO: Complete the spell check of each word

		}
	}
}

void lower(string& s) 
{
    // Ensures that a word is lowercase
	for (int i = 0; i < s.length(); ++i) 
    {
		s[i] = tolower(s[i]);
	}
}

string stripPunct(const string& s) 
{
	// Remove any single trailing
	// punctuation character from a word.  
	if (ispunct(s[s.length() - 1])) 
		return s.substr (0, s.length() - 1);
	
    return s;
}
