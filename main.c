#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libfdr/jrb.h"

void get_str(char *string) {
    do {
        fgets(string, 256, stdin);
    } while (string[0] == '\n');
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}

void get_int(int *a) {
    char string[256];
    do {
        fgets(string, 256, stdin);
    } while (string[0] == '\n');
    sscanf(string, "%d", a);
}

int main() {
    int n;
    char buff[256];
    Jval name, number;
    JRB book = make_jrb();
    JRB tmp;
    do {
        system("clear");
        printf("0.Add from file\n1.Add phone\n2.Search phone\n3.Show phone book\n4.Exit\nYour choice: ");
        get_int(&n);
        switch (n) {
            case 0:
                printf("Enter file name: ");
                get_str(buff);
                FILE *fp = fopen(buff, "r");
                while (!feof(fp)) {
                    fscanf(fp, "%ld ", &number.l);
                    fgets(buff, 256, fp);
                    if (buff[strlen(buff) - 1] == '\n') {
                        buff[strlen(buff) - 1] = '\0';
                    }
                    jrb_insert_str(book, strdup(buff), new_jval_l(number.l));
                }
                break;
            case 1:
                printf("Name: ");
                get_str(buff);
                name = new_jval_s(strdup(buff));
                printf("Number: ");
                get_str(buff);
                number = new_jval_l(strtol(buff, NULL, 10));
                jrb_insert_str(book, name.s, number);
                break;
            case 2:
                printf("Name: ");
                get_str(buff);
                JRB node = jrb_find_str(book, buff);
                if (node == NULL) {
                    printf("Not found number for %s!\n", buff);
                } else printf("Phone number of %s is %ld\n", buff, node->val.l);
                printf("Press enter to continue...");
                getchar();
                break;
            case 3:
                jrb_traverse(tmp, book) {
                    printf("%-35s%10ld\n", tmp->key.s, tmp->val.l);
                }
                printf("Press enter to continue...");
                getchar();
                break;
            case 4:
                jrb_free_tree(book);
                break;
            default:
                break;
        }
    } while (n != 4);
    return 0;
}
