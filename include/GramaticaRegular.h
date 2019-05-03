#ifndef GRAMATICAREGULAR_H
#define GRAMATICAREGULAR_H

#include <vector>

class GramaticaRegular{

private:
  std::vector<std::string> _terminais;
  std::vector<std::string> _producoes;
  std::string* _producaoInicial;

};

#endif //GRAMATICAREGULAR_H
