#ifndef SALES_H
#define SALES_H

#include <string>

using namespace std;

class Sales{
    public:
        void SalesHistory();        //Reads all the purchases of product
        void ClientPurchaseHistory(string specificClient);  //views certain client's purchase history and outputs it
};

#endif