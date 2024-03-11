#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOATS 1000

int print_monthly_sales(float sales_arr[], const char *months[]){
    int i;
    printf("\nMonthly sales report for 2022:\n\n");
    printf("Month \t\t Sales\n\n");
    for (i = 0; i < 12; i++){
        if (i== 1 || i == 8 || i == 10 || i == 11){
            printf("%s\t $%.2f \n",months[i], sales_arr[i]);
        }
        else{
            printf("%s\t\t $%.2f \n",months[i], sales_arr[i]);
        }
    }
    return 0;
}

float find_min(float sales_arr[], const char *months[]){
    int i; 
    float smallest = sales_arr[0];
    const char *min_month= months[0];
    for(i=1; i<12; i++){
        if (smallest > sales_arr[i]){
            smallest = sales_arr[i];
            min_month = months[i];
        }
    }
    printf("\nMinimum Sales:\t $%0.2f\t (%s)", smallest, min_month);
    return smallest;
}

float find_max(float sales_arr[], const char *months[]){
    int i; 
    float max = sales_arr[0];
    const char * max_month= months[0];
    for(i=1; i<12; i++){
        if (max < sales_arr[i]){
            max = sales_arr[i];
            max_month = months[i];
        }
    }
    printf("\nMaximum Sales:\t $%0.2f\t (%s)", max, max_month);
    return max;
}

float find_average_sales(float sales_arr[]){
    int i;
    float average = 0;
    for(i=0; i<12; i++){
        average += sales_arr[i];
    }
    average = average / 12;
    return average;
}

float find_6month_average(float sales_arr[], int start){
    int i;
    float average = 0;
    for(i=start; i<(start+6); i++){
        average += sales_arr[i];
    }
    average = average / 6;
    return average;
}

void print_sales_in_order(float sales_arr[], const char *months[]) {
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales_arr[i] < sales_arr[j]) {
                float temp = sales_arr[i];
                const char *temporary_month = months[i];

                sales_arr[i] = sales_arr[j];
                sales_arr[j] = temp;
                months[i] = months[j];
                months[j] = temporary_month;
            }
        }
    }

    printf("\n\nSales Report (Highest to Lowest):\n");
    printf("\nMonths\t\tSales\n\n");
    for (int i = 0; i < 12; i++) {
        printf("%s     \t$%.2f\n", months[i],sales_arr[i]);
    }
}

int main() {
    float sales_arr[MAX_FLOATS];
    FILE *file;
    char filename[100];
    int count = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        float sales_arr[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 
        60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
        return 1;
    }

    while (fscanf(file, "%f", &sales_arr[count]) == 1) {
        count++;
        if (count >= MAX_FLOATS) {
            printf("Exceeded maximum number of floats.\n");
            break;
        }
    }

    fclose(file);

    const char *months[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };

    print_monthly_sales(sales_arr, months);

    printf("\n\nSales summary:\n");
    find_min(sales_arr, months);
    find_max(sales_arr, months);
    printf("\nAverage Sales:\t $%0.2f\t\n", find_average_sales(sales_arr));

    printf("\n\nSix-Month Moving Average Report:\n");
    int i;
    for(i=0;i<7;i++){
        if(i<2){
            printf("\n%s \t-   %s\t $%0.2f",months[i], months[i+5], find_6month_average(sales_arr, i));
        }
        else{
            printf("\n%s \t\t-   %s\t $%0.2f",months[i], months[i+5], find_6month_average(sales_arr, i));
        }
        
    }
    print_sales_in_order(sales_arr, months);

    }
