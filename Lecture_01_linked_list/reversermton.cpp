ListNode* Solution::reverseBetween(ListNode* head, int b, int c) {
    int i=1;
    ListNode* cur=head,*temp,*tprev=NULL,*start=head,*end=head,*prev=NULL;
    while(i<b)
    {
        i++;
        prev=cur;
        cur=cur->next;
    }
    start=cur;
    
    while(i<=c)
    {
        i++;
        temp=cur->next;
        cur->next=tprev;
        tprev=cur;
        cur=temp;
    }
    
    if(prev!=NULL)
    prev->next=tprev;
    else 
    head=tprev;
    start->next=cur;
    return head;
    
}

