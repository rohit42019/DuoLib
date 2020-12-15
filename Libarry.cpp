using namespace std;
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstdio>
#include<fstream>
#include<windows.h>
void gotoxy(int x,int y);
//.......................................student class............................................................
class student
{
private:
   unsigned long int stid,rollno;
   int stbkid[10],token;
   unsigned long int doi[10];
    char stname[20],fname[20],course[30],branch[30],gender[5],college[50];
    int getdata_add_student()//************************getdata_add_student()************************
    {
         system("cls");
        ifstream finS;
        finS.open("student.txt",ios::in|ios::binary);
        int temp=0;
        student st;
        int sid;
        cout<<"\n\n\t\t\t\t\t\t\tEnter Student ID : ";
        cin>>sid;
        while((finS.read((char*)&st,sizeof(st))))
        {
            if(sid==st.stid)
            {
                temp++;
            }
        }
        finS.close();
        if(temp>0)
        {
            cout<<"\n\n\t\t\t\t\t\t\t(!!!!Student ID is already taken!!!!) ";
            return(1);
        }
        else
        {
            cout<<"\n\n\t\t\t\t\t\t\tEnter Student Name(without any spaces) : ";
            cin>>stname;
            cout<<"\n\n\t\t\t\t\t\t\tEnter Father's Name(without any spaces) : ";
            cin>>fname;
            cout<<"\n\n\t\t\t\t\t\t\tEnter Course Name(without any spaces): ";
            cin>>course;
            cout<<"\n\n\t\t\t\t\t\t\tEnter Branch Name(without any spaces) : ";
            cin>>branch;
            cout<<"\n\n\t\t\t\t\t\t\tEnter Student's Gender(Male/Female/Others) : ";
            cin>>gender;
            cout<<"\n\n\t\t\t\t\t\t\tEnter College Name(without any spaces) : ";
            cin>>college;
            cout<<"\n\n\t\t\t\t\t\t\tEnter the University Roll Number : ";
            cin>>rollno;
            cout<<"\n\n\t\t\t\t\t\t\tEnter the Number of Book Issued : ";
            cin>>token;
            stid=sid;

            return(0);
        }

    }
    void putdata_student()//******************putdata_student()************************************
    {
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t\tStudent Name : "<<stname;
        cout<<"\n\n\t\t\t\t\t\t\tFather's Name : "<<fname;
        cout<<"\n\n\t\t\t\t\t\t\tUniversity Roll Number : "<<rollno;
        cout<<"\n\n\t\t\t\t\t\t\tCourse Name : "<<course;
        cout<<"\n\n\t\t\t\t\t\t\tBranch Name : "<<branch;
        cout<<"\n\n\t\t\t\t\t\t\tGender : "<<gender;
        cout<<"\n\n\t\t\t\t\t\t\tCollege Name : "<<college;
        cout<<"\n\n\t\t\t\t\t\t\tNumber of Book Issued : "<<token;
        int n;
        cout<<"\n\n\t\t\t\t\t\t\tPress 1 for know all the issue books ID or any other number to return"<<endl;
        cin>>n;
        if(n==1)
        {
            if(token==0)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(!!!No book issued!!!)";
            }
            else if(token>0 && token<10)
            {
                cout<<"\n\n\t\t\t\t\t\t\tBooks ID : "<<endl;
                for(int i=0;i<token;i++)
                {
                    cout<<"\n\n\t\t\t\t\t\t\t"<<i+1<<". "<<stbkid[i]<<endl;
                }
            }
        }
    }
    void show_registered_student()
    {
        cout<<"\n"<<setw(30)<<stid<<setw(40)<<stname<<setw(40)<<fname<<setw(40)<<rollno<<endl;
    }
