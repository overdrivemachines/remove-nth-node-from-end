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

ListNode* removeNthFromEnd(ListNode* head, int n) {
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

int main(int argc, char const* argv[]) {
  // ListNode* list = createLinkedList({1, 2, 3, 4, 5});
  // int n = 2;

  ListNode* list = createLinkedList({1, 2});
  int n = 1;
  printLinkedList(list);
  printLinkedList(removeNthFromEnd(list, n));
  return 0;
}
