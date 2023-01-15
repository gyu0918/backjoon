/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:37:52 by junggkim          #+#    #+#             */
/*   Updated: 2023/01/08 20:28:17 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	static char	*store;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (check_check(fd, buffer, &store) == -1)
	{
		allfree(buffer, &store);
		return (NULL);
	}
	temp = new_strdup(store);
	if (temp == NULL)
	{
		allfree(buffer, &store);
		return (NULL);
	}
	store = rest(store);
	free(buffer);
	return (temp);
}

#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("ditto", O_RDONLY);
	char *buf = 0;
	int i = 0;

	while(1) {
		buf = get_next_line(fd);
		printf("%d : %s", i, buf);
		i++;
		free(buf);
		if (!buf)
			break;
	}
	system("leaks a.out");
	return 0;
}
