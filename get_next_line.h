/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:38:18 by junggkim          #+#    #+#             */
/*   Updated: 2023/01/08 19:38:19 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		new_strchr(char *str, char c);
char	*get_next_line(int fd);
int		check_check(int fd, char *buffer, char **store);
char	*new_strjoin(char *str1, char *str2);
int		new_strlen(char *store);
char	*new_strdup(char *store);
char	*rest(char *store);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

#endif
