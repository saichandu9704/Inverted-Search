#include "invertedIndex.h"

int save_DB(table_node_t *arr, file_node_t **head) {
    char fname[100], vali;
    printf("Enter file name: ");
    scanf(" %[^\n]", fname);

    if (!strstr(fname, ".txt")) {
        printf("ERROR : Invalid file extension\n");
        return 0;
    }

    FILE *fptr = fopen(fname, "r");
    if (fptr) {
        fseek(fptr, 0, SEEK_END);
        int pos = ftell(fptr);
        fclose(fptr);
        if (pos > 0) {
            printf("INFO : File exists and is not empty. Overwrite? (y/n): ");
            scanf(" %c", &vali);
            if (vali != 'y') return 0;
        }
    }
    fptr = fopen(fname, "w");
    if (!fptr) {
        printf("ERROR: Cannot open file for writing\n");
        return 0;
    }

    for (int i = 0; i < 27; i++) {
        main_node_t *temp = arr[i].link;
        while (temp) {
            sub_node_t *temp1 = temp->sub_link;
            while (temp1) {
                fprintf(fptr, "# %d; %s; %d; %s; %d; #\n", i, temp->word, temp->f_count, temp1->f_name, temp1->w_count);
                temp1 = temp1->link;
            }
            temp = temp->link;
        }
    }
    fclose(fptr);
    printf("INFO : Database successfully copied to %s\n", fname);
    printf("\n");
    return 1;
}
