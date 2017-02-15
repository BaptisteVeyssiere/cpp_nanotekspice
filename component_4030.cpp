//
// component_4030.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Wed Feb 15 15:46:10 2017 Nathan Scutari
//

#include <iostream>
#include "component_4030.hpp"

c_4030::c_4030(UNUSED const std::string &value)
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

c_4030::~c_4030()
{}

nts::Tristate	c_4030::Xor_gate(nts::Tristate pin_input1, nts::Tristate pin_input2)
{
  if (pin_input1 == nts::FALSE && pin_input2 == nts::FALSE ||
      (pin_input1 == nts::TRUE && pin_input2 == nts::TRUE))
    return (nts::FALSE);
  if (pin_input1 == nts::TRUE || pin_input2 == nts::TRUE)
    return (nts::TRUE);
  return (nts::UNDEFINED);
}

nts::Tristate	c_4030::Compute(size_t pin_num_this)
{
  if (pin_num_this == 3 || pin_num_this == 10)
    return (Xor_gate(this->Compute(pin_num_this - 1),
			       this->Compute(pin_num_this - 2)));
  else if (pin_num_this == 4 || pin_num_this == 11)
    return (Xor_gate(this->Compute(pin_num_this + 1),
			       this->Compute(pin_num_this + 2)));
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

void		c_4030::Dump(void) const
{
  std::cout << "Component : 4030" << std::endl;
  for (int i = 0 ; i < 14 ; ++i)
    {
      std::cout << "Pin " << i + 1 << ": ";
      if (pin_state[i] == nts::UNDEFINED)
	std::cout << "UNDEFINED" << std::endl;
      else
	std::cout << pin_state[i] << std::endl;
    }
}

void		c_4030::SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link[pin_num_this].link = &component;
  link[pin_num_this].pin_target = pin_num_target;
}
