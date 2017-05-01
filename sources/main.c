/*
** main.c for main in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:20:52 2017 goedert nicolas
** Last update Tue Mar 21 12:20:52 2017 goedert nicolas
*/

#include "minishell2.h"
#include "my_str_to_word_tab.h"
#include "get_next_line.h"

int		main1(t_init2 *init2, char **env)
{
  init2->i = 0;
  init2->tab = NULL;
  init2->elem = recup(env);
  init2->elem = startpath(init2->elem, 5);
  init2->newpath = my_str_to_word_tab(init2->elem, init2->tab);
  if ((access(init2->newpath[init2->i], F_OK)) == -1)
    init2->i++;
  while (1)
    {
      my_putstr("ZANGO LE DOZO -> ");
      if ((init2->buffer = get_next_line(0)) == NULL)
	return (0);
      init2->buffer = epur_str(init2->buffer);
      my_exit(init2->buffer);
      if (init2->buffer[0] != '\0')
	if (my_execve(init2->newpath, init2->buffer, env, init2->tab) == -1)
	  return (0);
      free(init2->buffer);
    }
}

int		main(int ac, char **av, char **env)
{
  t_init2	*init2;

  (void)ac;
  (void)av;
  if ((init2 = malloc(sizeof(t_init2))) == NULL)
    return (0);
  main1(init2, env);
  return (0);
}
