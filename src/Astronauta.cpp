#include <iostream>
#include "../include/Astronauta.hpp"

using namespace std;

Astronauta::Astronauta(string cpf, string nome, int idade)
{
    this->CPF = cpf;
    this->nome = nome;
    this->idade = idade;
    this->disponibilidade = true; // disponivel
    this->estado = true;          // vivo
}

Astronauta::~Astronauta() {}

void Astronauta::exibirInfo()
{
    cout << "CPF: " << CPF << " | Nome: " << nome << " | Idade: " << idade << endl;
    if (estado) // vivo
    {
        cout << "Estado: Vivo | ";
    }
    else
    {
        cout << "Estado: Morto | ";
    }

    if (disponibilidade) // disponivel
    {
        cout << "Disponibilidade: Disponivel" << endl;
    }
    else
    {
        cout << "Disponibilidade: Indisponivel" << endl;
    }
}