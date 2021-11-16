
#include <iostream>

template<class T>
concept Meowable2 = requires(T x) {
    x.val;
    sizeof(T::val2) > 1;
};

template<Meowable2 X>
void test(X x) {
    std::cout << "val1 = " << x.val << std::endl; // check x.val completion
}

auto test2(Meowable2 auto y) { // <- MSVC doesn't support terse syntax
    std::cout << "val2 = " << y.val2 << std::endl; // check y.val2 completion
}

template<class T>
concept NewMeowable = Meowable2<T> && requires(T t){ t.foo(); };

template<class T> requires NewMeowable<T>
class C {
public:
    NewMeowable auto bar(T t) { return t.foo(); } // check t.val, t.foo() completion
};

struct S {
    int val;
    int val2;

    S foo() { return S{};}
};

int main() {
    test(S{42});
    test2(S{42, 43});
    C<S> c;
    c.bar(S{});

    return 0;
}