public:

    int getsid()
    {
        return(stid);
    }
    char* getstname()
    {
        return(stname);
    }
    int gettoken()
    {
        return(token);
    }
    void settoken_issue()
    {
        token=token+1;
    }
    void settoken_return()
    {
        token=token-1;
    }
    void setstbkid_issue(int i,int value)
    {
        stbkid[i]=value;
    }
    int getstbkid_issue(int k)
    {
        return(stbkid[k]);
    }
    void setstbkid_return(int index,int high)
    {
        int temp;
        temp=stbkid[index];
        stbkid[index]=stbkid[high];
        stbkid[high]=temp;
    }
    void set_date_of_issue(int index,unsigned long int isdate)
    {
        doi[index]=isdate;
    }
    int get_date_of_issue(int index)
    {
        return(doi[index]);
    }

   void add_new_student()//*******************add_new_student()*********************************
    {
        ofstream foutS;
        foutS.open("Student.txt",ios::out|ios::app|ios::binary);
        student st;
        int i;
        i=st.getdata_add_student();
        if(i==0)
        {
            foutS.write((char*)&st,sizeof(st));
            cout<<"\n\n\t\t\t\t\t\t\t(Student Successfully Added)";
        }
        foutS.close();
    }
    void view_student_details()//************************view_student_details()************************
    {
        system("cls");
        ifstream finS;
        finS.open("Student.txt",ios::in|ios::binary);
        if(!finS)
        {
            cout<<"\n\n\n\t\t\t\t\t\t\tFile doesn't exists";
        }
        else
        {
            student st;
            int id,temp=0;
            cout<<"\n\n\n\t\t\t\t\t\t\tEnter Student ID : ";
            cin>>id;
            while((finS.read((char*)&st,sizeof(st))))
            {
                if(id==st.stid)
                {
                    st.putdata_student();
                    temp++;
                }
            }
            if(temp==0)
            {
                cout<<"\n\n\n\t\t\t\t\t\t\tStudent ID not Found";
            }
        }
        finS.close();
    }
    void delete_student()//**********************delete_student()*************************************
    {
        ifstream finS;
        int temp=0;
        finS.open("Student.txt",ios::in|ios::binary);
        if(!finS)
        {
            cout<<"\n\n\n\t\t\t\t\t\t\tFile doesn't exist";
        }
        else
        {
            system("cls");
            ofstream foutS;
            student stu;
            gotoxy(55,20);
            int sid;
            cout<<"\n\n\n\t\t\t\t\t\t\tEnter the Student ID : ";
            cin>>sid;
            foutS.open("tempstudent.txt",ios::out|ios::binary);
            while(finS.read((char*)&stu,sizeof(stu)))
            {
                if(sid!=stu.stid)
                {
                    foutS.write((char*)&stu,sizeof(stu));
                }
                else
                {
                    temp++;
                }
            }
            foutS.close();
            finS.close();
            remove("Student.txt");
            rename("tempstudent.txt","Student.txt");
            gotoxy(55,25);
            if(temp>0)
              {
                  cout<<"\n\n\n\t\t\t\t\t\t\tStudent Successfully deleted"<<endl;
              }
              else
              {
                cout<<"Student ID is not present";
              }

        }
    }

    void show_student_details()
    {
        putdata_student();
    }
    void student_registered()
    {
        system("cls");
        student st;
        int t=0;
        ifstream finS;
        finS.open("Student.txt",ios::in|ios::binary);
        if(!finS)
        {
            cout<<"\n\n\t\t\t\t\t\t\t(!!!File doesn't exist!!!)";
        }
        else
        {
            cout<<"\n"<<setw(30)<<"Student ID"<<setw(40)<<"Student Name"<<setw(40)<<"Father's Name"<<setw(40)<<"University ROLL.NO"<<endl;
            cout<<setw(30)<<"__________"<<setw(40)<<"____________"<<setw(40)<<"_____________"<<setw(40)<<"__________________"<<endl;
            while(finS.read((char*)&st,sizeof(st)))
            {
                st.show_registered_student();
                t++;
            }
            if(t==0)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(!!!No Student Registered!!!)";
            }
            else
            {
                cout<<"\n\n\n\t\t\t\t\t\t\tTotal Number of Student Registered : "<<t;
            }
        }
        finS.close();
    }
};
//................................................book class..............................................................
class book
{
    char bname[30];
    char aname[30];
    int bid,quantity;
void getdata()//********************************getdata()**************************************
{
    gotoxy(55,20);
    cout<<"Enter the book name(without any spaces) : ";
    cin>>bname;
    gotoxy(55,25);
    cout<<"Enter the Author name(without any spaces) : ";
    cin>>aname;
    gotoxy(55,30);
    cout<<"Enter the Book ID : ";
    cin>>bid;
    gotoxy(55,35);
    cout<<"Enter the Quantity : ";
    cin>>quantity;
}
void putdata()//********************************putdata()**************************************
{
    cout<<"\n\n"<<setw(15)<<bid<<setw(50)<<bname<<setw(50)<<aname<<setw(30)<<quantity;
}
void show_book_issue_details(int j,student st)
{
   unsigned long int n=st.get_date_of_issue(j);
    int y=n%10000;
    n=n/10000;
    int m=n%100;
    int d=n/100;
    cout<<"\n"<<setw(30)<<bid<<setw(40)<<bname<<setw(40)<<aname<<setw(20)<<d<<"/"<<m<<"/"<<y<<endl;
}
public:

