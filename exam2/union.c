#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    int flag;

    if (argc != 3 || argc == 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        flag = 0;
        j = 0;
        while (j < i)
        {
            if (argv[1][i] == argv[1][j])
                flag = 1;
            j++;
        }
        if (flag == 0)
            write(1, &argv[1][i], 1);
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        flag = 0;
        j = 0;
        while (argv[1][j])
        {
            if (argv[1][j] == argv[2][i])
                flag = 1;
            j++;
        }
        if (flag == 0)
        {
            j = 0;
            while (j < i)
            {
                if (argv[2][i] == argv[2][j])
                    flag = 1;
                j++;
            }
            if (flag == 0)
                write(1, &argv[2][i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}