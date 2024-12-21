/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * i=l1, *j=l2 ,*head = NULL, *tail = NULL ,*n;
    int carry = 0 , sum = 0;
    while(i!=NULL && j!=NULL){
        n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->val = 0;
        n->next = NULL;
        if(head == NULL){
            head = tail = n;
            n = head;
        }
        else{
            tail->next = n;
            tail = n;
        }
        // n->val+=carry;   
        sum = 0;
        sum = (i->val)+(j->val)+carry;
        carry = 0;
        if(sum>=10){
            carry = sum/10;
            n->val += sum%10;
        }
        if(!carry){
            n->val+=sum-carry;
        }
        i=i->next;
        j=j->next;
        
    }
    sum = 0;
    while(i!=NULL){
        n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->next = NULL;
        n->val =0;
        tail->next=n;
        tail=n;
        sum = carry + i->val;
        carry = 0;
        if(sum>=10){
            carry = sum/10;
            n->val += sum%10;
        }
        if(!carry) n->val+=sum;
        i = i->next;
    }
     while(j!=NULL){
        n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->next = NULL;
        n->val =0;
        tail->next=n;
        tail=n;
        sum = carry + j->val;
        carry = 0;
        if(sum>=10){
            carry = sum/10;
            n->val += sum%10;
        }
        if(!carry) n->val+=sum;
        j = j->next;
    }
    printf("%d",carry);
    if(carry!=0 &&(i==NULL && j ==NULL)){
        n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->next = NULL;
        n->val =carry;
        tail->next=n;
        tail=n;
    }
    
    return head;

}