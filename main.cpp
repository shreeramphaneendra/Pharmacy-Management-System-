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
medicine* searchName(vector<medicine>& medList, const string& medname) {
    for (medicine& m : medList) {
        if (m.name == medname)
            return &m;
    }
    return nullptr;
}
medicine* searchId(vector<medicine>& medList, int id) {
    for (medicine& m : medList) {
        if (m.id == id)
            return &m;
    }
    return nullptr;
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
void updateStock(medicine &m,int number)
{
    m.quantity-=number;
    
    if(m.quantity<0)
    {
        m.quantity=0;
    }
    
}
void saveInventory(const vector<medicine>& meds)
{
    ofstream out("/Users/shreeramssp/Desktop/inventorypharamacy.txt");
    for (medicine m : meds)
    {
        out << m.id << " "
        << m.name << " "
        << m.quantity << " "
        << m.expDate << " "
        << m.price <<" "
        <<m.category<<"\n";
    }
}
void billing(vector<medicine> &meds)
{
    float total =0.0;
    char choice;
    do
    {
        string name;
        cout<<" enter medicine name to purchase ";
        cin>>name;
        medicine *m=searchName(meds,name);
        if (m)
        {
            int qty;
            cout << "Enter quantity: ";
            cin >> qty;

            if (m->quantity >= qty)
            {
                float cost = qty * m->price;
                total += cost;

                updateStock(*m, qty);
                cout << "Added to bill: " << m->name << " x" << qty << " = ₹" << cost << "\n";
             }
            else
            {
                cout << "Only " << m->quantity << " units available.\n";
            }
        }
        else
        {
            cout << "Medicine not found.\n";
        }

        cout << "Do you want to buy another medicine? (y/n): ";
         cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    
    cout << "\n======= Final Bill =======\n";
        cout << "Total amount: ₹" << total << "\n";
        cout << "==========================\n";

    saveInventory(meds);
}
int main()
{
    vector<medicine> meds=uploadfile();
     if (meds.empty())
     {
        cout << "Inventory is empty. Exiting program.\n";
        return 0;
     }
     int choice;
     while(1)
     {
        cout << "\n=================================\n";
        cout << "     Pharmacy Inventory System\n";
        cout << "=================================\n";
        cout << "1. Search Medicine by ID\n";
        cout << "2. Search Medicine by Name\n";
        cout << "3. Search Medicine by Category\n";
        cout << "4. Purchase Medicines (Billing)\n";
        cout << "5. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
     }
}