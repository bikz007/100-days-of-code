class CircularQueue
{
    public:
    CircularQueue(uint32_t capacity) : entries_(capacity) {}
    uint32_t size_of_queue(){ return num_of_elements;}
    void enqueue(int elem)
    {
        if(num_of_elements == entries_.size())
        {
            std::rotate(entries_.begin(),entries_.begin()+head,entries_.end());
            head = 0;
            tail = num_of_elements;
            entries_.resize(entries_.size()*kScaleFactor);
        }
        entries_[tail] = elem;
        tail = (tail+1) % entries_.size();
        ++num_of_elements;
    }
    int dequeue()
    {
        if(!num_of_elements)
        {
            std::runtime_error("Empty queue");
        }
         --num_of_elements;
         auto ret_elem = entries_[head];
         head = (head+1) % entries_.size();
         return ret_elem;

    }
    private:
    const uint32_t kScaleFactor = 2;
    uint32_t head = 0, tail = 0, num_of_elements = 0;
    std::vector<int> entries_;
};