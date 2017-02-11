//
// Parser.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:30:49 2017 Baptiste Veyssiere
// Last update Fri Feb 10 16:11:23 2017 Baptiste Veyssiere
//

#ifndef PARSER_HPP
# define PARSER_HPP

#include <fstream>
#include <iostream>
#include "IParser.hpp"

class	Parser
{
private:
  std::string			buffer;
  //std::vector<IComponent*>	*Component;

public:
  Parser();
  Parser(Parser const&);
  virtual ~Parser() {}
  Parser const &operator=(Parser const&);

public:
  virtual void			feed(std::string const& input);
  virtual void			parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node	*createTree();

private:
  void				goToNextLine(int*) const;
  void				goToData(int*) const;
  std::string const		getWord(int*) const;
  std::string const		getLinkName(int*) const;
  nts::t_ast_node		*createLinkEnd(int*) const;
  nts::t_ast_node		*createLink(int*) const;
  nts::t_ast_node		*createLinks(int*) const;
  nts::t_ast_node		*createComponent(int*) const;
  nts::t_ast_node	        *createSection(int*, std::string const&) const;
  nts::t_ast_node		*createChipset(int*) const;
};

#endif //PARSER_HPP
