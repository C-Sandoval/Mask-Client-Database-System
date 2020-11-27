#ifndef SALESREPRESENTATIVES_H
#define SALESREPRESENTATIVES_H

#include <string>

using namespace std;

class SalesRepresentatives{
    public:
        void ViewSalesRep();
        void AddSalesRep(string name, string address, int sales);
        void ViewSpecificSalesRep(string specificSalesRep);
};

#endif