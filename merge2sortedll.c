node* mergeLists(node* head1, node* head2)
{
    if(head1==NULL) 
    	return head2;
    else if(head2==NULL)
    	return head1;
    node *head=NULL;
    node *l1=head1,*l2=head2,*tail=head;
    while(l1!=NULL && l2!=NULL)
    {
           if(l1->data>l2->data)
           {
               if(head==NULL)
               	head=tail=l2;
               else
               {
                    tail->next=l2;
                    tail=l2;
               }
               l2=l2->next;
           }
           else
           {
                 if(head==NULL)
                 	head=tail=l1;
                 else
                 {
                    tail->next=l1;
                    tail=l1;
                 }
               l1=l1->next;
           }
    }
    if(l1==NULL)
    	tail->next=l2;
    else
    	tail->next=l1;
    return head;
}
