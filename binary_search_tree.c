#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int data;
	struct node *right ,*left;
};

struct node* create(int data)
{
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct node* insert(struct node* node, int data)
{
	if (node == NULL)
		return create(data);
	
	else if (data<node->data)
		return node->left=insert(node->left,data);
	
	else return node->right=insert(node->right,data);
	
	//çalýþmazsa else if ve elsedeki returnleri silip en alta return root ekle
}

struct node *del(struct node *node, int data)
{
	if (node == NULL)
	printf("there is no number to delete");
	
	if(data<node->data)
	node->left = del(node->left,data);
	
	else if(data>node->data)
	node->right = del(node->right,data);

	else
	{
		if(node->left==NULL)
		{
			struct node* temp=node->right;
			free(node);
			return temp;
		}
		
		else if(node->right==NULL)
		{
			struct node* temp=node->left;
			free(node);
			return temp;
		}
		
		else
		{
			struct node* temp=node->right;
			node->data = temp->data;
			node->right=del(node->right,temp->data);
			return node;
		}
	}
	return node;
}

struct node* min(struct node* node)
{
	if(node && node->left!=NULL)
	return min(node->left);
	
	else return node->data;
}

struct node* max(struct node* node)
{
	if(node && node->right!=NULL)
	return max(node->right);
	
	else return node;
}

struct node* find(struct node* node, int data)
{
	if(data<node->data)
	{
		if(node->left!=NULL)
			return find(node->left,data);
		else return NULL;
	}
	
	else if(data>node->data)
	{
		if(node->right!=NULL)
			return find(node->right,data);
	}
	
	else 
	{
		if(node->data==data)
		printf("you find the number %d",data);

		else 
		printf("there is no this number");
	}	
}

int max_for_depth(int a, int b)
{
	if(a>b)
	return a;
	else return b;
}

struct node* depth(struct node* node)
{
	int l,r;
	l=depth(node->left);
	r=depth(node->right);
	
	max_for_depth(l,r);
	return max_for_depth;
}

int inorder(struct node* node)
{
	if(node == NULL)
		return 0;
		
	inorder(node->left);
	printf("%d",node->data);
	inorder(node->right);
	
	return 1;
}

int main(int argc, char *argv[]) {
	int i;
	
	struct node* root=NULL;
	
	do
	{
		printf("1--->INSERTION\n");
		printf("2--->INORDER TRAVERSAL\n");
		printf("3--->FINDING NUMBERS\n");
		printf("4--->DELETING NUMBERS\n");
		printf("5--->FIND MAX\n");
		printf("6--->FIND MIN\n");
		printf("7--->FIND DEPTH\n");
		printf("8--->EXIT\n");
		printf("Make your choice: ");
		scanf("%d",&i);
		
		
		switch(i)
		{
			case 1:
				printf("enter a number to insert");
				scanf("%d",&i);
				insert(root,i);
				break;
				
			case 2:
				inorder(root);
				break;
				
			case 3:
				printf("enter a number you want to find");
				scanf("%d",&i);
				find(root,i);
				break;
				
			case 4:
				printf("enter a number you want to delete");
				scanf("%d",&i);
				del(root,i);
				break;
				
			case 5:
				max(root);
				break;
				
			case 6:
				min(root);
				break;
				
			case 7:
				depth(root);
				break;
		}

	}
	while(i!=8);
	

	
	return 0;
}
