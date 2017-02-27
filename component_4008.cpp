//
// component_4008.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:25:28 2017 Nathan Scutari
// Last update Fri Feb 17 10:32:43 2017 Nathan Scutari
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
      if (i < 4)
	carry_out.push_back(nts::UNDEFINED);
      computed.push_back(false);
      pin_state.push_back(nts::UNDEFINED);
      this->link.push_back(link);
    }
  pin_order[0][0] = 7;
  pin_order[0][1] = 6;
  pin_order[1][0] = 5;
  pin_order[1][1] = 4;
  pin_order[2][0] = 3;
  pin_order[2][1] = 2;
  pin_order[3][0] = 1;
  pin_order[3][1] = 15;
  pin_state[6] = nts::TRUE;
  pin_state[7] = nts::FALSE;
  carry_out[0] = nts::TRUE;
}

c_4008::~c_4008()
{}

int	c_4008::Tristate_to_int(nts::Tristate t)
{
  if (t == nts::TRUE)
    return (1);
  return (0);
}

nts::Tristate	c_4008::Int_to_tristate(int i)
{
  if (i)
    return (nts::TRUE);
  return (nts::FALSE);
}

nts::Tristate	c_4008::Compute_si(size_t si)
{
  nts::Tristate	ret1;
  nts::Tristate	ret2;
  nts::Tristate ret3;
  int		sum;

  if ((ret1 = this->Compute(pin_order[si][0])) == nts::UNDEFINED ||
      (ret2 = this->Compute(pin_order[si][1])) == nts::UNDEFINED)
    {
      carry_out[si] = nts::UNDEFINED;
      return (nts::UNDEFINED);
    }
  if ((si == 0 && (link[9].link == NULL || (ret3 = link[9].link->Compute(link[9].pin_target)) == nts::UNDEFINED))
      || (si != 0 && (ret3 = this->Compute_si(si - 1)) == nts::UNDEFINED))
    {
      carry_out[si] = nts::UNDEFINED;
      return (nts::UNDEFINED);
    }
  else if (si != 0)
    ret3 = carry_out[si - 1];
  sum = Tristate_to_int(ret1) + Tristate_to_int(ret2) + Tristate_to_int(ret3);
  carry_out[si] = Int_to_tristate(sum / 2);
  return (Int_to_tristate(sum % 2));
}

nts::Tristate	c_4008::Compute(size_t pin_num_this)
{
  nts::Tristate	ret;

  if (pin_num_this >= 10 && pin_num_this <= 13)
    {
      computed[pin_num_this - 1] = true;
      ret =  this->Compute_si(pin_num_this - 10);
      computed[pin_num_this - 1] = false;
      return (ret);
    }
  if (pin_num_this == 14)
    {
      this->Compute_si(3);
      return (carry_out[3]);
    }
  if (computed[pin_num_this - 1] == false)
    {
      computed[pin_num_this - 1] = true;
      if (this->link[pin_num_this - 1].link)
	ret = link[pin_num_this - 1].link->Compute(link[pin_num_this - 1].pin_target);
      else
	ret =  pin_state[pin_num_this - 1];
      computed[pin_num_this - 1] = false;
      return (ret);
    }
  return (this->pin_state[pin_num_this - 1]);
}

void		c_4008::Dump(void) const
{
  std::cout << "Component : 4008" << std::endl;
  for (int i = 0 ; i < 16 ; ++i)
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
