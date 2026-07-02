/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lseek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:10:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:25:22 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reopen_at_start(int fd, char *path)
{
	int	new_fd;

	new_fd = open(path, O_RDONLY);
	if (new_fd < 0)
	{
		unlink(path);
		ft_clear_mkstemp_path();
		return (-1);
	}
	close(fd);
	unlink(path);
	ft_clear_mkstemp_path();
	return (new_fd);
}

int	ft_lseek(int fd, off_t offset, int whence)
{
	char	*path;

	if (fd < 0 || offset != 0 || whence != SEEK_SET)
		return (-1);
	path = ft_get_mkstemp_path(fd);
	if (!path)
		return (-1);
	return (reopen_at_start(fd, path));
}
