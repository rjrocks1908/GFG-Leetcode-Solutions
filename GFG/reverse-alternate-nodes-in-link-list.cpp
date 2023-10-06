/*
Question-
https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1

Intuition-
Connect All Odd Nodes and Connect All even nodes. Now reverse the even nodes
Then connect odd nodes with the reversed even nodes.

Implementation-

Complexities-
TC: O(N)
SC: O(1)
*/

class Solution
{
    public:
    Node *reverse(Node *even) {
        
        Node *prev = NULL;
        Node *curr = even;
        
        while (curr != NULL) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
    
    void rearrange(struct Node *odd)
    {
        //add code here
        if (odd == NULL or odd->next == NULL or odd->next->next == NULL)
            return;
            
        Node *prev = odd;
        Node *curr = odd->next;
        Node *even = curr;
        
        while (curr != NULL and curr->next != NULL) {
            
            Node *next = curr->next;
            prev->next = next;
            prev = next;
            curr->next = next->next;
            curr = next->next;
            
        }
        
        prev->next = NULL;
        
        Node *revEven = reverse(even);
        
        prev->next = revEven;
        
    }
};
