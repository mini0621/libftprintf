libftprintf
====

l'ecole 42 project libft, get_next_line and libftprintf.
A base library used in 42, 
including basic libc functions, linked lists, AVL tree, and printf.

topics: C, libc, memory allocation, algorythm, recursive, data structure, library, makefile, tree, linked list, AVL tree, self-balancing tree

skills: C programming basics, libc, memory allocation, leak management, makefile, data structure, recursive, fileIO


## Description
#### libc functions
``
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t			 ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
```

#### other util functions
```
size_t				ft_atozu(const char *str);
unsigned long long	ft_atollu(const char *str);
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
int					ft_sqrt(int nb);
int					ft_power(int base, int power);
char				*ft_strjoinfree(char **s1, char **s2, int i);
char				*ft_strupper(char *s);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_deltab(char **tab);
```

#### linked lists
```
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnomallocnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstlast(t_list *alst);
int					ft_lstlen(t_list *alst);
t_list				*ft_lstat(t_list *alst, unsigned int nbr);
void				ft_lstpushback(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **alst, t_list *new, int (*cmp)(void *, void *));
void				ft_lstdelof(t_list **alst, void *content, int (*cmp)(void *, void *));
t_list				*ft_lstfind(t_list *alst, void *content, int (*cmp)(void *, void *));
void				ft_lstsort(t_list **alist, int(*cmp)(void *, void *));
t_list				*ft_lstsub(t_list **top, t_list *tar);
```

#### queue
```
t_queue				*ft_qappend(t_queue *q, t_list *nl);
t_queue				*ft_qpush(t_queue *q, t_list *nl);
t_queue				*ft_qnew(void);
t_list				*ft_qpop(t_queue *q);
void				ft_qdel(t_queue **q, void (*del)(void *, size_t));
void				ft_qclear(t_queue **q, void (*del)(void *, size_t));
```

#### printf functions
```
int					ft_printf(const char *fmt, ...);
int					ft_sprintf(char *str, const char *fmt, ...);
int					ft_snprintf(char *str, size_t size, const char *fmt, ...);
int					ft_dprintf(int fd, const char *fmt, ...);
int					ft_asprintf(char **ret, const char *fmt, ...);
```

#### AVL tree
```
t_tnode			*ft_avlnew(void const *content, size_t contentsize);
t_tnode			*ft_avladd(t_tnode **root, t_tnode *new, int (*cmp)(void *, void *), void (*del)(void *));
int				height (t_tnode *n);
t_tnode			*rrotate(t_tnode *top);
t_tnode			*lrotate(t_tnode *top);
t_tnode			*ft_avlfind(t_tnode *root, void *value, int (*cmp)(void *, void *));
void			ft_treedel(t_tnode **root, void (*del)(void *));
```

#### get next line 
```
int					get_next_line(const int fd, char **line);
```

## Requirement
gcc

## Usage

#### to make a libftprintf.a library
```
make libftprintf
```
#### header files
includes/libftprintf.h

## Author

[Misaki Nishimoto](https://github.com/mini0621)
