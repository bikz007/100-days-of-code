"""
Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.
Example-1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example-2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example-3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
"""

from __future__ import print_function


class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

    def print_list(self):
        temp = self
        while temp is not None:
            print(temp.value, end='')
            temp = temp.next
        print()


def find_cycle_length(head):
    fast, slow = head, head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next

        if slow == fast:
            return count_cycle_length(slow)
    return 0


def count_cycle_length(head):
    current = head
    cycle_length = 0
    if not current:
        return cycle_length
    while True:
        cycle_length += 1
        current = current.next

        if current == head:
            break
    return cycle_length


def find_cycle_start(head):
    if not head:
        return head
    else:
        k = find_cycle_length(head)
        ptr1, ptr2 = head, head
        while k:
            k -= 1
            ptr2 = ptr2.next

        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next

        return ptr1


def main():
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)
    head.next.next.next.next.next = Node(6)

    head.next.next.next.next.next.next = head.next.next
    print("LinkedList cycle start: " +
          str(find_cycle_start(head).value))

    head.next.next.next.next.next.next = head.next.next.next
    print("LinkedList cycle start: " +
          str(find_cycle_start(head).value))

    head.next.next.next.next.next.next = head
    print("LinkedList cycle start: " +
          str(find_cycle_start(head).value))


main()
