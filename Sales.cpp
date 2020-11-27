#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

#include "Sales.h"

using namespace std;

//function used to read the whole SalesHistory text file 
void Sales::SalesHistory(){
    ifstream inFS;
    string salesHistory;
    
    inFS.open("SalesHistory.txt");
    if(!inFS.is_open()){
        cout << "SalesHistory file could not be opened" << endl;
    }
    
    cout << "Sales History Report:" << endl;
    cout << setfill('-') << setw(21) << "" << endl;
    cout << setfill(' ');
    
    while(!inFS.eof()){
        getline(inFS, salesHistory);
        
        if(!inFS.fail()){
            cout << salesHistory << endl;
        }
    }
    cout << setfill('-') << setw(21) << "" << endl;
    cout << setfill(' ');
    
    inFS.close();
}


//function that looks up a certain client's purchase history and outputs it
void Sales::ClientPurchaseHistory(string specificClient){
    ifstream inFS;
    string salesHistory;
    int lineFormat;
    
    inFS.open("SalesHistory.txt");
    if(!inFS.is_open()){
        cout << "SalesHistory file could not be opened" << endl;
    }
    
    while(!inFS.eof()){
        getline(inFS, salesHistory);
        
        for(int i = 0; i < salesHistory.size(); i++){
            if(salesHistory.at(i) == ':'){
                salesHistory = salesHistory.substr(0, i);
                
                if(!inFS.fail()){
                    if(salesHistory == specificClient){
                        lineFormat = 16 + salesHistory.size();
                        
                        cout << salesHistory << "'s Sales History" << endl;
                        cout << setfill('-') << setw(lineFormat) << "" << endl;
                        cout << setfill(' ');
                        
                        getline(inFS, salesHistory);
                        
                        while((isdigit(salesHistory.at(0)) == true) && (!inFS.eof())){
                            cout << salesHistory << endl;
                            
                            getline(inFS, salesHistory);
                            
                            if(inFS.eof() == true){
                                break;
                            }
                        }
                        
                        cout << setfill('-') << setw(lineFormat) << "" << endl;
                        cout << setfill(' ');
                        
                        break;
                    }
                }
            }
                
        }
    }
        
    inFS.close();
}