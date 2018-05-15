#ifndef GDV_ONLINE_H_
#define GDV_ONLINE_H_

#include <type_traits>
#include <cmath>

namespace gdv {
namespace online {

template <class Ty>
class max {
public:
    max() noexcept :
        max_{} {}

    max(Ty x) noexcept : 
        max_{x} {}

    max(const max &m) noexcept :
        max_{m.max_} {}

    max<Ty> operator = (const max &m) noexcept {
        max_ = m.max_;
    }

public:
    Ty add(Ty x) noexcept {
        max_ = std::max(x, max_);
        return max_;
    }

    Ty add(max<Ty> x) noexcept {
        max_ = std::max(max_, x.max_);
        return max_;
    }

    Ty value() const noexcept {return max_;}

    void clear() noexcept {
        max_ = static_cast<Ty>(0);
    }

    void reset(Ty x) noexcept {
        max_ = x;
    }

    operator Ty() noexcept {return max_;}

private:
    Ty max_;
};



template <class Ty>
class min {
public:
    min() noexcept :
        min_{} {}

    min(Ty x) noexcept : 
        min_{x} {}

    min(const min &m) noexcept :
        min_{m.min_} {}

    min<Ty> operator = (const min &m) noexcept {
        min_ = m.min_;
    }

public:
    Ty add(Ty x) noexcept {
        min_ = std::min(x, min_);
        return min_;
    }

    Ty add(min<Ty> x) noexcept {
        min_ = std::min(min_, x.min_);
        return min_;
    }

    Ty value() const noexcept {return min_;}

    void clear() noexcept {
        min_ = static_cast<Ty>(0);
    }

    void reset(Ty x) noexcept {
        min_ = x;
    }

    operator Ty() noexcept {return min_;}


private:
    Ty min_;
};




template <class Ty>
class average {
    static_assert(std::is_floating_point<Ty>::value, "template parameter Ty must be floating point.");

public:
    average() noexcept : 
        average_{}, 
        count_{} {}


    average(Ty avrg) noexcept : 
        average_{avrg},
        count_{} {}


    average(const average &avrg) noexcept : 
        average_{avrg.average_},
        count_{avrg.count_} {}


    average<Ty>& operator = (const average &avrg) noexcept {
        average_ = avrg.average_;
        count_ = avrg.count_;
    }


public:
    Ty add(Ty x) noexcept {
        average_ += (x - average_) / static_cast<Ty>(++count_);
        return average_;
    }


    Ty add(average x) noexcept {
        average_ += (x.average_ - average_) * static_cast<Ty>(x.count_) / static_cast<Ty>(count_ + x.count_);
        count_ += x.count_;
        return average_;
    }


    Ty value() const noexcept {return average_;}


    size_t size() const noexcept {return count_;}


    void clear() noexcept {
        count_ = 0;
        average_ = static_cast<Ty>(0);
    }


    operator Ty() noexcept {return average_;}
    
private:
    Ty      average_;
    size_t  count_;
};





template <class Ty>
class dispersion {
    static_assert(std::is_floating_point<Ty>::value, "template parameter Ty must be floating point.");

public:
    dispersion() noexcept :
        dispersion_{},
        average_{},
        count_{} {}


    dispersion(const dispersion& x) noexcept :
        dispersion_{x.dispersion_},
        average_{x.average_},
        count_{x.count_} {}


public:
    Ty add(Ty x) noexcept {
        Ty average_old = std::pow(average_, 2);
        average_ += (x - average_) / static_cast<Ty>(count_ + 1);
        Ty average_new = std::pow(average_, 2);
        dispersion_ += ((static_cast<Ty>(count_) * average_old - dispersion_ + std::pow(x, 2)) / static_cast<Ty>(count_ + 1)) - average_new;
        ++count_;
        return dispersion_;
    }



    Ty add(dispersion x) noexcept {
        Ty average_me = std::pow(average_, 2);
        Ty average_dst = std::pow(x.average_, 2);
        average_ += (x.average_ - average_) * static_cast<Ty>(x.count_) / static_cast<Ty>(count_ + x.count_);
        dispersion_ += (static_cast<Ty>(count_) * average_me + static_cast<Ty>(x.count_) * (x.dispersion_ - dispersion_ + average_dst)) / static_cast<Ty>(count_ + x.count_) - std::pow(average_, 2);
        count_ += x.count_;
        return dispersion_;
    }


    Ty value() const noexcept {return dispersion_;}


    Ty average() const noexcept {return average_;}


    size_t size() const noexcept {return count_;}


    void clear() noexcept {
        count_ = 0;
        average_ = static_cast<Ty>(0);
        dispersion_ = static_cast<Ty>(0);
    }

    operator Ty() noexcept {return dispersion_;}

private:
    Ty      dispersion_;
    Ty      average_;
    size_t  count_;
};








template <class Ty>
max<Ty>& operator << (max<Ty> &x, Ty y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
max<Ty>& operator << (max<Ty> &x, max<Ty> y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
min<Ty>& operator << (min<Ty> &x, Ty y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
min<Ty>& operator << (min<Ty> &x, min<Ty> y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
average<Ty>& operator << (average<Ty> &x, Ty y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
average<Ty>& operator << (average<Ty> &x, average<Ty> y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
dispersion<Ty>& operator << (dispersion<Ty> &x, Ty y) noexcept {
    x.add(y);
    return x;
}


template <class Ty>
dispersion<Ty>& operator << (dispersion<Ty> &x, dispersion<Ty> y) noexcept {
    x.add(y);
    return x;
}



} // namespace online
} // namespace gdv


#endif

