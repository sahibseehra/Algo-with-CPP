
void bubbleSort(node*&head){

    int n = length(head);

    for(int i=0;i<n-1;i++){

        ///Pairwise swapping
        node*current = head;
        node*prev = NULL;
        while(current && current->next){
            if(current->data > current->next->data){
                ///Swapping
                if(prev==NULL){
                   node*nextNode = current->next;
                   current->next = nextNode->next;
                   nextNode->next = current;
                   head = nextNode;
                   prev = head;

                }
                else{
                    node*nextNode = current->next;
                    prev->next = nextNode;
                    current->next = nextNode->next;
                    nextNode->next = current;
                    prev = nextNode;

                }


            }
            else{
                prev = current;
                current = current->next;
            }



        }


    }
}
