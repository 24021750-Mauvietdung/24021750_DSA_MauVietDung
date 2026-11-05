#include <iostream>
#include <algorithm> // Dùng cho hàm swap
using namespace std;

// Hàm phân hoạch Lomuto: Đưa pivot về đúng vị trí
int partition(int a[], int l, int r) {
    int pivot = a[r]; // Chọn phần tử cuối cùng làm chốt (pivot)
    int i = l - 1;    // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]); // Đẩy phần tử nhỏ hơn/bằng pivot về phía trái
        }
    }
    // Đưa pivot về đúng vị trí giữa (i + 1)
    swap(a[i + 1], a[r]);
    return (i + 1); // Trả về vị trí của pivot
}

// Hàm Quick Sort chính (Gọi đệ quy)
void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r); // Vị trí của pivot sau phân hoạch

        quickSort(a, l, p - 1);     // Sắp xếp đoạn bên trái pivot
        quickSort(a, p + 1, r);     // Sắp xếp đoạn bên phải pivot
    }
}

int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}