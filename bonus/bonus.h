#ifndef BONUS_H
# define BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "../src/src.h"
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
// # include "./tmazitov_gnl/get_next_line.h"

t_cmd_info	*main_process(int ac, char **av, char **envp);

//init
t_cmd_info	*init_all_cmds(int ac, char **av, char **envp);
t_cmd_info	*init_cmd_info(char **envp, char *cmd, int index);
t_cmd_info	*init_cmd(int ac, int counter, char **av, char **envp);
int			init(t_cmd_info *cmd_info, char *cmd, char**envp);
int			ft_file_fd(t_cmd_info *cmd, char *file);
char		*file_name(t_cmd_info *cmd, char **av, int ac);

//pipes
int			**create_all_pipes(t_cmd_info *cmd_list);
int			**fill_pipes(t_cmd_info *cmd, int **pipe_arr, int i);
int			*create_a_pipe(int **pipe_arr);
int			close_free_pipe_arr(int **pipe_arr);

//bonus
int			is_here_doc(char **av);
int			ft_here_doc(char *limiter);
int	which_fd(t_cmd_info *cmd, int ac, char **av);
void		close_pipe_free_input(char *input, int pfd[2]);

//execution
int			execute_all_cmds(t_cmd_info *cmd_list, int **pipe_arr);
int			execute_cmd(t_cmd_info *cmd, t_cmd_info *cmd_list, int **pipe_arr);
int			wait_cmds(t_cmd_info *cmd_head);
int			list_size(t_cmd_info *cmd_list);

#endif