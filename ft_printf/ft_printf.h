/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:52:14 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/26 17:19:07 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define GR(z, x) (z >= x ? z : x)
# define NEG(v) (v < 0 ? 1 : 0)
# define ABS(x) (x < 0 ? -x : x)
# define IS_FORMAT1(c) c == 'c' || c == 's' || c == 'p' || c == 'd' || c == '%'
# define IS_FORMAT2(c) c == 'i' || c == 'u' || c == 'x' || c == 'X'
# define IS_FORMAT(c) ( IS_FORMAT1(c) || IS_FORMAT2(c) ? 1 : 0)
# define IS_FLAG(c) ((c == '0' || c == '-' || c == '.' || c == '*') ? 1 : 0)
# define CO !(!is_point(s + 1) || g_f.p != 0 || value != 0)
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_flags {
	int		z;
	int		p;
	int		s;
}					t_flags;

void				point_detect(char *s, va_list *st);
void				zero_detect(char *s, va_list *st);
void				spaces_detect(char *s, va_list *st);
int					print_percentage(char *s, va_list *st);
int					print_int(char *s, va_list *st);
int					ft_printf(const char *s, ...);
int					ncount(int n);
int					print_s(int n);
int					print_z(int n, int is_neg);
int					is_point(char *s);
char				format_finder(const char *s);
int					print_format(va_list *st, char format, char *s);
int					skip(char *s);
int					print_uint(char *s, va_list *st);
unsigned int		ft_putunbr(unsigned int n);
void				my_putchar(char c);
int					uncount (unsigned int n);
void				reset(int *a, int *b);
void				tohex(unsigned int number, char font, int *size, char aff);
int					print_hex(char *s, va_list *st, char font);
void				tohex8(unsigned long number, int *size, char aff);
int					print_pointer(char *s, va_list *st);
int					print_char(char *s, va_list *st);
int					ft_putstr(char *s, int size);
int					print_string(char *s, va_list *st);
int					reducer(char *s, int *spaces, int value, int p);
int					ft_printf(const char *s, ...);
int					is_it_the_case(char *s, int *j);
int					skip_zm(char **s);

#endif
