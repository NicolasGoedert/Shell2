/*
** my_str_to_word_tab.h for str in /home/nicolas94200/PSU/PSU_2016_minishell2/include
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Wed Mar 22 12:37:36 2017 goedert nicolas
** Last update Wed Mar 22 12:37:36 2017 goedert nicolas
*/

#ifndef MY_STR_TO_WORD_TAB_H
# define MY_STR_TO_WORD_TAB_H_

typedef struct	s_init
{
  int		i;
  int		j;
  int		k;
}		t_init;

int		distance(char *str);
int		characters(char *str);
void		show_to_tab(char **tab);
char		**my_str_to_word_tab(char *str, char **tab);
void		var(t_init *init);

#endif /* !MY_STR_TO_WORD_TAB_H_ */
