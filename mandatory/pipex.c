#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;
	int			status_wait;

	if (ac != 5)
		return (0);
	if (!check_infile(av[1]))
		return (0);
	cmd_list = main_process(ac, av, envp);
	if (!cmd_list)
		return (0);
	status_wait = wait_cmds(cmd_list);
	free_list(cmd_list);
	return (status_wait);
}

t_cmd_info	*main_process(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;
	int			*pfd;

	cmd_list = init_all_cmds(ac, av, envp);
	if (!cmd_list)
		return (NULL);
	pfd = create_all_pipes(cmd_list);
	if (!pfd)
	{
		free_list(cmd_list);
		close_free_pfd(pfd);
		return (NULL);
	}
	execute_all_cmds(cmd_list, pfd);
	close_free_pfd(pfd);
	return (cmd_list);
}
