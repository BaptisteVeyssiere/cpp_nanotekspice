//
// Parser.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:37:22 2017 Baptiste Veyssiere
// Last update Mon Feb 27 23:17:07 2017 Baptiste Veyssiere
//

#include "Parser.hpp"

bool	isLooping;

void	sigint_handler(int sig)
{
  (void)sig;
  isLooping = false;
}

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
  //return (new c_4013(value));
  return (NULL);
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

void	Parser::add_value(char const *str)
{
  std::string	name;
  std::string	value;
  bool		isName;
  int		i;
  t_component	*component;
  nts::Tristate	state;

  name = "";
  value = "";
  isName = true;
  i = -1;
  while (str && str[++i])
    {
      if (str[i] == '=')
	{
	  if (isName == false)
	    throw std::exception();
	  isName = false;
	  continue;
	}
      if (isName == true)
	name += str[i];
      else
	value += str[i];
    }
  if (name == "" || (value != "0" && value != "1"))
    throw std::exception();
  std::cout << "name: " << name << " / value: " << value << std::endl;
  component = this->foundObject(name);
  if (std::stoi(value) == -1)
    state = nts::UNDEFINED;
  else
    state = std::stoi(value) < 1 ? nts::FALSE : nts::TRUE;
  if (state == nts::FALSE)
    std::cout << "state == nts::FALSE" << std::endl;
  ((c_input*)(component->component))->SetPin(state);
}

void	Parser::display()
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "output")
      std::cout << (*this->component)[i]->name << "=" << (*this->component)[i]->value << std::endl;
}

void	Parser::simulate()
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "output")
      (*this->component)[i]->component->Compute();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "clock")
      {
	if ((*this->component)[i]->value == 0)
	  {
	    ((c_input*)(*this->component)[i]->component)->SetPin(nts::TRUE);
	    (*this->component)[i]->value = 1;
	  }
	else if ((*this->component)[i]->value == 1)
	  {
	    ((c_input*)(*this->component)[i]->component)->SetPin(nts::FALSE);
	    (*this->component)[i]->value = 0;
	  }
      }
}

void	Parser::loop()
{
  isLooping = true;
  signal(SIGINT, sigint_handler);
  while (isLooping)
    simulate();
}

void	Parser::dump()
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    (*this->component)[i]->component->Dump();
}

void	Parser::handle_input(std::string const &input)
{
  size_t	size;
  std::string	commands[] =
    {
      "display",
      "simulate",
      "loop",
      "dump"
    };
  void		(Parser::*func[4])();

  func[0] = &Parser::display;
  func[1] = &Parser::simulate;
  func[2] = &Parser::loop;
  func[3] = &Parser::dump;

  for (int i = 0; i < 4; i++)
    if (commands[i] == input)
      {
	(this->*func[i])();
	return ;
      }
  size = input.size();
  for (size_t i = 0; i < size; i++)
    if (input[i] == '=')
      {
	this->add_value(input.c_str());
	return ;
      }
  throw std::exception();
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
      (*this->component)[i]->name = (*component->children)[i]->value;
      (*this->component)[i]->type = (*component->children)[i]->lexeme;
      for (int j = 0; j < 22; j++)
	(*this->component)[i]->isLinked[j] = false;
      (*this->component)[i]->value = -1;
      for (int j = i - 1; j >= 0; j--)
	if ((*this->component)[i]->name == (*this->component)[j]->name)
	  throw std::exception();
    }
}

t_component	*Parser::foundObject(std::string const &name)
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    {
      if ((*this->component)[i]->name == name)
	{
	  std::cout << "Object found! => " << (*this->component)[i]->name << " compared to " << name << std::endl;
	  return ((*this->component)[i]);
	}
      else
	std::cout << "Wrong object :( => " << (*this->component)[i]->name << " compared to " << name << std::endl;
    }
  throw std::exception();
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
      std::cout << "object searched: " << (*(*component->children)[i]->children)[0]->lexeme << std::endl;
      obj = this->foundObject((*(*component->children)[i]->children)[0]->lexeme);
      obj2 = this->foundObject((*(*component->children)[i]->children)[1]->lexeme);
      pin1 = std::stoi((*(*component->children)[i]->children)[0]->value);
      pin2 = std::stoi((*(*component->children)[i]->children)[1]->value);
      if (link_isValid(obj, obj2, pin1, pin2))
	{
	  obj->component->SetLink(std::stoi((*(*component->children)[i]->children)[0]->value),
				  *(obj2->component),
				  std::stoi((*(*component->children)[i]->children)[1]->value));
	  std::cout << obj->name << ":" << (*(*component->children)[i]->children)[0]->value << " was linked to " << obj2->name << ":" << (*(*component->children)[i]->children)[1]->value << std::endl;
	  obj->isLinked[pin1] = true;
	}
      else
	{
	  obj2->component->SetLink(std::stoi((*(*component->children)[i]->children)[1]->value),
				   *(obj->component),
				   std::stoi((*(*component->children)[i]->children)[0]->value));
	  	  std::cout << obj2->name << ":" << (*(*component->children)[i]->children)[1]->value << " was linked to " << obj->name << ":" << (*(*component->children)[i]->children)[0]->value << std::endl;
	  obj2->isLinked[pin2] = true;
	}
    }
}

void	Parser::checkOutputs() const
{
  size_t	size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "output" && (*this->component)[i]->isLinked == false)
      throw std::exception();

}

void	Parser::parseTree(nts::t_ast_node& root)
{
  this->createComponents(root);
  for (int i = 0; i < 4; i++)
    {
      std::cout << "New component created: " << std::endl;
      std::cout << "Type: " << (*this->component)[i]->type << std::endl;
      std::cout << "Valeur: " << (*this->component)[i]->value << std::endl;
      std::cout << "Name: " << (*this->component)[i]->name << std::endl;
    }
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

nts::t_ast_node	*Parser::createComp(int *i) const
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
      section->children->push_back(this->createComp(i));
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
    throw std::exception();
  aff_tree(root);
  this->parseTree(*root);
  this->sortComponents();
  return (root);
}
