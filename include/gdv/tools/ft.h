#ifndef GDV_FT_H_
#define GDV_FT_H_

#include <memory>
#include <type_traits>
#include <utility>
#include <cstring>


namespace gdv {


template <class Ty, class Allocator = std::allocator<Ty>>
class fft {
    static_assert(std::is_floating_point<Ty>::value, "template parameter T must be floating point."); 

public:
    using value_type = Ty;
    using pointer_type = Ty*;
    using size_type = size_t;
    using allocator_type = Allocator;
    using allocator_traits = std::allocator_traits<allocator_type>;
    
public:
    fft() : 
        allocator_{},
        size_{}, 
        power_{},
        nyquist_size_{}, 
        capacity_{},
        work_{},
        work_last_{},
        re_{},
        re_first_{}, 
        im_{},
        im_first_{} {
    }


    fft(size_type n) : 
        fft() {
            resize(n);
    }


    fft(
        pointer_type re_in, 
        pointer_type im_in, 
        pointer_type re_out, 
        pointer_type im_out, 
        size_type n) : fft() {
        calc(re_in, im_in, re_out, re_out);
    }
        

    fft(
        pointer_type in, 
        pointer_type re_out, 
        pointer_type im_out, 
        size_type n) : fft() {
        calc(in, re_out, re_out);
    }



    fft(
        pointer_type in, 
        pointer_type out, 
        size_type n) : fft() {
        calc(in, out);
    }


    ~fft() {
        destruct_range(work_, work_last_);
        allocator_.deallocate(work_, capacity_);
    }



public:
    void resize(size_type n) {
        if (size_ == n || n < 2) { return; }

        if (n <= capacity_) { return; } 

        size_type power = (size_type)std::log2(n);

        // n must be a power of 2.
        if (n & (~(((size_type)1) << power))) { return; }

        power_ = (size_type)std::log2(n);
        capacity_ = n * 4;
        size_ = n;
        nyquist_size_ = n / 2;

        size_type now_size = capacity_;

        if (work_) {
            destruct_range(work_, work_last_);
            allocator_.deallocate(work_, now_size);
        }

        size_type alloc_size = capacity_;
        work_ = allocator_.allocate(alloc_size);
        work_last_ = work_ + alloc_size;

        construct_range(work_, work_last_);
        
        re_first_ = work_;
        im_first_ = work_ + (capacity_ / 2 + 1);
    }



    void calc(
        pointer_type re_in, 
        pointer_type im_in, 
        pointer_type re_out, 
        pointer_type im_out, 
        size_type n) {
        resize(n);

        if (n & (~(((size_type)1) << power_))) { return; }

        re_ = re_first_;
        im_ = im_first_;
        
        std::memcpy(re_in, re_, sizeof(value_type) * size_);
        std::memcpy(im_in, im_, sizeof(value_type) * size_);

        calc_fft();

        std::memcpy(re_out, re_, sizeof(value_type) * size_);
        std::memcpy(im_out, im_, sizeof(value_type) * size_);
    }


    void calc(
        pointer_type in, 
        pointer_type re_out, 
        pointer_type im_out, 
        size_type n) {
        resize(n);

        if (n & (~(((size_type)1) << power_))) { return; }

        re_first_ = work_;
        im_first_ = work_ + (capacity_ / 2 + 1);

        re_ = re_first_;
        im_ = im_first_;
        
        std::memcpy(in, re_, sizeof(value_type) * size_);
        for (size_type i = 0; i < size_; ++i) {
            im_[i] = static_cast<value_type>(0);
        }

        calc_fft();

        std::memcpy(re_out, re_, sizeof(value_type) * size_);
        std::memcpy(im_out, im_, sizeof(value_type) * size_);
    }


    void calc(pointer_type in, pointer_type out, size_type n) {
        resize(n);

        if (n & (~(((size_type)1) << power_))) { return; }

        re_first_ = work_;
        im_first_ = work_ + (capacity_ / 2 + 1);

        re_ = re_first_;
        im_ = im_first_;
        
        std::memcpy(in, re_, sizeof(value_type) * size_);
        for (size_type i = 0; i < size_; ++i) {
            im_[i] = static_cast<value_type>(0);
        }

        calc_fft();

        for (size_type i = 0; i < size_; ++i) {
            re_[i] = std::hypot(re_[i], im_[i]);
        }
        std::memcpy(out, re_, sizeof(value_type) * size_);
    }



