/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:07:46 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/06/18 18:32:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
// max fd by my macbook 256, by ubuntu in 42 1024
# define MAX_FD 256
# define ERROR -1
# define SUCCS 1

typedef struct s_gnl
{
	char			*buf;
	char			*nl;
	int				len;
	int				eof;
	int				len_sum;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_gnl *lst);
void	ft_create_line(t_gnl *lst, char **line);
void	ft_save_rest(t_gnl *lst, t_gnl *rest[], int fd);
void	*ft_create_newnode(t_gnl *node);

void	ft_bzero(void *s, size_t n);
void	ft_gnl_clear(t_gnl **lst);
char	*ft_strchr(const char *s, int c);
char	*ft_strncat(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char*s);

#endif
