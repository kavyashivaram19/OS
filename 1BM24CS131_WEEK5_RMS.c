#include <stdio.h>
#define MAX 10

int main() {
    int n, time;
    int cap[MAX], period[MAX], remaining[MAX];
    int i, t;

    printf("Enter number of process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter capacity and period of P %d: ", i+1);
        scanf("%d %d", &cap[i],&period[i]);

        remaining[i] = 0;
    }

    printf("Enter total simulation time: ");
    scanf("%d", &time);

    printf("\nTime\tTask\n");

    for(t = 0; t < time; t++) {

        // Release tasks periodically
        for(i = 0; i < n; i++) {
            if(t % period[i] == 0) {
                remaining[i] = cap[i];
            }
        }

        int highest = -1;
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {
                if(highest == -1 || period[i] < period[highest]) {
                    highest = i;
                }
            }
        }

        if(highest != -1) {
            printf("%d\tT%d\n", t, highest + 1);
            remaining[highest]--;
        } else {
            printf("%d\tIdle\n", t);
        }
    }

    return 0;
}
