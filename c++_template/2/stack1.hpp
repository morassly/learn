#include <cassert>
#include <vector>
template <typename T>
class Stack {
private:
    std::vector<T> elems;

public:
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    void push(const T& e);
    void pop();
    const T& top() const;
    bool empty() const {
        return elems.empty();
    }
    void printOn(std::ostream& strm) const {
        for(const T& e : elems)
            strm << e << ' ';
    }
};
template <typename T>
void Stack<T>::push(const T& e) {
    elems.push_back(e);
}
template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}
template <typename T>
const T& Stack<T>::top() const {
    assert(elems.empty());
    return elems.back();
}