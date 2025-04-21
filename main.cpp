//  Created by Shreeram Majeti on 15/04/25.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class medicine 
{
    public:
        string name;
        int expDate;
        int quantity;
        float price;
        int id;
        string category;
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
{
    for(medicine &m:med)
    {
        if(m.id==id)
        {
            cout << "Medicine Found:\n";
            cout << "ID: " << m.id << "\nName: " << m.name << "\nQuantity: " << m.quantity<< "\nExpiry: " << m.expDate << "\nPrice: " << m.price << endl;
            return;
        }
    }
    cout<<"medicine out of stock";
}
void searchCategory(const vector<medicine>& meds, const string& category)
{
    bool found = false;
    for(medicine m :meds)
    {
        if (m.category == category)
        {
            cout << "ID: " << m.id << " Name: " << m.name << " Qty: " << m.quantity
                             << " Exp: " << m.expDate << " Price: " << m.price << endl;
                        found = true;
        }
    }
    if(!found)
    {
        cout<<"medicines out of stock";
    }
}
