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

void saveMedicinesIntoFile() {
    int n;
    cout << "=============================\n";
    cout << "  PHARMACY INVENTORY SYSTEM\n";
    cout << "=============================\n\n";
    
    cout << "Enter the number of medicines to record: ";
    cin >> n;

    vector<medicine> m(n);

    for (int i = 0; i < n; i++) {
        cout << "\n-----------------------------\n";
        cout << " Enter Details for Medicine " << (i + 1) << "\n";
        cout << "-----------------------------\n";

        cout << "Medicine Name          : ";
        cin >> m[i].name;

        cout << "Medicine ID            : ";
        cin >> m[i].id;

        cout << "Expiry Date (YYYYMM)   : ";
        cin >> m[i].expDate;

        cout << "Price (in Rs)          : ";
        cin >> m[i].price;

        cout << "Quantity in Stock      : ";
        cin >> m[i].quantity;
    }

    ofstream outfile("/Users/shreeramssp/Desktop/inventorypharamacy.txt");

    if (!outfile) {
        cout << " ERROR: Could not open file to write.\n";
        return;
    }

    outfile << "=============================\n";
    outfile << "  PHARMACY INVENTORY REPORT\n";
    outfile << "=============================\n\n";

    for (int i = 0; i < n; i++) {
        outfile << "-----------------------------\n";
        outfile << " Medicine " << (i + 1) << " Details\n";
        outfile << "-----------------------------\n";
        outfile << "Medicine Name          : " << m[i].name << "\n";
        outfile << "Medicine ID            : " << m[i].id << "\n";
        outfile << "Expiry Date (YYYYMM)   : " << m[i].expDate << "\n";
        outfile << "Price (in Rs)          : " << m[i].price << "\n";
        outfile << "Quantity in Stock      : " << m[i].quantity << "\n\n";
    }

    outfile.close();
    cout << "\n Inventory saved successfully to inventorypharamacy.txt\n";
}
    
int main() {
    saveMedicinesIntoFile();
    return 0;
}
