#include <bits/stdc++.h>
using namespace std;

// Hàm gộp hai mảng con đã sắp xếp: a[l..m] và a[m+1..r]
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng tạm
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Gộp hai mảng L và R vào mảng chính a
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Chép các phần tử còn lại của L (nếu có)
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Chép các phần tử còn lại của R (nếu có)
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

// Hàm Merge Sort chính (Gọi đệ quy)
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Vị trí giữa

        mergeSort(a, l, m);      // Sắp xếp nửa bên trái
        mergeSort(a, m + 1, r);  // Sắp xếp nửa bên phải

        merge(a, l, m, r);       // Trộn 2 nửa lại với nhau
    }
}

int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}