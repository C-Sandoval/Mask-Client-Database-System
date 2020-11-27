#include <iostream>
#include <string>

//required files
#include "SalesRepresentatives.h"
#include "Sales.h"

using namespace std;

int main(){
    Sales maskSales;     //Sales class object
    SalesRepresentatives SalesRep;   //Sales Representatives class object
    bool isOpen = true;   //used for the while loop
    char userInput;      //used as the primary input for selecting the options provided in the main while loop
    int userSelection;   //used for secondary inputs inside the if/else branches
    string clientLookUp;  //used specifically in the sales branch
    string newSalesRep;          //<--
    string newSalesRepAddress;   //<--all of these used in the sales Representatives branch
    int newSalesRepSales;        //<--
    string specificSalesRep;     //<--
   
   
    //opening line
    cout << "Welcome to Mask Central" << endl;
    cout << endl;


    //main loop for the program
    while(isOpen == true){
        cout << "Select an option:" << endl;
        cout << "c = View Clients" << endl;
        cout << "r = View Sales Representatives" << endl;
        cout << "p = View Product/Service" << endl;
        cout << "s = View Sales" << endl;
        cout << "q = Quit" << endl;
        cout << endl;
        
        //primary input for the selection above
        cout << "Please select an option: ";
        cin >> userInput;
        cout << endl;
        
        
        //the client branch goes here
        if(userInput == 'c'){
            cout << "Introduce the Client class here" << endl;
            cout << endl;
        }
        
        
        //Sales Representatives branch
        else if(userInput == 'r'){
            while(isOpen == true){
                cout << "Sales Representative Options" << endl;
                cout << endl;
                cout << "1. View Sales Representatives" << endl;
                cout << "2. Add New Sales Representatives" << endl;
                cout << "3. View Specific Sales Representative" << endl;
                cout << "4. Quit" << endl;
                cout << endl;
                cout << "Enter the number that corresponds with the options provided: " << endl;
                cin >> userSelection;
                cout << endl;
                
                cin.ignore();                
                
                if(userSelection == 1){
                    SalesRep.ViewSalesRep();
                }
                else if(userSelection == 2){
                    cout << "Enter the new Sales Representative's name: ";
                    getline(cin, newSalesRep);
                    cout << endl;
                    cin.ignore();
                    cout <<"Enter the new Sales Representative's address: ";
                    getline(cin, newSalesRepAddress);
                    cout << endl;
                    cout <<"Enter the new Sales Representative's sales: ";
                    cin >> newSalesRepSales;
                    cout << endl;
                    
                    //enters the provided info into SalesRepresentatives text file
                    SalesRep.AddSalesRep(newSalesRep, newSalesRepAddress, newSalesRepSales);
                    
                    cout << endl;
                }
                else if(userSelection == 3){
                    cout << "Enter the Sales Representative's name:" << endl;
                    getline(cin, specificSalesRep);
                    cout << endl;
                    SalesRep.ViewSpecificSalesRep(specificSalesRep);
                    cout << endl;
                }
                else if(userSelection == 4){
                    break;
                }
            }
            
            cout << endl;
        }
       
        
        //the product branch goes here
        else if(userInput == 'p'){
            cout << "Introduce the Product/Service class here" << endl;
            cout << endl;
        }
        
        
        //the sales branch 
        else if(userInput == 's'){
            while(isOpen == true){
                cout << "Sales History Options" << endl;
                cout << "1. View Sales History" << endl;
                cout << "2. View Client's Sales History" << endl;
                cout << "3. Quit" << endl;
                cout << endl;
                cout << "Enter the number that corresponds with the options provided: " << endl;
                cin >> userSelection;
                cout << endl;
                
                if(userSelection == 1){
                    maskSales.SalesHistory();
                    cout << endl;
                }
                
                else if(userSelection == 2){
                    cout << "Enter the client's name: ";
                    cin >> clientLookUp;
                    cout << endl;
                    maskSales.ClientPurchaseHistory(clientLookUp);
                    cout << endl;
                }
                
                else if(userSelection == 3){
                    break;
                }
            }
            cout << endl;
        }


        //the exit branch is here
        else if(userInput == 'q'){
            cout << "Please come again" << endl;
            break;
        }
    }

    return 0;
}