//this is simple implementation of stack data structure.
#include <bits/stdc++.h>
using namespace std;

class StackArray {
    int *arr;
    int topIdx;
    int cap;
public:
    explicit StackArray(int capacity)
        : arr(new int[capacity]), topIdx(-1), cap(capacity) {}

    ~StackArray() { delete[] arr; }

    bool empty() const { return topIdx == -1; }           // O(1)
    bool full()  const { return topIdx == cap - 1; }      // O(1)
    int  size()  const { return topIdx + 1; }             // O(1)

    void push(int x) {                                     // O(1)
        if (full()) throw runtime_error("Stack overflow");
        arr[++topIdx] = x;
    }

    int pop() {                                            // O(1)
        if (empty()) throw runtime_error("Stack underflow");
        return arr[topIdx--];
    }

    int peek() const {                                     // O(1)
        if (empty()) throw runtime_error("Stack is empty");
        return arr[topIdx];
    }
};

int main() {
    StackArray st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.peek() << "\n";
    cout << "Popped: " << st.pop() << "\n";
    cout << "Top: " << st.peek() << "\n";
    cout << "Size: " << st.size() << "\n";
    cout << "Empty? " << boolalpha << st.empty() << "\n";
    return 0;
}
