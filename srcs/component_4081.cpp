//
// component_4081.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Mon Feb 27 11:48:09 2017 Nathan Scutari
//

#include <iostream>
#include "component_4081.hpp"

c_4081::c_4081(UNUSED const std::string &value)
{
  t_link	link;

  link.pin_target = 0;
  link.link = NULL;
  for (int i = 0 ; i < 14 ; ++i)
    {
      computed.push_back(false);
      pin_state.push_back(nts::UNDEFINED);
      this->link.push_back(link);
    }
}

c_4081::~c_4081()
{}

nts::Tristate	c_4081::And_gate(nts::Tristate pin_input1, nts::Tristate pin_input2)
{
  if (pin_input1 == nts::FALSE || pin_input2 == nts::FALSE)
    return (nts::FALSE);
  if (pin_input1 == nts::TRUE && pin_input2 == nts::TRUE)
    return (nts::TRUE);
  return (nts::UNDEFINED);
}

nts::Tristate	c_4081::Compute(size_t pin_num_this)
{
  nts::Tristate	ret;

  if (computed[pin_num_this - 1] == true)
    return (pin_state[pin_num_this - 1]);
  computed[pin_num_this - 1] = true;
  if (pin_num_this == 3 || pin_num_this == 10)
    ret = And_gate(this->Compute(pin_num_this - 1),
		   this->Compute(pin_num_this - 2));
  else if (pin_num_this == 4 || pin_num_this == 11)
    ret = And_gate(this->Compute(pin_num_this + 1),
		   this->Compute(pin_num_this + 2));
  else if (this->link[pin_num_this - 1].link)
    ret = link[pin_num_this - 1].link->Compute(link[pin_num_this - 1].pin_target);
  else
    ret = pin_state[pin_num_this - 1];
  computed[pin_num_this - 1] = false;
  pin_state[pin_num_this - 1] = ret;
  return (ret);
}

void		c_4081::Dump(void) const
{
  std::cout << "Component : 4081" << std::endl;
  for (int i = 0 ; i < 14 ; ++i)
    {
      std::cout << "Pin " << i + 1 << ": ";
      if (pin_state[i] == nts::UNDEFINED)
	std::cout << "UNDEFINED" << std::endl;
      else
	std::cout << pin_state[i] << std::endl;
    }
}

void		c_4081::SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link[pin_num_this - 1].link = &component;
  link[pin_num_this - 1].pin_target = pin_num_target;
}
