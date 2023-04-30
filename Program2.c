#include <stdio.h>

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
