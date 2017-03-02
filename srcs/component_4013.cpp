//
// component_4013.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Wed Mar  1 18:21:24 2017 Nathan Scutari
//

#include <iostream>
#include "component_4013.hpp"

c_4013::c_4013(UNUSED const std::string &value)
{
  int	x;
  int	y;

  t_link	link;
  char		ttable[6][6] =
    {
      {'0', '0', '0', '0', '0', '1'},
      {'0', '0', '1', '0', '1', '0'},
      {'1', '0', 'x', '0', 'q', 'q'},
      {'x', '1', 'x', '0', '0', '1'},
      {'x', '0', 'x', '1', '1', '0'},
      {'x', '1', 'x', '1', '1', '1'}
      };

  x = -1;
  while (++x < 6)
    {
      y = -1;
      while (++y < 6)
	this->ttable[x][y] = ttable[x][y];
    }
  link.pin_target = 0;
  link.link = NULL;
  for (int i = 0 ; i < 14 ; ++i)
    {
      computed.push_back(false);
      pin_state.push_back(nts::UNDEFINED);
      this->link.push_back(link);
    }
}

c_4013::~c_4013()
{}

int		c_4013::Ttable_check(char t_value, nts::Tristate state)
{
  char	c;

  if (state == nts::TRUE)
    c = '1';
  else if (state == nts::FALSE)
    c = '0';
  else
    c = 'U';
  if (t_value == 'x')
    return (0);
  if (t_value == c)
    return (0);
  return (1);
}

nts::Tristate	c_4013::Char_To_Tristate(char c, nts::Tristate pin_q)
{
  if (c == 'q')
    return (pin_q);
  if (c == '0')
    return (nts::FALSE);
  else if (c == '1')
    return (nts::TRUE);
  return (nts::UNDEFINED);
}

nts::Tristate	c_4013::Compute_FF1(size_t pin_num_this)
{
  int	i;
  int	y;
  int	error;

  i = -1;
  if (pin_num_this == 2)
    std::cout << std::endl;
  while (++i < 6)
    {
      y = -1;
      error = 0;
      while (++y < 4)
	if (Ttable_check(ttable[i][y], this->Compute(3 + y)))
	  error = 1;
      if (error == 0)
	break;
    }
  std::cout << i << std::endl;
  if (i >= 6)
    return (nts::UNDEFINED);
  pin_state[0] = Char_To_Tristate(ttable[i][4], pin_state[0]);
  pin_state[1] = Char_To_Tristate(ttable[i][5], pin_state[1]);
  return (pin_state[pin_num_this - 1]);
}

nts::Tristate	c_4013::Compute_FF2(size_t pin_num_this)
{
  int	i;
  int	y;
  int	error;

  i = -1;
  while (++i < 6)
    {
      y = -1;
      error = 0;
      while (++y < 4)
	if (Ttable_check(ttable[i][y], this->Compute(11 - y)))
	  error = 1;
      if (error == 0)
	break;
    }
  if (i >= 6)
    return (nts::UNDEFINED);
  pin_state[11] = Char_To_Tristate(ttable[i][5], pin_state[11]);
  pin_state[12] = Char_To_Tristate(ttable[i][4], pin_state[12]);
  return (pin_state[pin_num_this - 1]);
}

nts::Tristate	c_4013::Compute(size_t pin_num_this)
{
  nts::Tristate	ret;

  if (computed[pin_num_this - 1] == true)
    return (pin_state[pin_num_this - 1]);
  computed[pin_num_this - 1] = true;
  if (pin_num_this == 1 || pin_num_this == 2)
    ret = Compute_FF1(pin_num_this);
  else if (pin_num_this == 12 || pin_num_this == 13)
    ret = Compute_FF2(pin_num_this);
  else if (this->link[pin_num_this - 1].link)
    ret = link[pin_num_this - 1].link->Compute(link[pin_num_this - 1].pin_target);
  else
    ret = pin_state[pin_num_this - 1];
  computed[pin_num_this - 1] = false;
  pin_state[pin_num_this - 1] = ret;
  return (ret);
}

void		c_4013::Dump(void) const
{
  std::cout << "Component : 4013" << std::endl;
  for (int i = 0 ; i < 14 ; ++i)
    {
      std::cout << "Pin " << i + 1 << ": ";
      if (pin_state[i] == nts::UNDEFINED)
	std::cout << "UNDEFINED" << std::endl;
      else
	std::cout << pin_state[i] << std::endl;
    }
}

void		c_4013::SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target)

{
  link[pin_num_this - 1].link = &component;
  link[pin_num_this - 1].pin_target = pin_num_target;
}
