#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
using std::string;
class Astronauta
{
public:
    string CPF, nome;
    int idade;
    bool estado, disponibilidade;

    Astronauta(string cpf, string nome, int idade);
    ~Astronauta();

    void exibirEstado(); // TODO: certificar que foram listados todos os métodos
};

#endif