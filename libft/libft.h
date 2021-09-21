/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:43:55 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 17:26:34 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	void			*name;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t len);

void				ft_bzero(void *str, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);

bool				ft_lencmp(char *s1, char *s2);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

char				*ft_strcpy(char *src, char *dst);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

bool				ft_strcmp(char *s1, char *s2);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					find_quote(char *s, int i);

void				*ft_calloc(size_t count, size_t size);

char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

char				**ft_split(char const *s, char c);

t_list				*ft_lstnew(void *content);

t_list				*ft_lstnew_pp(char **content);

void				ft_lstadd_front(t_list **lst, t_list *new);

t_list				*ft_lstnew(void *content);

t_list				*ft_lstnew_pp(char **content);

t_list				*ft_lstdup_2p(t_list *lst);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

t_list				*ft_lsthead_2p(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstadd_back_2p(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void*));

void				ft_lstclear(t_list **lst, void (*del)(void*));

void				ft_lstiter(t_list *lst, void (*f)(void*));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void*),
						void (*del)(void*));

void				ft_lstprint(t_list *lst, char type);

void				ft_lstnode_print_2p(t_list *lst);

void				ft_lstnode_print(t_list *lst, char *name);



#endif
