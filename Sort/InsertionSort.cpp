#include<bits/stdc++.h>
using namespace std;

void insertionsort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionsort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}