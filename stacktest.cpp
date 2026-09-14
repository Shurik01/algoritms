#include "stack.hpp"
#include <cassert>
int main(){
    Stack<int> s;

    s.push(1);
    assert(s.get_element()==1);

    s.push(3);
    assert(s.get_element() == 3);

    s.pop();
    assert(s.get_element() == 1);
    return 0;
}
