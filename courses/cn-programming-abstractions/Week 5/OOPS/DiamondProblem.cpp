#include<iostream>
using namespace std;

class A {
    public:
    A() {
        cout << "A's default cons\n";
    }

    void print() {
        cout << "A's print fn\n";
    }
};
class B : virtual public A {
    public:
    B() {
        cout << "B's default cons\n";
    }
    void print() {
        cout << "B's print fn\n";
    }
};
class C : virtual public A {
    public:
    C() {
        cout << "C's default cons\n";
    }
    void print() {
        cout << "C's print fn\n";
    }
};
class D : public B, public C {
    public:
    D() {
        cout << "D's default cons\n";
    }
    /*void print() {
        cout << "D's print fn\n";
    }*/
};

int main() {
    D d;
    d.A :: print();
}