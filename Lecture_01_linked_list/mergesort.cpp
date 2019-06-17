
node*merge(node* a,node*b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }

    node*newHead;
    if(a->data < b->data){
        newHead = a;
        newHead->next = merge(a->next,b);
    }
    else{
        newHead = b;
        newHead->next = merge(a,b->next);
    }

    return newHead;
}

node* mergeSort(node*l){
    if(l==NULL||l->next==NULL){
        return l;
    }

    node* mid = midPoint(l);
    node* a = l;
    node* b = mid->next;

    mid->next = NULL;

    ///Rec Sort
    a = mergeSort(a);
    b = mergeSort(b);

    ///Merge
    return merge(a,b);


}

