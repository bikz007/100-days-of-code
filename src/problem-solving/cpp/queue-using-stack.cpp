class MyQueue
{
    void enqueue(int elem){ enq.emplace_back(elem);}
    int dequeue()
    {
         if(deq.empty())
         {
            while(!enq.empty())
            {
                deq.emplace_back(enq.top());
                enq.pop();
            }
         }
         int ret_elem = deq.top();
         deq.pop();
         return ret_elem;
    }
private:
    std::stack<int> enq, deq;
};