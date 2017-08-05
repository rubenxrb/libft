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
# define TRUE 1
# define FALSE 0

# include "core.h"
# include "structs.h"
# include "get_next_line.h"

void		*ft_realloc(void *ptr, size_t size, size_t new_size);
char		*ft_itoa_base(int n, int base);
char		*ft_lltoa_base(long long n, int b);
char		*ft_uitoa_base(unsigned int n, int b);
char		*ft_ulltoa_base(unsigned long long n, int b);
char		ft_eseqtochar(char seq[2]);

char		*ft_hextoa(int n, size_t prec);
int			uctoutf8(const char *dest, wchar_t ch);
int			ft_hextoi(const char *hex);

int			ft_isblank(int c);
int			ft_ishex(int c);
int			ft_ishexstr(const char *hex);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_isletter(char c1, char c2);
int			ft_isescseq(char *seq, size_t s_len);

char		*ft_strrev(const char *s);
char		*ft_strinsrt(const char *dst, size_t n, const char *src);
char		*get_next_word(const char *s, char **word);
char		**split_blnk(const char *str);
void		free_tab(char **ap);
char		*ft_chardup(const int ch);
char		*strtolower(char *str);
char		*printfstrdup(const char *s1);

size_t		ft_puthex(int c, size_t prec);
size_t		ft_puthexnl(int c, size_t prec);
void		set_color(int c);
void		ft_print_bits(unsigned char byte);
void		ft_tabprint(const char **tab);

size_t		putcstr(char const *s, size_t col);
size_t		putcnstr(char const *s, size_t len, size_t col);

size_t		wchar_len(wchar_t ch);
size_t		wcharput(const wchar_t ch);
size_t		wstrput(wchar_t const *s);
size_t		wstrlen(const wchar_t *s);
wchar_t		*wstrnew(size_t len);

wchar_t		*wstrdup(const wchar_t *src);
wchar_t		*wchardup(const wchar_t src);
size_t		wcharput_fd(const wchar_t ch, const int fd);
size_t		wstrput_fd(const wchar_t *src, const int fd, size_t len);

int		ft_numlen(int n, int base);
int		ft_lnumlen(long n, int base);
int		ft_unumlen(unsigned int n, int base);
int		ft_ulnumlen(unsigned long n, int base);
char	get_sign(char *nbr);

#endif
