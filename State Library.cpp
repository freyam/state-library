#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

void banner();
void mainmenu();
void exit();

void bookmenu();
void searchbookmenu();
void editbookmenu();
void customermenu();
void searchcustomermenu();
void editcustomermenu();
void addbook();
void searchbybname();
void searchbybno();
void modifybook();
void deletebook();
void deleteallbooks();
void displayallbooks();
void issuebook();
void returnbook();

void addcustomer();
void searchbyregno();
void searchbyname();
void modifycustomer();
void deletecustomer();
void deleteallcustomers();
void displayallcustomers();

class book
{
private:
char bno[6], bname[50], aname[50];
int avail;

public:
void createbook()
{
        cout<<endl;
        cout<<"Book Number: "; cin>>bno; cout<<endl;
        cout<<"Book Title: "; cin.get(); cin.getline(bname,50); cout<<endl;
        cout<<"Book Author: "; cin.get(); cin.getline(aname,50); cout<<endl;
        avail = 1;
        system("cls");
}

void showbook()
{
        cout<<endl;
        cout<<"Book Number: "<<bno<<endl;
        cout<<"Book Title: "; puts(bname);
        cout<<"Book Author: "; puts(aname);
        cout<<"Availability: "; (avail==1) ? cout<<"Yes" : cout<<"No";
}

void modifybook()
{
        cout<<endl;
        cout<<"Book Number: "<<bno<<endl;
        cout<<"Modified Book Name: "; cin.get(); cin.getline(bname,50); cout<<endl;
        cout<<"Modified Author Name: "; cin.get(); cin.getline(aname,50); cout<<endl;
}

char* getbno() {
        return bno;
}
char* getbname() {
        return bname;
}
int getavail() {
        return avail;
}

void report() {
        cout<<"|    "<<bno<<"     |"<<"  "<<bname<<" by "<<aname<<endl;
}
};

class customer
{
private:
char regno[6], name[50], cbno[6], cbname[50];
int book_issued;

public:
void createcustomer()
{
        cout<<endl;
        cout<<"Customer Registration Number: "; cin>>regno; cout<<endl;
        cout<<"Customer Name: "; cin.get(); cin.getline(name,50);
        book_issued = 0; cbno[0] = '\0'; cbname[0] = '\0';
        system("cls");
}

void showcustomer()
{
        cout<<endl;
        cout<<"Customer Registration Number: "<<regno<<endl;;
        cout<<"Customer Name: "<<name<<endl;;
        if(book_issued==1)
        {
                cout<<"Book Issued: "<<cbno<<endl;
                cout<<"Book Name: "<<cbname<<endl;
        }
}

void modifycustomer()
{
        cout<<endl;
        cout<<"Customer Number: "<<regno<<endl;
        cout<<"Modified Customer Name: "; cin.get(); cin.getline(name,50); cout<<endl;
}

char* getregno() {
        return regno;
}
char* getcbno() {
        return cbno;
}
char* getname() {
        return name;
}
int getbook_issued() {
        return book_issued;
}
void getcbno(char t[]) {
        strcpy(cbno,t);
}
void getcbname(char t[]) {
        strcpy(cbname,t);
}

void bookissued() {
        book_issued=1;
}
void bookreturned() {
        book_issued=0; cbno[0] = '\0'; cbname[0] = '\0';
}

void report()
{
        cout<<"|    "<<regno<<"     |"<<"  "<<name<<"     ";
        if (book_issued==1) cout<<"("<<cbno<<" - "<<cbname<<")"<<endl;
        else cout<<endl;
}
};

fstream f, f1;
book bk;
customer ct;

int main()
{
        banner();

        char pass[5]; cin>>pass; if(strcmpi(pass,"frey")==0)

                mainmenu();
}

void banner()
{
        system("cls");

        cout<<endl<<endl;
        cout<<"     *********************************       "<<endl;
        cout<<"     *********************************       "<<endl;
        cout<<"     **                             **       "<<endl;
        cout<<"     **            State            **       "<<endl;
        cout<<"     **           Library           **       "<<endl;
        cout<<"     **                             **       "<<endl;
        cout<<"     **            ~Frey            **       "<<endl;
        cout<<"     **                             **       "<<endl;
        cout<<"     *********************************       "<<endl;
        cout<<"     *********************************       "<<endl;
        cout<<endl<<endl;
}

void mainmenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **          MAIN MENU          **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **     1. Book Management      **       "<<endl;
                cout<<"     **   2. Customer Management    **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **      0. Exit Library        **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: bookmenu(); break;
                case 2: customermenu(); break;
                case 0: exit();
                default: cout<<"Oops! Try Again..."; mainmenu();
                }
        } while (ch<=2);
}

void bookmenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **          BOOK MENU          **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **        1. Add Books         **       "<<endl;
                cout<<"     **       2. Search Books       **       "<<endl;
                cout<<"     **       3. Edit Books         **       "<<endl;
                cout<<"     **      4. Display Books       **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **      5. Issue a Book        **       "<<endl;
                cout<<"     **      6. Return a Book       **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     ** 0. Return to Previous Menu  **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: addbook(); break;
                case 2: searchbookmenu(); break;
                case 3: editbookmenu(); break;
                case 4: displayallbooks(); break;
                case 5: issuebook(); break;
                case 6: returnbook(); break;
                case 0: mainmenu(); break;
                default: cout<<"Oops! Try Again..."; bookmenu();
                }
        } while (ch<=6);
}

void searchbookmenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **      SEARCH BOOKS MENU      **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **     1. Search By Number     **       "<<endl;
                cout<<"     **     2. Search By Title      **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     ** 0. Return to Previous Menu  **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: searchbybno(); break;
                case 2: searchbybname(); break;
                case 0: bookmenu(); break;
                default: cout<<"Oops! Try Again..."; searchbookmenu();
                }
        } while (ch<=2);
}

void editbookmenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **       EDIT BOOKS MENU       **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **        1. Edit Books        **       "<<endl;
                cout<<"     **       2. Delete Books       **       "<<endl;
                cout<<"     **      3. Delete All Books    **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     ** 0. Return to Previous Menu  **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: modifybook(); break;
                case 2: deletebook(); break;
                case 3: deleteallbooks(); break;
                case 0: bookmenu(); break;
                default: cout<<"Oops! Try Again..."; editbookmenu();
                }
        } while (ch<=3);
}

void customermenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **        CUSTOMER MENU        **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **     1. Add Customer         **       "<<endl;
                cout<<"     **     2. Search Customers     **       "<<endl;
                cout<<"     **     3. Edit Customers       **       "<<endl;
                cout<<"     **     4. Display Customers    **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     ** 0. Return to Previous Menu  **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: addcustomer(); break;
                case 2: searchcustomermenu(); break;
                case 3: editcustomermenu(); break;
                case 4: displayallcustomers(); break;
                case 0: mainmenu(); break;
                default: cout<<"Oops! Try Again..."; customermenu();
                }
        } while (ch<=4);
}

void searchcustomermenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **    SEARCH CUSTOMER MENU     **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **   1. Search By Reg Number   **       "<<endl;
                cout<<"     **     2. Search By Name       **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     ** 0. Return to Previous Menu  **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: searchbyregno(); break;
                case 2: searchbyname(); break;
                case 0: customermenu(); break;
                default: cout<<"Oops! Try Again..."; searchcustomermenu();
                }
        } while (ch<=2);
}

void editcustomermenu()
{
        system("cls");
        int ch;

        do
        {
                cout<<endl<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            State            **       "<<endl;
                cout<<"     **           Library           **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **            ~Frey            **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **     EDIT CUSTOMERS MENU     **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **     1. Edit Customers       **       "<<endl;
                cout<<"     **    2. Delete Customers      **       "<<endl;
                cout<<"     **  3. Delete All Customers    **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     ** 0. Return to Previous Menu  **       "<<endl;
                cout<<"     **                             **       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<"     *********************************       "<<endl;
                cout<<endl<<endl;

                cout<<"Enter your choice: "; cin>>ch;
                switch(ch)
                {
                case 1: modifycustomer(); break;
                case 2: deletecustomer(); break;
                case 3: deleteallcustomers(); break;
                case 0: customermenu(); break;
                default: cout<<"Oops! Try Again..."; editcustomermenu();
                }
        } while (ch<=3);
}

void addbook()
{
        system("cls");

        char ch;
        f.open("Books.dat", ios::app);

        do
        {
                system("cls");

                bk.createbook();
                f.write((char*)&bk,sizeof(book));

                cout<<"Add One More? "; cin>>ch;
        } while(ch=='y' || ch=='Y');

        f.close();
}

void searchbybno()
{
        system("cls");

        int flag = 0;
        char no[6];

        cout<<"Book Number to be Searched: "; cin>>no;

        f.open("Books.dat", ios::in);
        while(f.read((char*)&bk,sizeof(book)))
        {
                if(strcmpi(bk.getbno(),no)==0)
                {
                        bk.showbook(); flag=1;
                }
        }

        f.close();

        if(flag==0) cout<<"This Book Doesn't Exist!";

        getch();
}

