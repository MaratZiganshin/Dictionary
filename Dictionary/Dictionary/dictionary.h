#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>

#include  "hashset.h"
#include  "hashset.cpp"

//using namespace std;

class hash_function {
public:
    hash_function() {}

    unsigned int operator()(const std::string& s) const 
    {		
        // TODO: Complete definition
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
    // TODO: Complete definition
};

#endif
