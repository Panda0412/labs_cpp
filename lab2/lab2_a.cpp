#include "lab2_a.h"
#include <iostream>
using namespace std;

//constructor
safe_long_long_t::safe_long_long_t(long long new_val): val(new_val) { }
//copy constructor
safe_long_long_t::safe_long_long_t(const safe_long_long_t &s_l_l_t): val(s_l_l_t.val) { }

//getter
const long long &safe_long_long_t::get_val(){ return val; }

//assignment operator
safe_long_long_t& safe_long_long_t::operator=(const safe_long_long_t &r) {
    if (this == &r) {
        cout << "self-assignment:";
        return *this;
    }
    cout << "assignment:";
    val = r.val;
    return *this;
}

//++a
const safe_long_long_t safe_long_long_t::operator++() { return ++val; };
//a++
const safe_long_long_t safe_long_long_t::operator++(int) { return val++; };

//--a
const safe_long_long_t safe_long_long_t::operator--() { return --val; };
//a--
const safe_long_long_t safe_long_long_t::operator--(int) { return val--; };

//math operators with =
safe_long_long_t& safe_long_long_t::operator+= (const safe_long_long_t &r) {
    val += r.val;
    return *this;
};
safe_long_long_t& safe_long_long_t::operator-= (const safe_long_long_t &r) {
    val -= r.val;
    return *this;
};
safe_long_long_t& safe_long_long_t::operator*= (const safe_long_long_t &r) {
    val *= r.val;
    return *this;
};
safe_long_long_t& safe_long_long_t::operator/= (const safe_long_long_t &r) {
    val /= r.val;
    return *this;
};
safe_long_long_t& safe_long_long_t::operator%= (const safe_long_long_t &r) {
    val %= r.val;
    return *this;
};

//math operators without =
safe_long_long_t operator+ (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() + r.get_val();
};
safe_long_long_t operator- (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() - r.get_val();
};
safe_long_long_t operator* (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() * r.get_val();
};
safe_long_long_t operator/ (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() / r.get_val();
};
safe_long_long_t operator% (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() % r.get_val();
};

//comparative operators
bool operator== (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() == r.get_val();
};
bool operator!= (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() != r.get_val();
};
bool operator> (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() > r.get_val();
};
bool operator>= (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() >= r.get_val();
};
bool operator< (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() < r.get_val();
};
bool operator<= (safe_long_long_t l, safe_long_long_t r) {
    return l.get_val() <= r.get_val();
};

//output and input operators
ostream& operator<< (ostream &out, const safe_long_long_t &s_l_l_t) {
    out << s_l_l_t.val;
    return out;
}
istream& operator>> (istream &in, safe_long_long_t &s_l_l_t) {
    in >> s_l_l_t.val;
    return in;
}

int main() {
    //tests

    //constructors and input
    safe_long_long_t a(10), b, c;
    cout << "Enter value for b:" << endl;
    cin >> b;
    safe_long_long_t d(a);
    cout << endl << "a = " << a << "; b = " << b << "; c = " << c << "; d = " << d << endl;

    //assignments typeid(a).name()
    cout << "d = d - "; d = d; cout << " d = " << d << endl;
    cout << "d = c - "; d = c; cout << " d = " << d << endl;

    //increments
    cout << endl << "increments:" << endl;
    safe_long_long_t x(10), y(10);
    cout << "old x = " << x << "; old y = " << y << endl;
    safe_long_long_t x1(x++), y1(++y);
    cout << "post-increment: x++ = " << x1 << "; new x = " << x << endl;
    cout << "pre-increment: ++y = " << y1 << "; new y = " << y << endl;

    //decrement
    cout << endl << "decrements:" << endl;
    safe_long_long_t m(10), n(10);
    cout << "old x = " << m << "; old y = " << n << endl;
    safe_long_long_t m1(m--), n1(--n);
    cout << "post-decrement: x-- = " << m1 << "; new x = " << m << endl;
    cout << "pre-decrement: --y = " << n1 << "; new y = " << n << endl;

    cout << endl << "a = " << a << "; b = " << b << "; x = " << x << endl;
    a += b; cout << "a += b: a = " << a << endl;
    a -= b; cout << "a -= b: a = " << a << endl;
    a *= b; cout << "a *= b: a = " << a << endl;
    a /= b; cout << "a /= b: a = " << a << endl;
    x %= a; cout << "x %= a: x = " << x << endl;

    x += 10;
    cout << endl << "a = " << a << "; b = " << b << "; x = " << x << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "x % a = " << x % a << endl;

    cout << endl << "a = " << a << "; b = " << b << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a <= b: " << (a <= b) << endl;

    return 0;
}