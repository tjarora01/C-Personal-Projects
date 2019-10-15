Complex& Complex::operator/= (const Complex& rhs) {
    Complex finalComplex;

    double divisor = (rhs.re * rhs.re) + (rhs.im * rhs.im);
    double num_re = (this->re * rhs.re) + (this->im * rhs.im);
    double num_img = (this->im * rhs.re) - (this->re * rhs.im);

    this->re = num_re/divisor;
    this->im = num_img/divisor;
    return finalComplex;
}

