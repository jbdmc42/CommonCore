/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkstemp_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:35:32 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:37:21 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_mkstemp_fd(void)
{
	static int	fd = -1;

	return (&fd);
}

char	*ft_mkstemp_path(void)
{
	static char	path[PATH_MAX];

	return (path);
}

void	ft_store_mkstemp_path(char *template, int fd)
{
	if (!template)
		return ;
	ft_strlcpy(ft_mkstemp_path(), template, PATH_MAX);
	*ft_mkstemp_fd() = fd;
}

char	*ft_get_mkstemp_path(int fd)
{
	if (fd != *ft_mkstemp_fd())
		return (NULL);
	return (ft_mkstemp_path());
}

void	ft_clear_mkstemp_path(void)
{
	*ft_mkstemp_fd() = -1;
	ft_mkstemp_path()[0] = '\0';
}
