//
// main.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:20:33 2013 louaze_j
// Last update Tue Jul  9 16:40:51 2013 louaze_j
//

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Graphic.hh"

static
bool	parseArgs(int ac, char **av, GraphicClient & client) {
  char	flag;

  while ((flag = getopt(ac, av, "p:h:")) > 0) {
    switch (flag) {
    case 'p':
      client.setPort(atoi(optarg));
      break;
    case 'h':
      client.setHost(optarg);
      break;
    case '?':
      return false;
    default:
      break;
    }
  }
  return true;
}

int	main(int ac, char **av)
{
  GraphicClient	client;

  if (parseArgs(ac, av, client) == false)
    return false;
  client.setSocket(new_socket(client.getPort(), client.getHost().c_str(), SOCK_CLIENT));
  std::cout << "Listening on " << client.getHost() << ":" << client.getPort() << "..." << std::endl;
  return 0;
}
