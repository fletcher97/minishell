/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:45:49 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/07 17:57:20 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dl_list
{
	void				*content;
	void				*name;
	struct s_dl_list	*prev;
	struct s_dl_list	*next;
}						t_dl_list;

void		ft_lstadd_back(t_list **lst, t_list *elem);
void		ft_lstadd_front(t_list **lst, t_list *elem);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *conten);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back_dl(t_dl_list **lst, t_dl_list *new);
t_dl_list	*ft_lstdup_dl(t_dl_list *lst);
t_dl_list	*ft_lsthead_dl(t_dl_list *lst);
t_dl_list	*ft_lstnew_dl(char **content);
t_dl_list	*ft_lstlast_dl(t_dl_list *lst);
void		ft_lstnode_print(t_dl_list *lst, char *name);
void		ft_lstnode_print_dl(t_dl_list *lst);
void		ft_lstprint(t_dl_list *lst, char type);

#endif
