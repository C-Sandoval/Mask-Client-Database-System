#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include "SalesRepresentatives.h"

using namespace std;

//reads the Sales Representatives text file and outputs it
void SalesRepresentatives::ViewSalesRep(){
    ifstream inFS;
    string salesRep;
    
    inFS.open("Sales Representatives.txt");
    if(!inFS.is_open()){
        cout << "Sales Representatives file could not be opened" << endl;
    }
    
    cout << setfill('-') << setw(25) << "" << endl;
    cout << setfill(' ');
    
    while(!inFS.eof()){
        getline(inFS, salesRep);
        
        if(!inFS.fail()){
            cout << salesRep << endl;
        }
    }
    cout << setfill('-') << setw(25) << "" << endl;
    cout << setfill(' ');
    
    inFS.close();
}


void SalesRepresentatives::AddSalesRep(string name, string address, int sales){
    ifstream inFS;
    ofstream outFS;
    vector<string> originalText;
    string text;
    
    //Reads the text file and stores the text into the vector 
    inFS.open("Sales Representatives.txt");
    if(!inFS.is_open()){
        cout << "Sales Representatives file could not be opened" << endl;
    }
    
    while(!inFS.eof()){
        getline(inFS, text);
        
        if(!inFS.fail()){
            originalText.push_back(text);
        }
    }
    inFS.close();
    
    
    //outputs the previous text with the new data to the Sales Representatives text file
    outFS.open("Sales Representatives.txt");
    if(!outFS.is_open()){
        cout << "Sales Representatives file could not be opened" << endl;
    }
    
    for(int i = 0; i < originalText.size(); i++){
        outFS << originalText.at(i) << endl;
    }
    
    //outputs the parameters into the Sales Representatives text file
    outFS << "Name: " << name << endl;
    outFS << "Address: " << address << endl;
    outFS << "Sales to Date: " << sales << endl;
    outFS << endl;
    
    
    outFS.close();
}


//Reads the Sales Representatives text file and outputs certain text based on parameter
void SalesRepresentatives::ViewSpecificSalesRep(string specificSalesRep){
    ifstream inFS;
    string text;
    
    inFS.open("Sales Representatives.txt");
    if(!inFS.is_open()){
        cout << "Sales Representatives file could not be opened" << endl;
    }
    
    while(!inFS.eof()){
        getline(inFS, text);
        
        if(text == ("Name: " + specificSalesRep)){
            cout << setfill('-') << setw(25) << "" << endl;
            cout << setfill(' ');
            
            if(!inFS.fail()){
                for(int i = 0; i < 3; i++){
                    cout << text << endl;
                    getline(inFS, text);
                }
            }
        }
    }
    cout << setfill('-') << setw(25) << "" << endl;
    cout << setfill(' ');
    
    inFS.close();
}