//
// component_4094.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Sat Mar  4 17:38:05 2017 Nathan Scutari
//

#include <iostream>
#include "component_4094.hpp"

c_4094::c_4094(UNUSED const std::string &value)
{
  t_link	link;
  int		pin_Q[8] = {4, 5, 6, 7, 14, 13, 12, 11};
  char		ttable[6][8] =
    {
      {'L', '0', 'X', 'X', 'U', 'U', 'Q', 'N'},
      {'H', '0', 'X', 'X', 'U', 'U', 'N', 'Q'},
      {'L', '1', '0', 'X', 'N', 'N', 'Q', 'N'},
      {'L', '1', '1', '0', '0', 'S', 'Q', 'N'},
      {'L', '1', '1', '1', '1', 'S', 'Q', 'N'},
      {'H', '1', '1', '1', 'N', 'N', 'N', 'Q'}
    };

  counter = 0;
  link.pin_target = 0;
  link.link = NULL;
  for (int i = 0 ; i < 6 ; ++i)
    {
      for (int y = 0 ; y < 8 ; ++y)
	this->ttable[i][y] = ttable[i][y];
    }
  for (int i = 0 ; i < 15 ; ++i)
    {
      if (i < 8)
	this->pin_Q[i] = pin_Q[i];
      computed.push_back(false);
      pin_state.push_back(nts::UNDEFINED);
      this->link.push_back(link);
    }
}

c_4094::~c_4094()
{}

char		c_4094::Clock_Cycle(nts::Tristate clock)
{
  if (this->clock == nts::FALSE && clock == nts::TRUE)
    return ('L');
  else if (this->clock == nts::TRUE && clock == nts::FALSE)
    return ('H');
  return ('U');
}

nts::Tristate	c_4094::Shift_Compute(size_t pin_num_this)
{
  int	i;
  i = -1;

  while (++i < 11)
    computed[3 + i] = true;
  i = -1;
  while (++i < 6)
    {
      for (int y = 0 ; y < 8 ; ++y)
	{
	  if (ttable[i][y] == Clock_Cycle(Compute(11)))
	}
    }
  return (pin_state[pin_num_this - 1]);
}

nts::Tristate	c_4094::Compute(size_t pin_num_this)
{
  nts::Tristate	ret;

  if (computed[pin_num_this - 1] == true)
    return (pin_state[pin_num_this - 1]);
  computed[pin_num_this - 1] = true;
  if (pin_num_this >= 4 && pin_num_this <= 14)
    ret = Shift_Compute(pin_num_this);
  return (ret);
}

void		c_4094::Dump(void) const
{
  std::cout << "Component : 4094" << std::endl;
  for (int i = 0 ; i < 14 ; ++i)
    {
      std::cout << "Pin " << i + 1 << ": ";
      if (pin_state[i] == nts::UNDEFINED)
	std::cout << "UNDEFINED" << std::endl;
      else
	std::cout << pin_state[i] << std::endl;
    }
}

void		c_4094::SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link[pin_num_this - 1].link = &component;
  link[pin_num_this - 1].pin_target = pin_num_target;
}
