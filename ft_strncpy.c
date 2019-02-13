/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:50:22 by rpapagna          #+#    #+#             */
/*   Updated: 2019/02/11 19:01:36 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (*src)
	{
		while (i < len && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
