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



template <size_t I>
struct placeholder {
    static constexpr size_t value = I;
};

template <size_t I, class Ty, class Args>
struct replace_placeholder;
template <size_t I, class ...Ty, class ArgHead, class ...ArgTail>
struct replace_placeholder<
    I,
    type_list<Ty...>,
    type_list<ArgHead, ArgTail...>> :
    std::conditional<
        contain<type_list<Ty...>, placeholder<I>>,
        typename replace_placeholder<
            I + 1,
            replace<type_list<Ty...>, placeholder<I>, ArgHead>,
            type_list<ArgTail...>
        >::type,
        typename std::conditional<
            empty<type_list<ArgHead, ArgTail...>>,
            type_list<Ty...>,
            push_back<type_list<Ty...>, ArgHead, ArgTail...>
        >::type
    > {};
template <size_t I, class ...Ty>
struct replace_placeholder<I, type_list<Ty...>, type_list<>> {
    using type = type_list<Ty...>;
};


/*template <template<class...> class Function, class ...Ty>
struct bind {
    template <class ...Args>
    using type = transfer<typename replace_placeholder<0, type_list<Ty...>, type_list<Args...>>::type, Function>;
};


template <class ...Ty>
struct f {
    using type = type_list<Ty...>;
};
template <template<class, class> class Function>
struct func {
    using type = typename Function<size_t, wchar_t>::type;
};

struct test {
    using type = struct {};
};

template <template<class...> class Function, class ...Ty>
using bnd = typename bind<Function, Ty...>::type;
*/
int main() {
    using ta0 = type_list<int, const char, double>;
    using ta1 = type_list<int, placeholder<1>, placeholder<0>, const char, double>;

    std::cout << min<ta0> << std::endl;
    std::cout << empty<ta0> << std::endl;
    std::cout << TypeNameString<head<ta0>>() << std::endl;
    std::cout << TypeNameString<replace<ta0, int, float>>() << std::endl;
    std::cout << TypeNameString<replace_placeholder<0, ta1, type_list<int, float>>::type>() << std::endl;
//    std::cout << TypeNameString<func<bnd<f, int, placeholder<1>, placeholder<0>, const char, double>>::type>() << std::endl;

    return 0;
}
