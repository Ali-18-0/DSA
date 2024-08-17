#include <iostream>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;  // Pointer to previous node, initially nullptr
    ListNode* curr = head;     // Pointer to current node, starts at head
    ListNode* next = nullptr;  // Pointer to next node, used for traversal
    
    while (curr != nullptr) {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move prev to current node
        curr = next;        // Move curr to next node (originally the next node)
    }
    
    return prev;  // New head of the reversed list
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Creating a linked list 1 -> 2 -> 3 -> 4 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    std::cout << "Original List: ";
    printList(head);

    head = reverseList(head);  // Reverse the list

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}