#include<bits/stdc++.h>
using namespace std;
//tao
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};

void duyet(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int sz(node *head){
    int dem=0;
    while(head!=NULL){
        ++dem;
        head=head->next;
    }
    return dem;
}

void themdau(node *&head, int x){
    node *newnode=new node(x);
    newnode->next=head;
    head=newnode;
}

void themcuoi(node *&head, int x){
    node *newnode=new node(x);
    node *tmp=head;
    if(head==NULL){
        head=newnode;
        return;
    }
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newnode;
}

void themgiua(node *&head, int x, int k){
    if(k<1 ||k>sz(head)+1){
        return;
    }
    node *newnode=new node(x);
    node *tmp=head;
    if(k==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
}

void xoadau(node *&head){
    if(head==NULL){
        return;
    }
    node *tmp=head;
    head=head->next;
    delete tmp;
}

void xoacuoi(node *&head){
    if(head==NULL){
        return;
    }
    node *tmp=head;
    if(head->next==NULL){
        delete tmp;
        head=NULL;
        return;
    }
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    node *cuoi=tmp->next;
    tmp->next=NULL;
    delete cuoi;
}

void xoagiua(node *&head, int k){
    if(k<1 ||k>sz(head)+1){
        return;
    }
    node *tmp=head;
    if(k==1){
        head=head->next;
        delete tmp;
    }
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;
    }
    node *xoa=tmp->next;
    tmp->next=tmp->next->next;
    delete xoa;
}

int main(){
    node *x=new node(1);
    node *y=new node(2);
    node *z=new node(3);
    x->next=y;
    y->next=z;
    // int a;
    // cin>>a;
    int k;
    cin>>k;
    xoagiua(x,k);
    duyet(x);
}