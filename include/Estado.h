#ifndef ESTADO_H
#define ESTADO_H

#include <unordered_map>

class Estado{

public:

  Estado();
  Estado(std::string rotulo);
  ~Estado();


  void setaRotulo(std::string rotulo);
  void adicionaAresta(char c, Estado* e);


private:

  std::unordered_multimap<char,Estado*> _adjacentes;
  std::string _rotulo;

};

#endif //ESTADO_H
