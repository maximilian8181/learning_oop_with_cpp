#include <bits/stdc++.h>

using namespace std;

class Fraction {
public:
    static const Fraction half;
    static const Fraction third;
    static const Fraction fourth;
    static const Fraction fifth;
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction add(Fraction another_frac) const;
    Fraction subtract(Fraction another_frac) const;
    Fraction multiply(Fraction another_frac) const;
    Fraction divide(Fraction another_frac) const;
    void print() const;
    void compare(Fraction another_frac) const;
    inline int GetNumerator() const { return this->numerator; }
    inline int GetDenominator() const { return this->denominator; }
private:
    int numerator;
    int denominator;
    void simplify();
    int gcd(int a, int b);
};

Fraction::Fraction():Fraction(0, 1) {

}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction Fraction::add(Fraction another_frac) const {
    Fraction result;

    if(this->denominator == another_frac.denominator) {
        result.numerator = this->numerator + another_frac.numerator;
        result.denominator = this->denominator;
    }
    else {
        result.numerator = (this->numerator * another_frac.denominator) + (another_frac.numerator * this->denominator);
        result.denominator = this->denominator * another_frac.denominator;
    }

    result.simplify();

    return result;
}

Fraction Fraction::subtract(Fraction another_frac) const {
    Fraction result;

    if(this->denominator == another_frac.denominator) {
        result.numerator = this->numerator - another_frac.numerator;
        result.denominator = this->denominator;
    }
    else {
        result.numerator = (this->numerator * another_frac.denominator) - (another_frac.numerator * this->denominator);
        result.denominator = this->denominator * another_frac.denominator;
    }

    result.simplify();

    return result;
}

Fraction Fraction::multiply(Fraction another_frac) const {
    Fraction result;

    result.numerator = this->numerator * another_frac.numerator;
    result.denominator = this->denominator * another_frac.denominator;

    result.simplify();

    return result;
}

Fraction Fraction::divide(Fraction another_frac) const {
    Fraction result;

    result.numerator = this->numerator * another_frac.denominator;
    result.denominator = this->denominator * another_frac.numerator;

    result.simplify();

    return result;
}

void Fraction::simplify() {
    if(numerator == 0) {
        denominator = 1;
        return;
    }

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

int Fraction::gcd(int a, int b) { 
    a = abs(a);
    b = abs(b);

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void Fraction::compare(Fraction another_frac) const {
    int left = this->numerator * another_frac.denominator;
    int right = another_frac.numerator * this->denominator;

    if(left < right) {
        cout << this->numerator << "/" << this->denominator << " is smaller than " << another_frac.numerator << "/" << another_frac.denominator << endl;
    }
    else if(left > right) {
        cout << this->numerator << "/" << this->denominator << " is bigger than " << another_frac.numerator << "/" << another_frac.denominator << endl;
    }
    else {
        cout << this->numerator << "/" << this->denominator << " is equal to " << another_frac.numerator << "/" << another_frac.denominator << endl;
    }
}

void Fraction::print() const {
    cout << this->numerator << "/" << this->denominator << endl;
}

const Fraction Fraction::half = Fraction(1, 2);
const Fraction Fraction::third = Fraction(1, 3);
const Fraction Fraction::fourth = Fraction(1, 4);
const Fraction Fraction::fifth = Fraction(1, 5);

int main() {
    Fraction f1 = Fraction(1, 6);
    Fraction f2 = Fraction(1, 10);

    Fraction f1_addition = f1.add(f2);
    Fraction f1_subtraction = f1.subtract(f2);
    Fraction f1_multiplication = f1.multiply(f2);
    Fraction f1_division = f1.divide(f2);
    
    f1_addition.print();
    f1_subtraction.print();
    f1_multiplication.print();
    f1_division.print();

    f1.compare(f2);

    Fraction f2_addition = f2.add(Fraction::half);
    f2_addition.print();

    Fraction::third.compare(Fraction::fourth);

    Fraction::fourth.print();

    Fraction test = Fraction::fifth.multiply(Fraction::half);
    test.print();

    return 0;
}
