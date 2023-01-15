/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:46:01 by junggkim          #+#    #+#             */
/*   Updated: 2023/01/09 03:10:39 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <stdlib.h>

char	*new_strdup(char *store)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\n')
		i++;
	len = i;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = store[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	allfree(char *buffer, char **store)
{
	free (buffer);
	free (*store);
	*store = NULL;
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*store[259];

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (check_check(fd, buffer, &store[fd]) == -1)
	{
		allfree(buffer, &store[fd]);
		return (NULL);
	}
	temp = new_strdup(store[fd]);
	if (temp == NULL)
	{
		allfree(buffer, &store[fd]);
		return (NULL);
	}
	store[fd] = rest(store[fd]);
	free(buffer);
	return (temp);
}

#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd1 = open("ditto", O_RDONLY);
	int fd2 = open("hype", O_RDONLY);
	char *buf = 0;
	int i = 0;

	while(1) {
		buf = get_next_line(fd1);
		printf("ditto : %d : %s", i, buf);
		free(buf);
		if (!buf)
			break;
		buf = get_next_line(fd2);
		printf("hypeboy : %d : %s", i, buf);
		i++;
		free(buf);
	}
	system("leaks a.out");
	return 0;
}
