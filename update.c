#include "invertedIndex.h"

int update_DB(table_node_t arr[])
{
        // int i=0;
        // for(i = 0; i < 27; i++) 
        // {
        //         if (arr[i].link != NULL) 
        //         {
        //                 printf("INFO : Hash table is not empty\n");
        //                 break;
        //         }
        // }
	// if(i==27)
	// {
        //         printf("INFO: Hash Table is Empty!\n");
        //         return SUCCESS;
        // }
        char filename[100];
        printf("Enter database file for updation: ");
        scanf(" %[^\n]", filename);
        if(strstr(filename,".txt")!=NULL)
        {
                FILE *ptr = fopen(filename, "r");
                if(ptr==NULL) 
                {
                        printf("INFO : File is not present in current directory\n");
                        return FAILURE;
                        //printf("INFO: Creating New file to Update\n");
                }
                else
                {
                        ptr=fopen(filename,"a+");
                        fseek(ptr, 0, SEEK_END);
                        if (ftell(ptr) == 0) 
                        {
                                printf("INFO : File is empty\n");
                                return FAILURE;
                        }
                        rewind(ptr);
                }
                char first_ch, last_ch;
                fseek(ptr, 0, SEEK_SET);
                fscanf(ptr, " %c", &first_ch);
                fseek(ptr, -2, SEEK_END);
                fread(&last_ch, 1, 1, ptr);
                rewind(ptr);

                if(first_ch=='#' && last_ch=='#')
                {
                        char f_str[50];
                        while(fgets(f_str,sizeof(f_str), ptr) != NULL) 
                        {
                                char *token;
                                int index;
                    
                                token = strtok(f_str, "#;");
                                if (!token) 
                                continue;
                                index = atoi(token);
                    
                                main_node_t *new = malloc(sizeof(main_node_t));
                                if (!new) 
                                {
                                    printf("ERROR: Memory allocation failed\n");
                                    return FAILURE;
                                }
                                new->link = NULL;
                                new->sub_link = NULL;
                    
                                token = strtok(NULL, "#;");
                                if (!token) 
                                continue;
                                strcpy(new->word, token);
                    
                                token = strtok(NULL, "#;");
                                if (!token) 
                                continue;
                                new->f_count = atoi(token);
                    
                                // Insert into hash table
                                if (arr[index].link == NULL) 
                                {
                                    arr[index].link = new;
                                } 
                                else 
                                {
                                    main_node_t *temp = arr[index].link;
                                    while (temp->link != NULL) 
                                    {
                                        temp = temp->link;
                                    }
                                    temp->link = new;
                                }
                    
                                // Read sub-nodes
                                sub_node_t *sub_temp = NULL;
                                for (int j = 0; j < new->f_count; j++) 
                                {
                                    sub_node_t *new_sub = malloc(sizeof(sub_node_t));
                                    if (!new_sub) 
                                    {
                                        printf("ERROR: Memory allocation failed\n");
                                        return FAILURE;
                                    }
                                    new_sub->link = NULL;
                    
                                    token = strtok(NULL, "#;");
                                    if (!token) 
                                    continue;
                                    strcpy(new_sub->f_name, token);
                    
                                    token = strtok(NULL, "#;");
                                    if (!token) 
                                    continue;
                                    new_sub->w_count = atoi(token);
                    
                                    if (new->sub_link == NULL) 
                                    {
                                        new->sub_link = new_sub;
                                        sub_temp = new_sub;
                                    } 
                                    else
                                    {
                                        sub_temp->link = new_sub;
                                        sub_temp = new_sub;
                                    }
                                }
                        }
                }
        }
        else
        {
                printf("ERROR: File name is not Valid\n\n");
                return FAILURE;
        }
}
