#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "colors.h"

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3
#define REPEATED -4
#define FILE_EMPTY -5
#define NOT_PRESENT -6

#define SIZE 26
#define BUFF_SIZE 255
#define NAMELENGTH 20

//inverted table

/*table*/
typedef struct table
{
	int index;
	struct node *link;
}table_node_t;

/* subnode structue */
typedef struct sub_node
{
	char f_name[NAMELENGTH];
	int w_count;
	struct sub_node *link;
}sub_node_t;

/* main node structure*/
typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	sub_node_t *sub_link;
	int f_count;
}main_node_t;

/* file node structure (Lineked list used to store the filenames */
typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}file_node_t;

/* validating files */
int validate_n_store_filenames(file_node_t **head, char *filenames);
int insert_at_last_main(file_node_t **head, char *word);
//int IsFileValid(char *);
//int store_filenames_to_list(char *f_name, file_node_t **head);
int update_main(file_node_t **head,main_node_t **temp,char *token);
int update_sub(file_node_t **head,main_node_t **temp);
int sl_delete_list(file_node_t **head, char *fname);
void insert_last(file_node_t **head, char *file_name);
int copy_data(table_node_t *arr, char *fname);

// int read_datafile(file_node_t *, main_node_t **, char *f_name);
// int update_sub_node(main_node_t **main_node);
// int update_word_count(main_node_t **head, char *fname;);

/* Create Database */
int create_DB(file_node_t **head, table_node_t arr[]); 

/* Display database */
int display_DB(table_node_t arr[]);

/* Update database */
int update_DB(table_node_t arr[]);

/* Search Database */
int search_DB(table_node_t arr[]);

/* Save Database */
int save_DB( table_node_t *arr, file_node_t **head);
