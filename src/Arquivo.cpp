#include <fstream>
#include <iostream>

#include "../include/Arquivo.h"


Arquivo::Arquivo(std::string arquivo){
  _streamArquivo = std::ifstream(arquivo);

  if(!_streamArquivo.is_()){
    std::cout << "Erro ao abrir arquivo: " << arquivo << '\n';
    _streamArquivo = std::ifstream();
  }
}

std::string Arquivo::leLinha(){
  std::string linha;
  if(_streamArquivo.is_open()){
    std::getline(_streamArquivo, linha);
  }
  return linha;
}

Automato* Arquivo::geraAutomato(){
  _streamArquivo.seekg(0, _streamArquivo.beg);
  if(_streamArquivo.is_open()){
    if(_streamArquivo.good()){
      std::string tipo("automato");
      if(tipo.compare(this->leLinha()) == 0){
        std::vector<char> alfabeto = Automato::geralAlfabeto(this->leLinha());
        std::string linhaAtual = this->leLinha();
        Automato* r = new Automato(alfabeto);
        Estado* e = new Estado();
        int pos = 0;
        int pos1 = 0;

        if(linhaAtual.find("*") != std::strig::npos){
          r.adicionaEstadoFinal(e);
        }

        if(linhaAtual.find("->") != std::string::npos){
          r.setaEstadoInicial(e);
        }

        pos = linhaAtual.find_first_of(">");
        pos1 = linhaAtual.find_first_of("|");
        e.setaRotulo(linhaAtual.substr(pos+1, pos1-(pos+1)));

        linhaAtual = this->lelinha();

        while(linhaAtual != std::string::npos){ //pega estados
          Estado* e = new Estado();
          pos = -1;
          if(linhaAtual.find("*") != std::strig::npos){
            r.adicionaEstadoFinal(e);
            pos = linhaAtual.find_first_of("*");
          }
          pos1 = linhaAtual.find_first_of("|");
          e.setaRotulo(linhaAtual.substr(pos+1,pos1-(pos+1)));
          r.adicionaEstado(e));
          linhaAtual = this->leLinha();
        }

        _streamArquivo.seekg(0, _streamArquivo.beg);
        this->leLinha();

        linhaAtual = this->lelinha();

        whiele()





        }
        while(_streamArquivo.good()){
            int pos1 = linhaAtual.find_first_of(">");
            int pos2 = linhaAtual.find_first_of("|");
            e->setaRotulo(linhaAtual.substr(pos1+1, pos2-1));
            pos = pos2;
            while(pos != std::string::npos){
              pos2 = linhaAtual.find_first_of("|", pos+1);


            }
        }
      } else {
        std::cout << "Erro no formato de arquivo" << '\n';
      }

    }
    std::cout << "Arquivo vazio ou chegou ao final do arquivo" << '\n';
  }
}


if(_arquivo.is_open()){
    std::string strAux;
    int pos;
    std::getline (_arquivo, strAux);
    if(strAux.compare(0,9, "*vertices") == 0){
      int nVertices = std::stoi(strAux.substr(10));
      if(nVertices){
        _vertices = new std::vector<Vertice*>(nVertices);
        for(int i = 1; i <= nVertices; i++){
          std::getline(_arquivo, strAux);
          pos = strAux.find_first_of(" ");
          if(pos != std::string::npos){
            (*_vertices)[i] = new Vertice(i,strAux.substr(pos+1));
          } else {
            std::cout << "Erro na formatacao da linha: " << i << std::endl;
          }
        }
        std::getline(_arquivo, strAux);
        if(strAux.compare("*edges") == 0){
          std::getline(_arquivo, strAux);
          while(_arquivo.good()){
            _qtdArestas++;
            pos = strAux.find_first_of(" ");
            int vertice1 = std::stoi(strAux.substr(0,pos));
            int pos2 = strAux.find_first_of(" ",pos+1);
            int vertice2 = std::stoi(strAux.substr(pos+1,pos2-pos-1));
            double peso = std::stod(strAux.substr(pos2+1));
            (*_vertices)[vertice1]->adicionaAresta((*_vertices)[vertice2], peso);
            (*_vertices)[vertice2]->adicionaAresta((*_vertices)[vertice1], peso);
            std::pair<Vertice*,Vertice*>* par1 = new std::pair<Vertice*,Vertice*>((*_vertices)[vertice1],(*_vertices)[vertice2]);
            std::pair<Vertice*,Vertice*>* par2 = new std::pair<Vertice*,Vertice*>((*_vertices)[vertice2],(*_vertices)[vertice1]);
            _arestas.insert(par1);
            _arestas.insert(par2);
            std::getline(_arquivo, strAux);
          }
