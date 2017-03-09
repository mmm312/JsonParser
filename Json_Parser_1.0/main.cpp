//
//  main.cpp
//  Json_Parser_1.0
//
//  Created by Muhtashim Mahi on 3/7/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "json_parse.hpp"
using namespace std;

string jsonFileIn(string input)    //Input the name of the file with the json txt
{
    
    //Adding txt for the file since the user will only input the name
    //open the file
    string temp;
    fstream inFile;
    input+=".txt";
    inFile.open(input.c_str());
    getline(inFile,temp);
    
    //check if the file name exists
    //if not exit the program
    if (inFile.fail())
    {
        cout<<" No File found in the name\nre-run the program";
        exit(1);
    }
    return temp;
}


int main()
{
    
    string fileName;  // string file to find file
    cout <<"Please enter the file name that you want to parse"<<endl;
    cin>>fileName;
    string fString;  // string to store txt string
    fString=jsonFileIn(fileName);
    json x;  //creating json object
    x.parse(fString);
    
    
    //outputing the weighted numbers of the files
    cout<<"The weight of the objects are "<< x.get_SizeS()+ x.getSizeO()<<endl;
    
    cout<<"The weight of the Arrays are "<< x.get_SizeA()<<endl;
    
    
    
    
    
    
    return 0;
}
