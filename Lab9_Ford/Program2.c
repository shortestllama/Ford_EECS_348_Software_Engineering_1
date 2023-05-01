#include <stdio.h>
/*#include <stdlib.h>

int rec(int s) {
		
}

void combinations(int s) {
	int num_safeties = 0;
	int num_field_goals = 0;
	int num_touchdowns = 0;
	int num_touchdowns_w_pat = 0;
	int num_touchdowns_w_conv = 0;
	int temp = s;
//gonna need to do recursion: take out 1 touchdown and look at that score, then take out 2, etc.
	if (s % 2 == 0) {
		num_safeties = s / 2;
		temp = s - 2;
//base cases are 2, 3, 4(?), 5(?), 6, 7, 8
//maybe do a matrix to store a list of combination lists
	}

	if (s % 3 == 0) {
		num_field_goals = s / 3;
	}
	
	if (s % 6 == 0) {
		num_touchdowns = s / 6;
	}

	if (s % 7 == 0) {
		num_touchdowns_w_pat = s / 7;
	}

	if (s % 8 == 0) {
		num_touchdowns_w_conv = s / 8;
	}

	printf("Possible combinations of scoring plays:\n");
	printf("%d TD + conv, %d TD + PAT, %d TD, %d FG, %d SFT\n", num_touchdowns_w_conv, num_touchdowns_w_pat, num_touchdowns, num_field_goals, num_safeties);
}

void rec_combs(int chosen[], int arr[], int index, int r, int start, int end, int s, int**** ans) {
	printf("h\n");
	
	if (index == r) {
		int sum = 0;
		int temp[5];
		int answer[5];

		for (int i = 0; i < 5; i++) {
			answer[i] = arr[chosen[i]];

			if (i < 3) {
				temp[i] = (8 - i) * arr[chosen[i]];
			}

			else {
				temp[i] = (6 - i) * arr[chosen[i]];
			}
		}

		for (int i = 0; i < 5; i++) {
			sum += temp[i];
		}

		printf("%d\n", sum);

		if (sum == s) {
			for (int i = 0; i < sizeof(ans)/sizeof(ans[0]); i++) {
				if (ans[i] == NULL) {
					printf("%ls\n", **ans[0]);
					**ans[i] = answer;
					printf("%ls\n", **ans[0]);
				}
			}
		}
		
		return;
	}

	for (int i = start; i <= end; i++) {
		chosen[index] = i;
		rec_combs(chosen, arr, index + 1, r, i, end, s, ans);
	}

	return;
}

void combs(int n_values[], int n, int r, int s, int*** ans) {
	int chosen[r + 1];
	rec_combs(chosen, n_values, 0, r, 0, n - 1, s, &ans);
}

//make a list of half the score and find the combinations of that list, then multiply the numbers in those combinations by their respective NFL scores and if see if the total is equal to the score 
int main() {
	int score;

	printf("Enter 0 or 1 to STOP\n");
	printf("Enter an NFL score: ");
	scanf("%d", &score);

	int* num_combs = (int*)malloc(sizeof(int) * score/2);
	int** ans = (int**)malloc(sizeof(int) * score);

	for (int i = 0; i < sizeof(ans)/sizeof(ans[0]); i++) {
		ans[i] = (int*)malloc(sizeof(int) * 5);
	}

	for (int i = 0; i <= score/2; i++) {
		num_combs[i] = i;
	}

	int n = sizeof(num_combs) / sizeof(num_combs[0]);

	while (score > 1) {
		combs(num_combs, n, 5, score, &ans);
		//combinations(score);

		int i = 0;
		while (ans[i] != NULL) {
			printf("%d TD + conv, %d TD + PAT, %d TD, %d FG, %d SFT\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3], ans[i][4]);
			i++;
		}

		printf("Enter 0 or 1 to STOP\n");
		printf("Enter an NFL score: ");
		scanf("%d", &score);
	}
}
*/
int main() {
	int score;

	printf("Enter 0 or 1 to STOP\n");
	printf("Enter an NFL score: ");
	scanf("%d", &score);

	while (score > 1) {
		for (int a = 0; a <= score/8; a++) {
			for (int b = 0; b <= score/7; b++) {
				for (int c = 0; c <= score/6; c++) {
					for (int d = 0; d <= score/3; d++) {
						for (int e = 0; e <= score/2; e++) {
							if (a*8 + b*7 + c*6 + d*3 + e*2 == score) {
								printf("%d TD + conv, %d TD + PAT, %d TD, %d FG, %d SFT\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}

		printf("Enter 0 or 1 to STOP\n");
		printf("Enter an NFL score: ");
		scanf("%d", &score);
	}
}
