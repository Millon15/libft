/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:15:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/31 20:55:59 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
*****************************************************************************
**************************************GNL************************************
*****************************************************************************
*/

# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

typedef	struct		s_gnl
{
	char			*arr;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

/*
*****************************************************************************
*************************************LIBFT***********************************
*****************************************************************************
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *);
void				ft_bzero(void *, size_t);
void				*ft_memccpy(void *, const void *, int, size_t);
void				*ft_memchr(const void *, int, size_t);
int					ft_memcmp(const void *, const void *, size_t);
void				*ft_memcpy(void *, const void *, size_t);
void				*ft_memmove(void *, const void *, size_t);
void				*ft_memset(void *, int, size_t);
char				*ft_strcpy(char *, const char *);
char				*ft_strdup(const char *);
char				*ft_strncpy(char *, const char *, size_t);
char				*ft_strstr(const char *, const char *);
char				*ft_strnstr(const char *, const char *, size_t);
char				*ft_strchr(const char *, int);
char				*ft_strrchr(const char *, int);
char				*ft_strcat(char *, const char *);
int					ft_strcmp(const char *, const char *);
int					ft_strncmp(const char *, const char *, size_t);
int					ft_atoi(const char *);
char				*ft_strcat(char *, const char *);
char				*ft_strncat(char *, const char *, size_t);
size_t				ft_strlcat(char *, const char *, size_t);
int					ft_isalpha(int);
int					ft_isdigit(int);
int					ft_isalnum(int);
int					ft_isascii(int);
int					ft_isprint(int);
int					ft_toupper(int);
int					ft_tolower(int);

void				*ft_memalloc(size_t);
void				ft_memdel(void **);
char				*ft_strnew(size_t);
void				ft_strdel(char **);
void				ft_strclr(char *);
void				ft_striter(char *, void (*)(char *));
void				ft_striteri(char *, void (*)(unsigned int, char *));
char				*ft_strmap(char const *, char (*)(char));
char				*ft_strmapi(char const *, char (*)(unsigned int, char));
int					ft_strequ(char const *, char const *);
int					ft_strnequ(char const *, char const *, size_t);
char				*ft_strsub(char const *, size_t, size_t);
char				*ft_strjoin(char const *, char const *);
char				*ft_strtrim(char const *);
char				**ft_strsplit(char const *, char);
char				*ft_itoa(int);
void				ft_putchar(char);
ssize_t				ft_putstr(char const *);
void				ft_putendl(char const *);
void				ft_putnbr(int);
void				ft_putchar_fd(char, int);
ssize_t				ft_putstr_fd(char const *, int);
void				ft_putendl_fd(char const *, int);
void				ft_putnbr_fd(int, int);

t_list				*ft_lstnew(void const *, size_t content_size);
void				ft_lstdelone(t_list **, void (*)(void *, size_t));
void				ft_lstdel(t_list **, void (*)(void *, size_t));
void				ft_lstadd(t_list **, t_list *);
void				ft_lstiter(t_list *, void (*)(t_list *));
t_list				*ft_lstmap(t_list *, t_list *(*)(t_list *));

void				ft_lstdelcont(void *, size_t);
void				ft_swap(int *, int *);
int					*ft_range(int, int);
void				ft_foreach(int *, int, void (*)(int));
char				*ft_itoa_base(int, int);
unsigned long int	ft_pow(int, int);
int					ft_root(int, int);
int					ft_fcd(int, int);
int					ft_isprint(int);
int					ft_iswhitespace(int);
int					ft_atoi_base(const char *, int);
unsigned long		ft_atou_base(const char *, int);
char				*ft_utoa_base(unsigned long, int);
char				*ft_strnjoin(char const *, char const *, size_t, size_t);
ssize_t				ft_putnstr(char const *, size_t);
ssize_t				ft_putnstr_fd(char const *, int fd, size_t);
ssize_t				ft_putnendl(char const *, size_t);
ssize_t				ft_putnendl_fd(char const *, int fd, size_t);
int					ft_module(int);
char				*checkintstr(char *);
int					ft_islowercase(const int);
int					ft_isuppercase(const int);
char				ft_itoc(const unsigned char, const bool);

#endif
