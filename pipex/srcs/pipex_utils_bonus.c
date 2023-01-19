/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:01:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/19 14:30:06 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	find_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			return (i);
		i++;
	}
	return (-1);
}

char	*cmd_join(char *env, char *cmd)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	while (env[i] != '/')
		i++;
	size = ft_strlen(env + i) + ft_strlen(cmd) + 2;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (env)
	{
		ft_strlcat(str, env + i, ft_strlen(env + i) + 1);
		free(env);
		env = NULL;
	}
	ft_strlcat(str, "/", ft_strlen(str) + 2);
	ft_strlcat(str, cmd, size);
	return (str);
}

int	search_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*make_path(char	*str)
{
	char	*path;

	path = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (path)
		ft_strlcpy(path, str, ft_strlen(str) + 1);
	return (path);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**tab;
	char	*path;

	path = NULL;
	i = find_env(envp);
	if ((cmd[0] == '.' || search_slash(cmd)) && !access(cmd, X_OK))
		path = make_path(cmd);
	tab = ft_split(envp[i], ':');
	i = 0;
	while (tab[i] && !path)
	{
		tab[i] = cmd_join(tab[i], cmd);
		if (!access(tab[i], X_OK))
			path = make_path(tab[i]);
		i++;
	}
	ft_free_tab(tab);
	return (path);
}
