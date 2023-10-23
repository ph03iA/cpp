#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[2222];
    int i, j;
    while (scanf("%s", s) != EOF)
    {
        int l = strlen(s);
        for (i = 0; i < l; i++)
        {
            if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
            {
                s[i] = 1;
                s[i + 1] = 1;
                s[i + 2] = 1;
            }
        }
        j = 0;
        for (i = 0; i < l; i++)
        {

            if (j == 1)
            {
                if (s[i] == 1 && s[i + 1] == 1 && s[i + 2] == 1)
                {
                    printf(" ");
                    j = 0;
                }
            }
            if (s[i] != 1)
            {
                printf("%c", s[i]);
                j = 1;
            }
        }
        printf("\n");
    }
    return 0;
}