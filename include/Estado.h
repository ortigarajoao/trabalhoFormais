#ifndef ESTADO_H
#define ESTADO_H

#include <unordered_map>

class Estado{


private:
  std::unordered_multimap<char,Estado*> _adjacentes;
};

#endif //ESTADO_H
