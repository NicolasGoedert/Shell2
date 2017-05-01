/*
** my_exit.c for exit in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:21:28 2017 goedert nicolas
** Last update Tue Mar 21 12:21:28 2017 goedert nicolas
*/

#include "minishell2.h"
#include "get_next_line.h"
#include "my_str_to_word_tab.h"

int		my_exit(char *buffer)
{
  if (my_strncmp("exit", buffer, my_strlen("exit")) == 0)
    exit (0);
  else
    return (0);
}
