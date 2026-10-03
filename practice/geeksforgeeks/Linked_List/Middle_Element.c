/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   struct Node *p=head;
   struct Node *f=head;
   
   while((f)&&(f->next))
   {
       p=p->next;
       f=(f->next)->next;
   }
   return p->data;
}
