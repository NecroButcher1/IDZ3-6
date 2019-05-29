#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
using namespace std;
#include "Stack.h"

/**
 * Совмещает два стека в один.
 * Элементы в стеках упорядочены от дна к вершине.
 *
 * @param s1 стек с элемнтами по невозрастанию.
 * @param s2 стек с элемнтами по неубыванию.
 * @param res стек, состоящий из всех элементов стеков a и b,
 * упорядоченных по невозрастанию.
 * @return код ошибки: 0 - нет ошибок.
 */
 template<typename T>
unsigned Merge(stack<T> s1, stack<T> s2, stack<T> &res) {
    res.doEmpty();
    unsigned out_value=0;
    stack<int> buff_stack;
    T buff_value1,buff_value2;
    if(s1.empty())out_value=1;
    else{
        if(s2.empty())out_value=2;
        else{
            stack<int> tmp1(s1);
            stack<int> tmp2(s2);
            while(!s1.empty()){//(!s2.empty())){
                s1.pop(buff_value1);
                buff_stack.push(buff_value1);
            }

            size_t res_size=buff_stack.getSize()+s2.getSize();
            size_t i=0;
            while(i<res_size){
                if(!s1.empty())buff_value1=s1.top();
                if(!s2.empty())buff_value2=s2.top();
                if((buff_value1<=buff_value2)&&(!buff_stack.empty())){
                        buff_stack.pop(buff_value1);
                        res.push(buff_value1);
                   }
                else if((buff_value1>=buff_value2)&&(!s2.empty())){
                        s2.pop(buff_value2);
                        res.push(buff_value2);
                    }
                if((s2.empty())&&(!buff_stack.empty())){
                    buff_stack.pop(buff_value1);
                    res.push(buff_value1);
                }
                if((!s2.empty())&&(buff_stack.empty())){
                    s2.pop(buff_value2);
                    res.push(buff_value2);
                }
                i++;
            }
            s1.doEmpty();
            s2.doEmpty();
            while(!tmp1.empty()){
                tmp1.pop(buff_value1);
                s1.push(buff_value1);
            }
            while(!tmp2.empty()){
                tmp2.pop(buff_value1);
                s2.push(buff_value1);
            }
        }
    }
    return out_value;
}

#endif // SORT_H_INCLUDED
