//
// component_output.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 10:52:05 2017 Nathan Scutari
// Last update Tue Feb 28 17:25:03 2017 Baptiste Veyssiere
//

#include <iostream>
#include "component_output.hpp"

c_output::c_output(UNUSED const std::string &value)
{
}

c_output::~c_output()
{}

void		c_output::SetLink(UNUSED size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link.link = &component;
  link.pin_target = pin_num_target;
}

nts::Tristate c_output::Compute(UNUSED size_t pin_num_this)
{
  if (link.link)
    return (link.link->Compute(link.pin_target));
  return (nts::UNDEFINED);
}

void		c_output::Dump(void) const
{
  std::cout << "Component : output" << std::endl;
  std::cout << "Pin 1: ";
  if (link.link)
    std::cout << "linked to pin: " << link.pin_target << std::endl;
  else
    std::cout << "not linked" << std::endl;
}
