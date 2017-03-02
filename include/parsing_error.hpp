//
// parsing_error.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Thu Mar  2 18:07:13 2017 Baptiste Veyssiere
// Last update Thu Mar  2 18:12:18 2017 Baptiste Veyssiere
//

#ifndef PARSING_ERROR_HPP_
# define PARSING_ERROR_HPP_

class	parsing_error : public std::exception
{
public:
  ~parsing_error() throw() {}
  parsing_error(std::string const &msg):
    _msg(msg) {}
  const char* what() const throw()
};

#endif /* !PARSING_ERROR_HPP_ */
