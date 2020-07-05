#ifndef LABS_CPP_LAB2_B_H
#define LABS_CPP_LAB2_B_H


template <class T>
class safe_c_array_t {
private:
    size_t size;
    T *arr;
public:
    //constructor
    explicit safe_c_array_t(size_t new_size): size(new_size), arr(new T[size]) { }
    //copy constructor
    safe_c_array_t(const safe_c_array_t &s_c_a_t) {
        size = s_c_a_t.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = s_c_a_t[i];
        }
    }

    //size getter
    size_t get_size() { return size; }

    //assignment operator
    safe_c_array_t& operator=(const safe_c_array_t<T> &r) {
        if (this == &r) {
            cout << endl << "self-assignment!";
            return *this;
        }
        delete[] arr;
        size = r.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = r[i];
        }
        return *this;
    }

    //operator[]
    T& operator[] (const size_t index) { return arr[index]; }
    const T& operator[] (const size_t index) const { return arr[index]; }

    //destructor
    ~safe_c_array_t() { delete[] arr; }
};


#endif //LABS_CPP_LAB2_B_H
