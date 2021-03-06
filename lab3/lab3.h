#ifndef LABS_CPP_LAB3_H
#define LABS_CPP_LAB3_H

#include <iostream>
using namespace std;


class int_list_t {
private:
    struct node_t {
        int val;
        node_t *next;
        node_t *prev;

        node_t(int new_val, node_t *new_next, node_t *new_prev) {
            val = new_val;
            next = new_next;
            prev = new_prev;
        }
    };
public:
    int_list_t(); // O(1)
    int_list_t(const int_list_t &other); // COPY $other list O(other.size)
    int_list_t(size_t count, int value); // create list $count size and fill it with $value O($count)
    ~int_list_t();    // O(size)

    int_list_t& operator=(const int_list_t &other); // O(size + other.size())

    int& operator[](size_t pos); // O(min($pos, size - $pos))
    const int operator[](size_t pos) const; // O(min($pos, size - $pos))

    int& back();    // last element O(1)
    const int back() const; // O(1)

    int& front();    // first element O(1)
    const int front() const; // O(1)

    void clear(); // O(size)
    size_t size() const; // O(1)
    bool empty() const; // O(1)

    void insert(size_t pos, int new_val); // insert element $new_val BEFORE element with index $pos O(min($pos, size - $pos))
    void push_front(int new_val); // O(1)
    void push_back(int new_val);    // O(1)

    void erase(size_t pos); // remove element with index $pos O(min($pos, size - $pos))
    void pop_front(); // O(1)
    void pop_back();  // O(1)

    int_list_t splice(size_t start_pos, size_t count); // splice part of list into result (not copy!) O($start_pos + $count)
    int_list_t& merge(int_list_t &other); // merge two lists, after operation $other must be valid empty list O(1)

    void reverse(); // O(size)
    void swap(int_list_t &other); // O(1)

    friend istream& operator>>(istream &stream, int_list_t &list);    // O(size)
    friend ostream& operator<<(ostream &stream, const int_list_t &list); // O(size)

private:
    size_t s;
    node_t *first;
    node_t *last;

    node_t *get(size_t pos) const;
};


#endif //LABS_CPP_LAB3_H
