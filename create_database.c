#include "invertedIndex.h"

int create_DB(file_node_t **head, table_node_t arr[]) 
{
	while(*head!=NULL)
	{
		int ind=0;
		FILE *ptr=fopen((*head)->f_name,"r");
		if (ptr == NULL) 
        {
            printf("Error: Could not open file %s\n", (*head)->f_name);
            *head = (*head)->link;
            continue;
        }
		char word[100];
		while(fscanf(ptr,"%s",word) != EOF)
		{
			if(isupper(word[0]))
			{
				ind=tolower(word[0])-'a';
			}
			else if(islower(word[0]))
			{
				ind=word[0]-97;
			}
			else
			{
				ind=26;
			}
			//to check the main arr link null or not
			if(arr[ind].link == NULL)
			{
				//create main_node
				main_node_t *m_new=malloc(sizeof(main_node_t));
				if (m_new==NULL) 
                {
                    printf("ERROR: Memory allocation failed!\n");
                    return FAILURE;
                }
				m_new->f_count=1;
				strcpy(m_new->word,word);
				m_new->link=NULL;
				sub_node_t *s_new=malloc(sizeof(sub_node_t));
				if (s_new==NULL) 
                {
                    printf("ERROR: Memory allocation failed!\n");
                    return FAILURE;
                }
				m_new->sub_link=s_new;
				arr[ind].link=m_new;

				//create sub_node
				s_new->w_count=1;
				strcpy(s_new->f_name,(*head)->f_name);
				s_new->link=NULL;
			}
			else
			{
				main_node_t *temp=arr[ind].link;
				main_node_t *prev=NULL;
				while(temp != NULL)//run a loop to NULL
				{
					//temp->word equal to word
					if(strcmp(temp->word,word)==0)
					{
						sub_node_t *t1=temp->sub_link;
						sub_node_t *prev1=NULL;
						while(t1 != NULL)
						{
							//file equal to file
							if(strcmp(t1->f_name,(*head)->f_name)==0)
							{
								t1->w_count++;
								break;
							}
							prev1=t1;
							t1=t1->link;
						}
						if(t1 == NULL)
						{
							//create a new Sub_node
							sub_node_t *new=malloc(sizeof(sub_node_t));
							if (new==NULL) 
                            {
                                printf("ERROR: Memory allocation failed!\n");
                                return FAILURE;
                            }
							new->w_count=1;
							strcpy(new->f_name,(*head)->f_name);
							new->link=NULL;
							prev1->link=new;
							temp->f_count++;
						}
						break;
					}
					prev=temp;
					temp=temp->link;
				}
				//create a new Sub_node
				if(temp == NULL)
				{
					main_node_t *m_new=malloc(sizeof(main_node_t));
					sub_node_t *s_new=malloc(sizeof(sub_node_t));
					if (m_new==NULL || s_new==NULL) 
                    {
                        printf("ERROR: Memory allocation failed!\n");
                        return FAILURE;
                    }
					//main node
					strcpy(m_new->word,word);
					m_new->f_count=1;
					m_new->link=NULL;
					m_new->sub_link=s_new;
					//sub node
					s_new->w_count=1;
					strcpy(s_new->f_name,(*head)->f_name);
					s_new->link=NULL;
					prev->link=m_new;
				}
			}
		}
		fclose(ptr);
		*head=(*head)->link;
	}
	printf("INFO: DataBase Created Succesufully!\n");
	printf("\n");
}
