#include <iostream> 
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool containsValue(const vector<ListNode*>& nodes, int value) {
    for (const ListNode* node : nodes) {
        if (node->val == value) {
            return true; // Return true as soon as the value is found
        }
    }
    return false; // If no node has the value, return false
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head != nullptr) {
            int ctr = 1;
            vector<ListNode*> nodes;
            nodes.push_back(head); 
            cout << ctr << "th node: " << head->val << " is unique." << endl; 
            ctr ++; 
            ListNode* current = head->next; 
            ListNode* prev = head;

            while (current != nullptr) {
                if (current != nullptr) {
                    cout << ctr << "th node: " << current->val << " is... "; 
                } 

                if (!containsValue(nodes, current->val)) {
                    nodes.push_back(current); 
                    prev = current;
                    current = current->next; 
                    cout << "unique." << endl; 
                } else {
                    prev->next = current->next;
                    current = current->next;
                    cout << "duplicate." << endl; 
                }

                ctr ++; 
            }
        }
        

       return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Before: ";
    printList(head);

    Solution soln;
    ListNode* uniqueHead = soln.deleteDuplicates(head);

    cout << "After: ";
    printList(uniqueHead);

    return 0;
}