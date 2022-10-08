
#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

class student
{
    string student_name,student_id,student_branch,student_session,date_of_issue,date_of_return;
public:
    student ()
    {
        student_name = "";
        student_id = "";
        student_branch="";
        student_session = "";
        date_of_issue= "";
        date_of_return = "";
    }

};

class book
{
    string author_name,publication_year,branch,book_name,book_id;
    int no_of_same_book;
public:
      book()
      {
         author_name="";
         publication_year="";
         branch="";
         book_name="";
         book_id="";
         no_of_same_book=0;
      }
    void add_book();
    void remove_book();
    void update_book();
    void list_book();
    void borrow_book();
    void return_book();
    void disp_book();

};

void book::disp_book()
{
    cout<<"\n Book id : "<<book_id<<"\n Book Name : "<<book_name<<"\n Author name : "<<author_name<<"\n Branch : "<<branch<<"\n Publication year : "<<publication_year
    <<"\n NO of book "<<no_of_same_book;
}
void book::return_book()
{
    add_book();
}
void book::borrow_book()
{
    cout<<"ENTER BOOK NAME=";
    cin>>book_name;
     cout<<"ENTER BOOK AUTHOR NAME=";
    cin>>author_name;
    cout<<"ENTER BRANCH NAME OF BOOK=";
    cin>>branch;
    no_of_same_book--;

}

void book::add_book()
{
    ofstream fout;
    fout.open("book1.dat");
    //fout <<"\n hell man ";


    cout<<"ENTER BOOK ID=";
    cin>>book_id;
    //fprintf(fp,"%s",book_id);
    fout<<book_id<<"\t";
     cout<<"ENTER BOOK NAME=";
    cin>>book_name;
    fout<<book_name<<"\t";
  //  fprintf(fp,"%s",book_name);
     cout<<"ENTER BOOK AUTHOR NAME=";
    cin>>author_name;
    fout<<author_name<<"\t";
   // fprintf(fp,"%s",author_name);
     cout<<"ENTER BOOK PUBLICATION YEAR=";
    cin>>publication_year;
    fout<<publication_year<<"\t";
 //   fprintf(fp,"%s",publication_year);
     cout<<"ENTER BRANCH NAME OF BOOK=";
    cin>>branch;
    fout<<branch<<"\t";
   // fprintf(fp,"%s",branch);
     cout<<"ENTER NO OF BOOKS=";
    cin>>no_of_same_book;
    fout<<no_of_same_book<<"\t";
   // fprintf(fp,"%d",no_of_same_book);
   fout.close();
}

void book::update_book()
{
    istream fin;
    ofstream fout;

    cout<<"ENTER BOOK ID=";
    cin>>book_id;
     cout<<"ENTER BOOK NAME=";
    cin>>book_name;
     cout<<"ENTER BOOK AUTHOR NAME=";
    cin>>author_name;
     cout<<"ENTER BOOK PUBLICATION YEAR=";
    cin>>publication_year;
     cout<<"ENTER BRANCH NAME OF BOOK=";
    cin>>branch;
     cout<<"ENTER NO OF BOOKS=";
    cin>>no_of_same_book;
}

bool validate_librarian(string a,string b)
{
    if(a=="mca" && b=="12580")
        return true;
    else
        return false;
}

bool validate_student(string a,string b)
{   pair<string,string> pr;
    pr={a,b};
    vector<pair<string,string>> student;
    student.push_back({"sweety","1411999"});
    student.push_back({"sakshi","281999"});
    student.push_back({"praduman","1672001"});
    for(auto it:student)
    {//cout<<it.first<<" "<<it.second<<endl;
    auto pr1=it;
      if(pr1==pr)
        return true;
    }
return false;
}



void LibrarianMenu(){
        cout << "\n*******LIBRARIAN MENU*******" << endl;
        cout<<"1.ADD BOOK"<<endl;
        cout<<"2.REMOVE BOOK"<<endl;
        cout<<"3.UPDATE BOOK"<<endl;
        cout<<"4.LIST OF ALL BOOKS"<<endl;
        cout<<"5.GO TO MAIN MENU"<<endl;
        cout<<"6.EXIT"<<endl;
}

void MainMenu(){
    cout << "\n*******MAIN MENU*******" << endl;
    cout<<"1.LIBRARIAN LOGIN"<<endl;
    cout<<"2.STUDENT LOGIN"<<endl;
    cout<<"3.EXIT"<<endl;
}


void StudentMenu(){
    cout << "\n*******STUDENT MENU*******" << endl;
    cout<<" 1.BORROW A BOOK"<<endl;
    cout<<"2.RETURN A BOOK"<<endl;
    cout<<"3.LIST OF ALL BOOKS"<<endl;
    cout<<"4.GO TO MAIN MENU"<<endl;
    cout<<"5.EXIT"<<endl;
}


////////////////////////////////////////////////////////////////////////////
int main()
{
    book b1;

    int ch,ch1,ch2;

    do{
        MainMenu();
        cout << "Enter your choice" << endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                string user,pass;
                cout << "\n*******LIBRARIAN LOGIN*******" << endl;
                cout<<"1.ENTER USERNAME=";
                cin>>user;
                cout<<"2.ENTER PASSWORD=";
                cin>>pass;

                if(validate_librarian(user,pass))
                {
                    cout<<"librarian login successfully";
                    getch();
                    system("cls");
                        LibrarianMenu();

                    cout<<"ENTER YOUR CHOICE=";
                    cin>>ch1;

                    switch(ch1)
                    {
                        case 1:
                          b1.add_book();
                          break;
                        case 2 :
                        //   b1.remove_book();
                          break;
                        case 3:
                        //   b1.update_book();
                          break;
                        case 4:
                        //   b1.list_book();
                          break;
                        case 5:
                          break;
                        case 6:
                          return 0;

                        default : cout<<"\n Wrong Choice !";
                        break;
                    }
                }

            }
            break;

        case 2:
        {
            string user,pass;
            cout << "\n*******STUDENT LOGIN*******" << endl;
            cout<<"1.ENTER USERNAME=";
            cin>>user;
            cout<<"2.ENTER PASSWORD=";
            cin>>pass;

            if(validate_student(user,pass))
            {   cout<<"student login successfully";
                getch();
                   system("cls");
                    StudentMenu();
                cout<<"ENTER YOUR CHOICE=";
                cin>>ch2;
            }

     /*switch(ch2)
    {
        case 1:
         s1.borrow_book();
         break;
        case 2:
         s1.return_book();
         break;
        case 3:
         s1.list_book();
         break;
        case 4:
         goto label;
         break;
        case 5:
        return 0;
        default :
        cout<<"\n Wrong Choice !";

    }*/
        break;
        }

        case 3:
            return 0;

        default:
            cout<<"wrong choice\n";
    }
    }while(1);
    return 0;
}
