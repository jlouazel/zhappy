/*
** zhappy_server.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu May  2 11:04:21 2013 julien fortin
** Last update Thu Jul 11 14:50:26 2013 louaze_j
*/

#ifndef	__SERVER_DATA_H__
#define	__SERVER_DATA_H__

#define DEFAULT_X	50
#define	DEFAULT_Y	50
#define	DEFAULT_TIME	100
#define	DEFAULT_NB_PL	1

#include	"lib_socket.h"
#include	"server_data_options.h"
#include	"server_data_io.h"
#include	"server_data_cmd.h"
#include	"game.h"

typedef struct	s_server
{
  const t_io		*io;
  const t_cmd		*cmd;
  const t_options	*options;
  const t_socket	*socket;
  const t_game		*game;
} t_server;

#endif
