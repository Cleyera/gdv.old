#ifndef GDV_TYPE_LIST_H_
#define GDV_TYPE_LIST_H_

#include <type_traits>

namespace gdv {

template <class ...Ty>
struct type_list{};


template <size_t I>
struct placeholder {
    static constexpr size_t value = I;
};

namespace detail {

//receive----------------------------------------------------------------------
template <class Elm, template <class...> class Ty>
struct transfer;
template <class ...Elm, template <class...> class Ty>
struct transfer<type_list<Elm...>, Ty> {
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
struct empty<type_list<Head, Tail...>> : std::false_type {};
template <>
struct empty<type_list<>> : std::true_type {};


//head-------------------------------------------------------------------------
template <class H, class ...Tail>
struct head {
    using type = H;
};
template <class H, class ...Tail>
struct head<type_list<H, Tail...>> {
    using type = H;
};


//tail-------------------------------------------------------------------------
template <class Head, class ...T>
struct tail;
template <class Head, class ...T>
struct tail<type_list<Head, T...>> {
    using type = type_list<T...>;
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
template <class Ty, size_t I>
struct at;
template <class Head, class ...Tail, size_t I>
struct at<type_list<Head, Tail...>, I> {
    using type = typename at<type_list<Tail...>, I - 1>::type;
};
template <class Head, class ...Tail>
struct at<type_list<Head, Tail...>, 0> {
    using type = Head;
};


//count------------------------------------------------------------------------
template <class Li, class Ty>
struct count;
template <class Head, class ...Tail, class Ty>
struct count<type_list<Head, Tail...>, Ty> {
    static constexpr size_t value =
        count<type_list<Tail...>, Ty>::value
         + (std::is_same<Ty, Head>::value ? 1 : 0);
};
template <class Ty>
struct count<type_list<>, Ty> {
    static constexpr size_t value = 0;
};


//count_if---------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct count_if;
template <class Head, class ...Tail, template<class> class Predicate>
struct count_if<type_list<Head, Tail...>, Predicate> {
    static constexpr size_t value =
        count_if<type_list<Tail...>, Predicate>::value
         + (Predicate<Head>::value ? 1 : 0);
};
template <template<class> class Predicate>
struct count_if<type_list<>, Predicate> {
    static constexpr size_t value = 0;
};


//concat-----------------------------------------------------------------------
template <class Ty0, class ...Ty1>
struct concat;
template <class ...Ty0, class ...Ty1>
struct concat<type_list<Ty0...>, type_list<Ty1...>> {
    using type = type_list<Ty0..., Ty1...>;
};
template <class ...Ty0, class ...Ty1>
struct concat<type_list<Ty0...>, Ty1...> {
    using type = type_list<Ty0..., Ty1...>;
};


//contain-----------------------------------------------------------------------
template <class Elm, class Ty>
struct contain;
template <class Head, class ...Tail, class Ty>
struct contain<type_list<Head, Tail...>, Ty> {
    static constexpr bool value = std::is_same<Head, Ty>::value ?
        true : contain<type_list<Tail...>, Ty>::value;
};
template <class Ty>
struct contain<type_list<>, Ty> : std::false_type {};



//Contain-----------------------------------------------------------------------
template <size_t I, class Elm, class Ty>
struct find_index_impl;
template <size_t I, class Head, class ...Tail, class Ty>
struct find_index_impl<I, type_list<Head, Tail...>, Ty> {
    static constexpr size_t value = std::is_same<Head, Ty>::value ? 
            I : find_index_impl<I + 1, type_list<Tail...>, Ty>::value;
};
template <size_t I, class Ty>
struct find_index_impl<I, type_list<>, Ty> {
    static constexpr size_t value = I;
};
template <class Elms, class Ty>
struct find_index;
template <class ...Elms, class Ty>
struct find_index<type_list<Elms...>, Ty> {
    static constexpr size_t value = find_index_impl<0, type_list<Elms...>, Ty>::value;
};



//all_of-----------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct all_of;
template <class Head, class...Tail, template<class> class Predicate>
struct all_of<type_list<Head, Tail...>, Predicate> {
    static constexpr bool value = Predicate<Head>::value ?
        all_of<type_list<Tail...>, Predicate>::value : false;
};
template <template<class> class Predicate>
struct all_of<type_list<>, Predicate> {
    static constexpr bool value = true;
};


//any_of-----------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct any_of;
template < class Head, class...Tail, template<class> class Predicate>
struct any_of<type_list<Head, Tail...>, Predicate> {
    static constexpr bool value = Predicate<Head>::value ?
        true : any_of<type_list<Tail...>, Predicate>::value;
};
template <template<class> class Predicate>
struct any_of<type_list<>, Predicate> {
    static constexpr bool value = false;
};


//none_of----------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct none_of;
template < class Head, class...Tail, template<class> class Predicate>
struct none_of<type_list<Head, Tail...>, Predicate> {
    static constexpr bool value = Predicate<Head>::value ?
        false : none_of<type_list<Tail...>, Predicate>::value;
};
template <template<class> class Predicate>
struct none_of<type_list<>, Predicate> {
    static constexpr bool value = true;
};


//for_each---------------------------------------------------------------------
template <class Ty, template<class> class Function>
struct for_each;
template <class ...Ty, template<class> class Function>
struct for_each<type_list<Ty...>, Function> {
    using type = type_list<typename Function<Ty>::type...>;
};



//push_back--------------------------------------------------------------------
template <class Elm, class ...Ty>
struct push_back;
template <class ...Elm, class ...Ty>
struct push_back<type_list<Elm...>, Ty...> {
    using type = type_list<Elm..., Ty...>;
};


//push_back_if-----------------------------------------------------------------
template <class Elm, class Ty, template<class> class Predicate>
struct push_back_if;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_back_if<type_list<Elm...>, Ty, Predicate>
    : std::conditional<
        Predicate<Ty>::value,
        type_list<Elm..., Ty>,
        type_list<Elm...>
    > {};
template <class Elm, class Ty, template<class> class Predicate>
struct push_back_if_not;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_back_if_not<type_list<Elm...>, Ty, Predicate>
    : std::conditional<
        !Predicate<Ty>::value,
        type_list<Elm..., Ty>,
        type_list<Elm...>
    > {};


//push_front-------------------------------------------------------------------
template <class Elm, class ...Ty>
struct push_front;
template <class ...Elm, class ...Ty>
struct push_front<type_list<Elm...>, Ty...> {
    using type = type_list<Ty..., Elm...>;
};


//push_front_if-----------------------------------------------------------------
template <class Elm, class Ty, template<class> class Predicate>
struct push_front_if;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_front_if<type_list<Elm...>, Ty, Predicate>
    : std::conditional<
        Predicate<Ty>::value,
        type_list<Ty, Elm...>,
        type_list<Elm...>
    > {};
template <class Elm, class Ty, template<class> class Predicate>
struct push_front_if_not;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_front_if_not<type_list<Elm...>, Ty, Predicate>
    : std::conditional<
        !Predicate<Ty>::value,
        type_list<Ty, Elm...>,
        type_list<Elm...>
    > {};



//extract_if-------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct extract_if;
template <class Head, class...Tail, template<class> class Predicate>
struct extract_if<type_list<Head, Tail...>, Predicate> {
    using type = typename push_front_if<
        typename extract_if<type_list<Tail...>, Predicate>::type,
        Head,
        Predicate
    >::type;
};
template <template<class> class Predicate>
struct extract_if<type_list<>, Predicate> {
    using type = type_list<>;
};



//remove_if-------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct remove_if;
template <class Head, class...Tail, template<class> class Predicate>
struct remove_if<type_list<Head, Tail...>, Predicate> {
    using type = typename push_front_if_not<
    typename extract_if<type_list<Tail...>, Predicate>::type,
    Head,
    Predicate
    >::type;
};
template <template<class> class Predicate>
struct remove_if<type_list<>, Predicate> {
    using type = type_list<>;
};


//replace----------------------------------------------------------------------
template <class Elm, class Src, class Dst>
struct replace;
template <class Head, class ...Tail, class Src, class Dst>
struct replace<type_list<Head, Tail...>, Src, Dst> {
    using type = typename push_front<
        typename replace<
            type_list<Tail...>,
            Src,
            Dst
        >::type,
        typename std::conditional<
            std::is_same<Src, Head>::value,
            Dst,
            Head
        >::type
    >::type;
};
template <class Src, class Dst>
struct replace<type_list<>, Src, Dst> {
    using type = type_list<>;
};


//replace_if----------------------------------------------------------------------
template <class Elm, class Dst, template<class> class Predicate>
struct replace_if;
template <class Head, class ...Tail, class Dst, template<class> class Predicate>
struct replace_if<type_list<Head, Tail...>, Dst, Predicate> {
    using type = typename push_front<
        typename replace_if<
            type_list<Tail...>,
            Dst,
            Predicate
        >::type,
        typename std::conditional<
            Predicate<Head>::value,
            Dst,
            Head
        >::type
    >::type;
};
template <class Dst, template<class> class Predicate>
struct replace_if<type_list<>, Dst, Predicate> {
    using type = type_list<>;
};




template <size_t I, class Ty, class Args>
struct replace_placeholder;
template <size_t I, class ...Ty, class ArgHead, class ...ArgTail>
struct replace_placeholder<
    I,
    type_list<Ty...>,
    type_list<ArgHead, ArgTail...>> :
    std::conditional<
        contain<type_list<Ty...>, placeholder<I>>::value,
        typename replace_placeholder<
            I + 1,
            typename replace<type_list<Ty...>, placeholder<I>, ArgHead>::type,
            type_list<ArgTail...>
        >::type,
        typename std::conditional<
            empty<type_list<ArgHead, ArgTail...>>::value,
            type_list<Ty...>,
            typename push_back<type_list<Ty...>, ArgHead, ArgTail...>::type
        >::type
    > {};
template <size_t I, class ...Ty>
struct replace_placeholder<I, type_list<Ty...>, type_list<>> {
    using type = type_list<Ty...>;
};


} // namespace detail


template <template<class...> class Function, class ...List>
struct bind {
    template <class ...Args>
    using apply = typename detail::transfer<
        typename detail::replace_placeholder<
            0,
            type_list<List...>,
            type_list<Args...>
        >::type,
        Function
    >::type;
    template <class ...Args>
    using func = apply<Args...>;
};

template <class List, template <class...> class Ty>
using transfer = typename detail::transfer<List, Ty>::type;

template <class List>
static constexpr size_t max = detail::max<List>::value;

template <class List>
static constexpr size_t min = detail::min<List>::value;

template <class List>
static constexpr size_t size = detail::size<List>::value;

template <class List>
static constexpr bool empty = detail::empty<List>::value;

template <class List>
using head = typename detail::head<List>::type;

template <class List>
using tail = typename detail::tail<List>::type;

template <class List>
using back = typename detail::back<List>::type;

template <class List, size_t I>
using at = typename detail::at<List, I>::type;

template <class List, class Ty>
static constexpr size_t count = detail::count<List, Ty>::value;

template <class List, class Ty>
static constexpr bool contain = detail::contain<List, Ty>::value;

template <class List, class Ty>
static constexpr size_t find_index = detail::find_index<List, Ty>::value;

template <class List, template<class> class Predicate>
static constexpr size_t count_if = detail::count_if<List, Predicate>::value;

template <class List1, class List2>
using concat = typename detail::concat<List1, List2>::type;

template <class List, template<class> class Predicate>
static constexpr bool all_of = detail::all_of<List, Predicate>::value;

template <class List, template<class> class Predicate>
static constexpr bool any_of = detail::any_of<List, Predicate>::value;

template <class List, template<class> class Predicate>
static constexpr bool none_of = detail::none_of<List, Predicate>::value;

template <class List, template<class> class Function>
using for_each = typename detail::for_each<List, Function>::type;

template <class List, class ...Ty>
using push_back = typename detail::push_back<List, Ty...>::type;

template <class List, class ...Ty>
using push_front = typename detail::push_front<List, Ty...>::type;

template <class List, template<class> class Predicate>
using extract_if = typename detail::extract_if<List, Predicate>::type;

template <class List, template<class> class Predicate>
using remove_if = typename detail::remove_if<List, Predicate>::type;

template <class List, class Src, class Dst>
using replace = typename detail::replace<List, Src, Dst>::type;

template <class List, class Dst, template<class> class Predicate>
using replace_if = typename detail::replace_if<List, Dst, Predicate>::type;

} // namespace gdv

#endif
