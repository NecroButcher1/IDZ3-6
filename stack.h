#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
template<typename T>
class stack{
private:
    struct node{
        T data;
        node* next;
    };
    node *ptr;
    size_t size;
public:
    stack():ptr(NULL),size(0){};
    stack(stack<T> *tmp){
        stack<T> tmp1;
        T value;
        while(!tmp.empty()){
            tmp.pop(value);
            tmp1.push(value);
            push(value);
        }
        while(!tmp1.empty()){
            tmp1.pop(value);
            tmp.push(value);
        }
    }
    void push(T _data){
        node* new_ptr= new node;
        new_ptr->next=ptr;
        new_ptr->data=_data;
        size++;
        ptr=new_ptr;
    }
    void pop(T &_data){
        if(!empty()){
            size--;
            _data=ptr->data;
            ptr=ptr->next;
        }
    }
    void pop(){
        if(!empty()){
            size--;
            ptr=ptr->next;
        }
    }
    T top(){return ptr->data;}
    void doEmpty(){while(!empty())ptr=ptr->next;size=0;}
    bool operator==(stack<T> &equal){
        bool eq=false;
        stack<T> tmp1=equal;
        stack<T> tmp2=*this;
        if(equal.getSize()!=getSize())eq=false;
        else{
            while((!tmp1.empty())&&(!tmp2.empty())){
                if(tmp1.ptr->data!=tmp2.ptr->data)eq=false;
                tmp1.pop();
                tmp2.pop();
            }
        }
        return eq;
    }
    void operator=(stack<T> &input){
        doEmpty();
        stack<T> tmp1(input);
        stack<T> tmp2;
        T value;
        while(!tmp1.empty()){
            tmp1.pop(value);
            tmp2.push(value);
            push(value);
        }
        while(!tmp2.empty()){
            tmp2.pop(value);
            tmp1.push(value);
        }
    }
    bool operator!=(stack<T> *equal){return !operator==(equal);}
    bool empty(){return(!ptr)?true:false;}
    size_t getSize(){return size;}
    ~stack(){
        doEmpty();
    }
};


#endif // STACK_H_INCLUDED
