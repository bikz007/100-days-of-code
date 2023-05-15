struct PostingListNode
{
    int data{};
    int order{-1};
    PostingListNode* jump{nullptr};
    PostingListNode* next{nullptr};
};

void set_jump_order_helper_rec(PostingListNode* l,int* order)
{
    if(l && l->order == -1)
    {
        l->order = *(order)++;
        set_jump_order_helper_rec(l->jump,order);
        set_jump_order_helper_rec(l->next,order);
    }
}

void set_jump_order_rec(PostingListNode* l)
{
    set_jump_order_helper_rec(l,new int(0));
}

void set_jump_order_iter(PostingListNode* l)
{
    std::stack<PostingListNode*> s;
    int order = 0;
    s.emplace(l);

    while(!s.empty())
    {
        auto curr_node = s.top();
        s.pop();

        if(curr_node && curr_node->order == -1)
        {
            curr_node->order = order++;
            s.emplace(s->next);
            s.emplace(s->jump);
        }
    }
}