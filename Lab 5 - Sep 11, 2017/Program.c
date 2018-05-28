#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *next;
};

struct node *list;	//its global
int main(){

int x,input;
list=NULL;

for(x=0; x<12; x++)
	addNode(x);
  displayList();

while(1){
printf("What action you want to perform \r\n 1-Add item(node) to list \r\n 2-Delete item(node) with particular value \r\n 3- Display List \r\n 4- Quit \r\n ");
scanf("%\d", &input);
switch(input)
{
	case 1:
		printf("Enter value to enter: ");
		scanf("%d", &input);
		addNode(input);
		break;

	case 2:
		printf("Enter value to delete form list: ");
		scanf("%d", &input);
		deleteItem(input); //list
		break;

	case 3:
		displayList();
		break;

	case 4:
		exit(0);
		break;
	default:
		printf("Enter Valid actions \r\n ");
  }
} 	//while loop

return 0;

}

void addNode(int num)
{
	struct node *temp, *r, *q;
	q=list;
	if(q==NULL)	//if NULL create first node
	{
		temp = (struct node*) malloc ( sizeof (struct node ) );
			temp -> info = num ;
			temp -> next = NULL;
			list = q = temp;
	}
	else
	{
		temp = q;
	 	/*go to last node*/
		while (temp -> next != NULL)
			temp = temp -> next;
		/* add node at the end */
		r = (struct node * ) malloc ( sizeof (struct node ) );
		r -> info = num;
		r -> next = NULL;
		temp -> next = r;
	}
}

void displayList()
{
	struct node *ptr;
	ptr=list;

	while(ptr!=NULL)
	{
		printf("Info at address %d is %d \r\n", ptr, ptr->info);
		ptr=ptr->next;
	}
}

void deleteItem(int val)
{
	struct node *temp, *ptr;
	temp = ptr = NULL;
	temp=list;
	while(temp != NULL)
	{
		if(temp -> info == val)
		{
			//found item, temp contain address of node to be deleted
			if(ptr==NULL) //now if ptr = NULL its first node
			{
				list = list->next;
				free(temp);
				break;
			}
			else //Its not the first node
			{
				ptr->next =temp->next;
				free(temp);
				break;
			}
		}
		else //val check
		{
			ptr = temp;
			temp = temp -> next;
		}
	} //while
}
