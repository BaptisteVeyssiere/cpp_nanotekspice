//
// AComponent.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Mar  2 14:57:08 2017 Nathan Scutari
// Last update Thu Mar  2 15:10:11 2017 Nathan Scutari
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

#include <vector>
#include "IComponent.hpp"

class	AComponent : public IComponent
{
private:
  std::vector<int>	computed;

public:
  virtual ~AComponent();
  void	Simulation_end();
};

#endif /* !ACOMPONENT_HPP_ */
