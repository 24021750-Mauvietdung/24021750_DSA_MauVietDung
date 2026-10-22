#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};

struct Stack{
    node *head=NULL;
    int sz=0;
    bool empty(){
        return head==NULL;
    }
    void push(int x){
        node *newnode=new node(x);
        newnode->next=head;
        head=newnode;
        sz++;
    }
    void pop(){
        if(empty()){
            return;
        }
        node *tmp=head;
        head=head->next;
        delete tmp;
        sz--;
    }
    int top(){
        if(empty()){
            cout<<"KO CO PHAN TU";
            return -1;
        }
        return head->data;
    }
    int size(){
        return sz;
    }
};
int main(){
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.pop();
    // while(!a.empty()){
    //     cout<<a.top()<<" ";
    //     a.pop();
    // }
    cout<<a.top();
}