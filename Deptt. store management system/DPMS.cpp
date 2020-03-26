#include<stdlib.h>
#include<dirent.h>
#include <bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;

class inventory{
private:
    string item;
    int qty;
    float mrp;
    int batch_no;
public:
    inventory()
    {
        item="No item";
        qty=0;
        mrp=0.0;
        batch_no=0;
    }
    void get_item()
    {
        cout<<"Enter item name"<<endl;
        cin.ignore();
        getline(cin, item);
        cout<<"Enter batch number"<<endl;
        cin>>batch_no;
        cout<<"Enter quantity of item"<<endl;
        cin>>qty;
        cout<<"Enter MRP"<<endl;
        cin>>mrp;
    }
    void show_item()
    {
        cout<<"---------------Displaying Item Details from inventory--------------"<<endl;
        cout<<"Item:  "<<item<<endl;
        cout<<"Batch No:  "<<batch_no<<endl;
        cout<<"MRP:  "<<mrp<<endl;
        cout<<"Quantity:  "<<qty<<endl;
    }
    int add_item();
};


int inventory::add_item()
{
    if(qty==0&&batch_no==0)
    {
        cout<<"Item details not entered"<<endl;
        return 0;
    }
    else{
    ofstream fout;
    fout.open("inventory.dat", ios::app| ios::binary);
    fout.write((char*)this, sizeof(*this));
    fout.close();
    return 1;
    }
}
int main()
{
    int inv_adder=1;
    inventory inv;
    inv.get_item();
    inv.show_item();
    while(inv_adder==1)
        {
            if(inv.add_item()){
                cout<<"Item added to inventory"<<"\n"<<"Press 1 to add more items. Press 2 to exit";
                cin>>inv_adder;
            }
            else
            {
                cout<<"Inventory updation failed. Exiting updation portal............"<<endl;
                break;
            }

        }
}
