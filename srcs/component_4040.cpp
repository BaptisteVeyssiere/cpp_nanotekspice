//
// component_4040.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Sat Mar  4 16:45:57 2017 Nathan Scutari
//

#include <iostream>
#include "component_4040.hpp"

c_4040::c_4040(UNUSED const std::string &value)
{
  t_link	link;
  int		pin_Q[12] = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};

  counter = 0;
  link.pin_target = 0;
  link.link = NULL;
  for (int i = 0 ; i < 15 ; ++i)
    {
      if (i < 12)
	this->pin_Q[i] = pin_Q[i];
      computed.push_back(false);
      pin_state.push_back(nts::UNDEFINED);
      this->link.push_back(link);
    }
}

c_4040::~c_4040()
{}

nts::Tristate	c_4040::Add_Counter(size_t pin_num_this)
{
  int	i;
  int	count;

  if (pin_state[pin_Q[0] - 1] == nts::UNDEFINED)
    Reset_Counter();
  i = -1;
  while (++i < 12)
    computed[pin_Q[i]] = true;
  i = -1;
  while (++i < 12)
    {
      if (pin_state[pin_Q[i] - 1] == nts::FALSE)
	{
	  pin_state[pin_Q[i] - 1] = nts::TRUE;
	  return (pin_state[pin_num_this - 1]);
	}
      else if (pin_state[pin_Q[i] - 1] == nts::TRUE)
	pin_state[pin_Q[i] - 1] = nts::FALSE;
    }
  return (pin_state[pin_num_this - 1]);
}

nts::Tristate	c_4040::Reset_Counter(void)
{
  for (int i = 0 ; i < 12 ; ++i)
    {
      pin_state[pin_Q[i] - 1] = nts::FALSE;
      computed[pin_Q[i] - 1] = true;
    }
  return (nts::FALSE);
}

nts::Tristate	c_4040::Compute(size_t pin_num_this)
{
  nts::Tristate	ret;

  if (computed[pin_num_this - 1] == true)
    return (pin_state[pin_num_this - 1]);
  computed[pin_num_this - 1] = true;
  if (pin_num_this != 11 && pin_num_this != 10)
    {
      if (this->Compute(11) == nts::FALSE && this->Compute(10) == nts::TRUE)
	ret = Add_Counter(pin_num_this);
      else if (this->Compute(11) == nts::TRUE)
	ret = Reset_Counter();
      else if (this->Compute(10) == nts::UNDEFINED)
	{
	  for (int i = 0 ; i < 12 ; ++i)
	    pin_state[pin_Q[i] - 1] = nts::UNDEFINED;
	  ret = nts::UNDEFINED;
	}
      else
	ret = pin_state[pin_num_this - 1];
    }
  else if (this->link[pin_num_this - 1].link)
    ret = link[pin_num_this - 1].link->Compute(link[pin_num_this - 1].pin_target);
  else
    ret = pin_state[pin_num_this - 1];
  pin_state[pin_num_this - 1] = ret;
  return (ret);
}

void		c_4040::Dump(void) const
{
  std::cout << "Component : 4040" << std::endl;
  for (int i = 0 ; i < 14 ; ++i)
    {
      std::cout << "Pin " << i + 1 << ": ";
      if (pin_state[i] == nts::UNDEFINED)
	std::cout << "UNDEFINED" << std::endl;
      else
	std::cout << pin_state[i] << std::endl;
    }
}

void		c_4040::SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link[pin_num_this - 1].link = &component;
  link[pin_num_this - 1].pin_target = pin_num_target;
}
