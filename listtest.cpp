#include "list.hpp"
#include <cassert>
int main(){
    List<int> list;

    list.push_back(2);
    assert(list.at(0) == 2);
    assert(list.get_size()==1);

    list.push_front(3);
    assert(list.at(0) == 3);
    assert(list.at(1) == 2);
    assert(list.get_size() == 2);

    list.insert(1, 4);
    assert(list.at(0) == 3);
    assert(list.at(1) == 4);
    assert(list.at(2) == 2);
    assert(list.get_size() == 3);

    list.pop_back();
    assert(list.get_size() == 2);

    list.pop_front();
    assert(list.at(0) == 4);
    assert(list.get_size() == 1);

    list.push_back(4);
    list.push_back(5);
    list.pop(1);
    assert(list.at(0) == 4);
    assert(list.at(1) == 5);
    return 0;
}