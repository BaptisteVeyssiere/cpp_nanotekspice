//
// Parser.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:37:22 2017 Baptiste Veyssiere
// Last update Fri Mar  3 10:02:45 2017 Baptiste Veyssiere
//

#include "Parser.hpp"

Parser::Parser()
{
  buffer = "";
  this->component = new std::vector<t_component*>;
}

Parser::Parser(Parser const& other)
{
  this->buffer = other.buffer;
  *(this->component) = *(other.component);
}

Parser const	&Parser::operator=(Parser const &other)
{
  this->buffer = other.buffer;
  *(this->component) = *(other.component);
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

nts::IComponent	*Parser::create4001(const std::string &value) const
{
  return (new c_4001(value));
}

nts::IComponent	*Parser::create4008(const std::string &value) const
{
  return (new c_4008(value));
}

nts::IComponent	*Parser::create4011(const std::string &value) const
{
  return (new c_4011(value));
}

nts::IComponent	*Parser::create4013(const std::string &value) const
{
  return (new c_4013(value));
}

nts::IComponent	*Parser::create4017(const std::string &value) const
{
  //return (new c_4017(value));
  return (NULL);
}

nts::IComponent	*Parser::create4030(const std::string &value) const
{
  return (new c_4030(value));
}

nts::IComponent	*Parser::create4040(const std::string &value) const
{
  //return (new c_4040(value));
  return (NULL);
}

nts::IComponent	*Parser::create4069(const std::string &value) const
{
  //return (new c_4069(value));
  return (NULL);
}

nts::IComponent	*Parser::create4071(const std::string &value) const
{
  return (new c_4071(value));
}

nts::IComponent	*Parser::create4081(const std::string &value) const
{
  return (new c_4081(value));
}

nts::IComponent	*Parser::create4094(const std::string &value) const
{
  //return (new c_4094(value));
  return (NULL);
}

nts::IComponent	*Parser::create4514(const std::string &value) const
{
  //return (new c_4514(value));
  return (NULL);
}

nts::IComponent	*Parser::create4801(const std::string &value) const
{
  return (new c_4081(value));
}

nts::IComponent	*Parser::create2716(const std::string &value) const
{
  //return (new c_2716(value));
  return (NULL);
}

nts::IComponent	*Parser::createinput(const std::string &value) const
{
  return (new c_input(value));
}

nts::IComponent	*Parser::createtrue(const std::string &value) const
{
  return (new c_true(value));
}

nts::IComponent	*Parser::createfalse(const std::string &value) const
{
  return (new c_false(value));
}

nts::IComponent	*Parser::createclock(const std::string &value) const
{
  return (new c_clock(value));
}

nts::IComponent	*Parser::createoutput(const std::string &value) const
{
  return (new c_output(value));
}

nts::IComponent	*Parser::createComponent(const std::string &type, const std::string &value)
{
  func_ptr	fptr[] =
    {
      &Parser::create4001,
      &Parser::create4008,
      &Parser::create4011,
      &Parser::create4013,
      &Parser::create4017,
      &Parser::create4030,
      &Parser::create4040,
      &Parser::create4069,
      &Parser::create4071,
      &Parser::create4081,
      &Parser::create4094,
      &Parser::create4514,
      &Parser::create4801,
      &Parser::create2716,
      &Parser::createinput,
      &Parser::createtrue,
      &Parser::createfalse,
      &Parser::createclock,
      &Parser::createoutput
    };
    std::string	str_list[] =
    {
      "4001",
      "4008",
      "4011",
      "4013",
      "4017",
      "4030",
      "4040",
      "4069",
      "4071",
      "4081",
      "4094",
      "4514",
      "4801",
      "2716",
      "input",
      "true",
      "false",
      "clock",
      "output"
    };

    for (int i = 0; i < 19; i++)
      if (type == str_list[i])
	return ((this->*fptr[i])(value));
    return (NULL);
}

void	Parser::createComponents(nts::t_ast_node& root)
{
  nts::t_ast_node	*component;
  size_t		size;

  component = (*root.children)[0];
  size = component->children->size();
  for (size_t i = 0; i < size; i++)
    {
      this->component->push_back(new t_component);
      (*this->component)[i]->component = this->createComponent((*component->children)[i]->lexeme, "");
      if ((*this->component)[i]->component == NULL)
	throw parsing_error((*component->children)[i]->lexeme + " is not a valid type");
      (*this->component)[i]->name = (*component->children)[i]->value;
      (*this->component)[i]->type = (*component->children)[i]->lexeme;
      for (int j = 0; j < 22; j++)
	(*this->component)[i]->isLinked[j] = false;
      (*this->component)[i]->value = -1;
      for (int j = i - 1; j >= 0; j--)
	if ((*this->component)[i]->name == (*this->component)[j]->name)
	  throw parsing_error(std::string("Component '") + (*this->component)[j]->name + std::string("' has already been defined"));
    }
}

t_component	*Parser::foundObject(std::string const &name)
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->name == name)
      return ((*this->component)[i]);
  throw parsing_error("Component '" + name + "' has not been defined");
}

