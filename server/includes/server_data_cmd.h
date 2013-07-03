/*
** server_data_cmd.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jun 21 16:29:14 2013 julien fortin
** Last update Tue Jul  2 16:38:13 2013 julien fortin
*/

#ifndef	__SERVER_DATA_CMD_H__
#define	__SERVER_DATA_CMD_H__

#define	SERVER_CMD_NB	0

typedef struct s_server t_server;

typedef struct  s_cmd
{
  const char	*name[SERVER_CMD_NB + 1];
  const char	*(*cmd[SERVER_CMD_NB + 1])(const t_server *,
					  const char *);
} t_cmd;

#endif
