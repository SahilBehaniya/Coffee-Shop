#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int price=70;

struct Node{
    int cust_id;
    int co_order;
    int bill;
    struct Node*next;
};
struct Node*temp,*head=NULL,*newnode,*max,*min,*prev,*previous,*current,*nextn,*tail,*now;

void order()
{
    int B;
    do
    {

        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter the customer id:");
        scanf("%d",&newnode->cust_id);
        printf("Enter the no of coffees Ordered:");
        scanf("%d",&newnode->co_order);
        newnode->bill=newnode->co_order*price;
        tail->next=newnode;
        tail=newnode;

        printf("\nEnter 1 to enter the details of the next bill");
        scanf("%d",&B);
        //break;
    }while(B==1);
}

void display()
{
    temp=head;
    if(head==NULL)
    {
        printf("\nNo Bills to display");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\nCustomer id=%d",temp->cust_id);
            printf("\nNo. of Coffees ordered=%d",temp->co_order);
            printf("\nBilling Amount=%d",temp->bill);
            printf("\n");
            temp=temp->next;
        }
    }
}

void max_min()
{
    int Ma=head->bill,Mi=head->bill;
    temp=head;
    if(head==NULL)
    {
        printf("\nThere are no Bills");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->bill>=Ma)
            {
                Ma=temp->bill;
                max=temp;
            }
            if(temp->bill<=Mi)
            {
                Mi=temp->bill;
                min=temp;
            }
            temp=temp->next;
        }
        printf("\nMax bill of the day=%d",max->bill);
        printf("\nID of customer with max bill=%d",max->cust_id);
        printf("\nCoffees ordered in the highest bill of the day=%d",max->co_order);
        printf("\n");
        printf("\nMin bill of the day=%d",min->bill);
        printf("\nID of customer with min bill=%d",min->cust_id);
        printf("\nCoffees ordered in the lowest bill of the day=%d",min->co_order);
    }
}

void billing()
{
    int co=0;
    temp=head;
    if(temp==NULL)
    {
        printf("\nNo sales in the day");
    }
    else
    {
        while(temp!=NULL)
        {
            co=co+temp->co_order;
            temp=temp->next;
        }
        printf("\nTotal coffees sold=%d",co);
        printf("\nToatal sale=%d",co*price);
    }
}

void del()
{
    temp=head;
    int id,T=0;
    printf("\nEnter the customer id whose bill is to deleted");
    scanf("%d",&id);
    if(head->cust_id==id)
    {
        head=temp->next;
        free(temp);
        printf("\nBill deleted");
    }
    else
    {
        while(temp->cust_id!=id)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        printf("\nBill deleted");
    }
}

void reverse()
{
    previous=NULL;
    current=head;
    nextn=head;
    while(nextn!=NULL)
    {
        nextn=nextn->next;
        current->next=previous;
        previous=current;
        current=nextn;
    }
    head=previous;
    printf("\nBills reversed");
}

void sort()
{
    struct Node*index=NULL,*temp2;
    temp=head;
    if(head==NULL)
    {
        printf("\nNothing to sort");
    }
    else
    {
        while(temp!=NULL)
        {
            index=temp->next;
            while(index!=NULL)
            {
                if(temp->co_order>index->co_order)
                {
                    temp2=temp;
                    temp=index;
                    index=temp2;
                }
                index=index->next;
            }
            temp=temp->next;
        }
        printf("\nBills sorted");
    }
}

int main()
{
    int M=1,P=0;
  
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter the customer id:");
        scanf("%d",&newnode->cust_id);
        printf("Enter the no of coffees Ordered:");
        scanf("%d",&newnode->co_order);
        newnode->bill=newnode->co_order*price;
        head=newnode;
        tail=newnode;
    
    int choice;
    while(M==1)
    {
        printf("\n\n1]Enter 1 to Enter the bills\n2]Enter 2 to display the bills\n3]Enter 3 to get maximum and minimum billing of the day");
        printf("\n4]Enter 4 to get sales of the day\n5]Enter 5 to delete a bill");
        printf("\n6]Enter 6 to reverse the bills\n7]Enter 7 to sort the bills\n8]Enter 8 to exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:order();
                    break;
            case 2:display();
                    break;
            case 3:max_min();
                    break;
            case 4:billing();
                    break;
            case 5:del();
                    break;
            case 6:reverse();
                    break;
            case 7:sort();
                    break;
            case 8:billing();
                    return 0;
                    break;
            default:printf("Wrong input give the correct input");
                    break;
        }
    }
}

