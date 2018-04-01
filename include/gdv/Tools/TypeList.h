#ifndef GDV_TypeList_H_
#define GDV_TypeList_H_

#include <type_traits>

namespace gdv {

template <class ...Ty>
struct TypeList{};


template <size_t I>
struct PlaceHolder {
    static constexpr size_t value = I;
};

namespace TypeListImpl {

//receive----------------------------------------------------------------------
template <class Elm, template <class...> class Ty>
struct Transfer;
template <class ...Elm, template <class...> class Ty>
struct Transfer<TypeList<Elm...>, Ty> {
    using type = Ty<Elm...>;
};


//Max--------------------------------------------------------------------------
template <class Head, class ...Tail>
struct Max;
template <class Head, class ...Tail>
struct Max <TypeList<Head, Tail...>> {
    static constexpr size_t value =
        sizeof(Head) > Max<TypeList<Tail...>>::value ?
        sizeof(Head) : Max<TypeList<Tail...>>::value;
};
template <>
struct Max<TypeList<>> {
    static constexpr size_t value = 0;
};

//Min--------------------------------------------------------------------------
template <class Head, class ...Tail>
struct Min;
template <class Head, class ...Tail>
struct Min <TypeList<Head, Tail...>> {
    static constexpr size_t value =
        sizeof(Head) < Min<TypeList<Tail...>>::value ?
        sizeof(Head) : Min<TypeList<Tail...>>::value;
};
template <class Ty>
struct Min<TypeList<Ty>> {
    static constexpr size_t value = sizeof(Ty);
};



//Size-------------------------------------------------------------------------
template <class ...Ty>
struct Size {
    static constexpr size_t value = sizeof...(Ty);
};
template <class ...Ty>
struct Size<TypeList<Ty...>> {
    static constexpr size_t value = sizeof...(Ty);
};


//Empty-------------------------------------------------------------------------
template <class Head, class ...Tail>
struct Empty;
template <class Head, class ...Tail>
struct Empty<TypeList<Head, Tail...>> : std::false_type {};
template <>
struct Empty<TypeList<>> : std::true_type {};


//Head-------------------------------------------------------------------------
template <class H, class ...Tail>
struct Head {
    using type = H;
};
template <class H, class ...Tail>
struct Head<TypeList<H, Tail...>> {
    using type = H;
};


//Tail-------------------------------------------------------------------------
template <class Head, class ...T>
struct Tail;
template <class Head, class ...T>
struct Tail<TypeList<Head, T...>> {
    using type = TypeList<T...>;
};


//Back-------------------------------------------------------------------------
template <class Head, class ...Tail>
struct Back;
template <class Head, class ...Tail>
struct Back<TypeList<Head, Tail...>> {
    using type = typename Back<TypeList<Tail...>>::type;
};
template <class Ty>
struct Back<TypeList<Ty>> {
    using type = Ty;
};


//At---------------------------------------------------------------------------
template <class Ty, size_t I>
struct At;
template <class Head, class ...Tail, size_t I>
struct At<TypeList<Head, Tail...>, I> {
    using type = typename At<TypeList<Tail...>, I - 1>::type;
};
template <class Head, class ...Tail>
struct At<TypeList<Head, Tail...>, 0> {
    using type = Head;
};


//Count------------------------------------------------------------------------
template <class Li, class Ty>
struct Count;
template <class Head, class ...Tail, class Ty>
struct Count<TypeList<Head, Tail...>, Ty> {
    static constexpr size_t value =
        Count<TypeList<Tail...>, Ty>::value
         + (std::is_same<Ty, Head>::value ? 1 : 0);
};
template <class Ty>
struct Count<TypeList<>, Ty> {
    static constexpr size_t value = 0;
};


//CountIf---------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct CountIf;
template <class Head, class ...Tail, template<class> class Predicate>
struct CountIf<TypeList<Head, Tail...>, Predicate> {
    static constexpr size_t value =
        CountIf<TypeList<Tail...>, Predicate>::value
         + (Predicate<Head>::value ? 1 : 0);
};
template <template<class> class Predicate>
struct CountIf<TypeList<>, Predicate> {
    static constexpr size_t value = 0;
};


//Concat-----------------------------------------------------------------------
template <class Ty0, class ...Ty1>
struct Concat;
template <class ...Ty0, class ...Ty1>
struct Concat<TypeList<Ty0...>, TypeList<Ty1...>> {
    using type = TypeList<Ty0..., Ty1...>;
};
template <class ...Ty0, class ...Ty1>
struct Concat<TypeList<Ty0...>, Ty1...> {
    using type = TypeList<Ty0..., Ty1...>;
};


//Contain-----------------------------------------------------------------------
template <class Elm, class Ty>
struct Contain;
template <class Head, class ...Tail, class Ty>
struct Contain<TypeList<Head, Tail...>, Ty> {
    static constexpr bool value = std::is_same<Head, Ty>::value ?
        true : Contain<TypeList<Tail...>, Ty>::value;
};
template <class Ty>
struct Contain<TypeList<>, Ty> : std::false_type {};



//Contain-----------------------------------------------------------------------
template <size_t I, class Elm, class Ty>
struct FindIndexImpl;
template <size_t I, class Head, class ...Tail, class Ty>
struct FindIndexImpl<I, TypeList<Head, Tail...>, Ty> {
    static constexpr size_t value = std::is_same<Head, Ty>::value ? 
            I : FindIndexImpl<I + 1, TypeList<Tail...>, Ty>::value;
};
template <size_t I, class Ty>
struct FindIndexImpl<I, TypeList<>, Ty> {
    static constexpr size_t value = I;
};
template <class Elms, class Ty>
struct FindIndex;
template <class ...Elms, class Ty>
struct FindIndex<TypeList<Elms...>, Ty> {
    static constexpr size_t value = FindIndexImpl<0, TypeList<Elms...>, Ty>::value;
};



//AllOf-----------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct AllOf;
template <class Head, class...Tail, template<class> class Predicate>
struct AllOf<TypeList<Head, Tail...>, Predicate> {
    static constexpr bool value = Predicate<Head>::value ?
        AllOf<TypeList<Tail...>, Predicate>::value : false;
};
template <template<class> class Predicate>
struct AllOf<TypeList<>, Predicate> {
    static constexpr bool value = true;
};


//AnyOf-----------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct AnyOf;
template < class Head, class...Tail, template<class> class Predicate>
struct AnyOf<TypeList<Head, Tail...>, Predicate> {
    static constexpr bool value = Predicate<Head>::value ?
        true : AnyOf<TypeList<Tail...>, Predicate>::value;
};
template <template<class> class Predicate>
struct AnyOf<TypeList<>, Predicate> {
    static constexpr bool value = false;
};


//NoneOf----------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct NoneOf;
template < class Head, class...Tail, template<class> class Predicate>
struct NoneOf<TypeList<Head, Tail...>, Predicate> {
    static constexpr bool value = Predicate<Head>::value ?
        false : NoneOf<TypeList<Tail...>, Predicate>::value;
};
template <template<class> class Predicate>
struct NoneOf<TypeList<>, Predicate> {
    static constexpr bool value = true;
};


//ForEach---------------------------------------------------------------------
template <class Ty, template<class> class Function>
struct ForEach;
template <class ...Ty, template<class> class Function>
struct ForEach<TypeList<Ty...>, Function> {
    using type = TypeList<typename Function<Ty>::type...>;
};



//PushBack--------------------------------------------------------------------
template <class Elm, class ...Ty>
struct PushBack;
template <class ...Elm, class ...Ty>
struct PushBack<TypeList<Elm...>, Ty...> {
    using type = TypeList<Elm..., Ty...>;
};


//PushBackIf-----------------------------------------------------------------
template <class Elm, class Ty, template<class> class Predicate>
struct PushBackIf;
template <class ...Elm, class Ty, template<class> class Predicate>
struct PushBackIf<TypeList<Elm...>, Ty, Predicate>
    : std::conditional<
        Predicate<Ty>::value,
        TypeList<Elm..., Ty>,
        TypeList<Elm...>
    > {};
template <class Elm, class Ty, template<class> class Predicate>
struct PushBackIfNot;
template <class ...Elm, class Ty, template<class> class Predicate>
struct PushBackIfNot<TypeList<Elm...>, Ty, Predicate>
    : std::conditional<
        !Predicate<Ty>::value,
        TypeList<Elm..., Ty>,
        TypeList<Elm...>
    > {};


//PushFront-------------------------------------------------------------------
template <class Elm, class ...Ty>
struct PushFront;
template <class ...Elm, class ...Ty>
struct PushFront<TypeList<Elm...>, Ty...> {
    using type = TypeList<Ty..., Elm...>;
};


//PushFrontIf-----------------------------------------------------------------
template <class Elm, class Ty, template<class> class Predicate>
struct PushFrontIf;
template <class ...Elm, class Ty, template<class> class Predicate>
struct PushFrontIf<TypeList<Elm...>, Ty, Predicate>
    : std::conditional<
        Predicate<Ty>::value,
        TypeList<Ty, Elm...>,
        TypeList<Elm...>
    > {};
template <class Elm, class Ty, template<class> class Predicate>
struct PushFrontIfNot;
template <class ...Elm, class Ty, template<class> class Predicate>
struct PushFrontIfNot<TypeList<Elm...>, Ty, Predicate>
    : std::conditional<
        !Predicate<Ty>::value,
        TypeList<Ty, Elm...>,
        TypeList<Elm...>
    > {};



//ExtractIf-------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct ExtractIf;
template <class Head, class...Tail, template<class> class Predicate>
struct ExtractIf<TypeList<Head, Tail...>, Predicate> {
    using type = typename PushFrontIf<
        typename ExtractIf<TypeList<Tail...>, Predicate>::type,
        Head,
        Predicate
    >::type;
};
template <template<class> class Predicate>
struct ExtractIf<TypeList<>, Predicate> {
    using type = TypeList<>;
};



//RemoveIf-------------------------------------------------------------------
template <class Ty, template<class> class Predicate>
struct RemoveIf;
template <class Head, class...Tail, template<class> class Predicate>
struct RemoveIf<TypeList<Head, Tail...>, Predicate> {
    using type = typename PushFrontIfNot<
    typename ExtractIf<TypeList<Tail...>, Predicate>::type,
    Head,
    Predicate
    >::type;
};
template <template<class> class Predicate>
struct RemoveIf<TypeList<>, Predicate> {
    using type = TypeList<>;
};


//Replace----------------------------------------------------------------------
template <class Elm, class Src, class Dst>
struct Replace;
template <class Head, class ...Tail, class Src, class Dst>
struct Replace<TypeList<Head, Tail...>, Src, Dst> {
    using type = typename PushFront<
        typename Replace<
            TypeList<Tail...>,
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
struct Replace<TypeList<>, Src, Dst> {
    using type = TypeList<>;
};


//ReplaceIf----------------------------------------------------------------------
template <class Elm, class Dst, template<class> class Predicate>
struct ReplaceIf;
template <class Head, class ...Tail, class Dst, template<class> class Predicate>
struct ReplaceIf<TypeList<Head, Tail...>, Dst, Predicate> {
    using type = typename PushFront<
        typename ReplaceIf<
            TypeList<Tail...>,
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
struct ReplaceIf<TypeList<>, Dst, Predicate> {
    using type = TypeList<>;
};




template <size_t I, class Ty, class Args>
struct ReplacePlaceholder;
template <size_t I, class ...Ty, class ArgHead, class ...ArgTail>
struct ReplacePlaceholder<
    I,
    TypeList<Ty...>,
    TypeList<ArgHead, ArgTail...>> :
    std::conditional<
        Contain<TypeList<Ty...>, PlaceHolder<I>>::value,
        typename ReplacePlaceholder<
            I + 1,
            typename Replace<TypeList<Ty...>, PlaceHolder<I>, ArgHead>::type,
            TypeList<ArgTail...>
        >::type,
        typename std::conditional<
            Empty<TypeList<ArgHead, ArgTail...>>::value,
            TypeList<Ty...>,
            typename PushBack<TypeList<Ty...>, ArgHead, ArgTail...>::type
        >::type
    > {};
template <size_t I, class ...Ty>
struct ReplacePlaceholder<I, TypeList<Ty...>, TypeList<>> {
    using type = TypeList<Ty...>;
};


} // namespace TypeListImpl


template <template<class...> class Function, class ...List>
struct Bind {
    template <class ...Args>
    using apply = typename TypeListImpl::Transfer<
        typename TypeListImpl::ReplacePlaceholder<
            0,
            TypeList<List...>,
            TypeList<Args...>
        >::type,
        Function
    >::type;
    template <class ...Args>
    using func = apply<Args...>;
};

template <class List, template <class...> class Ty>
using Transfer = typename TypeListImpl::Transfer<List, Ty>::type;

template <class List>
static constexpr size_t Max = TypeListImpl::Max<List>::value;

template <class List>
static constexpr size_t Min = TypeListImpl::Min<List>::value;

template <class List>
static constexpr size_t Size = TypeListImpl::Size<List>::value;

template <class List>
static constexpr bool Empty = TypeListImpl::Empty<List>::value;

template <class List>
using Head = typename TypeListImpl::Head<List>::type;

template <class List>
using Tail = typename TypeListImpl::Tail<List>::type;

template <class List>
using Back = typename TypeListImpl::Back<List>::type;

template <class List, size_t I>
using At = typename TypeListImpl::At<List, I>::type;

template <class List, class Ty>
static constexpr size_t Count = TypeListImpl::Count<List, Ty>::value;

template <class List, class Ty>
static constexpr bool Contain = TypeListImpl::Contain<List, Ty>::value;

template <class List, class Ty>
static constexpr size_t FindIndex = TypeListImpl::FindIndex<List, Ty>::value;

template <class List, template<class> class Predicate>
static constexpr size_t CountIf = TypeListImpl::CountIf<List, Predicate>::value;

template <class List1, class List2>
using Concat = typename TypeListImpl::Concat<List1, List2>::type;

template <class List, template<class> class Predicate>
static constexpr bool AllOf = TypeListImpl::AllOf<List, Predicate>::value;

template <class List, template<class> class Predicate>
static constexpr bool AnyOf = TypeListImpl::AnyOf<List, Predicate>::value;

template <class List, template<class> class Predicate>
static constexpr bool NoneOf = TypeListImpl::NoneOf<List, Predicate>::value;

template <class List, template<class> class Function>
using ForEach = typename TypeListImpl::ForEach<List, Function>::type;

template <class List, class ...Ty>
using PushBack = typename TypeListImpl::PushBack<List, Ty...>::type;

template <class List, class ...Ty>
using PushFront = typename TypeListImpl::PushFront<List, Ty...>::type;

template <class List, template<class> class Predicate>
using ExtractIf = typename TypeListImpl::ExtractIf<List, Predicate>::type;

template <class List, template<class> class Predicate>
using RemoveIf = typename TypeListImpl::RemoveIf<List, Predicate>::type;

template <class List, class Src, class Dst>
using Replace = typename TypeListImpl::Replace<List, Src, Dst>::type;

template <class List, class Dst, template<class> class Predicate>
using ReplaceIf = typename TypeListImpl::ReplaceIf<List, Dst, Predicate>::type;

} // namespace gdv

#endif
