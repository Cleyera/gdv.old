#include <iostream>
#include <cxxabi.h>
#include "gdv/gdv.h"

int main() {
    using ta0 = type_list<int, const char, double>;
    //using ta1 = type_list<short, volatile wchar_t, bool>;
    int status{};
    /*std::cout << typeid(at<ta0, 0>::type).name() << std::endl;
    std::cout << count<ta0, int>::value << std::endl;
    std::cout << count_if<ta0, std::is_const>::value << std::endl;
    std::cout << typeid(concat<ta0, ta1>::type).name() << std::endl;
    std::cout << all_of<type_list<const int>, std::is_const>::value << std::endl;
    std::cout << typeid(push_front<ta0, int>::type).name() << std::endl;
    std::cout << empty<type_list<int>>::value << std::endl;
    std::cout << abi::__cxa_demangle(typeid(remove_if<std::is_const, ta0>::type).name(), 0, 0, &status) << std::endl;
*/
    std::cout << min<ta0> << std::endl;
    std::cout << abi::__cxa_demangle(typeid(head<ta0>).name(), 0, 0, &status) << std::endl;

    return 0;
}
