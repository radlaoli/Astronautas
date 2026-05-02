#include <iostream>
#include "../include/Agencia.hpp"

using namespace std;

// funções auxiliares:
int Agencia::buscarIndiceAstronauta(string cpf)
{
    for (int i = 0; i < (int)astronautas.size(); i++)
    {
        if (astronautas[i].CPF == cpf)
        {
            return i;
        }
    }
    return -1;
}

int Agencia::buscarIndiceVoo(int codigo)
{
    for (int i = 0; i < (int)voos.size(); i++)
    {
        if (voos[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

void Agencia::cadastrarAstronauta(string cpf, int idade, string nome)
{
    if (buscarIndiceAstronauta(cpf) != -1)
    {
        cout << "Erro, CPF ja cadastrado!" << endl;
        return;
    }

    Astronauta novoAstronauta(cpf, nome, idade);
    astronautas.push_back(novoAstronauta);
    cout << "Astronauta cadastrado com sucesso!" << endl;
}

void Agencia::cadastrarVoo(int codigo)
{
    if (buscarIndiceVoo(codigo) != -1)
    {
        cout << "Erro, ja existe um voo com esse codigo!" << endl;
    }

    Voo novoVoo(codigo);
    voos.push_back(novoVoo);
    cout << "O novo voo foi cadastrado!" << endl;
}

void Agencia::finalizarVooSucesso(int codigo)
{
    int idVoo = buscarIndiceVoo(codigo);

    if (idVoo == -1)
    {
        cout << "Erro: Voo nao encontrado!" << endl;
        return;
    }
    if (voos[idVoo].estado != Voo::emCurso)
    {
        cout << "Erro: Apenas voos em curso podem ser finalizados!" << endl;
        return;
    }

    voos[idVoo].estado = Voo::finalizadoSucesso;
    for (string cpf : voos[idVoo].CPFs_Astronautas)
    {
        int idAstronauta = buscarIndiceAstronauta(cpf);
        if (idAstronauta != -1)
        {
            astronautas[idAstronauta].disponibilidade = true;
        }
    }
    cout << "Voo " << codigo << " finalizado com sucesso!" << endl;
}

void Agencia::listarAstronautasMortos()
{
    for (int i = 0; i < astronautas.size(); i++)
    {
        if (astronautas[i].estado == false)
        {
            cout << "CPF: " << astronautas[i].CPF << " | Nome: " << astronautas[i].nome << endl;
            cout << "Historico de Voos: " << endl
                 << "| ";
            for (int j = 0; j < astronautas[i].historicoVoos.size(); j++)
            {
                cout << astronautas[i].historicoVoos[j] << " | ";
            }
        }
    }
}