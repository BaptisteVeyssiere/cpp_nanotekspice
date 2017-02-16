//
// Parser.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:30:49 2017 Baptiste Veyssiere
// Last update Thu Feb 16 17:06:10 2017 Baptiste Veyssiere
//

#ifndef PARSER_HPP
# define PARSER_HPP

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <csignal>
#include "IParser.hpp"
#include "component_4001.hpp"
#include "component_4008.hpp"
#include "component_4011.hpp"
#include "component_4030.hpp"
#include "component_4071.hpp"
#include "component_4081.hpp"

typedef struct		s_component
{
  std::string		name;
  std::string		type;
  bool			isLinked;
  nts::IComponent	*component;
  int			value;
}			t_component;

class	Parser : public nts::IParser
{
private:
  std::string			buffer;
  std::vector<t_component*>	*component;

public:
  Parser();
  Parser(Parser const&);
  virtual ~Parser() {}
  Parser const &operator=(Parser const&);

public:
  virtual void			feed(std::string const& input);
  virtual void			parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node	*createTree();
  void				add_value(char const *str);
  void				handle_input(std::string const &input);

private:
  void				goToNextLine(int*) const;
  void				goToData(int*) const;
  std::string const		getWord(int*) const;
  std::string const		getLinkName(int*) const;
  nts::t_ast_node		*createLinkEnd(int*) const;
  nts::t_ast_node		*createLink(int*) const;
  nts::t_ast_node		*createLinks(int*) const;
  nts::t_ast_node		*createComp(int*) const;
  nts::t_ast_node	        *createSection(int*, std::string const&) const;
  nts::t_ast_node		*createChipset(int*) const;
  void				sortComponents();
  void				createComponents(nts::t_ast_node& root);
  t_component			*foundObject(std::string const &name);
  void				makeLinks(nts::t_ast_node& root);
  void				checkOutputs() const;
  void				display();
  void				simulate();
  void				loop();
  void				dump();
  nts::IComponent		*createComponent(const std::string &type, const std::string &value);
  nts::IComponent		*create4001(const std::string &value) const;
  nts::IComponent		*create4008(const std::string &value) const;
  nts::IComponent		*create4011(const std::string &value) const;
  nts::IComponent		*create4013(const std::string &value) const;
  nts::IComponent		*create4017(const std::string &value) const;
  nts::IComponent		*create4030(const std::string &value) const;
  nts::IComponent		*create4040(const std::string &value) const;
  nts::IComponent		*create4069(const std::string &value) const;
  nts::IComponent		*create4071(const std::string &value) const;
  nts::IComponent		*create4081(const std::string &value) const;
  nts::IComponent		*create4094(const std::string &value) const;
  nts::IComponent		*create4514(const std::string &value) const;
  nts::IComponent		*create4801(const std::string &value) const;
  nts::IComponent		*create2716(const std::string &value) const;
  nts::IComponent		*createinput(const std::string &value) const;
  nts::IComponent		*createoutput(const std::string &value) const;
  nts::IComponent		*createtrue(const std::string &value) const;
  nts::IComponent		*createfalse(const std::string &value) const;
  nts::IComponent		*createclock(const std::string &value) const;
};

typedef nts::IComponent*	(Parser::*func_ptr)(const std::string &value) const;

bool	link_isValid(t_component *obj, t_component *obj2, int pin1, int pin2);
char	input_pin(int pin);
char	clock_pin(int pin);
char	true_pin(int pin);
char	false_pin(int pin);
char	output_pin(int pin);
char	c4001_pin(int pin);
char	c4008_pin(int pin);
char	c4011_pin(int pin);
char	c4013_pin(int pin);
char	c4017_pin(int pin);
char	c4030_pin(int pin);
char	c4040_pin(int pin);
char	c4069_pin(int pin);
char	c4071_pin(int pin);
char	c4081_pin(int pin);
char	c4094_pin(int pin);
char	c4514_pin(int pin);
char	c4801_pin(int pin);
char	c2716_pin(int pin);

#endif //PARSER_HPP
