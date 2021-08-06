#include<iostream>
#include<fstream>
#include<string.h>
#include<list>
#include<iterator>
#include "files.h"

using namespace std;

files::files()
{
    strcpy(fileName,"Record.txt");
}
files::files(char f[])
{
    strcpy(fileName,f);
}

void files::readfile(list<listt>&contactList)
{
    char name[25];
    char address[80];
    int yob;
    char number[15];

    ifstream file(fileName);

    char l;
    if(file.is_open())
    {
        if(file.get()!=EOF)
        {
            if(file.get()=='\n')
            {
                do
                {
                    /* code */
                    listt A;
                    file.getline(name,25,'\n');
                    file.getline(address,80);
                    file>>yob;
                    file.get(l);
                    file.getline(number,15,'\n');
                    A.addRecord(name,number,address,yob);
                    contactList.push_back(A);
                } while (file.get()!=EOF);
                              
            }
        }
     
    }
 
}
void files::writefile(list<listt>&contactList)
{

    ofstream file(fileName);
    
    if(file.is_open())
    {
        if(!contactList.empty())
        {
            file<<"\n";
            list <listt>::iterator i;
            i=contactList.begin();
            for(i=contactList.begin();i!=contactList.end();i++)
            {
                file<<"\n";
                file<<i->name<<endl;
                file<<i->address<<endl;
                file<<i->yob<<endl;
                file<<i->number<<endl;    
            }
   
        }

    }
    file.close();    
}
void files::writefilecsv(list<listt>&contactList)
{

    ofstream file("Record.csv");
    file<<"Name,Address,YOB,Number\n";
    if(file.is_open())
    {
        if(!contactList.empty())
        {
            // file<<"\n";
            list <listt>::iterator i;
            i=contactList.begin();
            for(i=contactList.begin();i!=contactList.end();i++)
            {
                file<<"\n";
                file<<i->name<<" ";
                file<<",";
                file<<i->address<<" ";
                file<<",";
                file<<i->yob<<",";
                file<<i->number;    
            }
   
        }

    }
    file.close();    
}
