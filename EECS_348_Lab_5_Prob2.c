
#include <stdio.h>

void find_combinations(int score) {
    int td, td_and2, td_and1, fg, safety;
    printf("Possible combinations of scoring plays:\n");
    for (td_and2 = 0; td_and2 <= score / 8; td_and2++){
        for (td_and1 = 0; td_and1 <= score / 7; td_and1++){
            for (td = 0; td <= score / 6; td++) {
                for (fg = 0; fg <= score / 3; fg++) {
                    for (safety = 0; safety <= score / 2; safety++) {
                        int total_score = td * 6 + fg * 3 + safety * 2;
                        if (total_score == score) {
                            printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d FG, %d Safety\n", td_and2, td_and1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }
        find_combinations(score);
    }
    return 0;
}
