class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


def is_palindromic_linked_list(head):
    slow_ptr = head
    fast_ptr = head
    prev_of_slow_ptr = head

    # To handle odd size list
    midnode = None

    # Initialize result
    res = True

    if (head is not None and
            head.next is not None):

        # Get the middle of the list.
        # Move slow_ptr by 1 and
        # fast_ptrr by 2, slow_ptr
        # will have the middle node
        while (fast_ptr is not None and
                fast_ptr.next is not None):

            # We need previous of the slow_ptr
            # for linked lists  with odd
            # elements
            fast_ptr = fast_ptr.next.next
            prev_of_slow_ptr = slow_ptr
            slow_ptr = slow_ptr.next

        # fast_ptr would become NULL when
        # there are even elements in the
        # list and not NULL for odd elements.
        # We need to skip the middle node for
        # odd case and store it somewhere so
        # that we can restore the original list
        if (fast_ptr is not None):
            midnode = slow_ptr
            slow_ptr = slow_ptr.next

        # Now reverse the second half
        # and compare it with the first half
        second_half = slow_ptr

        # NULL terminate first half
        prev_of_slow_ptr.next = None

        # Reverse the second half
        second_half = reverse(second_half)

        # Compare
        res = compareLists(head, second_half)

        # Construct the original list back
        # Reverse the second half again
        second_half = reverse(second_half)

        if (midnode is not None):

            # If there was a mid node (odd size
            # case) which was not part of either
            # first half or second half.
            prev_of_slow_ptr.next = midnode
            midnode.next = second_half
        else:
            prev_of_slow_ptr.next = second_half
    return res


def reverse(head):
    prev = None
    while (head is not None):
        next = head.next
        head.next = prev
        prev = head
        head = next
    return prev


def compareLists(head1, head2):
    temp1 = head1
    temp2 = head2

    while (temp1 and temp2):
        if (temp1.value == temp2.value):
            temp1 = temp1.next
            temp2 = temp2.next
        else:
            return False

    # Both are empty return 1
    if (temp1 is None and temp2 is None):
        return True

    # Will reach here when one is NULL
    # and other is not
    return False


def main():
    head = Node(2)
    head.next = Node(4)
    head.next.next = Node(6)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(2)

    print("Is palindrome: " + str(is_palindromic_linked_list(head)))

    head.next.next.next.next.next = Node(2)
    print("Is palindrome: " + str(is_palindromic_linked_list(head)))


main()
