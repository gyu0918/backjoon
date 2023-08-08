#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    int flag;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    flag = 0;
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
        {
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    write(1, &argv[1][i], 1);
                    break;
                }
                j++;
            }
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}