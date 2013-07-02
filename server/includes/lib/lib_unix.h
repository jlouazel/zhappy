/*
** libmy_c_unix.h for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr  9 15:32:03 2013 julien fortin
** Last update Mon Jun 24 10:27:33 2013 julien fortin
*/

#ifndef	__LIBMY_C_UNIX_H__
#define	__LIBMY_C_UNIX_H__

int		get_file_size(int);
int             my_open(const char *, int);
int		xdup2(int, int);

const char	*get_current_time(void);

#endif
