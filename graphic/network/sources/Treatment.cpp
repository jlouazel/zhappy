//
// Treatment.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 02:14:07 2013 louaze_j
// Last update Fri Jul 12 00:31:57 2013 louaze_j
//
//

#include	<map>
#include	<utility>
#include	<cstdlib>
#include	"Parser.hh"
#include	"Graphic.hh"
#include	"eRessources.hh"

#include <iostream>

static void	msz(GraphicClient * client, std::vector<std::string> const & line)
{
  client->setWorld(new World(atoi(line[1].c_str()), atoi(line[2].c_str())));
}

static void	bct(GraphicClient * client, std::vector<std::string> const & line)
{
  int	x = atoi(line[1].c_str());
  int	y = atoi(line[2].c_str());

  if (client->getWorld())
    {
      Square *square = client->getWorld()->getMap()[RELATIV_POS(x, y, client->getWorld()->getWidth())];
      if (square)
	{
	  square->getContent()[FOOD] = atoi(line[3].c_str());
	  square->getContent()[LINEMATE] = atoi(line[4].c_str());
	  square->getContent()[DERAUMERE] = atoi(line[5].c_str());
	  square->getContent()[SIBUR] = atoi(line[6].c_str());
	  square->getContent()[MENDIANE] = atoi(line[7].c_str());
	  square->getContent()[PHIRAS] = atoi(line[8].c_str());
	  square->getContent()[THYSTAME] = atoi(line[9].c_str());
	  if (square->getX() == client->getWorld()->getWidth() - 1 && square->getX() == client->getWorld()->getHeight() - 1)
	    client->setReady(true);
	}
    }
}

static void	sgt(GraphicClient * client, std::vector<std::string> const & line)
{
  client->setTimeUnit(atoi(line[1].c_str()));
}

static void	tna(GraphicClient * client, std::vector<std::string> const & line)
{
  client->getTeams().push_back(new Teams(line[1]));
}

static void	pnw(GraphicClient * client, std::vector<std::string> const & line)
{
  Players	*player = new Players(atoi(line[2].c_str()),
				      atoi(line[3].c_str()),
				      atoi(line[1].c_str()),
				      atoi(line[5].c_str()),
				      line[6],
				      static_cast<eDirections>(atoi(line[4].c_str())));
  for (std::list<Teams *>::iterator it = client->getTeams().begin(); it != client->getTeams().end(); ++it)
    if ((*it)->getName() == line[6])
      (*it)->getMembers().push_back(player);
  client->getPlayers().insert(std::make_pair(player->getId(), player));
}

static void	ppo(GraphicClient * client, std::vector<std::string> const & line)
{
  client->getPlayers()[atoi(line[1].c_str())]->setX(atoi(line[2].c_str()));
  client->getPlayers()[atoi(line[1].c_str())]->setY(atoi(line[3].c_str()));
  client->getPlayers()[atoi(line[1].c_str())]->setDirection((eDirections)atoi(line[4].c_str()));
}

static void	plv(GraphicClient * client, std::vector<std::string> const & line)
{
  client->getPlayers()[atoi(line[1].c_str())]->setLvl(atoi(line[2].c_str()));
}

static void	pdi(GraphicClient * client, std::vector<std::string> const & line)
{
  std::string	teamName;
  int		id = atoi(line[1].c_str());

  if (client->getPlayers().empty() == false && client->getPlayers()[id])
    {
      teamName = client->getPlayers()[id]->getTeamName();
      for (std::list<Teams *>::iterator it  = client->getTeams().begin(); it != client->getTeams().end(); ++it)
	{
	  if ((*it)->getName() == teamName)
	    {
	      for (std::list<Players *>::iterator it2 = (*it)->getMembers().begin(); it2 != (*it)->getMembers().end(); ++it2)
		{
		  if ((*it2)->getId() == id)
		    {
		      delete *it2;
		      it2 = (*it)->getMembers().erase(it2);
		    }
		}
	    }
	}
    }
  else
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>VIDE" << std::endl;
  std::cout << "7" << std::endl;
  client->getPlayers().erase(atoi(line[1].c_str()));
  std::cout << "8" << std::endl;
  //  exit(0);
}

void		parseRead(GraphicClient * client, std::string const & line)
{
  std::cout << line << std::endl;
  std::map<int, std::string>	functions;
  functions[0] = "msz";
  functions[1] = "bct";
  functions[2] = "tna";
  functions[3] = "pnw";
  functions[4] = "ppo";
  functions[5] = "plv";
  functions[6] = "pin";
  functions[7] = "pex";
  functions[8] = "pbc";
  functions[9] = "pic";
  functions[10] = "pie";
  functions[11] = "pfk";
  functions[12] = "pdr";
  functions[13] = "pgt";
  functions[14] = "pdi";
  functions[15] = "enw";
  functions[16] = "eht";
  functions[17] = "ebo";
  functions[18] = "edi";
  functions[19] = "sgt";
  functions[20] = "sst";
  functions[21] = "seg";
  functions[22] = "smg";
  functions[23] = "suc";
  functions[24] = "sbp";
  functions[25] = "Err";
  std::vector<std::string>	parsedLine = Parser::splitString(line, " ");
  int indx = -42;
  for (std::map<int, std::string>::iterator it = functions.begin(); it != functions.end(); ++it)
    if (parsedLine[0] == it->second)
      {
	indx = it->first;
	break;
      }
  switch (indx)
    {
    case 0:
      msz(client, parsedLine);
      break;
    case 1:
      bct(client, parsedLine);
      break;
    case 2:
      tna(client, parsedLine);
      break;
    case 3:
      pnw(client, parsedLine);
      break;
    case 4:
      ppo(client, parsedLine);
      break;
    case 5:
      plv(client, parsedLine);
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      break;
    case 11:
      break;
    case 12:
      break;
    case 13:
      break;
    case 14:
      pdi(client, parsedLine);
      break;
    case 15:
      break;
    case 16:
      break;
    case 17:
      break;
    case 18:
      break;
    case 19:
      sgt(client, parsedLine);
      break;
    case 20:
      break;
    case 21:
      break;
    case 22:
      break;
    case 23:
      break;
    case 24:
      break;
    case 25:
      std::cout << "Connection reset by peer." << std::endl;
      exit(0);
      break;
    default:
      break;
    }
}
