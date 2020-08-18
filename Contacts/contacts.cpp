//////////////////////////////////////////////////////////////////
/*                                                              \\
*This is my First Project                                       //
*In this we create contact detail with file handling in c++     \\
*Detail //Time//Number//Name//Address//sorting by name or time  //
*we can find the number by //total number size                  \\
*/                                                              //
////////////////////////////////////////////////////////////////\\
HEADER BODY
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include"ctime"
using namespace std;
//MAIN BODY
class contacts
{
    private:
   static int Sr_No;
    char Name[50];
    char NUM[15];

    protected:
        void show()
        {
            cout<<Name<<endl;
            cout<<NUM<<endl;
        }
    public:

        contacts()
        {
            Sr_No=0;
            strcpy(Name,"None");
            strcpy(NUM,"None");
        }

        void add_Contact();
        void store_Contact();

        void view_Contact();
};
int contacts::Sr_No=1;

void contacts::add_Contact()//////    1
        {
            cout<<"Enter the name : ";
            cin.getline(Name,30);

            cout<<"Enter the number ";
            cin.getline(NUM,15);

            /*
            * exception handling
            * number is equal to 11 character
            */
            try{
                int counter=0;
               while(NUM[counter]!='\0')
               {
                 counter++;
               }
               if(--counter!=10)
                throw 1;
                else
                cout<<"~Number is inserted Successfully~"<<endl;
            }
            catch(int excep)
            {
                cout<<"Please enter 11 character"<<endl;
                cout<<"try again"<<endl;
                exit(0);
            }
        }
        void contacts::store_Contact()
        {
            show();
            ofstream fout;
            fout.open("contacts_profile.dat",ios::app | ios::binary);
            fout.write((char*)this,sizeof(*this));
            fout.close();
        }
        void contacts::view_Contact()
        {
            ifstream fin;
            fin.open("contacts_profile.dat",ios::app|ios::binary);
            if(!fin){
                cout<<"file not exits"<<endl;

            }
            else
            {
            fin.read((char*)this,sizeof(*this));
               while(!fin.eof()){

            fin.read((char*)this,sizeof(*this));
            show();
            cout<<sizeof(*this);
               }
            }
        }
main()
{
    contacts c;
    while(1)
    {
        cout<<"1. ADD CONTACT "<<endl;
        cout<<"2. UPDATE CONTACT "<<endl;
        cout<<"3. DELETE CONTACT "<<endl;
        cout<<"4. VIEW CONTACT "<<endl;
        cout<<"5. EXIT "<<endl;
        int choice;
        cin>>choice;
        cin.ignore(1);
        switch(choice)
        {
            case 1:
                c.add_Contact();
                c.store_Contact();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                c.view_Contact();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Enter Valid Number";
        }
    }
}
