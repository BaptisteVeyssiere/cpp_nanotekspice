//
// AComponent.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Mar  2 14:57:08 2017 Nathan Scutari
// Last update Thu Mar  2 15:38:05 2017 Nathan Scutari
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

#include <vector>
#include "IComponent.hpp"

class	AComponent : public nts::IComponent
{
protected:
  std::vector<int>	computed;

public:
  virtual ~AComponent();
  void	Simulation_End();
};

#endif /* !ACOMPONENT_HPP_ */
