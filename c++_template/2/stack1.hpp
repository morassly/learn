#include <cassert>
#include <deque>
#include <vector>
template <typename T>
class Stack {
private:
    std::vector<T> elems;

public:
    //Stack(const Stack&);
    //Stack& operator=(const Stack&);
    void push(const T& e);
    void pop();
    const T& top() const;
    bool empty() const {
        return elems.empty();
    }
    void printOn(std::ostream& strm) const {
        for (const T& e : elems)
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

template <>
class Stack<std::string> {
private:
    std::deque<std::string> elems;

public:
    void push(const std::string&);
    void pop();
    const std::string& top() const;
    bool empty() const {
        return elems.empty();
    }
};
void Stack<std::string>::push(const std::string& e) {
    elems.push_back(e);
}
void Stack<std::string>::pop(){
    assert(!elems.empty());
    elems.pop_back();
}
const std::string& Stack<std::string>::top() const{
    assert(!elems.empty());
    return elems.back();
}