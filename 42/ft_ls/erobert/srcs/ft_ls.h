/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 17:50:54 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 15:13:43 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define END "\033[0m"

typedef enum		e_arg
{
	MG,
	MR,
	MS,
	A,
	L,
	R,
	T
}					t_arg;

typedef struct		s_obj
{
	char			*mode;
	char			*links;
	char			*user;
	char			*group;
	char			*size;
	char			*blocks;
	time_t			epoch;
	char			*name;
	struct s_obj	*next;
}					t_obj;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_mode(int st_mode);
t_obj				*ft_objnew(struct dirent *dp, char *dir, int *arg);
int					ft_objcmp(t_obj *o1, t_obj *o2, int k);
t_obj				*ft_lstdir(DIR *dirp, char *dir, int *arg);
void				ft_lstrev(t_obj **obj);
void				ft_lstsort(t_obj **obj, int (*cmp)(), int k);
void				ft_spaces(t_obj *obj, int *arg);
int					ft_sixmonth(t_obj *obj);
char				ft_checkarg(char *av, int *arg);
void				ft_totalline(t_obj *obj, int *arg);
void				ft_printobj(t_obj *obj, int *arg);
int					ft_printfile(char *file, int *arg, int k);
void				ft_printdir(DIR *dirp, char *dir, int *arg);
int					ft_illegal(char c);
int					ft_notopen(char *s);
int					ft_nopermission(char *s);
int					ft_no_roption(char *dir, int *arg);
int					ft_roption(char *dir, int *arg);

#endif
