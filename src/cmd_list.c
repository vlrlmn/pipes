#include "src.h"

t_cmd_info	*add_cmd_to_list(t_cmd_info *cmd, t_cmd_info *head)
{
	t_cmd_info	*current;
	t_cmd_info	*new_cmd;

	new_cmd = cmd;
	new_cmd->next = NULL;
	if (!head)
	{
		head = new_cmd;
		head->next = NULL;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_cmd;
	}
	return (head);
}

int	free_cmd(t_cmd_info *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->cmd_path)
		free(cmd->cmd_path);
	if (cmd->cmd)
		free_split(cmd->cmd);
	if (cmd->connection)
		free(cmd->connection);
	if (cmd->file_fd > 0)
		close(cmd->file_fd);
	free(cmd);
	return (1);
}

int	free_list(t_cmd_info *cmd_list)
{
	t_cmd_info	*current;
	t_cmd_info	*tmp;

	if (!cmd_list)
		return (1);
	current = cmd_list;
	while (current)
	{
		tmp = current->next;
		free_cmd(current);
		current = tmp;
	}
	return (1);
}
