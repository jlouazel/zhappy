/*
** zappy.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu May  2 15:48:20 2013 julien fortin
** Last update Mon Jul  8 10:49:05 2013 julien fortin
*/

#ifndef	__SERVERZAPPY_H__
#define	__SERVERZAPPY_H__

#define	ENTRY_PORT	6969
#define	MAX_FAIL_SELECT 42

#include	<stdbool.h>
#include	"server_data.h"

const t_server	*server_init(t_server*, int, const char**);
const t_server  *destroy_server(t_server*);

const t_cmd	*init_server_cmd();
const t_cmd	*destroy_server_cmd(const t_cmd*);

const t_io      *init_server_io();
const t_io      *destroy_server_io(const t_io*);

const t_options	*init_server_options(int, const char**);
const t_options	*destroy_server_options(const t_options*);

const t_game    *init_game(const t_options*);

int		server_loop(const t_server*);
int		run(const t_server*);

bool		server_disconnect_player(const t_server*, t_player*);
bool            server_players_actions(const t_server *, fd_set *);
bool		server_listen_connection_queue(const t_server*, fd_set*);
bool            server_listen_player(const t_server *, fd_set *, int*);
bool            server_will_notify_player(const t_server *, fd_set *, int*);
bool		server_notify_player(const t_server *, fd_set*);

void		server_accept(const t_server*, const fd_set*);

#endif
