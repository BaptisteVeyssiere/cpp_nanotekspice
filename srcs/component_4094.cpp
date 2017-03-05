//
// component_4094.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Sun Mar  5 11:10:07 2017 Nathan Scutari
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

  link.pin_target = 0;
  link.link = NULL;
  clock = nts::UNDEFINED;
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

int		c_4094::Ttable_Check(char t_value, nts::Tristate state)
{
  char	c;

  if (state == nts::TRUE)
    c = '1';
  else if (state == nts::FALSE)
    c = '0';
  else
    c = 'U';
  if (t_value == 'X')
    return (0);
  if (t_value == c)
    return (0);
  return (1);
}

void		c_4094::Set_Shift(int i)
{
  int	x;

  x = 8;
  if (ttable[i][6] == 'Q')
    pin_state[8] = pin_state[pin_Q[6] - 1];
  else
    pin_state[9] = pin_state[pin_Q[6] - 1];
  if (ttable[i][4] == 'U')
    for (int i = 0 ; i < 8 ; ++i)
      pin_state[pin_Q[i] - 1] = nts::UNDEFINED;
  else if (ttable[i][4] != 'N')
    {
      while (--x > 0)
	pin_state[pin_Q[x] - 1] = pin_state[pin_Q[x - 1] - 1];
      pin_state[pin_Q[0] - 1] = nts::TRUE;
      if (ttable[i][4] == '0')
	pin_state[pin_Q[0] - 1] = nts::FALSE;
    }
}

nts::Tristate	c_4094::Shift_Compute(size_t pin_num_this)
{
  int	i;
  int	match;
  i = -1;

  while (++i < 11)
    computed[3 + i] = true;
  i = -1;
  while (++i < 6)
    {
      match = 1;
      if (ttable[i][0] != Clock_Cycle(Compute(3)) ||
	  Ttable_Check(ttable[i][1], Compute(15)) ||
	  Ttable_Check(ttable[i][2], Compute(1)) ||
	  Ttable_Check(ttable[i][3], Compute(2)))
	match = 0;
      if (match)
	break;
    }
  clock = Compute(3);
  if (i < 6)
    Set_Shift(i);
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
  else if (this->link[pin_num_this - 1].link)
    ret = link[pin_num_this - 1].link->Compute(link[pin_num_this - 1].pin_target);
  else
    ret = pin_state[pin_num_this - 1];
  pin_state[pin_num_this - 1] = ret;
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
