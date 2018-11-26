#ifndef COMPLEX_HPP
#define COMPLEX_HPP

namespace tutorial {
    class Complex {
    public:
        constexpr Complex(double re=0.0, double im=0.0);

        Complex& operator+=(Complex rhs);
        Complex& operator+=(double rhs);

        Complex& operator-=(Complex rhs);
        Complex& operator-=(double rhs);

        Complex& operator*=(Complex rhs);
        Complex& operator*=(double rhs);

        Complex& operator/=(Complex rhs);
        Complex& operator/=(double rhs);

        constexpr double real() const;
        constexpr double imag() const;

    private:
        double re_;
        double im_;
    };

    constexpr Complex::Complex(double re, double im):
        re_{re},
        im_{im}
    {}

    // user defined literal
    constexpr Complex operator""_i(long double d) {
        return {0, static_cast<double>(d)};
    }

    Complex operator+(Complex a, Complex b);
    Complex operator-(Complex a, Complex b);
    Complex operator/(Complex a, Complex b);
    Complex operator*(Complex a, Complex b);

    constexpr double Complex::real() const {
        return re_;
    }

    constexpr double Complex::imag() const {
        return im_;
    }

    inline bool operator==(Complex a, Complex b) {
        return a.real()==b.real() && a.imag()==b.imag();
    }

    inline bool operator!=(Complex a, Complex b) {
        return !(a==b);
    }

}


#endif
