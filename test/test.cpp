#include <iostream>
#include <cxxabi.h>
#include "gdv/gdv.h"

int main() {
    using ta0 = type_list<int, const char, double>;
    using ta1 = type_list<short, volatile wchar_t, bool>;
    int status{};
    std::cout << typeid(at<0, ta0>::type).name() << std::endl;
    std::cout <<count<int, ta0>::value << std::endl;
    std::cout <<count_if<std::is_const, ta0>::value << std::endl;
    std::cout << typeid(concat<ta0, ta1>::type).name() << std::endl;
    std::cout <<all_of<std::is_const, type_list<const int>>::value << std::endl;
    std::cout << typeid(push_front<int, ta0>::type).name() << std::endl;
    std::cout <<empty<type_list<int>>::value << std::endl;
    std::cout << abi::__cxa_demangle(typeid(remove_if<std::is_const, ta0>::type).name(), 0, 0, &status) << std::endl;

    return 0;
}
