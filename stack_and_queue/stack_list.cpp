#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Cấu trúc List dựa trên mảng tĩnh
struct List {
    int data[MAX];
    int size = 0;
};

// Cài đặt Stack bọc bên ngoài List
struct Stack {
    List L;

    // 1. Kiểm tra Stack rỗng - O(1)
    bool empty() {
        return L.size == 0;
    }

    // 2. Thêm phần tử vào đỉnh Stack (Thêm vào CUỐI mảng) - O(1)
    void push(int x) {
        if (L.size >= MAX) {
            cout << "Stack da day (Overflow)!\n";
            return;
        }
        L.data[L.size] = x; 
        L.size++;
    }

    // 3. Xóa phần tử ở đỉnh Stack (Xóa ở CUỐI mảng) - O(1)
    void pop() {
        if (empty()) {
            cout << "Stack rong, khong the pop!\n";
            return;
        }
        L.size--; 
    }

    // 4. Xem giá trị phần tử ở đỉnh Stack - O(1)
    int top() {
        if (empty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return L.data[L.size - 1]; 
    }

    // 5. Lấy kích thước Stack - O(1)
    int size() {
        return L.size;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Kich thuoc Stack: " << st.size() << endl; 
    cout << "Phan tu tren dinh (top): " << st.top() << endl;

    st.pop();
    cout << "Sau khi pop, top hien tai: " << st.top() << endl;

    cout << "Lay va in het phan tu ra khoi Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}