    int getbid()
    {
        return(bid);
    }
    int getquantity()
    {
        return(quantity);
    }
    void setquantity_issue()
    {
        quantity=quantity-1;
    }
    void setquantity_return()
    {
        quantity=quantity+1;
    }
    void issue_book_details(student stud)
    {
        system("cls");
        book bk;
        int i=0;
        ifstream finB;
        finB.open("Book.txt",ios::in|ios::binary);

        if(!finB)
        {
            cout<<"\n\n\t\t\t\t\t\t\t(!!!Book File doesn't exist!!!)";
        }
        else
        {
            cout<<"\n"<<setw(30)<<"Book Id"<<setw(40)<<"Book Name"<<setw(40)<<"Author Name"<<setw(30)<<"Date of Issue"<<endl;
            cout<<setw(30)<<"_______"<<setw(40)<<"_________"<<setw(40)<<"___________"<<setw(30)<<"_____________"<<endl;

                    while(finB.read((char*)&bk,sizeof(bk)))
                    {

                        if(stud.getstbkid_issue(i)==bk.getbid() && i<stud.gettoken())
                        {
                            bk.show_book_issue_details(i,stud);
                            i++;
                        }
                    }

            if(i==0)
            {
                //system("cls");
                cout<<"\n\n\t\t\t\t\t\t\t(!!!!!No Book Issued!!!!!)";
            }
        }
        finB.close();
    }

    void add_new_book()//********************************add_new_book()**************************************
    {
        system("cls");
        book objB;
        ofstream foutB;
        foutB.open("Book.txt",ios::out|ios::app|ios::binary);
        objB.getdata();
        foutB.write((char*)&objB,sizeof(objB));
        cout<<"\n\n\t\t\t\t\t\t\t(Book Successfully Added)";
        foutB.close();
    }
    void view_book_stock()//********************************view_book_stock()**************************************
    {
        system("cls");
        book obj;
        ifstream finB;
        finB.open("Book.txt",ios::in|ios::binary);
        cout<<"\n"<<setw(15)<<"Book Id"<<setw(50)<<"Book Name"<<setw(50)<<"Author Name"<<setw(30)<<"Quantity"<<endl;
        cout<<setw(15)<<"_______"<<setw(50)<<"_________"<<setw(50)<<"___________"<<setw(30)<<"________"<<endl;
        while((finB.read((char*)&obj,sizeof(obj))))
            obj.putdata();
        finB.close();
    }
        void delete_book()//********************************delete_book()**************************************
    {

        ifstream finB;
        ofstream foutB;
        book obj;
        int temp=0;
        int c;
        finB.open("Book.txt",ios::in|ios::binary);
        if(!finB)
        {
            cout<<"\n\n\t\t\t\t\t\t\t(File doesn't exists)";
        }
        else
        {
            system("cls");
        foutB.open("tempbook.txt",ios::out|ios::app|ios::binary);
        gotoxy(55,20);
        cout<<"Enter the book id : ";
        cin>>c;
        while(finB.read((char*)&obj,sizeof(obj)))
              {
                  if(c!=obj.bid)
                  {
                      foutB.write((char*)&obj,sizeof(obj));
                  }
                  else{
                    temp++;
                  }
              }
              finB.close();
              foutB.close();
              remove("Book.txt");
              rename("tempbook.txt","Book.txt");
              gotoxy(55,25);
              if(temp>0)
              {
                  cout<<"(Book Successfully Deleted)"<<endl;
              }
              else
              {
                cout<<"Book ID is not present";
              }

    }
    }

