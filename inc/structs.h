#ifndef STRUCTS_H
# define STRUCTS_H

//	nodes
typedef struct		s_dlln
{
	struct s_dlln	*next;
	struct s_dlln	*prev;
	void		*data;
	size_t		d_size;
}			t_dlln;

typedef struct		s_slln
{
	struct s_slln	*next;
	void		*data;
	size_t		d_size;
}			t_slln;

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
}			s_nbtnode;

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
	t_qnode		*front;
	t_qnode		*rear;
	size_t		len;
}			t_queue;

typedef struct		s_stack
{
	t_stckn		*top;
	size_t		len;
}			t_stack;

typedef struct		s_hashmap;
{
	t_array		table;
	int		(*f)(const void *);
}			t_hashmap;

typedef struct		s_tree
{
	void		*root;
	void		*leftmost;
	void		*rightmost;
	size_t		depth;
}			t_tree;

void			lst_addstr(t_lst *list, const char *str);
void			lst_addnewarray(t_lst *list, const char *name);/*allocates new content */
void			lst_addwstr(t_lst *list, const wchar_t *name);
void			lst_addarray(t_lst *list, t_array *add);/*connects ptr*/
void			dllst_addstr(t_lst *list, const char *str);

t_dlnode		*dllst_findstr(t_lst *list, const char *str, t_byte head);
void			dllst_delstr(t_lst *list, const char *str, t_byte head);
void			dllst_print(t_lst *list, t_byte head);
void			dllst_del(t_lst *list);

void			ft_lstadd_back(t_node **head, t_node *new);
size_t			ft_lstlen(t_node *head);

t_dlnode		*dlnode_new(void const *data, size_t data_size);
t_byte			dlnode_free(t_dlnode **node);
size_t			dlinklst_free(t_dlnode **lst);
void			dlnode_addnext(t_dlnode *curr, t_dlnode *add);
t_dlnode		*update_tail(t_dlnode *head);

t_dlnode		*split_dlinklst(t_dlnode **starting);
t_dlnode		*dlinklst_sort(t_dlnode **head, t_byte (*cmp)(void *, void *));
t_dlnode		*dlinklst_merge(t_dlnode *lst, t_dlnode *tmp, t_byte (*cmp)(void *, void *));

/*NEED*/
t_bnode			*bt_new(void const *data, size_t d_size);
t_bnode			*bt_lookup(t_bnode *tree, void const *data, size_t d_size);
t_bnode			*bt_insert(t_bnode *tree, void const *data, size_t d_size);
t_nbnode		*btn_new(const int n);
int			btn_lookup(t_nbnode *tree, const int n);
t_nbnode		*btn_insert(t_nbnode *tree, const int n);

t_snode			*snode_new(void const *data, size_t d_size);
t_snode			*stack_push(t_snode *top, t_snode *new);
t_snode			*stack_pop(t_snode *top);
t_snode			*stack_lookup(t_snode *top, t_snode *node);
void			snode_del(t_snode *node);
t_snode			*stack_last(t_snode *top);
void			stack_del(t_snode *top);
size_t			stack_len(t_snode *top);

t_array			*array_new(size_t d_size, size_t len);
t_array			*array_resize(t_array *old, size_t new_size);
t_array			*array_clone(t_array *src);
void			array_destroy(t_array *curr);
void 			*array_look(t_array *curr, size_t index);
void			append_char(t_array **curr, size_t times, char ch);
void			cat_char(t_array **curr, size_t times, int ch);
void			append_atchar(t_array **curr, size_t at, size_t times, char ch);


#endif
