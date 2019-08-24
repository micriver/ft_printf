/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:14:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/19 19:15:19 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	length = 0;
	while (str[length] != '\0')
		length++;
	i = -1;
	while (++i < --length)
	{
		temp = str[i];
		str[i] = str[length];
		str[length] = temp;
	}
	return (str);
}
