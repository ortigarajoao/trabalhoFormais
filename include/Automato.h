#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <vector>

#include "Estado.h"

class Automato{

public:
  Automato();
  Automato(std::vector<char> alfabeto);
  ~Automato();

  void adicionaEstado(Estado e);
  void adicionaEstadoFinal(Estado* f);
  void setaEstadoInicial(Estado* i);

  Estado* procuraEstado(std::string rotulo);


private:
  std::vector<Estado*> _estados;
  Estado* _inicial;
  std::vector<Estado*> _finais;
  std::vector<char> _alfabeto;


public:
  static std::vector<char> geralAlfabeto(std::string linha){
    std::vector<char> retorno;
    int cont = 0;
    if(linha.find("S|") != std::string::npos){
      int pos = linha.find_first_of('|');
      while(pos != std::string::npos){
        retorno[cont] = linha[pos+1];
        cont++;
        pos = linha.find_first_of("|", pos+1);
      }
    }
    return retorno;
  }

};

#endif //AUTOMATO_H
