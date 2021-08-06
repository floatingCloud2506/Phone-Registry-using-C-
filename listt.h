#include<iostream>
class listt
{
    public:
        char name[25];
        char address[80];
        int yob;
        char number[15];
        void addRecord(char *name, char *number, char *address, int yob);
        void display();        
        void modify(char *name, char *number, char *address);
        friend std::ostream&operator <<(std::ostream &out,const listt& );
};
