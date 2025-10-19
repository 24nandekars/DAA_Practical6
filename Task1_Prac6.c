
#include <stdio.h>
#include <limits.h>

void tsp(int array[4][4], int s) {
    int visited[4] = {0};
    visited[s] = 1;
    int current = s;
    int path[5];
    path[0] = s;
    int count = 1;
    int total = 0;
    printf("%d", s + 1);
    while (count < 4) {
        int min = INT_MAX;
        int next = -1;
        for (int i = 0; i < 4; i++) {
            if (!visited[i] && array[current][i] < min && array[current][i] != 0) {
                min = array[current][i];
                next = i;
            }
        }
        if (next == -1) {
            printf("\nNo valid tour possible from this starting city.\n");
            return;
        }
        visited[next] = 1;
        path[count++] = next;
        total += min;
        current = next;
        printf(" -> %d", current + 1);
    }
    // Return to start
    total += array[current][s];
    printf(" -> %d", s + 1);
    printf("\nTotal cost: %d\n", total);
}

int main() {
    int cost_matrix[4][4] = {{0, 10, 15, 20},
                             {5, 0, 9, 10},
                             {6, 13, 0, 12},
                             {8, 8, 9, 0}};
    int source;
    printf("Enter source city (1-4): ");
    scanf("%d", &source);
    source--;  // Adjust to 0-based
    if (source < 0 || source > 3) {
        printf("Invalid source. Please enter a number between 1 and 4.\n");
        return 1;
    }
    tsp(cost_matrix, source);
    return 0;
}
