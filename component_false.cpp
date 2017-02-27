//
// component_false.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 10:52:05 2017 Nathan Scutari
// Last update Mon Feb 27 11:27:41 2017 Nathan Scutari
//

#include <iostream>
#include "component_false.hpp"

c_false::c_false(UNUSED const std::string &value)
{}

c_false::~c_false()
{}


nts::Tristate c_false::Compute(size_t pin_num_this)
{
  return (nts::FALSE);
}

void		c_false::SetLink(UNUSED size_t pin_num_this,
			UNUSED nts::IComponent &component,
			UNUSED size_t pin_num_target)
{}

void		c_false::Dump(void) const
{
  std::cout << "Component : false" << std::endl;
  std::cout << "Pin 1: 0";
}
