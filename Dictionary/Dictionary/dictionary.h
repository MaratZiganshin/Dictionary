#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include  <fstream>

#include  "hashset.h"
#include  "hashset.cpp"

//using namespace std;

class hash_function {
public:
    hash_function() {}

    unsigned int operator()(const std::string& s) const 
    {		
        unsigned int hash = 0;
        unsigned int i = 0;

        for (i = 0; i < s.length();  i++)
        {
            hash = (hash * 1664525) + (unsigned char)(s[i]) + 1013904223;
        }
        return hash;
    }
};

class equality {
public:
    equality() {}
    bool  operator()(const std::string& a, const std::string& b)  const 
    {
		return  (a == b);
    }
};


class Dictionary: public HashSet<std::string, hash_function, equality>
{
public:
    Dictionary(const std::string& name)
    {
        ifstream file(name);
        if (!file)
            throw std::invalid_argument("File doesn't exist");
        while (!file.eof())
        {
            std::string temp;
            file >> temp;
            char last = temp[temp.length() - 1];
            if (!(last <= 'z' && last >= 'a' || last <= 'Z' && last >= 'A'))
                temp = temp.substr(0, temp.length() - 1);
            cout << temp << endl;
            insert(temp);
        }    
    }
};

#endif
