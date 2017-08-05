#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned char	t_byte;

//	nodes
typedef struct		s_dlln
{
	struct s_dlln	*next;
	struct s_dlln	*prev;
	void		*data;
	size_t		d_size;
}			t_dlln;

typedef struct		s_stckn
{
	struct s_stckn	*next;
	void		*data;
	size_t		d_size;
}			t_stckn;

typedef struct		s_trie
{
	int		**data;
	struct s_trie	*next;
}			t_trie;

typedef struct		s_btnode
{
	void		*left;
	void		*right;
	void		*data;
	size_t		d_size;
}			t_btnode;

typedef struct		s_nbtnode
{
	void		*left;
	void		*right;
	int		data;
}			t_nbtnode;

//	structs
typedef struct		s_array
{
	void		*array;
	size_t		d_size;
	size_t		len;
	size_t		bytes;
}			t_array;

typedef struct		s_list
{
	void		*head;
	void		*tail;
	size_t		len;
}			t_list;

typedef struct		s_queue
{
	struct s_queue	*front;
	struct s_queue	*rear;
	size_t		len;
}			t_queue;

typedef struct		s_stack
{
	t_stckn		*top;
	size_t		len;
}			t_stack;

typedef struct		s_hashmap
{
	t_array		table;
	void	(*f)(const void *p);
}			t_hashmap;

typedef struct		s_tree
{
	void		*root;
	void		*leftmost;
	void		*rightmost;
	size_t		depth;
}			t_tree;

void			lst_addstr(t_list *list, const char *str);
void			lst_addnewarray(t_list *list, const char *name);/*allocates new content */
void			lst_addwstr(t_list *list, const wchar_t *name);
void			lst_addarray(t_list *list, t_array *add);/*connects ptr*/
void			dllst_addstr(t_list *list, const char *str);

t_dlln		*dllst_findstr(t_list *list, const char *str, t_byte head);
void			dllst_delstr(t_list *list, const char *str, t_byte head);
void			dllst_print(t_list *list, t_byte head);
void			dllst_del(t_list *list);

void			ft_listadd_back(t_slln **head, t_slln *new);
size_t			ft_listlen(t_slln *head);

t_dlln		*dlnode_new(void const *data, size_t data_size);
t_byte			dlnode_free(t_dlln **node);
size_t			dlinklst_free(t_dlln **lst);
void			dlnode_addnext(t_dlln *curr, t_dlln *add);
t_dlln		*update_tail(t_dlln *head);

t_dlln		*split_dlinklst(t_dlln **starting);
t_dlln		*dlinklst_sort(t_dlln **head, t_byte (*cmp)(void *, void *));
t_dlln		*dlinklst_merge(t_dlln *lst, t_dlln *tmp, t_byte (*cmp)(void *, void *));

/*NEED*/
t_btnode			*bt_new(void const *data, size_t d_size);
t_btnode			*bt_lookup(t_btnode *tree, void const *data, size_t d_size);
t_btnode			*bt_insert(t_btnode *tree, void const *data, size_t d_size);
t_nbtnode		*btn_new(const int n);
int			btn_lookup(t_nbtnode *tree, const int n);
t_nbtnode		*btn_insert(t_nbtnode *tree, const int n);

t_stckn			*snode_new(void const *data, size_t d_size);
t_stckn			*stack_push(t_stckn *top, t_stckn *new);
t_stckn			*stack_pop(t_stckn *top);
t_stckn			*stack_lookup(t_stckn *top, t_stckn *node);
void			snode_del(t_stckn *node);
t_stckn			*stack_last(t_stckn *top);
void			stack_del(t_stckn *top);
size_t			stack_len(t_stckn *top);

t_array			*array_new(size_t d_size, size_t len);
t_array			*array_resize(t_array *old, size_t new_size);
t_array			*array_clone(t_array *src);
void			array_destroy(t_array *curr);
void 			*array_look(t_array *curr, size_t index);
void			append_char(t_array **curr, size_t times, char ch);
void			cat_char(t_array **curr, size_t times, int ch);
void			append_atchar(t_array **curr, size_t at, size_t times, char ch);

#endif
