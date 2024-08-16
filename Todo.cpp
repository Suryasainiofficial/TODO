#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct todolist{
    int id;
    string task;
};
int ID;
void banner();
void addtask();
void showtask();
int searchtask();
void deletetask();
void updatetask();
int main()
{
system("cls");
while(true)
{
    banner();
    cout<<"\n  1.Add Task";
    cout<<"\n  2.Show Task";
    cout<<"\n  3.Search Task";
    cout<<"\n  4.Delete Task";
    cout<<"\n  5.Update Task";
    int choice;
    cout<<" \n Enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:addtask();
        break;
        case 2:showtask();
        break;
        case 3:searchtask();
        break;
        case 4:deletetask();
        break;
        case 5:updatetask();
        break;
        default:
        break;
    }
    
}
return 0;
}

void banner(){
    cout<<"\n___________________________________"<<endl;
    cout<<"\n \t \t  MYTODO"<<endl;
    cout<<"\n_____________________________________"<<endl;

}
void addtask(){
    system("cls");
    banner();
    todolist todo;
    cout<<"enter new task:"<<endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout<<"SAVE?y/n"<<endl;
    cin>>save;
    if(save=='y'){
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();
        char more;
        cout<<"\n add more task? (y/n)";
        cin >>more;
        if(more=='y'){
            addtask();
        }
        else{
            system("cls");
            cout<<"\n added succesfully"<<endl;
            return;
        }

    }

system("cls");

}

void showtask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"task:"<<endl;

    while(!fin.eof())
    {
fin>>todo.id;
fin.ignore();
getline(fin,todo.task);
if(todo.task !=""){
    cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
}
else{
    cout<<"\t empty!"<<endl;
}

    }
    fin.close();
    char exit;
    cout<<"Exit?(y/n):";
    cin>>exit;
    if(exit !='y'){
showtask();
    }
    system("cls");
}



int searchtask()
{
system("cls");
banner();
int id;
cout<<"\n enter task id";
cin>>id;
todolist todo;
ifstream fin("todo.txt");
while(!fin.eof())
{
    fin>>todo.id;
    fin.ignore();
    getline(fin, todo.task);
    if(todo.id ==id)
    {
        system("cls");
        cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
        return id;


    }
}
system("cls");
cout<<"not found"<<endl;
return 0;

}






void deletetask()
{
system("cls");
int id = searchtask();
if(id!=0)
{
    char del;
    cout<<"\n \t Delete? (y/n)";
    cin>>del;
    if(del=='y')
    {
        todolist todo;
        ofstream tempfile;
        tempfile.open("tempfile.txt");
        ifstream fin;
        fin.open("todo.txt");
        int index=1;
        while(!fin.eof())
        {
            fin>>todo.id;
            fin.ignore();
            getline(fin, todo.task);
            if(todo.id!=id)
            {
                tempfile<<"\n"<<index;
                tempfile<<"\n"<<todo.task;
                index++;
                ID--;
            }
        }
        fin.close();
        tempfile.close();
        remove("todo.txt");
        rename("temp.txt","todo.txt");
        system("cls");
        cout<<"\n \t Deleted succesfully!"<<endl;
    }
    else
    {
system("cls");
cout<<"Task is not deleted"<<endl;
    }
}

}





void updatetask()
{
    system("cls");
    int id =searchtask();
char upd;
cout<<"\n \t Update?y/n";
cin>>upd;
if(upd=='y')
{

todolist ntodo;
cout<<"enter new task "<<endl;
cin.get();
getline(cin,ntodo.task);

    todolist todo;
    ofstream tempfile;
    tempfile.open("tempfile.txt");
    ifstream fin;
    fin.open("todo.txt");
    while(!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id!=id)
        {
            tempfile<<"\n"<<todo.id;
            tempfile<<"\n"<<todo.task;
        }
        else
        {  
            tempfile<<"\n"<<todo.id;
            tempfile<<"\n"<<ntodo.task;
        }
    }
    fin.close();
    tempfile.close();
    remove("todo.txt");
    rename("tempfile.txt","todo.txt");
    system("cls");
    cout<<"\n \t updated successfully"<<endl;



}
    
    else{
        system("cls");
        cout<<"\n \t task is not updated"<<endl;
        return;
    }
}