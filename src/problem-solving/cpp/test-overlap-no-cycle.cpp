struct list_node
{
    int val{};
    list_node *next{nullptr};

    list_node(int n_val) : val(n_val){}
};

int list_length(list_node *lst)
{
    int count = 0;
    while (lst)
    {
        ++count;
        lst = lst->next;
    }
    return count;
}

void advance_list(int k, list_node **lst)
{
    while (lst && k--)
    {
        *lst = (*lst)->next;
    }
}

list_node *test_overlap_no_cycle(list_node *l1, list_node *l2)
{
    int l1_len = list_length(l1), l2_len = list_length(l2);

    advance_list(abs(l1_len - l2_len), l1_len > l2_len ? &l1 : &l2);

    while (l1 && l2 && l1 != l2)
    {
        l1 = l1->next, l2 = l2->next;
    }

    return l1;
}

int main()
{

    list_node* l1 = new list_node(1);
    l1->next = new list_node(2);
    l1->next->next = new list_node(3);
    l1->next->next->next = new list_node(4);
    l1->next->next->next->next = new list_node(5);

    list_node* l2 = new list_node(1);
    l2->next = l1->next->next->next;

    auto result = test_overlap_no_cycle(l1,l2);

    delete l1;
    delete l2;

    return 0;
}