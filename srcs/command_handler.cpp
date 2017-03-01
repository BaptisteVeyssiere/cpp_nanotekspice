//
// Command_handler.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Wed Mar  1 14:21:46 2017 Baptiste Veyssiere
// Last update Wed Mar  1 17:33:55 2017 Baptiste Veyssiere
//

#include "command_handler.hpp"

bool    isLooping;

static void    sigint_handler(int sig)
{
  (void)sig;
  isLooping = false;
}

Command_handler::Command_handler() {}

Command_handler::~Command_handler() {}

void	Command_handler::init(std::vector<t_component*> *component)
{
  this->component = component;
}

t_component     *Command_handler::foundObject(std::string const &name)
{
  size_t        size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->name == name)
      return ((*this->component)[i]);
  throw std::exception();
}

void	Command_handler::simulate()
{
  size_t        size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "output")
      (*this->component)[i]->value = (*this->component)[i]->component->Compute();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "clock")
      {
        if ((*this->component)[i]->value == 0)
          {
            ((c_clock*)(*this->component)[i]->component)->SetPin(nts::TRUE);
            (*this->component)[i]->value = 1;
          }
        else if ((*this->component)[i]->value == 1)
          {
            ((c_clock*)(*this->component)[i]->component)->SetPin(nts::FALSE);
            (*this->component)[i]->value = 0;
          }
      }
}

void	Command_handler::loop()
{
  isLooping = true;
  signal(SIGINT, sigint_handler);
  while (isLooping)
    simulate();
}

void	Command_handler::dump() const
{
  size_t        size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    (*this->component)[i]->component->Dump();
}

void	Command_handler::handle_input(std::string const &input)
{
  size_t        size;

  if (input == "display" || input == "simulate" || input == "loop" || input == "dump")
    {
      if (input == "display")
	this->display();
      else if (input == "simulate")
	this->simulate();
      else if (input == "loop")
	this->loop();
      else if (input == "dump")
	this->dump();
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

void	Command_handler::display() const
{
  size_t        size;

  size = this->component->size();
  for (size_t i = 0; i < size; i++)
    if ((*this->component)[i]->type == "output")
      std::cout << (*this->component)[i]->name << "=" << (*this->component)[i]->value << std::endl;
}

void    Command_handler::add_value(char const *str)
{
  std::string   name;
  std::string   value;
  bool          isName;
  int           i;
  t_component   *component;
  nts::Tristate state;

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
  component = this->foundObject(name);
  if (std::stoi(value) == -1)
    state = nts::UNDEFINED;
  else
    state = std::stoi(value) < 1 ? nts::FALSE : nts::TRUE;
  ((c_input*)(component->component))->SetPin(state);
}
