#include <iostream>
#include "../include/Agencia.hpp"

using namespace std;

void Agencia::cadastrarAstronauta(string cpf, int idade, string nome)
{
    for (int i = 0; i < astronautas.size(); i++)
    {
        if (astronautas[i].CPF == cpf)
        {
            cout << "Erro, CPF ja cadastrado!" << endl;
            return;
        }
    }

    Astronauta novoAstronauta(cpf, nome, idade);
    astronautas.push_back(novoAstronauta);

    cout << "O novo Astronauta foi cadastrado!" << endl;
}

void Agencia::cadastrarVoo(int codigo)
{
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].codigo == codigo)
        {
            cout << "Erro, ja existe um voo com esse codigo!" << endl;
            return;
        }
    }
    Voo novoVoo(codigo);
    voos.push_back(novoVoo);

    cout << "O novo voo foi cadastrado!" << endl;
}