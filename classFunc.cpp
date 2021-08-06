#include <string.h>
#include "listt.h"
#include <iostream>
#include <fstream>
#include <list> 
#include <iterator> 
#include<iomanip>
using namespace std;

void listt::addRecord(char name[],char number[],char address[],int yob)
{
   strcpy(this->name,name);
   strcpy(this->number,number);
   strcpy(this->address,address);
   this->yob=yob;
}
void listt::display()
{
    cout<<"Name: "<<name<<endl<<endl;
    cout<<"Number: "<<number<<endl<<endl;
    cout<<"Address: "<<address<<endl<<endl;
    cout<<"YOB: "<<yob<<endl<<endl;
    cout << "--------------------------------------------------------------------------------------------------\n";


}

void listt::modify(char *name, char *number, char *address)
{
    strcpy(this->number,number);
    strcpy(this->address,address);
}

// std::ostream&operator <<(std::ostream &out,const listt&l )
// {
//     out<<"Name: "<<l.name<<endl<<endl;
//     out<<"Number: "<<l.number<<endl<<endl;
//     out<<"Address: "<<l.address<<endl<<endl;
//     out<<"YOB: "<<l.yob<<endl<<endl;
//     out<<"----------------------------------------------------------------------\n";
//     return out;
// }
std::ostream&operator <<(std::ostream &out,const listt&l )
{
    out<<setw(10)<<l.name<<setw(15)<<l.number<<setw(50)<<l.address
    <<setw(15)<<l.yob<<endl;
    out<<endl;
    return out;
}



 