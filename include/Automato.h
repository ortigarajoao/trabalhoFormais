#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <vector>

#include "Estado.h"

class Automato{

public:
  Automato();
  Automato(std::string arquivo);
  ~Automato();

private:
  std::vector<Estado> _estados;
  Estado* _inicial;
  std::vector<Estado*> _finais;
  std::vector<char> _alfabeto;

};

#endif //AUTOMATO_H
