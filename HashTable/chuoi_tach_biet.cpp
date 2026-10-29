#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 7;
vector<int> hashTable[SIZE];

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunc(key);
    hashTable[index].push_back(key);
}

bool search(int key) {
    int index = hashFunc(key);
    for (int x : hashTable[index]) {
        if (x == key) return true;
    }
    return false;
}

void removeKey(int key) {
    int index = hashFunc(key);
    for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
        if (*it == key) {
            hashTable[index].erase(it);
            return;
        }
    }
}

int main() {
    insert(10);
    insert(17); // Trùng vị trí băm với 10 (10 % 7 = 3, 17 % 7 = 3)

    cout << "Tim 17: " << (search(17) ? "Co" : "Khong") << endl;

    removeKey(17);
    cout << "Tim 17 sau khi xoa: " << (search(17) ? "Co" : "Khong") << endl;

    return 0;
}