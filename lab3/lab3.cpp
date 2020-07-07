#include "lab3.h"
#include <iostream>
using namespace std;

int_list_t::int_list_t(): s(0), first(nullptr), last(nullptr) { }
int_list_t::int_list_t(const int_list_t &other): int_list_t() {
    node_t *current_node = other.first;
    for (int i = 0; i < other.s; i++) {
        push_back(current_node->val);
        current_node = current_node->next;
    }
    s = other.s;
}
int_list_t::int_list_t(size_t count, int value): int_list_t() {
    for (int i = 0; i < count; i++) {
        push_back(value);
    }
}
int_list_t::~int_list_t() { clear(); }

int_list_t& int_list_t::operator=(const int_list_t &other) {
    if (this == &other) {
        return *this;
    }
    int_list_t other_list(other);
    int_list_t::swap(other_list);
    return *this;
}

int_list_t::node_t *int_list_t::get(size_t pos) const {
    if (pos >= 0 && pos <= s/2) {
        node_t *current = first;
        while (pos > 0) {
            current = current->next;
            pos--;
        }
        return current;
    } else if (pos > s/2 && pos < s) {
        node_t *current = last;
        while (pos < s-1) {
            current = current->prev;
            pos++;
        }
        return current;
    } else {
        cout << "Error! Invalid pos" << endl;
        return nullptr;
    }
}
int& int_list_t::operator[](size_t pos) {
    node_t *needed = get(pos);
    return needed->val;
}
const int int_list_t::operator[](size_t pos) const {
    node_t *needed = get(pos);
    return needed->val;
}

int& int_list_t::back() { return last->val; }
const int int_list_t::back() const { return last->val; }
int& int_list_t::front() { return first->val; }
const int int_list_t::front() const { return first->val; }

void int_list_t::clear() {
    node_t *current = first, *next_node;
    for (int i = 0; i < s; i++) {
        next_node = current->next;
        delete current;
        current = next_node;
    }
    s = 0;
    first = nullptr;
    last = nullptr;
}
size_t int_list_t::size() const { return s; }
bool int_list_t::empty() const { return s==0; }

void int_list_t::insert(size_t pos, int new_val) {
    if (pos == 0) {
        push_front(new_val);
    } else if (pos == s) {
        push_back(new_val);
    } else {
        node_t *next_node = get(pos), *prev_node = next_node->prev;
        auto *new_node = new node_t(new_val, next_node, prev_node);
        prev_node->next = new_node;
        next_node->prev = new_node;
        s++;
    }
}
void int_list_t::push_front(int new_val) {
    if (empty()) {
        auto *new_node = new node_t(new_val, nullptr, nullptr);
        first = new_node;
        last = new_node;
    } else {
        node_t *next_node = first;
        auto *new_node = new node_t(new_val, next_node, nullptr);
        next_node->prev = new_node;
        first = new_node;
    }
    s++;
}
void int_list_t::push_back(int new_val) {
    if (empty()) {
        auto *new_node = new node_t(new_val, nullptr, nullptr);
        first = new_node;
        last = new_node;
    } else {
        node_t *prev_node = last;
        auto *new_node = new node_t(new_val, nullptr, prev_node);
        prev_node->next = new_node;
        last = new_node;
    }
    s++;
}

void int_list_t::erase(size_t pos) {
    if (pos == 0) {
        pop_front();
    } else if (pos == s-1) {
        pop_back();
    } else {
        node_t *waste_node = get(pos), *prev_node = waste_node->prev, *next_node = waste_node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete waste_node;
        s--;
    }
}
void int_list_t::pop_front() {
    node_t *waste_node = first, *next_node = waste_node->next;
    next_node->prev = nullptr;
    delete waste_node;
    first = next_node;
    s--;
}
void int_list_t::pop_back() {
    node_t *waste_node = last, *prev_node = waste_node->prev;
    prev_node->next = nullptr;
    delete waste_node;
    last = prev_node;
    s--;
}

int_list_t int_list_t::splice(size_t start_pos, size_t count){
    int_list_t result;
    node_t *current = get(start_pos);
    for (int i = 0; i < count; i++) {
        result.push_back(current->val);
        current = current->next;
        erase(start_pos);
    }
    first = get(0);
    last = get(s-1);

    result.s = count;
    result.first = result.get(0);
    result.last = result.get(s-1);

    return result;
}
int_list_t& int_list_t::merge(int_list_t &other) {
    s += other.s;
    other.first->prev = last;
    last->next = other.first;
    last = other.last;
    return *this;
}

void int_list_t::reverse() {
    node_t *current = first;
    for (int i = 0; i < s; i++) {
        std::swap(current->prev, current->next);
        current =current->prev;
    }
    std::swap(first, last);
}
void int_list_t::swap(int_list_t &other) {
    std::swap(s, other.s);
    std::swap(first, other.first);
    std::swap(last, other.last);
}

istream& operator>>(istream &stream, int_list_t &list) {
    int new_val;
    if (stream >> new_val) {
        list.push_back(new_val);
    }
    return stream;
}
ostream& operator<<(ostream &stream, const int_list_t &list) {
    for (int i = 0; i < list.s; i++) {
        stream << list[i] << " ";
    }
    return stream;
}

int main() {
    int_list_t list1, list2, list3;
    cout << "list1 empty? " << list1.empty() << endl;
    for (int i = 0; i < 10; i++) {
        list1.push_front(i);
    }
    cout << "And now list1 empty? " << list1.empty() << endl;
    cout << "Size: " << list1.size() << "; First: " << list1.front() << "; Last: " << list1.back() << endl;
    cout << "list1: " << list1 << endl;

    list2 = list1;
    cout << endl << "list2 (equal list1): " << list2 << endl;
    list2.reverse();
    cout << "Reversed list2: " << list2 << endl;

    list1.pop_front();
    cout << endl << "list1 without first element: " << list1 << endl;
    list1.erase(4);
    cout << "list1 without IV element: " << list1 << endl;
    list1.pop_back();
    cout << "list1 without last element: " << list1 << endl;

    list1.insert(0, 9);
    cout << endl << "list1 with new first element: " << list1 << endl;
    list1.insert(5, 4);
    cout << "list1 with new V element: " << list1 << endl;
    list1.insert(list1.size(), 0);
    cout << "list1 with new last element: " << list1 << endl;

    list3 = list1.splice(0, 5);
    cout << endl << "list3 with first 5 elements of list1: " << list3 << endl;
    cout << "list1 after splice: " << list1 << endl;

    list1.merge(list3);
    cout << endl << "list1 merge with list3: " << list1 << endl;

    return 0;
};