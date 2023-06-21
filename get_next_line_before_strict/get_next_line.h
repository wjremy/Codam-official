/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:09:52 by wremy             #+#    #+#             */
/*   Updated: 2023/01/11 20:17:10 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*add_chunk_to_line(char *line, char *chunk);
char	*save_after_n(char	*line);
char	*del_after_n(char	*line);
char	*shrink_chunk(char	*chunk, int rt);
void	ft_strcpy(char *dst, char *src);
char	*get_next_line(int fd);

#endif