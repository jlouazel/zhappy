//
// Parser.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 10:30:51 2013 louaze_j
// Last update Wed Jul 10 10:34:34 2013 louaze_j
//

#ifndef	__PARSER_HH__
#define	__PARSER_HH__

#include <vector>
#include <string>

class Parser {
private:
  Parser();
  ~Parser();

public:
  static std::vector<std::string>	splitString(std::string const &, std::string const &);
};

#endif
