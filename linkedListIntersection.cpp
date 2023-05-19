#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() { //The destructor has the same name as the class preceded by a ~ (tilde) symbol
        delete next;
    }
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        
        return a;
    }
};

int main() {
    // Create the first linked list: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode* intersectionNode = new ListNode(8);
    headA->next->next = intersectionNode;
    intersectionNode->next = new ListNode(4);
    intersectionNode->next->next = new ListNode(5);

    // Create the second linked list: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersectionNode;

    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        std::cout << "Intersection Node: " << intersection->val << std::endl;
    } else {
        std::cout << "No Intersection Found" << std::endl;
    }

    // Clean up memory
    delete headA;

    return 0;
}
