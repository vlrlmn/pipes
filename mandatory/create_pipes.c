#include "pipex.h"

int	*create_all_pipes(t_cmd_info *cmd_list)
{
	t_cmd_info	*cmd;
	int			*pfd1;

	pfd1 = malloc(sizeof(int) * 2);
	if (!pfd1)
		return (NULL);
	if (pipe(pfd1) < 0)
		return (NULL);
	cmd = cmd_list;
	while (cmd)
	{
		if (cmd->inout == 'i')
		{
			cmd->connection[0] = cmd->file_fd;
			cmd->connection[1] = pfd1[1];
		}
		if (cmd->inout == 'o')
		{
			cmd->connection[0] = pfd1[0];
			cmd->connection[1] = cmd->file_fd;
		}
		cmd = cmd->next;
	}
	return (pfd1);
}

int	close_free_pfd(int *pfd)
{
	close(pfd[0]);
	close(pfd[1]);
	free(pfd);
	return (1);
}
