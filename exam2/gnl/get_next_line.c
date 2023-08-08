#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(const char *str)
{
    int i = 0;
    
    if (!str)
        return (0);
    while (*str)
        i++;
    return (i);
}

int ft_strchr(char *str, char f)
{
    int i;

    i = 0;
    while (str[i++])
    {
        if (str[i] == f)
            return (i);
    }
    return (-1);
}


char    *ft_substr(const char *store, int begin, int len)
{
    int     i;
    char    *result;

    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (store[begin] && i < len)
        result[i++] = store[begin++];
    result[i] = '\0';
    return (result);
}

char    *ft_strjoin(char *store, char c)
{
    char    *result;
    int     i;
    int     len;

    i = 0;
    len = ft_strlen(store);
    result = (char *)malloc(sizeof(char) * len + 2);
    while (i < len)
    {
        result[i] = store[i];
        i++;
    }
    result[i++] = c;
    result[i] = '\0';
    if (store)
        free(store);
    return (result);
}

int get_next_line(char **line)
{
    static char *store;
    char        buffer[1];
    char        *tmp;
    int         pos;

    store = (char *)malloc(sizeof(char) * 2);
    if (!store || !line)
        return (-1);
    while (read(0, buffer, 1) > 0)
    {
        store = ft_strjoin(store, buffer[0]);
        if (buffer[0] == '\n')
            break;
    }
    if ((pos = ft_strchr(store, '\n')) >= 0)
    {
        *line = ft_substr(store, 0 ,pos);
        tmp = store;
        store = ft_substr(store, pos + 1, ft_strchr(store, '\0'));
        free(tmp);
        return (1);
    }
    *line = ft_substr(store, 0, '\0');
    free(store);
    return (0);
} 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void    v(void)
{
    system("leaks a.out");
}

int main(void)
{
	char 	*line;
	int	ret;

    atexit(v);
	line = NULL;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d %s\n", ret, line);
	free(line);
}