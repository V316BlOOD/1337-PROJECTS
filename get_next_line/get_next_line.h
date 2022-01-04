/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:15:00 by yaziz             #+#    #+#             */
/*   Updated: 2019/11/15 00:12:27 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

ssize_t		f(char *s, char c);
char		*cut(char *str, ssize_t index);
char		*save(char *saving_var, char *second_str);
int			free_ret(char **p, int ret);
char		*duplicate(char *dup, char **tofree);
int			get_next_line(int fd, char **line);
int			get_next_line_third(char **s, char **str, char **line);
int			get_next_line_second(char **saved_var, char **line, char **str);

#endif