void searchbybname()
{
        system("cls");

        int flag = 0;
        char name[20];

        cout<<"Book Name to be Searched: "; cin.get(); cin.getline(name,20);

        f.open("Books.dat", ios::in);
        while(f.read((char*)&bk,sizeof(book)))
        {
                if(strcmpi(bk.getbname(),name)==0)
                {
                        bk.showbook(); flag=1;
                }
        }

        f.close();

        if(flag==0) cout<<"This Book Doesn't Exist!";

        getch();
}

void modifybook()
{
        system("cls");

        int flag = 0;
        char no[6];

        cout<<"Book Number to be Modified: "; cin>>no;

        f.open("Books.dat", ios::in | ios::out);
        while(f.read((char*)&bk,sizeof(book)) && flag==0)
        {
                if(strcmpi(bk.getbno(),no)==0)
                {
                        bk.showbook(); flag=1;
                        cout<<endl<<endl;

                        cout<<"Enter the New Details: "<<endl;
                        bk.modifybook();

                        int pos=-1*sizeof(bk);
                        f.seekp(pos,ios::cur);
                        f.write((char*)&bk,sizeof(book));
                }
        }

        f.close();

        if(flag==0) cout<<"This Book Doesn't Exist!";

        getch();
}

void deletebook()
{
        system("cls");

        int flag = 0;
        char no[6];

        cout<<"Book Number to be Deleted: "; cin>>no;

        f.open("Books.dat", ios::in | ios::out);

        fstream f2;
        f2.open("temp.dat", ios::out);

        f.seekg(0,ios::beg);

        while(f.read((char*)&bk,sizeof(book)))
        {
                if(strcmpi(bk.getbno(),no)!=0)
                        f2.write((char*)&bk,sizeof(book));
                else
                        flag=1;
        }

        f.close();
        f2.close();

        remove("Books.dat");
        rename("temp.dat","Books.dat");

        if(flag==0) cout<<"This Book Doesn't Exist!";
        else if (flag==1) cout<<"Book Deleted!";

        getch();
}

void deleteallbooks()
{
        system("cls");

        char ch;

        cout<<"Delete all? Sure? "; cin>>ch;

        if(ch=='y') remove("Books.dat");
        else editbookmenu();
}

void displayallbooks()
{
        system("cls");

        f.open("Books.dat", ios::in);

        cout<<endl<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"**                                 BOOKS LIST                                 **"<<endl;
        cout<<"********************************************************************************"<<endl<<endl;
        while(f.read((char*)&bk,sizeof(book))) bk.report();

        f.close();

        getch();
}

void addcustomer()
{
        system("cls");

        char ch;
        f.open("Customers.dat", ios::app);
        do
        {
                system("cls");

                ct.createcustomer();
                f.write((char*)&ct,sizeof(customer));

                cout<<"Add One More? "; cin>>ch;
        } while(ch=='y' || ch=='Y');

        f.close();
}

void searchbyregno()
{
        system("cls");

        int flag = 0;
        char no[6];

        cout<<"Customer's Registration Number to be Searched: "; cin>>no;

        f.open("Customers.dat", ios::in);
        while(f.read((char*)&ct,sizeof(customer)))
        {
                if(strcmpi(ct.getregno(),no)==0)
                {
                        ct.showcustomer(); flag=1;
                }
        }

        f.close();

        if(flag==0) cout<<"This Customer Doesn't Exist!";

        getch();
}

void searchbyname()
{
        system("cls");

        int flag = 0;
        char name[20];

        cout<<"Customer Name to be Searched: "; cin.get(); cin.getline(name,20);

        f.open("Customers.dat", ios::in);
        while(f.read((char*)&ct,sizeof(customer)))
        {
                if(strcmpi(ct.getname(),name)==0)
                {
                        ct.showcustomer(); flag=1;
                }
        }

        f.close();

        if(flag==0) cout<<"This Customer Doesn't Exist!";

        getch();
}

void modifycustomer()
{
        system("cls");

        int flag = 0;
        char no[6];

        cout<<"Customer Number to be Modified: "; cin>>no;

        f.open("Customers.dat", ios::in | ios::out);
        while(f.read((char*)&ct,sizeof(customer)) && flag==0)
        {
                if(strcmpi(ct.getregno(),no)==0)
                {
                        ct.showcustomer(); flag=1;
                        cout<<endl<<endl;

                        cout<<"Enter the New Details: "<<endl;
                        ct.modifycustomer();

                        int pos=-1*sizeof(ct);
                        f.seekp(pos,ios::cur);
                        f.write((char*)&ct,sizeof(customer));
                }
        }

        f.close();

        if(flag==0) cout<<"This Customer Doesn't Exist!";

        getch();
}

