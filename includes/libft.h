/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:43:55 by fferreir          #+#    #+#             */
/*   Updated: 2021/08/23 14:20:28 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_lists
{
	void			*content;
	struct s_lists	*next;
}					t_lists;

void				*ft_memset(void *str, int c, size_t len);

void				ft_bzero(void *str, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

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

t_lists				*ft_lstnew(void *content);

void				ft_lstadd_front(t_lists **lst, t_lists *new);

t_lists				*ft_lstnew(void *content);

void				ft_lstadd_front(t_lists **lst, t_lists *new);

int					ft_lstsize(t_lists *lst);

t_lists				*ft_lstlast(t_lists *lst);

void				ft_lstadd_back(t_lists **lst, t_lists *new);

void				ft_lstdelone(t_lists *lst, void (*del)(void*));

void				ft_lstclear(t_lists **lst, void (*del)(void*));

void				ft_lstiter(t_lists *lst, void (*f)(void*));

t_lists				*ft_lstmap(t_lists *lst, void *(*f)(void*),
						void (*del)(void*));

#endif
