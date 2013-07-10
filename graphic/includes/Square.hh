//
// Square.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:39:00 2013 louaze_j
// Last update Tue Jul  9 02:01:21 2013 louaze_j
//

#ifndef	__SQUARE_HH__
#define	__SQUARE_HH__

#include <vector>

class	Square {
private:
  int	_x;
  int	_y;
  std::vector<int>	_content;

public:
  Square(int, int);
  ~Square();
};

#endif




