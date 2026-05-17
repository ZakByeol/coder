#include <iostream>
using namespace std;

void display(){
    cout<<"전역범위의 함수가 호출되었습니다."<<endl;
}

namespace MyNamespace {
    void display() {
        cout << "Hello from MyNamespace!" << endl;
    }
}

namespace AnotherNamespace {
    void display() {
        cout << "Hello from AnotherNamespace!" << endl;
    }
    namespace MyNamespace {
        void display2() {
            cout << "Hello from AnotherNamespace::MyNamespace!" << endl;
        }
    }
}   

int main() {
    int num = 5;


    MyNamespace::display();
    AnotherNamespace::display();
    ::display();
    // MyNamespace::display2(); 안됨
    AnotherNamespace::MyNamespace::display2();

    return 0;
}