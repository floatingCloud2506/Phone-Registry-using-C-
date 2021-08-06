#include <iostream>
#include <fstream>
#include "files.h"
#include <list>
#include <string.h>
#include <iterator>
#include<iomanip>
using namespace std;
list<listt> contactList;
void Display()
{
    list<listt>::iterator i;
    cout<<"\n\n\n";
    cout<<setw(49)<<"PHONE REGISTRY\n\n";
    
    cout<<setw(6)<<"Name"<<setw(15)<<"Number"<<setw(40)<<"Address"
    <<setw(28)<<"YOB"<<endl;
    cout << "--------------------------------------------------------------------------------------------------\n";

    for (i = contactList.begin(); i != contactList.end(); i++)
    {

        // (*i).display();
        cout<<(*i);
    }
    cout << "--------------------------------------------------------------------------------------------------\n";



}
void add()
{
    int n, yob;
    char name[25], number[15], address[80];
    listt *A;
    A = new listt[100];
    list<listt>::iterator i;
        cout << "--------------------------------------------------------------------------------------------------\n";
    cout << "Enter the number of contacts to be added to the registry\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter name\n";
        fflush(stdin);
        cin.getline(name, 25);
        cout << "Enter number\n";
        fflush(stdin);
        cin.getline(number, 15);
        cout << "Enter address\n";
        fflush(stdin);
        cin.getline(address, 80);
        cout << "Enter yob\n";
        cin >> yob;
        A[i].addRecord(name, number, address, yob);
        contactList.push_back(A[i]);
    }
}
void Modify()
{
    char name[25],number[15],address[80];
    list<listt>::iterator i;
    cout << "Enter the name whose record you want to modify\n";
    fflush(stdin);
    cin.getline(name, 25);

    for (i = contactList.begin(); i != contactList.end(); i++)
    {
        if (strcmp((*i).name, name) == 0)
        {
            cout<<"\nContact "<<name<<" found\n";
            cout<<"Enter the number \n";
            fflush(stdin);
            cin.getline(number,15);
            cout<<"Enter the address\n";
            fflush(stdin);
            cin.getline(address,80);
            (*i).modify(name, number, address);
            return;
        }
    }
    cout<<"\nContact "<<name<<" not found\n";
    return;

}
void Delete()
{
    char name[25];
    cout<<"Enter the name whose record you wish to delete\n";
    fflush(stdin);
    cin.getline(name,25);
 
    list<listt>::iterator i;
    for(i=contactList.begin();i!=contactList.end();i++)
    {
        if (strcmp((*i).name, name) == 0)
        {
            cout<<"\nContact "<<name<<" found\n";
            i=contactList.erase(i);       
            cout<<"Contact "<<name<<" deleted\n";
            return;     
        }
        
    }
    cout<<"\nContact "<<name<<" not found\n";
    return;
}
void search()
{
    char name[25];
    cout<<"Enter the name whose record you wish to search\n";
    fflush(stdin);
    cin.getline(name,25);
 
    list<listt>::iterator i;
    for(i=contactList.begin();i!=contactList.end();i++)
    {
        if (strcmp((*i).name, name) == 0)
        {
            cout<<"\nContact "<<name<<" found\n\n";       
            (*i).display();
            return;     
        }
        
    }
    cout<<"\nContact "<<name<<" not found\n";
    return;

}
void Reverse()
{
    contactList.reverse();
    return;
}

int main()
{
    int c, op;
    files f1;
    f1.readfile(contactList);
    do
    {
        cout << "\nEnter the operation:\n";
        cout << "1 - Add records\n";
        cout << "2 - Print all the records\n";
        cout <<"3 - Modify a record using name as the key\n";
        cout <<"4 - Delete a record using name as the key\n";
        cout <<"5 - Search a record using name as the key\n";
        cout <<"6 - Reverse the record\n";
        cin >> op;
        switch (op)
        {
        case 1:
            add();
            Display();
            break;

        case 2:
            Display();
            break;

        case 3:
            Modify();
            Display();
            break;

        case 4:
            Delete();
            Display();
            break;
        
        case 5:
            search();
            break;

        case 6:
            Reverse();
            Display();
            break;

        default:
            break;
        }
        cout << "\nDo you want to continue?enter 0 to exit or 1 to continue\n";
        cin >> c;
    } while (c);

    f1.writefile(contactList);
    char c1[25];
    strcpy(c1,"Record.csv");
    files f2(c1);
    f2.writefilecsv(contactList);
    return 0;
}