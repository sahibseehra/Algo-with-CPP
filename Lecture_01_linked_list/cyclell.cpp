ListNode* Solution::detectCycle(ListNode* head) {
    ListNode* slow=head,*fast=head,*cur;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
            cur=head;
            while(cur!=slow)
            {
                cur=cur->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
