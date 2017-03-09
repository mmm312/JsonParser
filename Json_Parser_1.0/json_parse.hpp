//
//  json_parse.hpp
//  Json_Parser_1.0
//
//  Created by Muhtashim Mahi on 3/7/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#ifndef json_parse_hpp
#define json_parse_hpp
#include <string>
#include <stdio.h>
#include "json_store.hpp"
using namespace std;

class json:public jStore      //public inheritance of the jStore class
{
public:
    
    string skip(string s);
    void parse(string& jsonInput);
    string editB(int b,string inputB);
    string editN(int n,string inputN);
    string ifNull();
    string ifTrue();
    string ifFalse();
    string ifValue(string val);
    void vecInput(string s);
    void vecInputB(string b);
    string editA(int a,string inputA);
    int get_SizeS();
    int get_SizeA();
    int get_SizeO();
    
};

#endif /* json_parse_hpp */
