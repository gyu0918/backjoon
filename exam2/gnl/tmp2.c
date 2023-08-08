#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *result;
    int i;
    int len;

    i = -1;
    len = ft_strlen(str);
    if (!str)
        return (0);
    result = malloc(len + 1);
    while (str[++i])
        result[i] = str[i];
    result[i] = 0;
    return (result);
}

char *get_next_line(int fd)
{
    char buffer;
    char rtn[7000000];
    int n;
    int i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    i = 0;
    n = read(fd, &buffer, 1);
    while (n > 0)
    {
        rtn[i++] = buffer;
        if (buffer == '\n')
            break;
        n = read(fd, &buffer, 1);
    }
    rtn[i] = 0;
    if (n <= 0 || i == 0)
        return (0);
    return (ft_strdup(rtn));
}