#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Solver {

    public:
        Solver() {}

        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };
        

        /*
         *  Removes nodes from LinkedList with val delVal, and returns
         *  number of elements removed.
         * 
         */
        int numberElementsRemoved(int delVal, ListNode *head) {
            int delCount = 0;
            printLinkedList(head);

            // Check for empty list.
            if (head == nullptr) {
                printLinkedList(head);
                return delCount;
            }

            // Find the legitimate head of the list.
            ListNode *start     = head;
            while (start->val == delVal) {
                delCount++;
                if (start->next == NULL) {
                    head = NULL;
                    printLinkedList(head);
                    return delCount;
                }
                start = start->next;
            }
            
            // Now go through list, removing elements.
            ListNode *currNode  = start;
            // Iterate through linked-list, until we reach the end.
            while (currNode->next != NULL) {
                // While the next value exists and should be removed, remove it.
                while (currNode->next != NULL && currNode->next->val == delVal) {
                    currNode->next = currNode->next->next;
                    delCount++;
                }
                if (currNode->next == NULL) break;
                currNode = currNode->next;
            }

            printLinkedList(start);

            return delCount;
        }

        ListNode* reverseLinkedList(ListNode *head) {
            printLinkedList(head);

            ListNode *prevNode  = NULL;
            ListNode *currNode  = head;

            // Reverse linked list.
            while (currNode != NULL) {
                ListNode *nextTemp = currNode->next;
                currNode->next = prevNode;
                
                prevNode = currNode;
                currNode = nextTemp;
            }

            printLinkedList(prevNode);
            return prevNode;
        }

        ListNode* craftLinkedList(std::vector<int> list) {
            if (list.size() == 0) return NULL;
            ListNode *head = new ListNode(list[0]);
            ListNode *currNode = head;
            for (int i = 1; i < list.size(); i++) {
                currNode->next = new ListNode(list[i]);
                currNode = currNode->next;
            }
            return head;
        }


    private:

        void printLinkedList(ListNode *head) {
            ListNode *currNode = head;
            printf("\n[");
            while (currNode != NULL) {
                printf("%d", currNode->val);
                if (currNode->next != NULL)
                    printf(", ");
                currNode = currNode->next;
            }
            printf("]");
        }

};