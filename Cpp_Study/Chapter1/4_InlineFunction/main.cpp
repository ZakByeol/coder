#include <iostream>
using namespace std; // std:: is required for cout, cin, endl, string, etc

// Inline function example
// 매크로 함수의 실행속도 이점은 가져가되, 정의의 복잡성이란 단점은 제거함!
inline int square(int x) {
    return x * x;
}

int main() {
    int num = 5;
    cout << "The square of " << num << " is: " << square(num) << endl;

    return 0;
}