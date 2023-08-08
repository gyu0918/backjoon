#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    int len;
    char    *result;
    int     i;

    len = ft_strlen(str);
    result = malloc(len + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (str[i])
    {
        result[i] = str[i];
        i++;
    }
    result[i] = 0;
    return (result);
}

char    *get_next_line(int fd)
{
    char    rtn[7000000];
    char    buffer;
    int     i;
    int     n;

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
    if (i == 0 && n <= 0)
        return (0);
    return (ft_strdup(rtn));
}

/////////////////////////////////////
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int len;
    int i;

    len = 0;
    if (!str)
        return "(null)";
    i = 0;
    while (str[i])
    {
        len += write(1, &str[i], 1);
        i++;
    }
    return (len);
}

int ft_puthex(unsigned int n)
{
    int len;

    len = 0;
    if (n > 15)
    {
        len += ft_puthex(n / 16);
        len += ft_puthex(n % 16);
    }
    else if (n > 9)
        len += ft_putchar(n + 87);
    else
        len += ft_putchar(n + 48);
    return (len);
}

int ft_putnbr(int nb)
{
    int         len;
    long long   n;

    len = 0;
    n = nb;
    if (n < 0)
    {
        len += write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    else
        len += ft_putchar(n + 48);
    return (len);
}

int ft_printf(const char *format, ...)
{
    int     len;
    va_list ptr;
    int     i;

    va_start(ptr, format);
    i = -1;
    len = 0;
    while (format[++i])
    {
        if (format[i] != '%')
            len += write(1, &format[i], 1);
        else if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                len += ft_putstr(va_arg(ptr, char *));
            else if (format[i] == 'x')
                len += ft_puthex(va_arg(ptr, unsigned int));
            else if (format[i] == 'd')
                len += ft_putnbr(va_arg(ptr, int));
        }
    }
    va_end(ptr);
    return (len);
}