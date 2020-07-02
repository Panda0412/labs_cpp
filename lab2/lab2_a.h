#ifndef LABS_CPP_LAB2_A_H
#define LABS_CPP_LAB2_A_H

#include <iostream>
using namespace std;


class safe_long_long_t {
    private:
        long long val;
    public:
        //constructor
        safe_long_long_t(long long new_val = 0);
        //copy constructor
        safe_long_long_t(const safe_long_long_t &s_l_l_t);

        //getter
        const long long &get_val();

        //assignment operator
        safe_long_long_t& operator=(const safe_long_long_t &r);

        //++a
        const safe_long_long_t operator++();
        //a++
        const safe_long_long_t operator++(int);

        //--a
        const safe_long_long_t operator--();
        //a--
        const safe_long_long_t operator--(int);

        //math operators with =
        safe_long_long_t& operator+= (const safe_long_long_t &r);
        safe_long_long_t& operator-= (const safe_long_long_t &r);
        safe_long_long_t& operator*= (const safe_long_long_t &r);
        safe_long_long_t& operator/= (const safe_long_long_t &r);
        safe_long_long_t& operator%= (const safe_long_long_t &r);

        //output and input operators
        friend ostream& operator<< (ostream &out, const safe_long_long_t &s_l_l_t);
        friend istream& operator>> (istream &in, safe_long_long_t &s_l_l_t);
};


//math operators without =
safe_long_long_t operator+ (safe_long_long_t l, safe_long_long_t r);
safe_long_long_t operator- (safe_long_long_t l, safe_long_long_t r);
safe_long_long_t operator* (safe_long_long_t l, safe_long_long_t r);
safe_long_long_t operator/ (safe_long_long_t l, safe_long_long_t r);
safe_long_long_t operator% (safe_long_long_t l, safe_long_long_t r);

//comparative operators
bool operator== (safe_long_long_t l, safe_long_long_t r);
bool operator!= (safe_long_long_t l, safe_long_long_t r);
bool operator> (safe_long_long_t l, safe_long_long_t r);
bool operator>= (safe_long_long_t l, safe_long_long_t r);
bool operator< (safe_long_long_t l, safe_long_long_t r);
bool operator<= (safe_long_long_t l, safe_long_long_t r);

//output and input operators
ostream& operator<< (ostream &out, const safe_long_long_t &s_l_l_t);
istream& operator>> (istream &in, safe_long_long_t &s_l_l_t);


#endif //LABS_CPP_LAB2_A_H
