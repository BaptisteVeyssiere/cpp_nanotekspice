//
// Command_handler.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Wed Mar  1 11:45:56 2017 Baptiste Veyssiere
// Last update Wed Mar  1 15:03:12 2017 Baptiste Veyssiere
//

#ifndef COMMAND_HANDLER_HPP_
# define COMMAND_HANDLER_HPP_

#include "Parser.hpp"

class	Command_handler
{
private:
  std::vector<t_component*>	*component;

private:
  Command_handler(const Command_handler &);
  const Command_handler	&operator=(const Command_handler &);
  t_component	*foundObject(std::string const &);

public:
  Command_handler();
  ~Command_handler();
  void	handle_input(std::string const &);
  void	init(std::vector<t_component*>*);
  void	add_value(char const *);
  void	simulate();
  void	display();
  void	loop();
  void	dump();
};

#endif /* !COMMAND_HANDLER_HPP_ */
