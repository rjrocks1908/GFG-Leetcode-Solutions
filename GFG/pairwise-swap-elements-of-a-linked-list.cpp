/*
Question-
https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

Intuition-
The idea in this to traverse the linked list and swap each pair of adjacent node. To do this,
we would be using 3 pointers - prev, curr and next.
prev - to change the prevously swapped element next pointer to point to the newly swapped element
curr - to change the current pointer element to the next pointer element
next - keep a track of the next element to the current element.

Implementation-
Simple implementation Just do the dry run.

Complexities-
TC: O(N)
SC: O(1)
*/

class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if (head == NULL or head->next == NULL)
            return head;
        
        Node *curr = head;
        Node *prev = NULL;
        head = head->next;
        
        while (curr != NULL and curr->next != NULL) {
            
            Node *next = curr->next;
            curr->next = next->next;
            next->next = curr;
            if (prev != NULL) {
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
            
        }
        
        return head;
    }
};