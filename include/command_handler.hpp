//
// Command_handler.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Wed Mar  1 11:45:56 2017 Baptiste Veyssiere
// Last update Wed Mar  1 17:55:31 2017 Baptiste Veyssiere
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
  void	display() const;
  void	loop();
  void	dump() const;
};

int	aff_error_msg(std::string const &, const int);
int	read_config_file(std::string const &, Parser*);
void	free_tree(nts::t_ast_node*);
int	parse_config_file(int, char**, Parser*);

#endif /* !COMMAND_HANDLER_HPP_ */
