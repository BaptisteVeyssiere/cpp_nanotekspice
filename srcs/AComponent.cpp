//
// AComponent.cpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Mar  2 15:21:58 2017 Nathan Scutari
// Last update Thu Mar  2 15:23:11 2017 Nathan Scutari
//

#include "AComponent.hpp"

AComponent::~AComponent()
{}

void	AComponent::Simulation_End()
{
  int	i;

  i = -1;
  while (++i < computed.size())
    computed[i] = 0;
}
