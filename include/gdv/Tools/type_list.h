#ifndef GDV_TYPE_LIST_H_
#define GDV_TYPE_LIST_H_

#include <type_traits>

namespace gdv {

template <class ...Ty>
struct type_list{};

namespace type_list_impl {

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
template <bool Flag, class Elm, class Ty>
struct push_back_if_impl;
template <class ...Elm, class Ty>
struct push_back_if_impl<true, type_list<Elm...>, Ty> {
    using type = typename push_back<type_list<Elm...>, Ty>::type;
};
template <class ...Elm, class Ty>
struct push_back_if_impl<false, type_list<Elm...>, Ty> {
    using type = type_list<Elm...>;
};
template <class Elm, class Ty, template<class> class Predicate>
struct push_back_if;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_back_if<type_list<Elm...>, Ty, Predicate> {
    using type = typename push_back_if_impl<
        Predicate<Ty>::value, type_list<Elm...>, Ty
    >::type;
};
template <class Elm, class Ty, template<class> class Predicate>
struct push_back_if_not;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_back_if_not<type_list<Elm...>, Ty, Predicate> {
    using type = typename push_back_if_impl<
        !Predicate<Ty>::value, type_list<Elm...>, Ty
    >::type;
};


//push_front-------------------------------------------------------------------
template <class Elm, class ...Ty>
struct push_front;
template <class ...Elm, class ...Ty>
struct push_front<type_list<Elm...>, Ty...> {
    using type = type_list<Ty..., Elm...>;
};


//push_front_if-----------------------------------------------------------------
template <bool Flag, class Elm, class Ty>
struct push_front_if_impl;
template <class ...Elm, class Ty>
struct push_front_if_impl<true, type_list<Elm...>, Ty> {
    using type = typename push_front<type_list<Elm...>, Ty>::type;
};
template <class ...Elm, class Ty>
struct push_front_if_impl<false, type_list<Elm...>, Ty> {
    using type = type_list<Elm...>;
};
template <class Elm, class Ty, template<class> class Predicate>
struct push_front_if;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_front_if<type_list<Elm...>, Ty, Predicate> {
    using type = typename push_front_if_impl<
        Predicate<Ty>::value, type_list<Elm...>, Ty
    >::type;
};
template <class Elm, class Ty, template<class> class Predicate>
struct push_front_if_not;
template <class ...Elm, class Ty, template<class> class Predicate>
struct push_front_if_not<type_list<Elm...>, Ty, Predicate> {
    using type = typename push_front_if_impl<
        !Predicate<Ty>::value, type_list<Elm...>, Ty
    >::type;
};



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

} // namespace type_list_impl


template <class List, template <class...> class Ty>
using transfer = typename type_list_impl::transfer<List, Ty>::type;

template <class List>
static constexpr size_t max = type_list_impl::max<List>::value;

template <class List>
static constexpr size_t min = type_list_impl::min<List>::value;

template <class List>
static constexpr size_t size = type_list_impl::size<List>::value;

template <class List>
static constexpr bool empty = type_list_impl::empty<List>::value;

template <class List>
using head = typename type_list_impl::head<List>::type;

template <class List>
using tail = typename type_list_impl::tail<List>::type;

template <class List>
using back = typename type_list_impl::back<List>::type;

template <class List, size_t I>
using at = typename type_list_impl::at<List, I>::type;

template <class List, class Ty>
static constexpr size_t count = type_list_impl::count<List, Ty>::value;

template <class List, template<class> class Predicate>
static constexpr size_t count_if = type_list_impl::count_if<List, Predicate>::value;

template <class List1, class List2>
using concat = typename type_list_impl::concat<List1, List2>::type;

template <class List, template<class> class Predicate>
static constexpr bool all_of = type_list_impl::all_of<List, Predicate>::value;

template <class List, template<class> class Predicate>
static constexpr bool any_of = type_list_impl::any_of<List, Predicate>::value;

template <class List, template<class> class Predicate>
static constexpr bool none_of = type_list_impl::none_of<List, Predicate>::value;

template <class List, template<class> class Function>
using for_each = typename type_list_impl::for_each<List, Function>::type;

template <class List, class ...Ty>
using push_back = typename type_list_impl::push_back<List, Ty...>::type;

template <class List, class ...Ty>
using push_front = typename type_list_impl::push_front<List, Ty...>::type;

template <class List, template<class> class Predicate>
using extract_if = typename type_list_impl::extract_if<List, Predicate>::type;

template <class List, template<class> class Predicate>
using remove_if = typename type_list_impl::remove_if<List, Predicate>::type;


} // namespace gdv

#endif
