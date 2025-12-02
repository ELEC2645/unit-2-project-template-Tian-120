#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "funcs.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

void scientific_menu(void)
{
    int choice;

    printf("\n----------- Scientific & Mathematics Tools -----------\n");
    printf("\n"
           "\t1. Unit Conversion\n"
           "\t2. Basic Statistics\n"
           "\t3. Back to Main Menu\n"
           "\n");
    printf("------------------------------------------------------\n");

    choice = get_user_input_sub(3);

    switch(choice)
    {
        case 1:
            unit_conversion();
            break;
        case 2:
            basic_statistics();
            break;
        case 3:
            return;
    }
}

void unit_conversion(void)
{
    int choice;
    float input, result;

    printf("\n----------- Unit Conversion -----------\n");
    printf("\n"
           "\t1. Hz to rad/s\n"
           "\t2. rad/s to Hz\n"
           "\t3. dBm to mW\n"
           "\t4. mW to dBm\n"
           "\t5. Back\n"
           "\n");
    printf("---------------------------------------------\n");

    choice = get_user_input_sub(5);

    switch(choice)
    {
        case 1:
            printf("\nEnter frequency in Hz: ");
            scanf("%f", &input);
            result = hzToRad(input);
            printf("Result: %.4f rad/s\n", result);
            break;

        case 2:
            printf("\nEnter angular frequency (rad/s): ");
            scanf("%f", &input);
            result = radToHz(input);
            printf("Result: %.4f Hz\n", result);
            break;

        case 3:
            printf("\nEnter power in dBm: ");
            scanf("%f", &input);
            result = dbmToMw(input);
            printf("Result: %.4f mW\n", result);
            break;

        case 4:
            printf("\nEnter power in mW: ");
            scanf("%f", &input);
            result = mwToDbm(input);
            printf("Result: %.4f dBm\n", result);
            break;

        case 5:
            return;
    }
}


float hzToRad(float hz)
{
    return hz * 2 * M_PI;
}

float radToHz(float rad)
{
    return rad / (2 * M_PI);
}

float dbmToMw(float dbm)
{
    return pow(10, dbm / 10);
}

float mwToDbm(float mw)
{
    return 10 * log10(mw);
}

void basic_statistics(void)
{
    int n;
    float value;
    float data[20];
    float sum = 0.0f;
    float min = 0.0f;
    float max = 0.0f;
    int i;

    printf("\n----------- Basic Statistics -----------\n");
    printf("\nEnter number of data points (1-20): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        printf("Invalid number of data points.\n");
        return;
    }

    printf("\nPlease enter %d values:\n", n);

    for (i = 0; i < n; i++) {
        printf("  Value %d: ", i + 1);
        if (scanf("%f", &value) != 1) {
            printf("Invalid input. Stopping.\n");
            return;
        }
        data[i] = value;
        sum += value;

        if (i == 0 || value < min) {
            min = value;
        }
        if (i == 0 || value > max) {
            max = value;
        }
    }

    float mean = sum / n;

    printf("\nResults:\n");
    printf("  Count: %d\n", n);
    printf("  Min  : %.4f\n", min);
    printf("  Max  : %.4f\n", max);
    printf("  Mean : %.4f\n", mean);
    printf("---------------------------------------------\n");
}

void eee_menu(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    
    int choice;

    printf("\n----------- Electronic & Electrical Engineering Tools -----------\n");
    printf("\n"
           "\t1. RC Filter Calculator\n"
           "\t2. Resistor Network Calculator\n"
           "\t3. Back to Main Menu\n"
           "\n");
    printf("-----------------------------------------------------------------\n");

    choice = get_user_input_sub(3);

    switch(choice)
    {
        case 1:
            rc_filter_tool();
            break;

        case 2:
            resistor_network_tool();
            break;

        case 3:
            return;
    }
}

void rc_filter_tool(void)
{
    float R, C, fc;

    printf("\n----------- RC Filter Calculator -----------\n");

    printf("\nEnter resistance R (ohms): ");
    scanf("%f", &R);

    printf("Enter capacitance C (farads): ");
    scanf("%f", &C);

    fc = 1.0f / (2 * M_PI * R * C);

    printf("\nCutoff frequency: %.4f Hz\n", fc);
    printf("---------------------------------------------\n");
}

void resistor_network_tool(void)
{
    int choice;
    float R1, R2, result;

    printf("\n----------- Resistor Network Calculator -----------\n");
    printf("\n"
           "\t1. Series Connection\n"
           "\t2. Parallel Connection\n"
           "\t3. Back\n"
           "\n");
    printf("---------------------------------------------------\n");

    choice = get_user_input_sub(3);

    switch(choice)
    {
        case 1:
            printf("\nEnter R1: ");
            scanf("%f", &R1);
            printf("Enter R2: ");
            scanf("%f", &R2);
            result = R1 + R2;
            printf("\nSeries Result: %.4f ohms\n", result);
            break;

        case 2:
            printf("\nEnter R1: ");
            scanf("%f", &R1);
            printf("Enter R2: ");
            scanf("%f", &R2);
            result = 1.0f / (1.0f/R1 + 1.0f/R2);
            printf("\nParallel Result: %.4f ohms\n", result);
            break;

        case 3:
            return;
    }
}
