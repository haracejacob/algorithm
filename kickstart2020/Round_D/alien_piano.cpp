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
    int K = 0;
    int i = 0;
    int breaking_rule = 0;
    int pitch = 0;
    int previous_pitch = 0;

    int flag = 0;
    int serial = 0;

    scanf("%d", &K);
    scanf("%d", &pitch);

    for (i = 1; i < K; i++)
    {
        previous_pitch = pitch;
        scanf("%d", &pitch);

        if (pitch > previous_pitch)
        {
            if (flag > 0)
            {
                serial++;
            }
            else
            {
                flag = 1;
                serial = 1;
            }
        }
        else if (pitch < previous_pitch)
        {
            if (flag < 0)
            {
                serial++;
            }
            else
            {
                flag = -1;
                serial = 1;
            }
        }

        if (serial >= 4)
        {
            flag = 0;
            serial = 0;
            breaking_rule++;
        }
    }

    return breaking_rule;
}