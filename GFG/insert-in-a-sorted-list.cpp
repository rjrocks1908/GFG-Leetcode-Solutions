/*
Question-
https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

Intuition-
Find the just larger number than the given number and then using prev pointer which point
to the previous node to the greater number than data we can insert the node in between them.
But before that we also need to handle cases where element is added in the front or in the 
last of the linked list

Implementation-
Take two pointers prev and curr
Check whether data is smaller than the first node, if it is then insert it and return the temp itself.
Now run the while loop till curr != NULL and stop when you find a node whose value is just greater than
the given data. Insert node using prev pointer.

Complexities-
TC: O(N)
SC: O(1)
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node *temp = new Node(data);
        Node *prev = NULL;
        Node *curr = head;
        
        if (curr->data > data) {
            temp->next = curr;
            return temp;
        }
        
        while (curr != NULL) {
            
            if (curr->data > data) {
                prev->next = temp;
                temp->next = curr;
                break;
            } else {
                prev = curr;
                curr = curr->next;
            }
            
        }
        
        if (curr == NULL) {
            prev->next = temp;
        }
        
        return head;
    }
};