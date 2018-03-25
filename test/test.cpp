#include <iostream>
#include <cxxabi.h>
#include "gdv/gdv.h"

template <class Ty> class TypeNameString {
public:
    TypeNameString() {
        int status{};
        name_ = abi::__cxa_demangle(typeid(Ty).name(), 0, 0, &status);
    }
    ~TypeNameString() {free(name_);}
    operator const char* () {return name_;}
private:
    char *name_;
};

template <class ...T>
struct f {};
template <template<class> class F>
struct func {
    using type = F<double>;
};

int main() {
    using ta0 = TypeList<int, const char, double>;
    using ta1 = TypeList<int, PlaceHolder<1>, PlaceHolder<0>, const char, double>;

    std::cout << Min<ta0> << std::endl;
    std::cout << Empty<ta0> << std::endl;
    std::cout << TypeNameString<Head<ta0>>() << std::endl;
    std::cout << TypeNameString<Replace<ta0, int, float>>() << std::endl;
//    std::cout << TypeNameString<replace_placeholder<0, ta1, type_list<int, float>>::type>() << std::endl;
//    std::cout << TypeNameString<func<Bind<f, int>>::type>() << std::endl;

    return 0;
}
