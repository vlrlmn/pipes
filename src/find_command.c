#include "src.h"

char	*find_command_path(char *cmd, char **envp)
{
	char	*path;
	char	*cmd_path;
	char	**path_arr;

	path = find_path(envp);
	if (!path)
	{
		write(2, "PATH not found\n", 16);
		return (NULL);
	}
	path_arr = ft_split(path, ':');
	if (!path_arr)
		return (NULL);
	cmd_path = check_if_cmd_exists(path_arr, cmd);
	free_split(path_arr);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

char	*check_if_cmd_exists(char **path_arr, char *cmd)
{
	int		counter;
	char	*path_line;

	counter = 0;
	path_line = NULL;
	while (path_arr[counter])
	{
		path_line = add_cmd_to_line_in_path(path_arr[counter], cmd);
		if (!path_line)
			return (NULL);
		if (if_path_to_cmd(path_line))
			return (path_line);
		free(path_line);
		counter++;
	}
	return (NULL);
}

int	if_path_to_cmd(char *path_line)
{
	if (access(path_line, F_OK) == -1)
		return (0);
	if (access(path_line, X_OK) == -1)
	{
		perror("cmd is not executable\n");
		return (0);
	}
	return (1);
}

char	*add_cmd_to_line_in_path(char *line, char *cmd)
{
	char	*path_line;

	path_line = ft_strjoin(line, cmd);
	if (!path_line)
	{
		free(path_line);
		return (NULL);
	}
	return (path_line);
}
