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

    Astronauta();
    ~Astronauta();

    void cadastrar(string cpf, int idade, string nome_completo);
    void estadoAstronauta();
};

#endif