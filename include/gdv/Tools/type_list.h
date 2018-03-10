#ifndef GDV_TYPE_LIST_H_
#define GDV_TYPE_LIST_H_

#include <type_traits>

namespace gdv {

template <class ...Ty>
struct type_list{};

//receive----------------------------------------------------------------------
template <template <class...> class Ty, class ...Elm>
struct receive;
template <template <class...> class Ty, class ...Elm>
struct receive<Ty, type_list<Elm...>> {
    using type = Ty<Elm...>;
};


//max--------------------------------------------------------------------------
template <class Head, class ...Tail>
struct max;
template <class Head, class ...Tail>
struct max <type_list<Head, Tail...>> {
    static constexpr size_t value =
        sizeof(Head) > max<type_list<Tail...>>::value ?
        sizeof(Head) : max<type_list<Tail...>>::value;
};
template <>
struct max<type_list<>> {
    static constexpr size_t value = 0;
};

//min--------------------------------------------------------------------------
template <class Head, class ...Tail>
struct min;
template <class Head, class ...Tail>
struct min <type_list<Head, Tail...>> {
    static constexpr size_t value =
        sizeof(Head) < min<type_list<Tail...>>::value ?
        sizeof(Head) : min<type_list<Tail...>>::value;
};
template <class Ty>
struct min<type_list<Ty>> {
    static constexpr size_t value = sizeof(Ty);
};



//size-------------------------------------------------------------------------
template <class ...Ty>
struct size {
    static constexpr size_t value = sizeof...(Ty);
};
template <class ...Ty>
struct size<type_list<Ty...>> {
    static constexpr size_t value = sizeof...(Ty);
};


//empty-------------------------------------------------------------------------
template <class Head, class ...Tail>
struct empty;
template <class Head, class ...Tail>
struct empty<type_list<Head, Tail...>> {
    static constexpr bool value = false;
};
template <>
struct empty<type_list<>> {
    static constexpr bool value = true;
};


//head-------------------------------------------------------------------------
template <class Head, class ...Tail>
struct head {
    using type = Head;
};
template <class Head, class ...Tail>
struct head<type_list<Head, Tail...>> {
    using type = Head;
};


//tail-------------------------------------------------------------------------
template <class Head, class ...Tail>
struct tail;
template <class Head, class ...Tail>
struct tail<type_list<Head, Tail...>> {
    using type = type_list<Tail...>;
};


//back-------------------------------------------------------------------------
template <class Head, class ...Tail>
struct back;
template <class Head, class ...Tail>
struct back<type_list<Head, Tail...>> {
    using type = typename back<type_list<Tail...>>::type;
};
template <class Ty>
struct back<type_list<Ty>> {
    using type = Ty;
};


//at---------------------------------------------------------------------------
template <size_t I, class Head, class ...Tail>
struct at;
template <size_t I, class Head, class ...Tail>
struct at<I, type_list<Head, Tail...>> {
    using type = typename at<I - 1, type_list<Tail...>>::type;
};
template <class Head, class ...Tail>
struct at<0, type_list<Head, Tail...>> {
    using type = Head;
};


//count------------------------------------------------------------------------
template <class Ty, class Head, class ...Tail>
struct count;
template <class Ty, class Head, class ...Tail>
struct count<Ty, type_list<Head, Tail...>> {
    static constexpr size_t value =
        count<Ty, type_list<Tail...>>::value
         + (std::is_same<Ty, Head>::value ? 1 : 0);
};
template <class Ty>
struct count<Ty, type_list<>> {
    static constexpr size_t value = 0;
};


//count_if---------------------------------------------------------------------
template <template<class> class Predicate, class Head, class...Tail>
struct count_if;
template <template<class> class Predicate, class Head, class...Tail>
struct count_if<Predicate, type_list<Head, Tail...>> {
    static constexpr size_t value =
        count_if<Predicate, type_list<Tail...>>::value
         + (Predicate<Head>::value ? 1 : 0);
};
template <template<class> class Predicate>
struct count_if<Predicate, type_list<>> {
    static constexpr size_t value = 0;
};


//concat-----------------------------------------------------------------------
template <class Ty0, class Ty1>
struct concat;
template <class ...Ty0, class ...Ty1>
struct concat<type_list<Ty0...>, type_list<Ty1...>> {
    using type = type_list<Ty0..., Ty1...>;
};


//all_of-----------------------------------------------------------------------
template <template<class> class Predicate, class Head, class...Tail>
struct all_of;
template <template<class> class Predicate, class Head, class...Tail>
struct all_of<Predicate, type_list<Head, Tail...>> {
    static constexpr bool value = Predicate<Head>::value ?
        all_of<Predicate, type_list<Tail...>>::value :
        false;
};
template <template<class> class Predicate>
struct all_of<Predicate, type_list<>> {
    static constexpr bool value = true;
};


//any_of-----------------------------------------------------------------------
template <template<class> class Predicate, class Head, class...Tail>
struct any_of;
template <template<class> class Predicate, class Head, class...Tail>
struct any_of<Predicate, type_list<Head, Tail...>> {
    static constexpr bool value = Predicate<Head>::value ?
        true : any_of<Predicate, type_list<Tail...>>::value;
};
template <template<class> class Predicate>
struct any_of<Predicate, type_list<>> {
    static constexpr bool value = false;
};


//none_of----------------------------------------------------------------------
template <template<class> class Predicate, class Head, class...Tail>
struct none_of;
template <template<class> class Predicate, class Head, class...Tail>
struct none_of<Predicate, type_list<Head, Tail...>> {
    static constexpr bool value = Predicate<Head>::value ?
        false : none_of<Predicate, type_list<Tail...>>::value;
};
template <template<class> class Predicate>
struct none_of<Predicate, type_list<>> {
    static constexpr bool value = true;
};


//for_each---------------------------------------------------------------------
template <template<class> class Function, class ...Ty>
struct for_each;
template <template<class> class Function, class ...Ty>
struct for_each<Function, type_list<Ty...>> {
    using type = type_list<typename Function<Ty>::type...>;
};



//push_back--------------------------------------------------------------------
template <class Ty, class ...Elm>
struct push_back;
template <class Ty, class ...Elm>
struct push_back<Ty, type_list<Elm...>> {
    using type = type_list<Elm..., Ty>;
};


//push_back_if-----------------------------------------------------------------
template <bool Flag, class Ty, class ...Elm>
struct push_back_if_impl;
template <class Ty, class ...Elm>
struct push_back_if_impl<true, Ty, type_list<Elm...>> {
    using type = typename push_back<Ty, type_list<Elm...>>::type;
};
template <class Ty, class ...Elm>
struct push_back_if_impl<false, Ty, type_list<Elm...>> {
    using type = type_list<Elm...>;
};
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_back_if;
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_back_if<Predicate, Ty, type_list<Elm...>> {
    using type = typename push_back_if_impl<
        Predicate<Ty>::value, Ty, type_list<Elm...>
    >::type;
};
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_back_if_not;
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_back_if_not<Predicate, Ty, type_list<Elm...>> {
    using type = typename push_back_if_impl<
        !Predicate<Ty>::value, Ty, type_list<Elm...>
    >::type;
};


//push_front-------------------------------------------------------------------
template <class Ty, class ...Elm>
struct push_front;
template <class Ty, class ...Elm>
struct push_front<Ty, type_list<Elm...>> {
    using type = type_list<Ty, Elm...>;
};


//push_front_if-----------------------------------------------------------------
template <bool Flag, class Ty, class ...Elm>
struct push_front_if_impl;
template <class Ty, class ...Elm>
struct push_front_if_impl<true, Ty, type_list<Elm...>> {
    using type = typename push_front<Ty, type_list<Elm...>>::type;
};
template <class Ty, class ...Elm>
struct push_front_if_impl<false, Ty, type_list<Elm...>> {
    using type = type_list<Elm...>;
};
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_front_if;
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_front_if<Predicate, Ty, type_list<Elm...>> {
    using type = typename push_front_if_impl<
        Predicate<Ty>::value, Ty, type_list<Elm...>
    >::type;
};
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_front_if_not;
template <template<class> class Predicate, class Ty, class ...Elm>
struct push_front_if_not<Predicate, Ty, type_list<Elm...>> {
    using type = typename push_front_if_impl<
        !Predicate<Ty>::value, Ty, type_list<Elm...>
    >::type;
};



//extract_if-------------------------------------------------------------------
template <template<class> class Predicate, class Head, class...Tail>
struct extract_if;
template <template<class> class Predicate, class Head, class...Tail>
struct extract_if<Predicate, type_list<Head, Tail...>> {
    using type = typename push_front_if<
        Predicate,
        Head,
        typename extract_if<Predicate, type_list<Tail...>>::type
    >::type;
};
template <template<class> class Predicate>
struct extract_if<Predicate, type_list<>> {
    using type = type_list<>;
};



//remove_if-------------------------------------------------------------------
template <template<class> class Predicate, class Head, class...Tail>
struct remove_if;
template <template<class> class Predicate, class Head, class...Tail>
struct remove_if<Predicate, type_list<Head, Tail...>> {
    using type = typename push_front_if_not<
        Predicate,
        Head,
        typename remove_if<Predicate, type_list<Tail...>>::type
    >::type;
};
template <template<class> class Predicate>
struct remove_if<Predicate, type_list<>> {
    using type = type_list<>;
};

} // namespace gdv

#endif
