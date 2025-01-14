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

ListNode* middleNode(ListNode* head) {
    if (head == nullptr) return nullptr;

    // Collect all nodes in a vector
    vector<ListNode*> nodes; 
    nodes.push_back(head); // what does push_back do? adds an element(head) to the end of a vector
    
    ListNode* current = head->next;
    while (current != nullptr) {
        nodes.push_back(current);
        current = current->next;
    }

    // Compute the "middle" index
    int length = nodes.size();
    // If there's only one node, return it
    if (length < 2) {
        return nodes[0];
    }

    // Divide length by 2
    int half = length / 2;
    // For even lengths, this automatically gives the "second" middle.
    // For odd lengths, it gives the single middle.

    // The original Go code has an if-check using (length % half == 1), but it
    // returns the same index either way. So effectively, returning nodes[half] works.
    return nodes[half];
}

// Helper function to print the list from a given node (for testing)
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    // Example usage:
    // Construct a list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    cout << "List: ";
    printList(head);

    // Find middle
    ListNode* mid = middleNode(head);
    cout << "Middle node value: " << (mid ? mid->val : -1) << endl;

    // Clean up (in real code, you'd delete all nodes)
    return 0;
}
