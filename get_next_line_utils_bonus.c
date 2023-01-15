/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:24:41 by junggkim          #+#    #+#             */
/*   Updated: 2023/01/09 07:20:18 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	new_strlen(char *store)
{
	int	i;

	if (!store)
		return (0);
	i = 0;
	while (store[i])
		i++;
	return (i);
}

int	new_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*new_strjoin(char *store, char *buffer)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(new_strlen(store) + new_strlen(buffer) + 1);
	if (result == NULL)
		return (NULL);
	if (store)
		while (store[i])
			result[j++] = store[i++];
	i = 0;
	if (buffer)
		while (buffer[i])
			result[j++] = buffer[i++];
	result[j] = '\0';
	if (store != NULL)
		free(store);
	return (result);
}

int	check_check(int fd, char *buffer, char **store)
{
	int	count;

	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1 || (count == 0 && new_strlen(*store) == 0))
			return (-1);
		buffer[count] = '\0';
		*store = new_strjoin(*store, buffer);
		if (*store == NULL)
			return (-1);
		if (new_strchr(*store, '\n'))
			return (1);
		if (count < BUFFER_SIZE)
			return (1);
	}
}

char	*rest(char *store)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\n')
		i++;
	len = new_strlen(&store[i]);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (j < len)
		result[j++] = store[i++];
	result[j] = '\0';
	free(store);
	return (result);
}
