#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float* read_data_from(char* file_name) {
    const int months = 12;
    float* month_sales_data = (float*)malloc(sizeof(float) * months);

    FILE* fp = fopen(file_name, "r+");
    if (fp == NULL) {
        printf("Please check your file again!\n");
    }

    for (int i = 0; i < months; ++i) {
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }

    return month_sales_data;
}


void print_data(float* sales, char* month_name[]) {
	printf("Month               Sales\n");
	for(int i = 0; i < 12; ++i) {
		printf("%-20s%.2f\n", month_name[i], sales[i]);
	}
}

void print_summary(float* sales, char* month_name[]) {
	float min = sales[0];
	int min_ind = 0;
	float max = sales[0];
	int max_ind = 0;
	float sum = 0;

	for (int i = 0; i < 12; i++) {
		sum += sales[i];

		if (sales[i] < min) {
			min = sales[i];
			min_ind = i;
		}

		if (sales[i] > max) {
			max = sales[i];
			max_ind = i;
		}
	}

	float avg = sum / 12;

	printf("\nSales summary:\n\n");
	printf("Minimum sales:      %.2f (%s)\n", min, month_name[min_ind]);
	printf("Maximum sales:      %.2f (%s)\n", max, month_name[max_ind]);
	printf("Average sales:      %.2f\n", avg);
}

void print_six_month_avg(float* sales, char* month_name[]) {
	printf("\nSix-Month moving average report:\n\n");

	for (int i = 0; i < 6; i++) {
		float temp_sum = 0;

		for (int j = i; j < i + 6; j++) {
			temp_sum += sales[i];
		}

		float temp_avg = temp_sum / 6;
		char temp_months[20] = "";
		strcat(temp_months, month_name[i]);
		strcat(temp_months, " - ");
		strcat(temp_months, month_name[i + 6]);
		printf("%-20s%.2f\n", temp_months, temp_avg);
	}
}

void print_report(float* sales, char* month_name[]) {
	printf("\nSales report (highest to lowest):\n\n");
	printf("Month               Sales\n");

	int in_order[12];

	for (int i = 0; i < 12; i++) {
		float max = 0;

		for (int j = 0; j < 12; j++) {
			if (i == 0) {
				if (sales[j] > max) {
					max = sales[j];
					in_order[i] = j;
				}
			}

			else {
				if (sales[j] > max && sales[j] < sales[in_order[i - 1]]) {
					max = sales[j];
					in_order[i] = j;
				}
			}	
		}
	}

	for (int i = 0; i < 12; i++) {
		printf("%-20s%.2f\n", month_name[in_order[i]], sales[in_order[i]]);
	}
}


int main() {
	float* month_sales_data = read_data_from("file.txt");
	char* months [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	print_data(month_sales_data, months);
	print_summary(month_sales_data, months);
	print_six_month_avg(month_sales_data, months);
	print_report(month_sales_data, months);
	return 0;
}