void	Parser::makeLinks(nts::t_ast_node& root)
{
  nts::t_ast_node	*component;
  t_component		*obj;
  t_component		*obj2;
  int			pin1;
  int			pin2;
  size_t		size;

  component = (*root.children)[1];
  size = component->children->size();
  for (size_t i = 0; i < size; i++)
    {
      obj = this->foundObject((*(*component->children)[i]->children)[0]->lexeme);
      obj2 = this->foundObject((*(*component->children)[i]->children)[1]->lexeme);
      pin1 = std::stoi((*(*component->children)[i]->children)[0]->value);
      pin2 = std::stoi((*(*component->children)[i]->children)[1]->value);
      if (link_isValid(obj, obj2, pin1, pin2))
	{
	  obj->component->SetLink(std::stoi((*(*component->children)[i]->children)[0]->value),
				  *(obj2->component),
				  std::stoi((*(*component->children)[i]->children)[1]->value));
	  obj->isLinked[pin1] = true;
	}
      else
	{
	  obj2->component->SetLink(std::stoi((*(*component->children)[i]->children)[1]->value),
				   *(obj->component),
				   std::stoi((*(*component->children)[i]->children)[0]->value));
	  obj2->isLinked[pin2] = true;
	}
    }
}

void	Parser::checkOutputs() const
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "output" && (*this->component)[i]->isLinked[1] == false)
      throw parsing_error("Output '" + (*this->component)[i]->name + "' has not been linked");
}

void	Parser::parseTree(nts::t_ast_node& root)
{
  this->createComponents(root);
  this->makeLinks(root);
  this->checkOutputs();
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
    throw parsing_error("Pin of the '" + name + "' component has not been found");
  return (name);
}

nts::t_ast_node	*Parser::createLinkEnd(int *i) const
{
  nts::t_ast_node	*link_end = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  link_end->type = nts::ASTNodeType::LINK_END;
  link_end->lexeme = this->getLinkName(i);
  link_end->value = this->getWord(i);
  if (link_end->value == "")
    throw parsing_error("Pin of the '" + link_end->lexeme + "' component has not been found");
  //this->goToData(i);
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
      if (this->buffer[*i] == '\n' && j == 0)
	throw parsing_error("Unexpected newline");
    }
  if (this->buffer[*i] == ' ' || this->buffer[*i] == '\t' || this->buffer[*i] == '\n')
    {
      for (size_t j = *i; this->buffer[j] != '\n'; j++)
	if (this->buffer[j] != ' ' && this->buffer[j] != '\t')
	  throw parsing_error("Unexpected data found at end of line");
    }
  else if (this->buffer[*i])
    throw parsing_error("Unexpected data found at end of line");
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

nts::t_ast_node	*Parser::createComp(int *i) const
{
  nts::t_ast_node	*component = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);

  component->type = nts::ASTNodeType::COMPONENT;
  component->lexeme = this->getWord(i);
  while (this->buffer[*i] == ' ' || this->buffer[*i] == '\t')
    ++(*i);
  if (this->buffer[*i] == '\n')
    throw parsing_error("Unexpected newline");
  component->value = this->getWord(i);
  for (size_t j = *i; this->buffer[j] != '\n'; j++)
    if (this->buffer[j] != ' ' && this->buffer[j] != '\t')
      throw parsing_error("Unexpected data found at end of line");
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
      section->children->push_back(this->createComp(i));
      this->goToData(i);
    }
  return (section);
}

nts::t_ast_node *Parser::createSection(int *i, std::string const &section) const
{
  if (this->buffer.find(section, *i) != (unsigned int)*i)
    throw parsing_error("Section name not recognized");
  else
    *i += section.size();
  if (section == "chipsets:")
    return (this->createChipset(i));
  return (this->createLinks(i));
}

static bool	compareByAscii(const t_component *a, const t_component *b)
{
  return (a->name < b->name);
}

void	Parser::sortComponents()
{
  if (!(this->component))
    return ;
  std::sort(this->component->begin(), this->component->end(), compareByAscii);
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
    throw parsing_error("Unexpected third section found");
  this->parseTree(*root);
  this->sortComponents();
  return (root);
}

std::vector<t_component*>	*Parser::getSystem() const
{
  return (this->component);
}

void	Parser::freeSystem()
{
  size_t	size;

  size = 0;
  if (this->component)
    size = this->component->size();
  for (size_t i = 0; i < size; i++)
    {
      if ((*this->component)[i]->component)
	delete (*this->component)[i]->component;
      if ((*this->component)[i])
	delete (*this->component)[i];
    }
  if (this->component)
    delete this->component;
}
