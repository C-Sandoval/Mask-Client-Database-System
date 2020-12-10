#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Manufacturers.h"

using namespace std;

void Manufacturers::ListManufacturers(){
    ifstream inFS;
    string fileText;
    
    inFS.open("Mask Manufacturing Companies.txt");
    if(!inFS.is_open()){
        cout << "The Mask Manufactoring Companies text file could not be opened" << endl;
    };
    
    cout << setfill('-') << setw(29) << "" << endl;
    cout << setfill(' ');
    
    while(!inFS.eof()){
        getline(inFS, fileText);
        
        if(!inFS.fail()){
            cout << fileText << endl;
        }
    }
    cout << setfill('-') << setw(29) << "" << endl;
    cout << setfill(' ');
    
    inFS.close();
}