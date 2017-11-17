#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <set>

#include "dictionary.h"

using namespace std;

void lower(string& s);
string stripPunct(const string& s);
void checkSpelling(ifstream& in, Dictionary& dict);


int main(int argc, char* argv[]) 
{

	Dictionary d("C:\\GitHub\\Dictionary\\Dictionary\\Dictionary\\wordlist.txt");
    int k = 1;
    ifstream inf("C:\\GitHub\\Dictionary\\Dictionary\\Dictionary\\test.txt");
	checkSpelling(inf, d);
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
            char last = word[word.length() - 1];
            word = stripPunct(word);
            lower(word);
            set<string> suggestions;
            if (!dict.search(word))
            {
                cout << "line " << line_number << ": " << word + " not found " << endl;
                cout << "\tsuggestions:" << endl;
                for (int i = 0; i < 26; i++)
                {
                    char letter = 97 + i;
                    for (int j = 0; j < word.length(); j++)
                    {
                        string newWord = word;
                        newWord[j] = letter;
                        if (dict.search(newWord))
                            suggestions.insert(newWord);
                    }
                    for (int j = 0; j <= word.length(); j++)
                    {
                        string newWord = word;
                        newWord = newWord.insert(j, 1, letter);
                        if (dict.search(newWord))
                            suggestions.insert(newWord);
                    }
                }
                for (int i = 0; i < word.length(); i++)
                {
                    string newWord = word;
                    newWord.erase(i, 1);
                    if (dict.search(newWord))
                        suggestions.insert(newWord);
                }
                for (int i = 1; i < word.length(); i++)
                {
                    string newWord = word;
                    char letter = newWord[i];
                    newWord[i] = newWord[i - 1];
                    newWord[i - 1] = letter;
                    if (dict.search(newWord))
                        suggestions.insert(newWord);
                }
                for (string str : suggestions)
                    cout << "\t\t" << str << endl;
            }
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
