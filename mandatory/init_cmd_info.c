#include "pipex.h"

t_cmd_info	*init_all_cmds(int ac, char **av, char **envp)
{
	int			i;
	int			var;
	int			counter;
	t_cmd_info	*cmd_head;
	t_cmd_info	*cmd;

	i = 0;
	counter = 2;
	var = ac - 3;
	cmd_head = NULL;
	while (i++ < var)
	{
		cmd = init_cmd(ac, counter, av, envp);
		if (!cmd)
		{
			if (cmd_head)
				free_list(cmd_head);
			exit(127);
		}
		cmd_head = add_cmd_to_list(cmd, cmd_head);
		counter++;
	}
	return (cmd_head);
}

t_cmd_info	*init_cmd(int ac, int counter, char **av, char **envp)
{
	t_cmd_info	*cmd;
	char		*file;

	if (counter == 2)
		file = av[1];
	else
		file = av[ac - 1];
	cmd = init_cmd_info(envp, av[counter], counter - 1);
	if (!cmd)
		return (NULL);
	cmd->file_fd = ft_file_fd(cmd, file, counter, ac);
	if (cmd->file_fd == -1)
	{
		free_cmd(cmd);
		return (NULL);
	}
	return (cmd);
}

t_cmd_info	*init_cmd_info(char **envp, char *cmd, int index)
{
	t_cmd_info	*cmd_info;

	cmd_info = malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		return (NULL);
	cmd_info->cmd = NULL;
	cmd_info->cmd_path = NULL;
	cmd_info->connection = NULL;
	cmd_info->status = 0;
	cmd_info->index = index;
	cmd_info->envp = envp;
	if (!(init(cmd_info, cmd, envp)))
		return (NULL);
	return (cmd_info);
}

int	init(t_cmd_info *cmd_info, char *cmd, char**envp)
{
	cmd_info->cmd = ft_split(cmd, ' ');
	if (!cmd_info->cmd)
	{
		free_cmd(cmd_info);
		return (0);
	}
	cmd_info->cmd_path = find_command_path(cmd_info->cmd[0], envp);
	if (!cmd_info->cmd_path)
	{
		write(2, "command not found: ", 20);
		ft_putendl_fd(cmd_info->cmd[0], 2);
		free_cmd(cmd_info);
		return (0);
	}
	cmd_info->connection = malloc(sizeof(int) * 2);
	if (!cmd_info->connection)
	{
		free_cmd(cmd_info);
		return (0);
	}
	return (1);
}

int	ft_file_fd(t_cmd_info *cmd, char *file, int cmd_index, int ac)
{
	int		fd;
	mode_t	mode;

	if (cmd_index == 2 && file)
	{
		fd = open(file, O_RDONLY);
		cmd->inout = 'i';
	}
	else if (cmd_index == ac - 2)
	{
		mode = S_IRUSR | S_IWUSR;
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, mode);
		cmd->inout = 'o';
	}
	else
	{
		fd = 0;
		cmd->inout = 'c';
	}
	return (fd);
}
