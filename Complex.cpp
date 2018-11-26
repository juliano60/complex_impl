#include "Complex.hpp"
#include <stdexcept>

namespace tutorial {
    Complex& Complex::operator+=(Complex rhs) {
        re_ += rhs.re_;
        im_ += rhs.im_;

        return *this;
    }

    Complex& Complex::operator-=(Complex rhs) {
        re_ -= rhs.re_;
        im_ -= rhs.im_;

        return *this;
    }

    Complex& Complex::operator*=(Complex rhs) {
        double r = re_*rhs.re_ - im_*rhs.im_;
        double i = re_*rhs.im_ + im_*rhs.re_;

        re_ = r;
        im_ = i;

        return *this;
    }

    Complex& Complex::operator/=(Complex rhs) {
        double denom = rhs.re_*rhs.re_ + rhs.im_*rhs.im_;
        
        if (!denom) {
            throw std::runtime_error{"Division by zero"};
        }

        double r = (re_*rhs.re_ + im_*rhs.im_) / denom;
        double i = (im_*rhs.re_ - re_*rhs.im_) / denom;

        re_ = r;
        im_ = i;

        return *this;
    }

    Complex operator+(Complex a, Complex b) {
        a+=b;
        return a;
    }

    Complex operator-(Complex a, Complex b) {
        a-=b;
        return a;
    }

    Complex operator/(Complex a, Complex b) {
        a/=b;
        return a;
    }
    
    Complex operator*(Complex a, Complex b) {
        a*=b;
        return a;
    }

} 

