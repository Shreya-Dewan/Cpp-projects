/*****************************RAILWAY RESERVATION SYSTEM****************************/

/****************Preprocessors*****************/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;
class sign_in
{
    protected:
    char id[20];
    char pwd[20];
    public:
       virtual void fun()=0;   //to make sign_in an abstract class
    void getdata()
    {
        cout<<"Enter id: ";
        cin>>id;
        fflush(stdin);
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); //to clear input buffer
        cout<<"Enter password: ";
        cin>>pwd;
        fflush(stdin);
    }
};

class admin_data::public sign_in
{

};


int main()
{
    ofstream f;
    sign_in s;
    fopen("dat.txt","a");
    s.getdata();
    f.write((char*)&s, sizeof(s));


    return 0;

}
