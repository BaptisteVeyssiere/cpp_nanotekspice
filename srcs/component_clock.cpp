//
// component_clock.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 10:52:05 2017 Nathan Scutari
// Last update Tue Feb 28 18:40:19 2017 Nathan Scutari
//

#include <iostream>
#include "component_clock.hpp"

c_clock::c_clock(const std::string &value)
{
  if (value == "0")
    pin_state = nts::FALSE;
  else if (value == "1")
    pin_state = nts::TRUE;
  else
    pin_state = nts::UNDEFINED;
}

c_clock::~c_clock()
{}


nts::Tristate c_clock::Compute(UNUSED size_t pin_num_this)
{
  return (pin_state);
}

void		c_clock::SetPin(nts::Tristate value)
{
  pin_state = value;
}

void		c_clock::SetLink(UNUSED size_t pin_num_this,
			UNUSED nts::IComponent &component,
			UNUSED size_t pin_num_target)
{}

void		c_clock::Dump(void) const
{
  std::cout << "Component : clock" << std::endl;
  std::cout << "Pin 1: ";
  if (pin_state == nts::UNDEFINED)
    std::cout << "UNDEFINED" << std::endl;
  else
    std::cout << pin_state << std::endl;
}
