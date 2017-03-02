//
// component_4013.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Thu Mar  2 15:38:28 2017 Nathan Scutari
//

#ifndef COMPONENT_4013_HPP_
# define COMPONENT_4013_HPP_

#include <vector>
#include <string>
#include "link.hpp"
#include "AComponent.hpp"

class	c_4013 : public AComponent
{
private:
  std::vector<nts::Tristate>			pin_state;
  std::vector<struct s_link>			link;
  char						ttable[6][6];

public:
  c_4013(const std::string &value);
  virtual ~c_4013();

  nts::Tristate Compute(size_t pin_num_this = 1);
  nts::Tristate	Compute_FF1(size_t pin_num_this);
  nts::Tristate	Compute_FF2(size_t pin_num_this);
  nts::Tristate	Char_To_Tristate(char c, nts::Tristate pin_q);
  int		Ttable_check(char t_value, nts::Tristate state);
  void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_4013_HPP_ */
