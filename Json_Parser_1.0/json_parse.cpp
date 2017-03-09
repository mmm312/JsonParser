//
//  json_parse.cpp
//  Json_Parser_1.0
//
//  Created by Muhtashim Mahi on 3/7/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#include "json_parse.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cctype>
#include "json_store.hpp"

string json::skip(string s)       //Skip any empty spaces
{
    remove(s.begin(),s.end(),' ');
    return s;
}

//Begin of parse function
void json::parse(string& jsonInput)
{
    string tempJ;
    tempJ=skip(jsonInput);
    
    tempJ.erase(0);     //erase the initial '{'
    tempJ.erase(-1);    //erase the last '}'
    
    for (int i=0;i< tempJ.size();i++)   //loop to go through entire string
    {
        switch(tempJ[i])           // switch statement parses the string as the file is read
        {
            case '{':                  // for objects
            {
                
                string tempB;          // create a temporary string
                tempB=editB(i, tempJ); //store edited string to tempB
                vecInputB(tempB);          //take string and store as object
            
            }break;
            case 'n':  // for null
            {
                string tempN;      // create a temporary string
                tempN=ifNull();    //store edited string to tempN
                addDataS(tempN);   //add the string to the vector
            }break;
            case 't':   //for true
            {
                string tempT;      // create a temporary string
                tempT=ifTrue();    //store edited string to tempT
                addDataS(tempT);   //add the string to the vector
            }break;
            case 'f': // for false
            {
                string tempF;      // create a temporary string
                tempF=ifFalse();   //store edited string to tempF
                addDataS(tempF);    //add the string to the vector
            }break;
            case ':':   //for value
            {
                string tempV;      // create a temporary string
                tempV=editN(i,tempJ);//store edited string to tempV
                addDataS(tempV);    //add the string to the vector
            }break;
            case'[':       //for arrays
            {
                string tempA;    // create a temporary string
                tempA=editA(i, jsonInput);   //store edited string to tempA
                vecInput(tempA);  //take string and store as array
            }
        }
    }
    
}

string editA(int a,string inputA)     //search through string to find ']' and return the string
{
    string substringA;
    while(inputA[a+1]==']')
    {
        substringA+=inputA[a+1];
        a++;
    }
    return substringA;
}



string json::editB(int b,string inputB)   //search through string to find '}' and return string
{
    string substringB;
    while(inputB[b]=='}')
    {
        substringB+=inputB[b];
        b++;
    }
    
    return skip(substringB);    // skip any spaces
}



string json::ifNull()     // if n return as null
{return "null";}


string json::ifTrue()    // if t return as true
{return "true";}


string json::ifFalse()    // if f return as false
{return "false";}


string json::ifValue(string val)    //if value return as value
{
    return val;
}



void json::vecInput(string s)        // edit the array and then add to the array vector
{
    string temp;
    int count;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',' || (i+1)==s.size())
        {
            temp.erase();
            continue;
        }else
        {
            temp+=s[i];
            count++;
            continue;
        }
        
    }
    addDataA(temp,count);    // call the push back to add to vector
    
}

void json:: vecInputB(string b)
{
    string tempb;
    int countb;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]==',' || (i+1)==b.size())
        {
            tempb.erase();
            continue;
        }else
        {
            tempb+=b[i];
            countb++;
            continue;
        }
        
    }
    addDataA(tempb,countb);
}

int json::get_SizeS()
{
    return getSizeS();
    
}
int json::get_SizeA()
{
    return getSizeA();
   
}
int json::get_SizeO()
{
    return getSizeO();
    
}








