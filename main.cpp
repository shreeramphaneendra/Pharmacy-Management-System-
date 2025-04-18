#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class medicine {
public:
    string name;
    int expDate;
    int quantity;
    float price;
    int id;
};
vector<medicine> uploadfile()
{
    ifstream infile("/Users/shreeramssp/Desktop/inventorypharamacy.txt");
    vector<medicine> meds;
    medicine m;
    if(!infile)
    {
        cout<<" ERROR file not opening ";
        return;
    }
    while(infile>>m.id>>m.name>>m.quantity>>m.expDate>>m.price)
    {
        meds.push_back(m);
    }
    inflie.close();
    return meds;
}