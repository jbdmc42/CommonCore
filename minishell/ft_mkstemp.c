/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkstemp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:10:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:37:59 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int		*ft_mkstemp_fd(void);
char	*ft_mkstemp_path(void);
void	ft_store_mkstemp_path(char *template, int fd);
char	*ft_get_mkstemp_path(int fd);
void	ft_clear_mkstemp_path(void);

static int	validate_template(char *template)
{
	size_t	len;

	if (!template)
		return (0);
	len = ft_strlen(template);
	if (len < 6 || ft_strncmp(template + len - 6, "XXXXXX", 6) != 0)
		return (0);
	return (1);
}

static void	fill_candidate(char *template, unsigned int value)
{
	static const char	charset[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	size_t				len;
	int					i;

	len = ft_strlen(template);
	i = 5;
	while (i >= 0)
	{
		template[len - 6 + i] = charset[value % 36];
		value /= 36;
		i--;
	}
}

int	ft_mkstemp(char *template)
{
	unsigned long	attempt;
	int				fd;

	if (!validate_template(template))
		return (-1);
	attempt = 0;
	while (attempt < 100000)
	{
		fill_candidate(template, (unsigned int)attempt);
		fd = open(template, O_CREAT | O_EXCL | O_RDWR, 0600);
		if (fd >= 0)
		{
			ft_store_mkstemp_path(template, fd);
			return (fd);
		}
		if (errno != EEXIST)
			return (-1);
		attempt++;
	}
	ft_clear_mkstemp_path();
	return (-1);
}