    void calc_inverse(
        pointer_type re_in, 
        pointer_type im_in, 
        pointer_type re_out, 
        pointer_type im_out, 
        size_type n) {
        resize(n);

        if (n & (~(((size_type)1) << power_))) { return; }

        re_first_ = work_;
        im_first_ = work_ + (capacity_ / 2 + 1);

        re_ = re_first_;
        im_ = im_first_;
        
        std::memcpy(re_in, re_, sizeof(value_type) * size_);
        std::memcpy(im_in, im_, sizeof(value_type) * size_);

        calc_fft_inverse();

        std::memcpy(re_out, re_, sizeof(value_type) * size_);
        std::memcpy(im_out, im_, sizeof(value_type) * size_);
    }



    size_type size() const noexcept {return size_;}


    size_type nyquist_size() const noexcept {return nyquist_size_;}


    size_type capacity() const noexcept {return capacity_;}

    
private:

    void construct_range(pointer_type first, pointer_type last) {
        for (; first != last; ++first) {
            allocator_traits::construct(allocator_, first);
        }
    }



    void destroy_range(pointer_type first, pointer_type last) {
        for (; first != last; ++first) {
            allocator_traits::destroy(allocator_, first);
        }
    }


    void scrambler(pointer_type re, pointer_type im, size_type n) {
        size_type i{};
        for (size_type j = 0; j < n - 1; ++j) {
            for (size_type k = n >> 1; k > (i ^= k); k >>= 1);
            if (j < i) {
                std::swap(re[i], re[j]);
                std::swap(im[i], im[j]);
            }
        }
    }

    
    void calc_fft() {
        pointer_type re1 = re_first_;
        pointer_type re2 = re1 + size_;
        pointer_type im1 = im_first_;
        pointer_type im2 = re2 + size_;
        value_type theta = static_cast<value_type>(2) * pi<value_type> / size_;
        size_type dst = 2;


        for (size_type i = 0; i < power_; ++i) {

            size_type num = size_ / dst;
            value_type step = theta / num;

            for (size_type j = 0; j < num; ++j) {

                value_type angle{};
                size_type num2 = size_ / 2;

                for (size_type k = 0; k < size_; ++k) {
                    size_type to = j * dst + k;
                    value_type s = std::sin(angle);
                    value_type c = std::cos(angle);
                    if (k < num2) {
                        size_type from = to + num2;
                        re2[to] = re1[to] + re1[from] * c + im1[from] * s;
                        im2[to] = im1[to] + im1[from] * c - re1[from] * s;
                    } else {
                        size_type from = to - num2;
                        re2[to] = re1[from] + re1[to] * c + im1[to] * s;
                        im2[to] = im1[from] + im1[to] * c - re1[to] * s;
                    }
                    angle += step;
                }
            }
            std::swap(re1, re2);
            std::swap(im1, im2);
            dst *= 2;
        }

        re_ = re1;
        im_ = im1;
    }



    void calc_fft_inverse() {
        pointer_type re1 = re_first_;
        pointer_type re2 = re1 + size_;
        pointer_type im1 = im_first_;
        pointer_type im2 = re2 + size_;
        value_type theta = static_cast<value_type>(2) * pi<value_type> / size_;
        size_type dst = 2;

        for (size_type i = 0; i < size_; ++i) {
            re1[i] /= size_;
            im1[i] /= size_;
        }

        for (size_type i = 0; i < power_; ++i) {

            size_type num = size_ / dst;
            value_type step = theta / num;

            for (size_type j = 0; j < size_; ++j) {

                value_type angle{};
                size_type num2 = size_ / 2;

                for (size_type k = 0; k < size_; ++k) {
                    size_type to = j * dst + k;
                    value_type s = std::sin(angle);
                    value_type c = std::cos(angle);
                    if (k < num2) {
                        size_type from = to + num2;
                        re2[to] = re1[to] + re1[from] * c - im1[from] * s;
                        im2[to] = im1[to] + im1[from] * c + re1[from] * s;
                    } else {
                        size_type from = to - num2;
                        re2[to] = re1[from] + re1[to] * c - im1[to] * s;
                        im2[to] = im1[from] + im1[to] * c + re1[to] * s;
                    }
                    angle += step;
                }
            }
            std::swap(re1, re2);
            std::swap(im1, im2);
            dst *= 2;
        }

        re_ = re1;
        im_ = im1;
    }


private:
    allocator_type allocator_;
    size_type size_;
    size_type power_;
    size_type nyquist_size_;
    size_type capacity_;
    pointer_type work_;
    pointer_type work_last_;
    pointer_type re_;
    pointer_type re_first_;
    pointer_type im_;
    pointer_type im_first_;
};

} // namespace gdv

#endif

