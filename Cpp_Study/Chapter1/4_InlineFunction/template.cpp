#include <iostream>
using namespace std; // std:: is required for cout, cin, endl, string, etc

template <typename T>
inline T square(T x) {
    return x * x;
}

// 인클라인 함수의 단점, 매크로함수 처럼 매개변수의 타입이 고정되지 않음
// 따라서 템플릿을 활용하여 매개변수의 타입을 유연하게 처리할 수 있다!