void deletecustomer()
{
        system("cls");

        int flag = 0;
        char no[6];

        cout<<"Customer Registration Number to be Deleted: "; cin>>no;

        f.open("Customers.dat", ios::in | ios::out);

        fstream f2;
        f2.open("temp.dat", ios::out);

        f.seekg(0,ios::beg);
        while(f.read((char*)&ct,sizeof(customer)))
        {
                if(strcmpi(ct.getregno(),no)!=0)
                        f2.write((char*)&ct,sizeof(customer));
                else
                        flag=1;
        }

        f.close();
        f2.close();

        remove("Customers.dat");
        rename("temp.dat","Customers.dat");

        if(flag==0) cout<<"This Customer Doesn't Exist!";
        else if (flag==1) cout<<"Customer Deleted!";

        getch();
}

void deleteallcustomers()
{
        system("cls");

        char ch;

        cout<<"Delete all? Sure? "; cin>>ch;

        if(ch=='y') remove("Customers.dat");
        else editcustomermenu();
}

void displayallcustomers()
{
        system("cls");

        f.open("Customers.dat", ios::in);

        cout<<endl<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"**                              CUSTOMERS LIST                                **"<<endl;
        cout<<"********************************************************************************"<<endl<<endl;
        while(f.read((char*)&ct,sizeof(customer))) ct.report();

        f.close();

        getch();
}

void issuebook()
{
        system("cls");

        char bn[6], cn[6];
        int bflag = 0, cflag = 0;

        f.open("Customers.dat", ios::in | ios::out);
        f1.open("Books.dat", ios::in | ios::out);

        cout<<endl<<"The Customer's Registration: "; cin>>cn;

        while(f.read((char*)&ct,sizeof(customer)) && cflag==0)
        {
                if(strcmpi(ct.getregno(),cn)==0)
                {
                        cflag=1;
                        if(ct.getbook_issued()==0)
                        {
                                cout<<"Book Number to be Issued: "; cin>>bn;
                                while(f1.read((char*)&bk,sizeof(book)) && bflag==0)
                                {
                                        if(strcmpi(bk.getbno(),bn)==0)
                                        {
                                                cout<<endl<<ct.getname()<<" issued Book No. "<<bk.getbno()<<" - "<<bk.getbname();
                                                bflag=1; ct.bookissued();

                                                ct.getcbno(bk.getbno());
                                                ct.getcbname(bk.getbname());

                                                int pos=-1*sizeof(ct);
                                                f.seekp(pos, ios::cur);
                                                f.write((char*)&ct,sizeof(customer));
                                        }
                                }
                                if (bflag==0) cout<<"This Book Doesn't Exist!";
                        }
                        else cout<<"You Haven't Returned the Last Book Yet!";
                }
        }
        if(cflag==0) cout<<"This Customer Doesn't Exist!";

        f.close();
        f1.close();

        getch();
}

void returnbook()
{
        system("cls");

        char bn[6], cn[6];
        int bflag = 0, cflag = 0;

        f.open("Customers.dat", ios::in | ios::out);
        f1.open("Books.dat", ios::in | ios::out);

        cout<<endl<<"The Customer's Registration: "; cin>>cn;

        while(f.read((char*)&ct,sizeof(customer)) && cflag==0)
        {
                if(strcmpi(ct.getregno(),cn)==0)
                {
                        cflag=1;
                        if(ct.getbook_issued()==1)
                        {
                                while(f1.read((char*)&bk,sizeof(book)) && bflag==0)
                                {
                                        if(strcmpi(bk.getbno(),ct.getcbno())==0)
                                        {
                                                cout<<endl<<ct.getname()<<" returned Book No. "<<bk.getbno()<<" - "<<bk.getbname();
                                                bflag=1; ct.bookreturned();

                                                int pos=-1*sizeof(ct);
                                                f.seekp(pos,ios::cur);
                                                f.write((char*)&ct,sizeof(customer));
                                        }
                                }
                                if(bflag==0) cout<<"This Book Doesn't Exist or is Currently Unavailable!";
                        }
                        else cout<<"No Book is Issued! Please Check!";
                }
        }
        if(cflag==0) cout<<"This Customer Doesn't Exist!";

        f.close();
        f1.close();

        getch();

}

void exit()
{
        system("cls");

        cout<<"Thank You for Visiting us at THE STATE LIBRARY!";
        cout<<"\nWe hope you enjoyed your Stay here! Keep Reading!"<<endl;

        getch();
        exit(0);
}
