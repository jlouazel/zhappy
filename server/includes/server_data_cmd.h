/*
** server_data_cmd.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jun 21 16:29:14 2013 julien fortin
** Last update Sun Jul 14 00:37:43 2013 julien fortin
*/

#ifndef	__SERVER_DATA_CMD_H__
#define	__SERVER_DATA_CMD_H__

#define	SERVER_CMD_PLAYER_NB	11
#define	SERVER_CMD_GRAPH_NB	9

typedef struct s_server		t_server;
typedef struct s_graphical	t_graphical;

#include	"player.h"

typedef struct  s_cmd_player
{
  double	time[SERVER_CMD_PLAYER_NB + 1];
  const char	*name[SERVER_CMD_PLAYER_NB + 1];
  const char	*(*cmd[SERVER_CMD_PLAYER_NB + 1])(t_player *,
						  const t_server *,
						  void *);
} t_cmd_player;

typedef struct s_cmd_graph
{
  const char	*name[SERVER_CMD_GRAPH_NB + 1];
  const char	*(*cmd[SERVER_CMD_GRAPH_NB + 1])(t_graphical *,
						 const t_server *,
						 const char *);
} t_cmd_graph;

#endif
