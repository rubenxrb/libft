#ifndef CORE_H
# define CORE_H

# include <stddef.h>

typedef struct			s_slln
{
	void				*data;
	size_t				d_size;
	struct s_slln		*next;
}						t_slln;

void		*ft_memalloc(size_t size);
void		*ft_memset(void *p, int c, size_t size);
void		ft_memdel(void **ap);
void		ft_bzero(void *p, size_t size);
void		*ft_memcpy(void *restrict dst, const void *restrict src,
			size_t size);
void		*ft_memccpy(void *restrict dst, const void *restrict src, int c,
			size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *p, int c, size_t n);
void		*ft_memrchr(const void *p, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_toupper(int c);
int			ft_tolower(int c);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isblank(int c);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnew(size_t size);
char		*ft_strcat(char *restrict s1, const char *restrict s2);
char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *small);
char		*ft_strnstr(const char *big, const char *small, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);

size_t		ft_putchar(const char ch);
size_t		ft_putchar_fd(const char ch, int fd);
size_t		ft_putstr(char const *s);
size_t		ft_putstr_fd(char const *s, int fd);
size_t		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);

t_slln		*ft_lstnew(void const *data, size_t d_size);
void		ft_lstdelone(t_slln **curr, void (*bzero)(void *, size_t));
void		ft_lstdel(t_slln **head, void (*bzero)(void *, size_t));
void		ft_lstadd(t_slln **head, t_slln *new);
void		ft_lstiter(t_slln *head, void (*f)(t_slln *node));
t_slln		*ft_lstmap(t_slln *head, t_slln *(*f)(t_slln *node));

#endif
