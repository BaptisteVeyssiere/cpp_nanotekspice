//
// component_true.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 10:52:05 2017 Nathan Scutari
// Last update Mon Feb 27 11:27:18 2017 Nathan Scutari
//

#include <iostream>
#include "component_true.hpp"

c_true::c_true(UNUSED const std::string &value)
{}

c_true::~c_true()
{}


nts::Tristate c_true::Compute(size_t pin_num_this)
{
  return (nts::TRUE);
}

void		c_true::SetLink(UNUSED size_t pin_num_this,
			UNUSED nts::IComponent &component,
			UNUSED size_t pin_num_target)
{}

void		c_true::Dump(void) const
{
  std::cout << "Component : true" << std::endl;
  std::cout << "Pin 1: 1";
}