  void book_issue()
    {
        system("cls");
        gotoxy(50,20);
        int bid,sid,count=0,tp=0,tempr=0;
        book bk;
        int tempr2=0;
        student st;

        fstream finS,finB;

        finS.open("Student.txt",ios::in|ios::out|ios::binary);
        if(!finS)
        {
            cout<<"Student file not found";
        }
        else
        {
            cout<<"\tEnter the Student ID : ";
            cin>>sid;
            while(finS.read((char*)&st,sizeof(st)))
            {
                if(sid==st.getsid())
                {

                    finB.open("Book.txt",ios::in|ios::out|ios::binary);
                    if(!finB)
                    {
                        cout<<"\n\n\t\t\t\t\t\t\t(Book File not found)";

                    }
                    else
                    {
                        cout<<"\n\n\t\t\t\t\t\t\tEnter the Book ID ";
                        cin>>bid;
                        while(finB.read((char*)&bk,sizeof(bk)))
                        {
                            if(bid==bk.getbid())
                            {
                               if(st.gettoken()>0 && st.gettoken()<=10)
                               {
                                   for(int i=0;i<st.gettoken();i++)
                                   {
                                       if(st.getstbkid_issue(i)==bk.getbid())
                                       {
                                           tempr2++;
                                           break;
                                       }
                                   }
                               }
                               else if(st.gettoken()>10)
                               {
                                   cout<<"\n\n\t\t\t\t\t\t\t(!!Maximum Limit reached cannot issue more books!!)";
                                   cout<<"\n\n\t\t\t\t\t\t\t(!!Maximum Limit reached cannot issue more books!!)";
                                   count=-1;
                                   break;
                               }
                               else
                               {
                                   tempr2=0;
                               }
                               if(tempr2>0)
                               {
                                   cout<<"\n\n\t\t\t\t\t\t\t(!!!Book already issued!!!)";
                                   count=-1;
                                   break;
                               }
                               else
                               {
                                   if(bk.getquantity()!=0)
                                   {
                                       unsigned long int issuedate;
                                       cout<<"\n\n\t\t\t\t\t\t\tEnter the Date Of Book Issue in (DDMMYYYY)format (without any spaces) "<<endl;
                                       cout<<"\n\n\t\t\t\t\t\t\tExample : 21,november 2000 can be written as 21112000 : ";
                                       cin>>issuedate;
                                       st.set_date_of_issue(st.gettoken(),issuedate);

                                       int j=bk.getbid();
                                       st.setstbkid_issue(st.gettoken(),j);



                                       int pos1=-1*sizeof(st);
                                       finS.seekg(pos1,ios::cur);
                                       st.settoken_issue();
                                       finS.write((char*)&st,sizeof(st));

                                       bk.setquantity_issue();
                                       int pos2=-1*sizeof(bk);
                                       finB.seekg(pos2,ios::cur);
                                       finB.write((char*)&bk,sizeof(bk));







                                       count++;
                                       break;
                                   }
                                   else
                                   {
                                       cout<<"\n\n\t\t\t\t\t\t\t(Book is not available(quantity=0))";
                                       count=-1;
                                       break;
                                   }
                               }

                            }

                        }

                        if(count==0)
                        {
                            cout<<"\n\n\t\t\t\t\t\t\t(Book ID is not present)";
                        }
                        else if(count>0)
                        {
                        cout<<"\n\n\t\t\t\t\t\t\t(Book successfully issued)";
                        }
                        finB.close();

                    }

                        tempr++;
                        break;
                }
            }
            if(tempr==0)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(Student ID not found)";
            }
        }

