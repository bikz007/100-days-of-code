#include<iostream>
#include<stack>

class MyStack
{
    private:
    struct ElementWithCachedMax
    {
        int element{}, max{};
    };
    std::stack<ElementWithCachedMax> element_with_cached_max_;

    public:
    bool empty()
    {
        return element_with_cached_max_.empty();
    }

    int peekMax()
    {
        if(empty())
        {
            return -9999;
        }
        else{
            return element_with_cached_max_.top().max;
        }
    }

    void push(int x)
    {
        element_with_cached_max_.emplace(ElementWithCachedMax{x, std::max(x,empty() ? x : peekMax())});
    }

    int pop()
    {
        if(empty())
        {
            return -9999;
        }
        else{
            auto pop_elem = element_with_cached_max_.top().element;
            element_with_cached_max_.pop();
            return pop_elem;
        }
    }
};