//
// component_4008.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Wed Feb 15 16:45:46 2017 Nathan Scutari
//

#include <iostream>
#include "component_4008.hpp"

c_4008::c_4008(UNUSED const std::string &value)
{
  t_link	link;

  link.pin_target = 0;
  link.link = NULL;
  for (int i = 0 ; i < 16 ; ++i)
    {
      computed.push_back(false);
      pin_state.push_back(nts::UNDEFINED);
      this->link.push_back(link);
    }
}

c_4008::~c_4008()
{}

nts::Tristate	c_4008::Compute_si(size_t si)
{

}

nts::Tristate	c_4008::Compute(size_t pin_num_this)
{
  if (pin_num_this >= 10 && pin_num_this <= 13)
    return (this->Compute_si(pin_num_this - 10));
  if (computed[pin_num_this] == false)
    {
      computed[pin_num_this] = true;
      if (this->link[pin_num_this].link)
	return (link[pin_num_this].link->Compute(link[pin_num_this].pin_target));
      else
	return (pin_state[pin_num_this]);
    }
  return (this->pin_state[pin_num_this]);
}

void		c_4008::Dump(void) const
{
  std::cout << "Component : 4008" << std::endl;
  for (int i = 0 ; i < 14 ; ++i)
    {
      std::cout << "Pin " << i + 1 << ": ";
      if (pin_state[i] == nts::UNDEFINED)
	std::cout << "UNDEFINED" << std::endl;
      else
	std::cout << pin_state[i] << std::endl;
    }
}

void		c_4008::SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link[pin_num_this].link = &component;
  link[pin_num_this].pin_target = pin_num_target;
}
