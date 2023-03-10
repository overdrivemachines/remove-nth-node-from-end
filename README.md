# remove-nth-node-from-end

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?

# Solution

Method 1:

1. Reverse the linked list
2. Find the nth node and its previous node
3. Point the previous node to the nth's next node
4. Reverse the linked list again

Runtime: 7 ms Beats 41.54%
Memory: 10.6 MB Beats 79.90%

Method 2: 2 Pointers

1. left = 1st node. right = nth node.
2. move both left and right down the list until right->next is NULL
3. left will point to the node we want to remove

Runtime: 3 ms Beats 83.85%
Memory: 10.6 MB Beats 79.90%
