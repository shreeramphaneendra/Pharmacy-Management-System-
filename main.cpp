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
        return meds;
    }
    while(infile>>m.id>>m.name>>m.quantity>>m.expDate>>m.price)
    {
        meds.push_back(m);
    }
    infile.close();
    return meds;
}
void searchName(vector<medicine> &med,string medname)
{
    for(medicine &m:med)
    {
        if(m.name==medname)
        {
            cout << "Medicine Found:\n";
            cout << "ID: " << m.id << "\nName: " << m.name << "\nQuantity: " << m.quantity<< "\nExpiry: " << m.expDate << "\nPrice: " << m.price << endl;
            return;
        }
    }
    cout<<"medicine out of stock";
} 
void searchId(vector<medicine>& med,int id)

