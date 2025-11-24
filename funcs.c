#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcs.h"

int get_user_input_sub(int max_items)
{
    char buf[128];
    int valid = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            printf("\nInput error!");
            return -1;
        }

        buf[strcspn(buf, "\r\n")] = '\0';

        if (strlen(buf) == 0 || strspn(buf, "0123456789") != strlen(buf)) {
            printf("Enter an integer!\n");
            valid = 0;
        } else {
            value = atoi(buf);
            if (value >= 1 && value <= max_items) {
                valid = 1;
            } else {
                printf("Invalid menu item!\n");
                valid = 0;
            }
        }
    } while (!valid);

    return value;
}

void menu_item_1(void) {
    printf("\n>> Menu 1\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 1 */
}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}