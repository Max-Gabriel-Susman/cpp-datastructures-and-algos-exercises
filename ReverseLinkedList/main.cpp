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


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

class Solution {
public: 
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head != nullptr) {
            // if (head->next != nullptr) {
            //     if (head->next->next == nullptr) {
            //         cout << "before if (right == 2 || left == 2) which is: " << (right == 2 || left == 2) << endl;
            //         if (right != 2 && left != 2) {
            //             cout << "head->next->next == nullptr" << endl;
            //             head->next->next = head; 
            //             ListNode* newHead = head->next;
            //             head->next = nullptr;
            //             return newHead;
            //         }
            //     }
            // }
            int ctr =0;
            cout << "ctr: " << ctr << ", current value: " << head->val << endl; 
            cout << "before loop" << endl; 
            cout << endl;
            vector<ListNode*> nodes;
            vector<ListNode*> nodesBetween;
            nodes.push_back(head);
            // ctr ++;
            // ListNode* current = head->next;
            ListNode* current = head;
            ListNode* prev = head;
            ListNode* prevNodeBetween;
            ListNode* beforeBetween = nullptr;
            ListNode* headBetween;
            int leftIndex = left - 1;

            bool between = false; 
            bool afterNodesBetween = false; 
            bool previouslyHeadBetween = false;
            bool beforeReversal = true;
            bool rightIndexFound = false;
            bool beforeReversalInbetween = true;

            // if (before == nullptr) {
            //     cout << "before == nullptr" << endl;
            // } else {
            //     cout << "before != nullptr" << endl;
            // }

            while (current != nullptr) {
                cout << endl; 
                cout << "ctr: " << ctr << ", leftIndex: " << leftIndex << endl; 
                cout << "ctr: " << ctr << ", current value: " << current->val << endl;
                cout << "right - 2: " << right - 2 << endl;
                // if (ctr == right - 2 && !rightIndexFound) {
                //         cout << "right Index!" << endl; 
                //         between = false;
                //         after = true;
                //         rightIndexFound == true;
                //         nodesBetween.push_back(current);
                //     // prev->next = current;
                //     current = current->next;
                //     cout << "inbetween" << endl;
                //     }

                if (ctr == right - 0) {
                    cout << "right Index!: " << right << endl; 
                    between = false;
                    afterNodesBetween = true;

                    cout << "previous: " << prev->val << endl;

                    nodesBetween.push_back(current);
                    // prev->next = current;
                    current = current->next;
                    
                    cout << "inbetween" << endl;
                } 
                if (afterNodesBetween && beforeReversalInbetween) {
                    cout << "after" << endl;
                    for (int i = nodesBetween.size() - 1; i > -1 ; i--) {
                        if (beforeReversal) {
                            cout << ", first reversal iteration: " << i << ": " << nodesBetween[i]->val << endl;
                            beforeBetween->next = nodesBetween[i];
                            prevNodeBetween = nodesBetween[i];
                            beforeReversal = false;
                        } else {
                            prevNodeBetween->next = nodesBetween[i];
                            prevNodeBetween = nodesBetween[i];
                            cout << ", not first reveral iteration: " << i << ": " << nodesBetween[i]->val << endl;
                        }
                        prevNodeBetween->next = current;
                    }
                    cout << endl;
                    printList(head);
                    cout << endl;
                    cout << "exiting reversal sequencce, ctr: " << ctr << endl << endl;
                    beforeReversalInbetween = false;

                }
                // if (ctr == right) {
                //     cout << "right Index!" << endl; 
                //     between = false;
                //     after = true;
                //     nodesBetween.push_back(current);
                //     // prev->next = current;
                //     current = current->next;
                //     cout << "inbetween" << endl;
                // }
                if (ctr == leftIndex) {
                        cout << "left Index!" << endl;
                        between = true;
                        beforeBetween = prev;
                        cout << "beforeBetween is: " << beforeBetween->val << endl;
                        // nodesBetween.push_back(current);
                        previouslyHeadBetween = true; 
                        headBetween = current;
                } else if (!between) {
                    // if (ctr == leftIndex) {
                    //     cout << "left Index!" << endl;
                    //     between = true;
                    //     beforeBetween = prev;
                    //     cout << "beforeBetween is: " << beforeBetween->val << endl;
                    //     // nodesBetween.push_back(current);
                    //     previouslyHeadBetween = true; 
                    //     headBetween = current;
                    // } else {
                        
                        nodes.push_back(current); 
                        prev = current;
                        current = current->next;
                        cout << "not between" << endl;
                    // }
                    // if (ctr == right) {
                    //     cout << "right Index!" << endl; 
                    // }
                } else {
                    // if (ctr == right) {
                    //     cout << "right Index!" << endl; 
                    //     between = false;
                    //     after = true;
                    // } else {
                    //     // prev->next = current->next;
                    //     // current = current->next;
                    // }
                    // if (previouslyHeadBetween) {
                    //     cout << "previouslyHeadBetween" << endl; 
                    //     prev->next = headBetween;
                    //     previouslyHeadBetween = false;
                    // }
                    // nodesBetween.push_back(current);
                    // // prev->next = current;
                    // current = current->next;
                    // cout << "inbetween" << endl;

                    if (ctr == right) {
                        // cout << "right Index!" << endl; 
                        // between = false;
                        // after = true;
                        //  nodesBetween.push_back(current);
                        // // prev->next = current;
                        // current = current->next;
                        // cout << "inbetween" << endl;
                    } else {
                        nodesBetween.push_back(current);
                        // prev->next = current;
                        current = current->next;
                        cout << "inbetween" << endl;
                    }
                   

                    //   if (ctr != right) {
                    //     nodesBetween.push_back(current);
                    //     // prev->next = current;
                    //     current = current->next;
                    //     cout << "inbetween" << endl;
                    //   }
                }
                cout << endl;
                ctr ++;
            }
            cout << "size of nodesBetween is: " << nodesBetween.size() << endl;
            // for (int i = 0; i < nodesBetween.size(); i++) {
            for (int i = nodesBetween.size() - 1; i > -1 ; i--) {
                cout << ", " << i << ": " << nodesBetween[i]->val << endl;
            }
        }
        return head;
    }
};


int main() {
    cout << "Before: ";
    
    // issue must lie with needing a preceding node
    // ListNode* head = new ListNode(3);
    // head->next = new ListNode(5);

    // sorts but has memory error, must rely on a node after inbetween
    // ListNode* head = new ListNode(7);
    // head->next = new ListNode(3);
    // head->next->next = new ListNode(5);

    ListNode* head = new ListNode(7);
    head->next = new ListNode(3);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(1);

    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    printList(head);

    Solution soln;
    // ListNode* uniqueHead = soln.reverseBetween(head, 1, 2);
    ListNode* uniqueHead = soln.reverseBetween(head, 2, 3);
    // ListNode* uniqueHead = soln.reverseBetween(head, 2, 4);

    cout << "After: ";
    printList(uniqueHead);

    return 0;
}