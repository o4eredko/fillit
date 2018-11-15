/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:52:26 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/31 15:18:43 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_LIBFT_H
# define LIBFT_TEST_LIBFT_H

# include <string.h>

# include <unistd.h>

# include <stdlib.h>

# include <stdio.h>

# define			CHECK(x) if (!x) return (0)

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memset(void *b, int c, size_t n);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strchr(const char *s, int c);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strdup(const char *s1);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t				ft_strlen(const char *s);

char				*ft_strncat (char *s1, const char *s2, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);

char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(const char *haystack, const char *needle);

int					ft_tolower(int c);

int					ft_toupper(int c);

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

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct				s_dancing_list
{
	struct s_dancing_list 	*up;
	struct s_dancing_list 	*down;
	struct s_dancing_list 	*left;
	struct s_dancing_list 	*right;
	void					**content;
	size_t 					c_count;
	size_t 					*c_size;
	long 					cords[2];
}							t_dancing_list;


t_dancing_list				*ft_dlstnew(void const **content, size_t c_count, size_t *c_size, long *cords);

#endif