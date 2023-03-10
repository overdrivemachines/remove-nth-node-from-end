#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> values) {
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}

// Method 1:
// 1. Reverse the linked list
// 2. Find the nth node and its previous node
// 3. Point the previous node to the nth's next node
// 4. Reverse the linked list again
// Runtime: 7 ms Beats 41.54%
// Memory: 10.6 MB Beats 79.90%
ListNode* removeNthFromEnd1(ListNode* head, int n) {
  ListNode* prev = nullptr;
  ListNode* cur = head;
  ListNode* next;
  int i = 0;

  if ((head == nullptr) || (n <= 0))
    return head;

  if ((n == 1) && (head->next == nullptr))
    return nullptr;

  // 1, 2, 3, 4, 5
  // reverse the linked list
  while (cur != nullptr) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  head = prev;
  cur = prev;

  // find the nth node and its previous node
  while (++i < n) {
    prev = cur;
    cur = cur->next;
  }

  // cout << "Prev: " << prev->val << endl;
  // cout << "Cur: " << cur->val << endl;

  if (n == 1) {
    head = head->next;
  } else if (n > 1) {
    prev->next = cur->next;
  }

  // reverse the list
  prev = nullptr;
  cur = head;
  while (cur != nullptr) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  head = prev;

  return head;
}

// Method 2: 2 Pointers
// 1. left = 1st node. right = nth node.
// 2. move both left and right down the list until right->next is NULL
// 3. left will point to the node we want to remove
// Runtime: 3 ms Beats 83.85%
// Memory: 10.6 MB Beats 79.90%
ListNode* removeNthFromEnd(ListNode* head, int n) {
  if ((head == nullptr) || (n <= 0))
    return head;

  if ((n == 1) && (head->next == nullptr))
    return nullptr;

  ListNode* left = head;
  // ListNode* cur = head;
  ListNode* right = head;
  int i = 0;

  // assign the right node to be nth node from the start
  for (i = 0; ((i < n) && (right->next)); i++) {
    right = right->next;
  }

  // cout << "Left: " << left->val << " Right: " << right->val << " i: " << i << " n: " << n << endl;

  if (i != n) {
    // remove the head
    return head->next;
  }

  // now move the left pointer down the link list until the right's next is null
  while (right->next != nullptr) {
    left = left->next;
    right = right->next;
  }
  // cout << "Left: " << left->val << " Right: " << right->val << endl;
  // left->next points to the nth node from the end of the list
  if (left->next != nullptr)
    left->next = left->next->next;  // removing the nth node from the end of the list
  return head;
}

int main(int argc, char const* argv[]) {
  // ListNode* list = createLinkedList({1, 2, 3, 4, 5});
  // int n = 2;

  // ListNode* list = createLinkedList({1, 2, 3});
  // int n = 2;  // expected: [1, 3]

  // ListNode* list = createLinkedList({1, 2});
  // int n = 1;  // expected: [1]

  // ListNode* list = createLinkedList({1, 2});
  // int n = 2;  // expected: [2]

  ListNode* list = createLinkedList({1, 2, 3});
  int n = 3;  // expected:
  printLinkedList(list);
  printLinkedList(removeNthFromEnd(list, n));
  return 0;
}
