#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* start = NULL;
struct node* temp;


struct node* createNode()
{
    struct node* createNode = (struct node*)malloc(sizeof(struct node));
    return createNode;
}

void add_to_end(int data){
	struct node* to_be_added = (struct node*)malloc(sizeof(struct node));
	
	to_be_added->data = data;
	to_be_added->next=NULL;
	
	if(start == NULL){
		start = to_be_added;
	}
	
	else{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = to_be_added;
	}
}

void add_to_start(int y)
{
    struct node* to_be_added = createNode();
    to_be_added->data = y;
    to_be_added->next=NULL;
    temp = start;
    to_be_added->next = temp;
    start = to_be_added;
}

void add_to_middle(int z, int index)
{
    int counter = 0;
    struct node* to_be_added = createNode();
    to_be_added->data = z;
    to_be_added->next=NULL;
    temp = start;
    if(index == 0)
    {
        add_to_start(z);
    }
    else
    {
            while(temp != NULL)
            {
                if(counter+1 == index)
                    break;
                temp = temp->next;
                counter++;
            }
            struct node* temp1 = createNode();
            temp1 = temp->next;
            temp->next = to_be_added;
            to_be_added->next = temp1;
    }

}

void del_from_end()
{
    if(start == NULL)
    {
        printf("\n List is empty");
    }
    else
    {
        temp = start;
        if(start->next == NULL)
        {
            free(start);
            start = NULL;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            struct node* nextNode = temp->next;
            free(nextNode);
            temp->next = NULL;
        }
    }
}

void del_from_start()
{
    if(start != NULL)
    {
        if(start->next != NULL)
        {
            struct node* temp2 = start;
            start = start->next;
            free(temp2);
        }
        else
        {
            free(start);
            start = NULL;
        }
    }
    else
    {
        printf("\nthere is no node to delete...");
    }

}

void del_from_middle(int t)
{
    if(start->data == t)
    {
        del_from_start();
    }
    else
    {
        temp = start;
        while(temp->next->data != t)
        {
            temp = temp->next;
        }
        struct node* temp1 = temp->next->next;
        struct node* temp2 = temp;
        free(temp->next);
        temp2->next = temp1;
    }

}


void print()
{
    if(start == NULL)
    {
        printf("\n There is no node in list, please add node to list");
    }
    else
    {
        temp = start;
        printf("\n********************\n");
        while(temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
        printf("\n");
    }

}

int main()
{
	int choice,item, i, index,h;
 	while(1 == 1)
   		{
	        printf("\n1- Add an element to the end ... ");
	        printf("\n2- Add an element to the start ... ");
	        printf("\n3- Add an element to the middle ... ");
	        printf("\n4- Delete an element from the end ... ");
	        printf("\n5- Delete an element from the start ... ");
	        printf("\n6- Delete an element from the middle ... ");
	        printf("\n Choice ... ");
	        scanf("%d", &choice);
    	
    	
	    switch(choice)
	    {
	        case 1:
	
	            printf("\n How many node will you add? ... ");
	            scanf("%d", &h);
	            for(i = 0; i < h; i++)
	            {
	                printf("\n %d. add the number... ", i+1);
	                scanf("%d", &item);
	                add_to_end(item);
	                print();
	            }
	            break;
	        case 2:
	            printf("enter the number that you will add to end ... ");
	            scanf("%d", &item);
	            add_to_start(item);
	            print();
	            break;
	        case 3:
	            printf("Which number will you add? ...");
	            scanf("%d", &item);
	            printf("Which index will you add (index start from 0) ");
	            scanf("%d", &index);
	            add_to_middle(item, index);
	            print();
	            break;
	        case 4:
	            del_from_end();
	            print();
	            break;
	        case 5:
	            del_from_start();
	            print();
	            break;
	        case 6:
	            printf("\n which number do you want to delete? ...");
	            scanf("%d", &item);
	            del_from_middle(item);
	            print();
	            break;
	    }
	}
    return 0;
}
