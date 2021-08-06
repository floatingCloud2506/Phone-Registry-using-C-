#include<list>
#include<iostream>
#include"listt.h"
using namespace std;
class files
{
    public:
        char fileName[25];
        files();
        files(char f[]);
        void readfile(list<listt>&contactList);
        void writefile(list<listt>&contactList);
        void writefilecsv(list<listt>&contactList);
};
