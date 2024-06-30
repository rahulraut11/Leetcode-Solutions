/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

int count(ListNode* head){
    int c=0;
    if(head==NULL)
    return 0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
        int del=count(head)-n+1;
        if(del==1){
            ListNode* p=head;
            head=head->next;
            delete(p);
            return head;
        }
        int c=1;
        ListNode* p=head;
        ListNode* r=p->next;
        while(c!=(del-1)){
            c++;
            p=p->next;
            r=r->next;



        }
        p->next=r->next;
        delete(r);
        return head;


        

    }
};
    
