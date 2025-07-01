/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:58:04 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/06/19 15:28:58 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define MAX_FD 1024
# define ERROR -1
# define SUCCS 1

typedef struct s_lst
{
	char			*buf;
	char			*nl;
	int				len;
	int				eof;
	int				len_sum;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_lst *lst);
void	ft_create_line(t_lst *lst, char **line);
void	ft_save_rest(t_lst *lst, t_lst *rest[], int fd);
void	*ft_create_newnode(t_lst *node);

void	ft_bzero(void *s, size_t n);
void	ft_lst_clear(t_lst **lst);
char	*ft_strchr(const char *s, int c);
char	*ft_strncat(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char*s);

#endif
