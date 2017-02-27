//
// test_c.cpp for test in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb 16 20:40:28 2017 Nathan Scutari
// Last update Mon Feb 27 11:53:24 2017 Nathan Scutari
//

#include <iostream>
#include "all_components.hpp"

int	main()
{
  nts::IComponent	*outp = new c_output("");
  nts::IComponent	*inp = new c_input("0");
  nts::IComponent	*comp = new c_4071("");

  comp->SetLink(1, *inp, 1);
  comp->SetLink(2, *comp, 3);
  outp->SetLink(1, *comp, 3);
  outp->Compute();
  comp->Dump();
  ((c_input*)inp)->SetPin(nts::TRUE);
  outp->Compute();
  comp->Dump();
  ((c_input*)inp)->SetPin(nts::FALSE);
  outp->Compute();
  comp->Dump();
}
