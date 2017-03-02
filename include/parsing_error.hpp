//
// parsing_error.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Thu Mar  2 18:07:13 2017 Baptiste Veyssiere
// Last update Thu Mar  2 18:18:48 2017 Baptiste Veyssiere
//

#ifndef PARSING_ERROR_HPP_
# define PARSING_ERROR_HPP_

#include <string>
#include <stdexcept>

class	parsing_error : public std::exception
{
public:
  ~parsing_error() throw() {}
  parsing_error(std::string const &msg):
    _msg(msg) {}
  const char* what() const throw()
  { return _msg.c_str(); }
private:
  std::string	_msg;
};

#endif /* !PARSING_ERROR_HPP_ */
