
#include "invertedIndex.h"

int main(int argc, char *argv[])
{
	file_node_t *head=NULL;
	if(argc<2)
	{
		printf("ERROR: Invalid no of Arguments\n");
		return 0;
	}
	int argcn=1;
	while(argcn<argc)
	{
		if(validate_n_store_filenames(&head, argv[argcn])!=SUCCESS)
		{

		}  
		argcn++;
	}
	printf("Validation Succesfully Completed!\n");
	/* Define the main function here */

	table_node_t arr[27];
	for(int i=0;i<27;i++)
	{
		arr[i].index=i;
		arr[i].link=NULL;
	}
	int ch,flag=0;;
	char *word;
	while(1)
	{
		printf("1. Create DataBase\n");
		printf("2. Display DataBase\n");
		printf("3. Update DataBase\n");
		printf("4. Search DataBase\n");
		printf("5. Save DataBase\n");
		printf("6. Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					if(create_DB(&head, arr)==FAILURE)
					{
						printf("ERROR: Creating Database Failed!\n");
						return 0;
					}
					flag=1;
					break;
			case 2:
					if(display_DB(arr)==FAILURE)
					{
						return FAILURE;
					}
					break;
			case 3:
					if(flag==0)
					{
						if(update_DB(arr)==FAILURE)
						{
							printf("ERROR: Updating of Hash Table Failed\n\n");
						}
						else
						{
							printf("INFO: DataBase Updated Successfully\n\n");
						}
					}
					else
					{
						printf("ERROR: You Can't Update DataBase After DataBase Created!\n");
						printf("\n");
					}
					break;
			case 4:
					if(search_DB(arr)==FAILURE)
					{
						//return 0;
					}
					break;
			case 5:
					if(save_DB(arr,&head)==FAILURE)
					{
						//return 0;
					}
					break;
			case 6:
					return 0;
					break;
			default:
			printf("Invalid Choice!\n\n");
		}
	}
}

int validate_n_store_filenames(file_node_t **head, char *filenames)
{
	if(strstr(filenames,".txt")!=NULL)
	{
		FILE *ptr=fopen(filenames,"r");
		if(ptr==NULL)
		{
			printf("ERROR: \"%s\" file Not present!\n",filenames);
			return NOT_PRESENT;
		}
		fseek(ptr,0,SEEK_END);
		if(ftell(ptr)!=0)
		{
			rewind(ptr);
			fclose(ptr);
			file_node_t *temp=*head;
			while(temp!=NULL)
			{
				if(strcmp(temp->f_name,filenames)!=0)
				{
					temp=temp->link;
				}
				else
				{
					printf("ERROR: \"%s\" File is Already Exists!\n",filenames);
					return FAILURE;
				}
			}
			if(insert_at_last_main(head, filenames)==FAILURE)
			{
				return FAILURE;
			}
			return SUCCESS;
		}
		else
		{
			printf("ERROR: \"%s\" File is Empty!\n",filenames);
			fclose(ptr);
			return FILE_EMPTY;
		}
	}
	else
	{
		printf("ERROR: \"%s\" file is Not valid!\n",filenames);
		return FAILURE;
	}
}

int insert_at_last_main(file_node_t **head, char *word)
{
	file_node_t *new=malloc(sizeof(file_node_t));
	if(new==NULL)
	{
		return FAILURE;
	}
	strcpy(new->f_name,word);
	new->link=NULL;
	if(*head==NULL)
	{
		*head=new;
		return SUCCESS;
	}
	file_node_t *temp=*head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=new;
	return SUCCESS;
}