/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:55:20 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 01:49:58 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef enum	e_lm
{
	none = 0,
	h,
	hh,
	l,
	ll,
	L
}				t_lm;

typedef struct	s_flags
{
	char	sharp;
	char	min_0;
	char	plus_sp;
}				t_flags;

typedef struct	s_printops
{
	t_flags	flag;
	int		width;
	int		precision;
	t_lm	lmod;
	char	cnvrtsp;
}				t_printops;

typedef char *(*t_prcs_fp)(va_list *, t_printops *, size_t *);

typedef struct	s_funcs
{
	char		cnvrt_specifier;
	t_prcs_fp	function;
}				t_funcs;

typedef struct	s_double
{
	int		sign;
	uint16_t	expo;
	uint64_t	frac;
}				t_double;


typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubfree(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_sqrt(int nb);
int					ft_power(int base, int power);
t_list				*ft_lstlast(t_list *alst);
int					ft_lstlen(t_list *alst);
t_list				*ft_lstat(t_list *alst, unsigned int nbr);
void				ft_lstpushback(t_list **alst, t_list *new);
void				ft_lstdelof(t_list **alst, void *content,
		int (*cmp)(void *, void *));
t_list				*ft_lstfind(t_list *alst, void *content,
		int (*cmp)(void *, void *));
char				*ft_strjoinfree(char **s1, char **s2, int i);
char				*ft_strupper(char *s);

int					ft_printf(const char *fmt, ...);
void				printoutput(char *output, size_t len);
char				*join_chars(char **output, char *fmt, size_t *len);
char				*join_cnvrt(char **output, char **start, va_list *ap, size_t *len);

char				*convert(va_list *ap, char **start, size_t *l);
t_prcs_fp			getprcsf(t_printops *opt);

int 				is_cnvrtsp(char c);
t_printops			*initoption(void);
t_printops			*readops(char **start);
void				storeops(char **start, int i, t_printops *opt);

char				*prcs_e(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_x(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_o(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_u(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_d(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_p(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_s(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_c(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_f(va_list *ap, t_printops *opt, size_t *l);
char				*prcs_ld(va_list *ap, t_printops *opt, int *sign);
char				*prcs_db(va_list *ap, t_printops *opt, int *sign);
char				*sp_double(int sign, uint64_t frac);

long long 			ft_llpower(long long base, long long power);
char				*ft_lltoa(long long n);
unsigned long long 	ft_lluporwer(unsigned long long base, unsigned long long power);
char				*ft_llutoa(unsigned long long n, unsigned int base);

long double			ft_neg_power(int power);
char				get_n_dig(long double n);
long double 		round_ld(long double n, int precision);
char				*ft_ldtolltoa(long double n, int precision);

void				carry_frac(unsigned long long *frac10);
void				add_frac(unsigned long long *a, unsigned long long **b);
void				mult_frac(unsigned long long *frac, int a, int times);
int					div_frac(unsigned long long *a, int times);
int					shift_frac_right(unsigned long long *a);
int					shift_frac_left(unsigned long long *a);
unsigned long long get_mincarry(unsigned long long *a, unsigned long long carry);

char				*fractoa(unsigned long long *frac, int e);
unsigned long long *init_frac(uint64_t frac, short expo, int frac_bits);
char				*get_frac10(t_double *n, int frac_bits, int subnormal);

int					get10th_expo(uint16_t expo);
char				*ft_ldtoa(t_double *n, int precision, int e);
t_double			*get_ldouble(long double n);
int		round_s(char **s, int point, int precision);
int		skip_zeros(char *s);
char	*sub_integer(char **s, int point, int precision);


char				*ft_dbtoa(t_double *n, int precision, int e);
t_double			*get_double(double n);

char				*normalize(char **s, int expo, int precision, int iszero);
char				*prcs_eld(va_list *ap, t_printops *opt, int *sign);
char				*prcs_edb(va_list *ap, t_printops *opt, int *sign);
void				round_e(char **s, int precision);
char	*prcs_flags(t_printops *opt, char **s, int sign);
char	*prcs_sharp(char sp, char **s);
char	*prcs_plus(char	sp, char **s, char c);
char	*prcs_zero(char sp, char **s, int w, t_flags *flags);
char	*prcs_min(char sp, char **s, int w, char min);

char	*prcs_precision(char sp, char **s, int precision);
char	*prcs_precision_end(char sp, char **s, int precision);

#endif 
