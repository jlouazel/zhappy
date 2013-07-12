/*
** server_data_cmd.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jun 21 16:29:14 2013 julien fortin
** Last update Fri Jul 12 20:18:27 2013 julien fortin
*/

#ifndef	__SERVER_DATA_CMD_H__
#define	__SERVER_DATA_CMD_H__

#define	SERVER_CMD_NB	11

typedef struct s_server t_server;

#include	"player.h"

typedef struct  s_cmd
{
  double	time[SERVER_CMD_NB + 1];
  const char	*name[SERVER_CMD_NB + 1];
  const char	*(*cmd[SERVER_CMD_NB + 1])(t_player *,
					   const t_server *,
					   void *);
} t_cmd;

#endif
