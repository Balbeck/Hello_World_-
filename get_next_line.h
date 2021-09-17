/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:53:18 by balbecke          #+#    #+#             */
/*   Updated: 2021/05/15 01:42:45 by balbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/stat.h>

int	main();

int	get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
# endif
