#include "Parser.hh"

std::vector< std::string>	Parser::splitString(std::string const &s, std::string const &delim) {
  std::vector< std::string>	vec;
  std::string			str = s, tmp;
  size_t			i = 0;

  while (str.size() > 0 && (i = str.find_first_of(delim)) != std::string::npos)
    {
      tmp = str.substr(0, i);
      if (tmp.size())
	vec.push_back(tmp);
      str = str.substr(i + 1, str.size());
    }
  tmp = str;
  if (tmp.size())
    vec.push_back(str);
  return vec;
}
