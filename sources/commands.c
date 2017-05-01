/*
** commands.c for commands in /home/nicolas94200/PSU_2016_minishell2/sources
**
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
**
** Started on  Tue Mar 21 12:20:35 2017 goedert nicolas
** Last update Tue Mar 21 12:20:35 2017 goedert nicolas
*/

#include "minishell2.h"
#include "my_str_to_word_tab.h"
#include "get_next_line.h"

char		*startpath(char *str, int i)
{
  char		*buff;
  int		j;

  j = 0;
  if ((buff = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[i])
    {
      buff[j] = str[i];
      i++;
      j++;
    }
  return (buff);
}

void		var3(t_init3 *init3)
{
  init3->i = 1;
  init3->j = 0;
  init3->tab = NULL;
}

int		my_execve(char **path, char *buffer, char **env, char **tab)
{
  t_init3	*init3;
  pid_t		pid;

  pid = fork();
  if ((init3 = malloc(sizeof(t_init3))) == NULL)
    return (0);
  var3(init3);
  init3->commands = my_str_to_word_tab(buffer, tab);
  while (init3->i != 0 && path[init3->j] != '\0')
    {
      init3->newpath = my_strcat(path[init3->j], "/");
      init3->newpath = my_strcat(init3->newpath, init3->commands[0]);
      if ((init3->i = access(init3->newpath, F_OK)) == -1)
	init3->j++;
    }
  if (pid == 0)
    {
      if ((execve(init3->newpath, init3->commands, env)) == -1)
	my_perror("Command not found.\n");
      return (-1);
    }
  else
    wait(NULL);
  return (1);
}
