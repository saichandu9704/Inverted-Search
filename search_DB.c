#include "invertedIndex.h"

int search_DB(table_node_t arr[])
{
    int ind=0;
    char n_word[27];
    printf("Enter Which Word Do you Want:");
    scanf(" %[^\n]",n_word);
    if(isupper(n_word[0]))
    {
        ind=tolower(n_word[0])-'a';
    }
    else if(islower(n_word[0]))
    {
        ind=tolower(n_word[0])-97;
    }
    else
    {
        ind=26;
    }
    if(arr[ind].link==NULL)
    {
        printf("ERROR: \"%s\" is Not Found!\n",n_word);
        printf("\n");
        return FAILURE;
    }
    else
    {
        //main node
        main_node_t *temp=arr[ind].link;
        while(temp!=NULL)
        {
            if(strcmp(temp->word,n_word)==0)
            {
                    printf("OUTPUT:\"%s\" is present in %d files\n",n_word,temp->f_count);//word is present in filecount and filename and word count
                    //sub node
                    sub_node_t *t1=temp->sub_link;
                    while(t1!=NULL)
                    {
                        printf("%s -> %d\n",t1->f_name,t1->w_count);
                        t1=t1->link;
                    }
                    printf("\n");
                    break;
            }
            else
            {
                temp=temp->link;
                // printf("ERROR: \"%s\" is Not Found!\n",n_word);
                // break;
            }
        }
    }
}
