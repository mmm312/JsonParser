//
//  json_store.cpp
//  Json_Parser_1.0
//
//  Created by Muhtashim Mahi on 3/8/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#include "json_store.hpp"


// adding elements to the vector
void jStore::addDataS(string d)
{
    dataS.push_back(d);
}
void jStore::addDataA(string a, int i)
{
    // problem adding
    dataA.push_back( new string[i] );}

void jStore::addDataO(string o,int j)
{
    dataO.push_back(new string[j]);
}

// returning the size of the vectors
int jStore::getSizeS()
{
    return dataS.size();
}
int jStore::getSizeA()
{
    return dataA.size();
}
int jStore::getSizeO()
{
    return dataO.size();
}

