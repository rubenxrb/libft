/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

# include "get_next_line.h"
//# include "ft_printf.h"
//# include "ft_ls.h"

typedef unsigned char	t_byte;

// data structure nodes
typedef struct		s_node
{
	void			*data;
	size_t			d_size;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlnode
{
	void			*data;
	size_t			d_size;
	struct s_dlnode	*next;
	struct s_dlnode	*prev;
}					t_dlnode;

typedef struct		s_bnode
{
	void			*data;
	size_t			d_size;
	struct s_bnode	*left;
	struct s_bnode	*right;
}					t_bnode;

typedef struct		s_nbnode
{
	int				num;
	struct s_nbnode	*left;
	struct s_nbnode	*right;
}					t_nbnode;

typedef struct		s_snode
{
	void			*data;
	size_t			d_size;
	struct s_snode	*prev;
}					t_snode;

// data structures
typedef struct		s_lst
{
	void			*head;
	void			*tail;
	size_t			len;
}					t_lst;

typedef struct		s_btree
{
	void			*root;
	void			*left;
	void			*right;
}					t_tree;

typedef struct		s_stack
{
	struct s_snode	*top;
	size_t			len;
}					t_stack;

typedef struct		s_array
{
	void			*data;
	size_t			d_size;
	size_t			len;
	size_t			bytes;
}					t_array;

// memptrs
void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size, size_t new_size);
void				*ft_memset(void *p, int c, size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *p, size_t size);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *p, int c, size_t n);
void				*ft_memrchr(const void *p, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

//	convert
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_hextoa(int n, size_t prec); /* need */
int					uctoutf8(const char *dest, wchar_t ch);
int					ft_hextoi(const char *hex);

//	identifiers
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
int					ft_ishex(int c);
int					ft_ishexstr(const char *hex);
int					ft_isemoji(int c); /* need */

//	strings
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *small);
char				*ft_strnstr(const char *big, const char *small, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrev(const char *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strinsrt(const char *dst, size_t n, const char *src);
size_t				count_words(const char *str);
char				*get_next_word(const char *s, char **word);
char				**split_blnk(const char *str);
void				free_tab(char **ap);

//	prints
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_print_bits(unsigned char byte);
void				ft_putnbrnl(int n);
void				ft_puthex(int n); /* need */
void				ft_puthexnl(int n); /* need */
void				set_color(int c);

//	linkedlst
t_node				*ft_lstnew(void const *data, size_t d_size);				//ok
void				ft_lstdelone(t_node **curr, void (*bzero)(void *, size_t));	//ok <test>
void				ft_lstdel(t_node **head, void (*bzero)(void *, size_t));	//needs update
void				ft_lstadd(t_node **head, t_node *new);						//needs update
void				ft_lstiter(t_node *head, void (*f)(t_node *node));			//ok <test>
t_node				*ft_lstmap(t_node *head, t_node *(*f)(t_node *node));		//ok <test>
void				ft_lstadd_back(t_node **head, t_node *new);					//ok
size_t				ft_lstlen(t_node *head);									//test

// binarytrees
t_bnode				*bt_new(void const *data, size_t d_size);
t_bnode				*bt_lookup(t_bnode *tree, void const *data, size_t d_size);
t_bnode				*bt_insert(t_bnode *tree, void const *data, size_t d_size);
t_nbnode			*btn_new(const int n);
int					btn_lookup(t_nbnode *tree, const int n);
t_nbnode			*btn_insert(t_nbnode *tree, const int n);

// stack
t_snode				*snode_new(void const *data, size_t d_size); 				//ok
t_snode				*stack_push(t_snode *top, t_snode *new);					//ok
t_snode				*stack_pop(t_snode *top);									//ok
t_snode				*stack_lookup(t_snode *top, t_snode *node);					//ok
void				snode_del(t_snode *node);									//ok
t_snode				*stack_last(t_snode	*top);									//ok
void				stack_del(t_snode *top);									//ok
size_t				stack_len(t_snode *top);									//needs test [ok]

//array
t_array				*array_new(void *data, size_t d_size, size_t len);			//ok
t_array				*array_resize(t_array *old, size_t new_size);				//ok
t_array				*array_clone(t_array *src);									//ok
void				array_destroy(t_array *curr);								//ok
void 				*array_look(t_array *curr, size_t index);					//ok

//	misc
int					ft_digitnum(int n, int base);

#endif
