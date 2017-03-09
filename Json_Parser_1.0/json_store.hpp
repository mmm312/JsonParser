//
//  json_store.hpp
//  Json_Parser_1.0
//
//  Created by Muhtashim Mahi on 3/8/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#ifndef json_store_hpp
#define json_store_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class jStore
{
private:
    vector<string>dataS;     //vector for strings
    vector<string*>dataA;    //vector pointer for strings
    vector<string*>dataO;    //vector pointer for objects
    
public:
    void addDataS(string d);
    void addDataA(string a, int i);
    void addDataO(string o, int j);
    int getSizeS();
    int getSizeA();
    int getSizeO();
    
    

};


#endif /* json_store_hpp */
