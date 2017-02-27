//
// component_input.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 10:52:05 2017 Nathan Scutari
// Last update Mon Feb 27 11:10:00 2017 Nathan Scutari
//

#include <iostream>
#include "component_input.hpp"

c_input::c_input(const std::string &value)
{
  if (value == "0")
    pin_state = nts::FALSE;
  else if (value == "1")
    pin_state = nts::TRUE;
  else
    pin_state = nts::UNDEFINED;
}

c_input::~c_input()
{}


nts::Tristate c_input::Compute(size_t pin_num_this)
{
  return (pin_state);
}

void		c_input::SetPin(nts::Tristate value)
{
  pin_state = value;
}

void		c_input::Dump(void) const
{
  std::cout << "Component : input" << std::endl;
  std::cout << "Pin 1: ";
  if (pin_state == nts::UNDEFINED)
    std::cout << "UNDEFINED" << std::endl;
  else
    std::cout << pin_state << std::endl;
}
