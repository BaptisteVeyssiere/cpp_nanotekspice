//
// Parser.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:37:22 2017 Baptiste Veyssiere
// Last update Fri Feb 10 16:25:17 2017 Baptiste Veyssiere
//

#include "Parser.hpp"

Parser::Parser()
{
  buffer = "";
}

Parser::Parser(Parser const& other)
{
  this->buffer = other.buffer;
}

Parser const	&Parser::operator=(Parser const &other)
{
  this->buffer = other.buffer;
  return (*this);
}

void	Parser::feed(std::string const& input)
{
  size_t	size;
  bool		writer;

  size = input.size();
  writer = true;
  for (size_t i = 0; i < size; i++)
    {
      if (input[i] == '#')
	writer = false;
      else if (input[i] == '\n')
	writer = true;
      if (writer)
	this->buffer += input[i];
    }
}

void	Parser::parseTree(nts::t_ast_node& root)
{
  (void)root;
}

void	Parser::goToData(int *i) const
{
  if (*i >= 0 && this->buffer != "" && this->buffer[*i] == 0)
    return ;
  while (this->buffer[*i] == ' ' || this->buffer[*i] == '\t' || this->buffer[*i] == '\n')
    ++(*i);
}

std::string const	Parser::getWord(int *i) const
{
  std::string	word;

  word = "";
  while (this->buffer[*i] && this->buffer[*i] != ' ' && this->buffer[*i] != '\n' && this->buffer[*i] != '\t')
    word += this->buffer[(*i)++];
  return (word);
}

std::string const	Parser::getLinkName(int *i) const
{
  std::string	name;

  name = "";
  while (this->buffer[*i] && this->buffer[*i] != ' ' && this->buffer[*i] != '\n' && this->buffer[*i] != '\t' && this->buffer[*i] != ':')
    name += this->buffer[(*i)++];
  if (buffer[*i] == ':')
    ++(*i);
  else
    {
      std::cout << "Pin of the " << name << " component was not find" << std::endl;
      throw std::exception();
    }
  return (name);
}

nts::t_ast_node	*Parser::createLinkEnd(int *i) const
{
  nts::t_ast_node	*link_end = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  link_end->type = nts::ASTNodeType::LINK_END;
  link_end->lexeme = this->getLinkName(i);
  std::cout << "lexeme: " << link_end->lexeme << std::endl;
  link_end->value = this->getWord(i);
  std::cout << "value: " << link_end->value << std::endl;
  if (link_end->value == "")
    throw std::exception();
  this->goToData(i);
  return (link_end);
}

nts::t_ast_node	*Parser::createLink(int *i) const
{
  nts::t_ast_node	*link = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  link->type = nts::ASTNodeType::LINK;
  for (size_t j = 0; j < 2; j++)
    {
      link->children->push_back(this->createLinkEnd(i));
      while (this->buffer[*i] == ' ' || this->buffer[*i] == '\t')
	++(*i);
      if (this->buffer[*i] == '\n')
	throw std::exception();
    }
  if (this->buffer[*i] == ' ' || this->buffer[*i] == '\t' || this->buffer[*i] == '\n')
    for (size_t j = *i; this->buffer[j] != '\n'; j++)
      if (this->buffer[j] != ' ' && this->buffer[j] != '\t')
	throw std::exception();
  return (link);
}

nts::t_ast_node	*Parser::createLinks(int *i) const
{
  nts::t_ast_node	*section = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  section->lexeme = ".links";
  section->type = nts::ASTNodeType::SECTION;
  this->goToData(i);
  while (this->buffer[*i] && this->buffer[*i] != '.')
    {
      section->children->push_back(this->createLink(i));
      this->goToData(i);
    }
  return (section);
}

nts::t_ast_node	*Parser::createComponent(int *i) const
{
  nts::t_ast_node	*component = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  component->type = nts::ASTNodeType::COMPONENT;
  component->lexeme = this->getWord(i);
  std::cout << "lexeme: " << component->lexeme << std::endl;
  while (this->buffer[*i] == ' ' || this->buffer[*i] == '\t')
    ++(*i);
  if (this->buffer[*i] == '\n')
    throw std::exception();
  component->value = this->getWord(i);
  std::cout << "value: " << component->value << std::endl;
  for (size_t j = *i; this->buffer[j] != '\n'; j++)
    if (this->buffer[j] != ' ' && this->buffer[j] != '\t')
      throw std::exception();
  return (component);
}

nts::t_ast_node	*Parser::createChipset(int *i) const
{
  nts::t_ast_node	*section = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  section->lexeme = ".chipsets";
  section->type = nts::ASTNodeType::SECTION;
  this->goToData(i);
  while (this->buffer[*i] && this->buffer[*i] != '.')
    {
      section->children->push_back(this->createComponent(i));
      this->goToData(i);
    }
  return (section);
}

nts::t_ast_node *Parser::createSection(int *i, std::string const &section) const
{
  if (this->buffer.find(section, *i) != (unsigned int)*i)
    {
      std::cout << "Section name not recognized" << std::endl;
      throw std::exception();
    }
  else
    *i += section.size();
  if (section == "chipsets:")
    return (this->createChipset(i));
  return (this->createLinks(i));
}

void	aff_tree(nts::t_ast_node *node)
{
  if (node->type == nts::ASTNodeType::DEFAULT)
    std::cout << "Default:";
  else if (node->type == nts::ASTNodeType::COMPONENT)
    std::cout << "Component:";
  else if (node->type == nts::ASTNodeType::LINK)
    std::cout << "Link:";
  else if (node->type == nts::ASTNodeType::SECTION)
    std::cout << "Section:";
  else if (node->type == nts::ASTNodeType::LINK_END)
    std::cout << "Link end:";
  if (node->type != nts::ASTNodeType::LINK && node->type != nts::ASTNodeType::DEFAULT)
    std::cout << node->lexeme << " --> " << node->value << std::endl;
  else
    std::cout << std::endl;
  for (size_t j = 0; j < node->children->size(); j++)
    aff_tree((*node->children)[j]);
}

nts::t_ast_node	*Parser::createTree()
{
  nts::t_ast_node	*root = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);
  int			i;
  std::string		section;

  i = 0;
  root->type = nts::ASTNodeType::DEFAULT;
  section = "chipsets:";
  for (size_t j = 0; j < 2; j++)
    {
      this->goToData(&i);
      if (this->buffer[i] == '.')
	root->children->push_back(this->createSection(&(++i), section));
      section = "links:";
    }
  this->goToData(&i);
  if (this->buffer[i] == '.')
    throw std::exception();
  aff_tree(root);
  return (root);
}
