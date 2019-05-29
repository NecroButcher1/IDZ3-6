#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "Merge.h"
using namespace std;
void menu();
int main()
{
    stack<int> s1,s2,result;
    int check(0),value,size(0);
    while(check!=7){
        menu();
        cin>>check;
        while((!cin)||(check<1)||(check>7)){
            system("cls");
            cin.clear();
            cin.ignore(32767,'\n');
            menu();
            cin>>check;
        }
        if(check==1){
            system("cls");
            s1.doEmpty();
            cout<<"Press size stack >>";
            cin>>size;
            while((!cin)||(size<1)){
                system("cls");
                cin.clear();
                cin.ignore(32767,'\n');
                cout<<"Press size stack >>";
                cin>>size;
            }
            int max=INT_MAX;
            for(size_t i=0;i<size;i++){
                system("cls");
                cout<<"press"<<i<<" elem >>";
                cin>>value;
                while((!cin)||(value>max)){
                    system("cls");
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"press"<<i<<" elem >>";
                    cin>>value;
                }
                max=value;
                s1.push(value);
            }
            check=0;
        }
        if(check==2){
             system("cls");
            s2.doEmpty();
            cout<<"Press size stack >>";
            cin>>size;
            while((!cin)||(size<1)){
                system("cls");
                cin.clear();
                cin.ignore(32767,'\n');
                cout<<"Press size stack >>";
                cin>>size;
            }
            int min=INT_MIN;
            for(size_t i=0;i<size;i++){
                system("cls");
                cout<<"press"<<i<<" elem >>";
                cin>>value;
                while((!cin)||(value<min)){
                    system("cls");
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"press"<<i<<" elem >>";
                    cin>>value;
                }
                min=value;
                s2.push(value);
            }
            check=0;
        }
        if(check==3){
            system("cls");
            if(s1.empty())cout<<"stack 1 is empty"<<endl;
            else{
                stack<int> buff(s1);
                while(!buff.empty()){
                    buff.pop(value);
                    cout<<value<<" ";
                }
            }
            cout<<endl;
            check=0;
        }
        if(check==4){
            system("cls");
            if(s2.empty())cout<<"stack 2 is empty"<<endl;
            else{
                stack<int> buff(s2);
                while(!buff.empty()){
                    buff.pop(value);
                    cout<<value<<" ";
                }
            }
            cout<<endl;
            check=0;
        }
        if(check==5){
            system("cls");
            unsigned checker=Merge(s2,s1,result);
            if(checker==0)cout<<"Sort"<<endl;
            if(checker==1)cout<<"1 stack empty";
            if(checker==2)cout<<"2 stack empty";
            check=0;
        }
        if(check==6){
            system("cls");
            if(result.empty())cout<<"result"<<endl;
            else{
                stack<int> buff(result);
                while(!buff.empty()){
                    buff.pop(value);
                    cout<<value<<" ";
                }
            }
            cout<<endl;
            check=0;
        }
    }
    return 0;
}
void menu(){cout<<"===================<<"<<endl<<"[1.fill 1 stack"<<endl<<"2.fill 2 stack"<<endl<<"3.see 1 stack"<<endl
                <<"4.see 2 stack"<<endl<<"5.merge"<<endl<<"6.check result"<<endl<<"7.exit]"<<endl;
}
