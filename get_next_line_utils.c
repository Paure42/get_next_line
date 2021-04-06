/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_lines_utils.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 14:47:26 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 14:57:49 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = count * size;
	if (!(str = malloc(i)))
		return (0);
	i = -1;
	while (++i < (count * size))
		str[i] = 0;
	return (str);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = -1;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	i += ft_strlen(s2);
	if (!(str = malloc((i + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++n])
	{
		str[i] = s2[n];
		i++;
	}
	str[i] = 0;
	free((char*)s1);
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len, int f)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = NULL;
	i = ft_strlen(s);
	if (start >= i)
		return (free_strs((char*)s, str));
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (free_strs((char*)s, str));
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	if (f == 1)
		free((char*)s);
	return (str);
}
