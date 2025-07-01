/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:08:35 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/06/18 18:33:25 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n-- > 0)
		*temp++ = 0;
}

void	ft_lst_clear(t_lst **lst)
{
	if ((*lst)->next)
		ft_lst_clear(&((*lst)->next));
	free((*lst)->buf);
	free(*lst);
	*lst = NULL;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s || *s == (char)c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char			*tmp;
	unsigned int	d_len;

	d_len = ft_strlen(dst);
	tmp = dst + d_len;
	while (*src && n-- > 1)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dst);
}

size_t	ft_strlen(const char*s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
