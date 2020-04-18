#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve();
int* sort(int* costs, int N);

int main()
{
    int i = 0; // for loop
    int T = 0; // # of test cases
    int answer = 0;
    
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        answer = solve();
        printf("Case #%d: %d\n", i, answer);
    }
    
    return 0;
}

int solve()
{
    int i = 0; // for loop
    int N = 0; // # of houses
    int B = 0; // budget
    int answer = 0;
    int *costs; // cost of the house
    int *sorted_costs;
    int *selected; // check for selected house
    int minimum = 0;
    
    scanf("%d %d", &N, &B);
    
    costs = (int*)malloc(sizeof(int) * N);
    selected = (int*)malloc(sizeof(int) * N);
    memset(selected, 0, sizeof(int) * N);
    
    for (i = 0; i < N; i++)
    {
        scanf("%d", &costs[i]);
    }
    
    sorted_costs = sort(costs, N);
    
    for (i = 0 ; i < N; i++)
    {
        if (sorted_costs[i] > B)
            break;
        
        B -= sorted_costs[i];
        answer++;
    }
    
    free(costs);
    free(sorted_costs);
    
    return answer;
}

int* sort(int* costs, int N)
{
    int counts[1001] = {0};
    int i = 0;
    int position = 0;
    int* sorted_costs = (int*)malloc(sizeof(int) * N);
    int value = 0;
    
    for (i = 0; i < N; i++)
    {
        counts[costs[i]]++;
    }
    
    for (i = 1; i < 1001; i++)
    {
        counts[i] += counts[i-1];
    }
    
    for (i = N - 1; i >= 0; i--)
    {
        value = costs[i];
        sorted_costs[--counts[value]] = value;
    }
    
    return sorted_costs;
}
