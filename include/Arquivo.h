#ifndef ARQUIVO_H
#define ARQUIVO_H

#include<string>

#include "../include/Automato.h"
#include "../include/ExpressaoRegular.h"
#include "../include/GramaticaRegular.h"

class Arquivo{

public:

  Arquivo(std::string arquivo);
  ~Arquivo();

  bool abrir(std::string arquivo);
  std::string leLinha();

  Automato* geraAutomato();
  GramaticaRegular* geraGramaticaRegular();
  ExpressaoRegular* geraExpressaoRegular();


private:
  std::ifstream _streamArquivo;

};

#endif // ARQUIVO_H
