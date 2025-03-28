#include "invertedIndex.h"

int display_DB(table_node_t arr[])
{
	/* Definition here */
	//printf("%s%-10s%-10s%-10s%-10s\n","index","word","file_count","file name","in file present");
	
	int i=0;
	while(i<27)
	{
		if(arr[i].link!=NULL)
		{
			break;
		}
		i++;
	}
	if(i==27)
	{
		printf("INFO: DataBase is Empty\n");
		printf("\n");
		return SUCCESS;
	}
	i=0;
	while(i<27)
	{
		main_node_t *temp=arr[i].link;
		if(temp!=NULL)
		{
			while(temp!=NULL)
			{
				printf("[%-2d] ",i);
				printf("%-10s",temp->word);
				printf("%-5d ",temp->f_count);
				sub_node_t *temp1=temp->sub_link;
				while (temp1 != NULL)
                {
                    printf("%-10s %-5d", temp1->f_name, temp1->w_count);
                    temp1 = temp1->link;
                }
				printf("\n");
				temp=temp->link;
			}
		}
		i++;
	}
	printf("\n");
}

