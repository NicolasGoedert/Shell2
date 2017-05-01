/*
** minishell2.h for mini in /home/nicolas94200/PSU/PSU_2016_minishell2/include
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Wed Mar 22 12:37:14 2017 goedert nicolas
** Last update Wed Mar 22 12:37:14 2017 goedert nicolas
*/

#ifndef MINISHELL2_H_
# define MINISHELL2_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
** struct du epur_str.c
*/

typedef struct	s_init4
{
  int		i;
  int		j;
  char		*new;
}		t_init4;

/*
** struct de my_execve.c
*/

typedef struct	s_init3
{
  int		i;
  int		j;
  char		*newpath;
  char		**commands;
  char		**tab;
}		t_init3;

/*
** struct du main.c
*/

typedef struct	s_init2
{
  int		i;
  char		*elem;
  char		*buffer;
  char		**tab;
  char		**newpath;
}		t_init2;

/*
** struct du strncmp.c
*/

typedef struct	s_init1
{
  int		i;
  int		size1;
  int		size2;
}		t_init1;

/*
** basics.c && basics2.c
*/

void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strlen(char *str);
char		*my_strcpy(char *dest, char *src);
void		my_perror(char *str);
char		*my_strchr(char *str, int c);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
void		my_strncmp1(t_init1 *init1, char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
int		epur_str2(t_init4 *init4, char *str);
char		*epur_str(char *str);

/*
**recup_path.c
*/

char		*recup(char **env);

/*
** commands.c && commands2.c
*/

char		*startpath(char *str, int i);
void		var3(t_init3 *init3);
int		my_execve(char **path, char *buffer, char **env, char **tab);
int		my_exit(char *buffer);

/*
** main.c
*/

int		main1(t_init2 *init2, char **env);

#endif /* !MINISHELL2_H_ */
