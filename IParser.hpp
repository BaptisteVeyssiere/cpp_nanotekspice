//
// IParser.hpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:24:43 2017 Baptiste Veyssiere
// Last update Mon Feb 27 22:20:43 2017 Baptiste Veyssiere
//

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
# define CPP_NANOTEKSPICE_PARSER_HPP

# include <string>
# include <vector>
# include "all_components.hpp"

namespace nts
{
  enum class ASTNodeType : int
    {
      DEFAULT = -1,
      NEWLINE = 0,
      SECTION,
      COMPONENT,
      LINK,
      LINK_END,
      STRING
    };

  typedef struct s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children)
      : children(children) { }
    std::string		lexeme;
    ASTNodeType		type;
    std::string		value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  class IParser
  {
  public:
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t_ast_node& root) = 0;
    virtual t_ast_node *createTree() = 0;
    virtual ~IParser() {}
  };
}

#endif //CPP_NANOTEKSPICE_PARSER_HPP
