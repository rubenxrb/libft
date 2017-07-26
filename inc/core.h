#ifndef CORE_H
# define CORE_H

# include <stddef.h>

typedef struct s_slln t_slln;

void	*ft_memalloc(size_t size);						//libft
void	*ft_memset(void *p, int c, size_t size);				//libft
void	ft_memdel(void **ap);							//libft
void	ft_bzero(void *p, size_t size);						//libft
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t size);	//libft
void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);			//libft
void	*ft_memchr(const void *p, int c, size_t n);				//libft
void	*ft_memrchr(const void *p, int c, size_t n);				//libft
int	ft_memcmp(const void *s1, const void *s2, size_t n);			//libft

int	ft_atoi(const char *str);						//libft
char	*ft_itoa(int n);							//libft
int	ft_toupper(int c);							//libft
int	ft_tolower(int c);							//libft
int	ft_isalpha(int c);							//libft
int	ft_isdigit(int c);							//libft
int	ft_isalnum(int c);							//libft
int	ft_isascii(int c);							//libft
int	ft_isprint(int c);							//libft

size_t	ft_strlen(const char *s);						//libft
char	*ft_strdup(const char *s1);						//libft
char	*ft_strcpy(char *dst, const char *src);					//libft
char	*ft_strncpy(char *dst, const char *src, size_t len);			//libft
char	*ft_strnew(size_t size);						//libft
char	*ft_strcat(char *restrict s1, const char *restrict s2);			//libft
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);	//libft
size_t	ft_strlcat(char *dst, const char *src, size_t size);			//libft
char	*ft_strchr(const char *s, int c);					//libft
char	*ft_strrchr(const char *s, int c);					//libft
char	*ft_strstr(const char *big, const char *small);				//libft
char	*ft_strnstr(const char *big, const char *small, size_t len);		//libft
int	ft_strcmp(const char *s1, const char *s2);				//libft
int	ft_strncmp(const char *s1, const char *s2, size_t n);			//libft
void	ft_strdel(char **as);							//libft
void	ft_strclr(char *s);							//libft
void	ft_striter(char *s, void (*f)(char *));					//libft
void	ft_striteri(char *s, void (*f)(unsigned int, char *));			//libft
char	*ft_strmap(char const *s, char (*f)(char));				//libft
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));		//libft
int	ft_strequ(char const *s1, char const *s2);				//libft
int	ft_strnequ(char const *s1, char const *s2, size_t n);			//libft
char	*ft_strsub(char const *s, unsigned int start, size_t len);		//libft
char	*ft_strjoin(char const *s1, char const *s2);				//libft
char	*ft_strtrim(char const *s);						//libft
char	**ft_strsplit(char const *s, char c);					//libft

size_t	ft_putchar(const char ch);						//libft
size_t	ft_putchar_fd(const char ch, int fd);					//libft
size_t	ft_putstr(char const *s);						//libft
size_t	ft_putstr_fd(char const *s, int fd);					//libft
//size_t	ft_write(const char *s, size_t len, int fd);			//libft
size_t	ft_putendl(char const *s);						//libft
//size_t	ft_putendl_fd(char const *s, int fd);					//libft
void	ft_putnbr(int n);							//libft
void	ft_putnbr_fd(int n, int fd);						//libft
//void	ft_putnbrnl(int n);							//libft

t_slln	*ft_lstnew(void const *data, size_t d_size);				//libft
void	ft_lstdelone(t_slln **curr, void (*bzero)(void *, size_t));		//libft
void	ft_lstdel(t_slln **head, void (*bzero)(void *, size_t));		//libft
void	ft_lstadd(t_slln **head, t_slln *new);					//libft
void	ft_lstiter(t_slln *head, void (*f)(t_slln *node));			//libft
t_slln	*ft_lstmap(t_slln *head, t_slln *(*f)(t_slln *node));			//libft

#endif
