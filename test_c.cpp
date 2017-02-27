//
// test_c.cpp for test in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb 16 20:40:28 2017 Nathan Scutari
// Last update Thu Feb 16 20:53:53 2017 Nathan Scutari
//

#include <iostream>
#include "all_components.hpp"

int	main()
{
  nts::IComponent	*comp = new c_4008("");

  std::cout << comp->Compute(10) << std::endl;
  comp->Dump();
}
