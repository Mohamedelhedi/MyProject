#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class library
{
    char bookname[100],author_name[50],Id_book[20],publication[50];
    int quantity,price;
    public:
        library()
        {
            strcpy(bookname,"");
            strcpy(author_name,"");
            strcpy(Id_book,"");
            strcpy(publication,"");
            quantity=0;
            price=0;
        }
          void Member();
          void administrator();
          void get();
          void password();
          void password_change();
          void get_data();
          void booklist(int);
          void modify();
          void show_book(int);
          void see(int);
          int branch(int);
          void Remove_member();
          void Create_member();
          void Modify_member ();

};
void library::get()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Students\n\n\t\t2.Administrator\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            Member();
        }
        else if(i==2)
            password();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :";
            getch();
            system("CLS");
           get();
        }
}
void library::Member()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :";
                getch();
                system("cls");
                Member();
            }
}
void library::password()
{
    int i=0;
    char ch,st[21],ch1[21]={"ENSI"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        administrator();

    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        get();
    }
}
void library::booklist(int i)
{
    int j;
    system("cls");
    cout<<"\t\t********Welecome to the booklist********\n"<<endl;
    cout<<"\t\tThe booklist is in maintenance now\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\n\t\t1.Go to main menu\n\n\t\t2.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>j;
    if (j==1)
    {
        system("cls");
        get();
    }
    else if (j==2)
    {
        system("cls");
        exit(0);
    }
    else
    {
        cout<<"\n\t\tYour choice is wrong :\n ";
        getch();
        booklist(0);
    }


}
void library::see(int i)
{
    string c;
    system("cls");
    cout<<"this is the book"<<endl;
    cout<<"\n\t\tDo you want to come back to menu or to exit ?"<<endl<<"\n\t\tpress \"M\" for menu or \"E\" to leave"<<endl<<"\n\t>>>>Your choice is : ";
    c=getch();
    while(1)
    {


    if (c=="M")
    {
         system("cls");
         get();
    }
    else if (c=="E")
        exit(0);
    else
    {
        cout<<"your choice is wrong please repeat ... "<<endl;
        getch();
        system("cls");
        see(1);
    }
    }


}
void library::administrator()
{
    int i;
    cout<<"\t\t *-*-*-*-*-*-Welecome Administrator *-*-*-*-*-*-\n"<<endl;
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Go to main menu\n\n\t\t5.Change Password\n\n\t\t6.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
     switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:system("cls");
                     get();
                     break;
            case 5:password_change();
                    break;
            case 6:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            administrator();
}
}
void library::modify()
{
   int j;
    system("cls");
    cout<<"\t\tYou can't neither modify nor add a book .there is maintenance\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.Return\n\n\t\t2.Go to main menu\n\n\t\t3.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>j;
    if (j==1)
    {
        system("cls");
        administrator();
    }
    else if (j==2)
    {
         system("cls");
        get();
    }
    else if (j==3)
    {
        system("cls");
        exit(0);
    }
    else
    {
        cout<<"\n\t\tYour choice is wrong :\n ";
        getch();
        modify();
    }

}
void library::password_change()
{
    int j;
    system("cls");
    cout<<"\t\tYou can't change your password now.there is maintenance\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.Return\n\n\t\t2.Go to main menu\n\n\t\t3.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>j;
    if (j==1)
    {
        system("cls");
        administrator();
    }
    else if (j==2)
    {
         system("cls");
        get();
    }
    else if (j==3)
    {
        system("cls");
        exit(0);
    }
    else
    {
        cout<<"\n\t\tYour choice is wrong :\n ";
        getch();
        password_change();
    }
}
int main()
{
    library objet;
    objet.get();
    getch();
    return 0;
}
