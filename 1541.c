#include <stdio.h>
#include <string.h>

int main()
{
    char    form[51];
    int     arr[25] = {0};
    scanf("%s", form);
    int     len = strlen(form);
    int     i, j = 0, k = 0, temp = 0, sum = 0, result = 0;
    
    i = 0;
    while (i <= len)
    {
        if (form[i] == '-' || i == len)
        {
            sum += temp;
            arr[j] = sum;
            j++;
            temp = 0;
            sum = 0;
        }
        else if (form[i] == '+')
        {
            sum += temp;
            temp = 0;
        }
        else
        {
            temp *= 10;
            temp += form[i] - '0';
        }
        i++;
    }
    result = arr[0];
    i = 1;
    while (i < j)
    {
        result -= arr[i];
        i++;
    }
    printf("%d", result);
    return (0);
}