         finS.close();

    }

    int book_return()
    {
        system("cls");
        gotoxy(50,20);
        int bid,sid,count=0,temp=0,tp=0;
        book bk;
        student st;
        fstream finS,finB;
        finS.open("Student.txt",ios::in|ios::out|ios::binary);
        finB.open("Book.txt",ios::in|ios::out|ios::binary);

        if(!finS)
        {
        cout<<"\n\n\t\t\t\t\t\t\tStudent file doesn't exist";
        }
        else if(!finB)
        {
        cout<<"\n\n\t\t\t\t\t\t\tBook File doesn't exist";
        }
        else
        {
            cout<<"\n\n\t\t\t\t\t\t\tEnter the Student ID : ";
            cin>>sid;
            while(finS.read((char*)&st,sizeof(st)))
            {
                if(sid==st.getsid())
                {
                    cout<<"\n\n\t\t\t\t\t\t\tEnter the Book ID : ";
                    cin>>bid;
                    while(finB.read((char*)&bk,sizeof(bk)))
                    {
                        if(bid==bk.getbid())
                        {
                            if(st.gettoken()==0)
                            {
                                cout<<"\n\n\t\t\t\t\t\t\tNo Book Issued";
                                getch();
                                return(0);
                            }
                            else if(st.gettoken()>0 && st.gettoken()<=10)
                            {
                                for(int i=0;i<st.gettoken();i++)
                                {
                                    if(st.getstbkid_issue(i)==bk.getbid())
                                    {
                                        st.setstbkid_return(i,st.gettoken()-1);


                                        bk.setquantity_return();
                                        int pos=-1*sizeof(bk);
                                        finB.seekg(pos,ios::cur);
                                        finB.write((char*)&bk,sizeof(bk));

                                        st.settoken_return();
                                        pos=-1*sizeof(st);
                                        finS.seekg(pos,ios::cur);
                                        finS.write((char*)&st,sizeof(st));
                                        tp++;
                                        int days,newfine;
                                        cout<<"\n\n\t\t\t\t\t\t\tEnter the Number of days Student have this book : ";
                                        cin>>days;
                                        if(days>20)
                                        {
                                            newfine=(days-20);
                                            cout<<"\n\n\t\t\t\t\t\t\tTotal Fine is : Rs. "<<newfine;
                                        }
                                        else if(days>=0 && days<=20)
                                        {
                                            cout<<"\n\n\t\t\t\t\t\t\tNo Fine";
                                        }
                                        else
                                        {
                                            cout<<"\n\n\t\t\t\t\t\t\tInvalid Number(Days must be positive)";
                                        }
                                        break;
                                    }
                                }
                            }
                            temp++;
                            break;
                        }
                    }
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(!!!Student ID not found!!!)";
            }
            else if(temp==0)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(!!!Book ID not found!!!)";
            }
            else if(tp==0)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(!!!This Book is not issued!!!)";
            }
            else
            {
                cout<<"\n\n\t\t\t\t\t\t\t(Book Successfully Returned)";
            }
        }
        finS.close();
        finB.close();
        return(0);
    }




};
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&Administrator()&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int Administrator()
{
    book b;
    student s,st;
    system("cls");
    string username;
    ifstream finS;
    int n,sid,t;
    char i,g;
    int count=0;
    const int size=80;
    char readUserName[size];
    char readPassword[size];
    string password;

    gotoxy(55,20);
    cout<<"Enter the Username(without any spaces) : ";
    cin>>username;
    ifstream finU,finP;
    finU.open("Usernames.txt",ios::in);
    finP.open("Passwords.txt",ios::in);
    while(finU)
    {
        finU.getline(readUserName,80);
        finP.getline(readPassword,80);

        if(username==readUserName)
        {
            for(n=1;n<=3;n++)
            {
            cout<<"\n\n\n\n\t\t\t\t\t\t\tEnter the Password(without any spaces) : ";
            cin>>password;
            if(password==readPassword)
            {
                cout<<"\n\n\t\t\t\t\t\t\t(Press Any Key) ";
                getch();
                do
                {
                system("cls");
                cout<<"\n\t\t\t\t\t****************Account Holder : "<<username<<"*************"<<endl;
                cout<<"\n\n\t\t\t\t\t\t\t1. Add new book\n\n\t\t\t\t\t\t\t2. Add New Student\n\n\t\t\t\t\t\t\t3. Delete book\n\n\t\t\t\t\t\t\t4. Delete Student\n\n\t\t\t\t\t\t\t5. View Book stock\n\n\t\t\t\t\t\t\t6. View Student Details\n\n\t\t\t\t\t\t\t7. Issue Book\n\n\t\t\t\t\t\t\t8. Return Book\n\n\t\t\t\t\t\t\t9. Issue Book Details\n\n\t\t\t\t\t\t\t10. Press T to know the total number of student registered\n\n\t\t\t\t\t\t\tOr Press R to Return to Main Menu\n\n\t\t\t\t\t\t\tOr Press E to exit"<<endl;
                g=getche();
                switch(g)
                {
                    case '1': b.add_new_book();
                    break;
                    case '2': s.add_new_student();
                    break;
                    case '3': b.delete_book();
                    break;
                    case '4': s.delete_student();
                    break;
                    case '5': b.view_book_stock();
                    break;
                    case '6': s.view_student_details();
                    break;
                    case '7': b.book_issue();
                    break;
                    case '8': b.book_return();
                    break;
                    case '9':
                              finS.open("Student.txt",ios::in|ios::binary);
                              cout<<"\n\n\t\t\t\t\t\t\tEnter the Student ID : ";
                              cin>>sid;
                              while(finS.read((char*)&st,sizeof(st)))
                              {
                                  t=0;
                                  if(sid==st.getsid())
                                  {
                                      b.issue_book_details(st);
                                      t++;
                                      break;
                                  }
                              }
                              if(t==0)
                              {
                                 cout<<"\n\n\t\t\t\t\t\t\t(!!!Student ID not found!!!)";
                              }
                              finS.close();
                    break;
                    case 'T' : s.student_registered();
                    break;
                    case 'R': return(0);
                    break;
                    case 'E': exit(0);

                    default:cout<<"\n\nWrong choice";
                }
                getch();
                }while(g!='E' || g!='e');

                break;
            }
            else
            {
                cout<<"\n\n\t\t\t\t\t\t\tIncorrect Password!!";
                if(n<3)
                    cout<<"\n\n\t\t\t\t\t\t\tYou have only "<<(3-n)<<" chances left to enter the password";
                else if(n==3)
                    cout<<"\n\n\t\t\t\t\t\t\tNo chances left";
            }
            }
            count++;
            finU.close();
            finP.close();
        }

    }
    if(count==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\tError : Username doesn't exist!!";
        return(0);
    }
}
//&&&&&&&&&&&&&&&&&&&&&&&gotozy()&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int Student()
{
    system("cls");
    student st;
    book bk;
    ifstream finS;
    finS.open("Student.txt",ios::in|ios::binary);
    int sid,count=0;
    char ch;
    gotoxy(50,15);
    cout<<"\tEnter the Student ID : ";
    cin>>sid;
    while(finS.read((char*)&st,sizeof(st)))
    {
        if(sid==st.getsid())
        {
            do
            {
                system("cls");
                cout<<"\n\t\t\t\t\t****************Account Holder : "<<st.getstname()<<"*************"<<endl;
                gotoxy(50,15);
                cout<<"\t1. Account Details\n\n\t\t\t\t\t\t\t2. Issue Book Details\n\n\t\t\t\t\t\t\t3. Main Menu\n\n\t\t\t\t\t\t\t4. Exit";
                ch=getche();
                switch(ch)
                {
                    case '1': st.show_student_details();
                    break;
                    case '2': bk.issue_book_details(st);
                    break;
                    case '3': return(0);
                    break;
                    case '4': exit(0);
                    break;
                    default : cout<<"\n\n\t\t\t\t\t\t\t(!!!Wrong choice!!!)";
                }
                getch();
            }while(ch!=5);
            count++;
            break;
        }
    }
    finS.close();
    if(count==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t(!!!Student ID not found!!!)";
    }
    return(0);
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ main()@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
{
    char ch;
    do
    {
    system("cls");
    gotoxy(30,5);
    cout<<"*************************************Welcome To Duo-Lib***********************************";
    gotoxy(55,20);
    cout<<"1. Login as Student"<<endl;
    gotoxy(55,25);
    cout<<"2. Login as Administrator"<<endl;
    gotoxy(55,30);
    cout<<"3. Exit"<<endl;
    ch=getche();
    switch(ch)
    {
        case '1': Student();
        break;
        case '2': Administrator();
        break;
        case '3': exit(0);
        default: cout<<"\n\n \t\t\t\t\t\t(Wrong choice! Try Again)";
    }
    getch();
    }while(ch!='3');
    return(0);
}
