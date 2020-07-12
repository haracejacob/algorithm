#include <stdio.h>
#include <stdlib.h>

int solve();
int get_anwser(int N, int* V);

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
    int N = 0;
    int i =0;
    int breaking_days = 0;
    int maximum_v = -1;
    int first_v = -1;
    int second_v = -1;
    int third_v = -1;

    scanf("%d", &N);
    scanf("%d", &third_v);
    for (i=1; i < N; i++)
    {
        first_v = second_v;
        second_v = third_v;
        scanf("%d", &third_v);

        if (maximum_v < first_v) {
            maximum_v = first_v;
        }

        if (second_v > maximum_v && second_v > third_v)
        {
            breaking_days++;
        }
    }
    first_v = second_v;
    second_v = third_v;

    if (maximum_v < first_v) {
        maximum_v = first_v;
    }

    if (second_v > maximum_v)
    {
        breaking_days++;
    }

    return breaking_days;
}