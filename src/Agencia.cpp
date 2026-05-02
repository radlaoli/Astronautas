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

void Agencia::finalizarVooSucesso(int codigo)
{
    for (int i = 0; i < (int)voos.size(); i++)
    {
        if (voos[i].codigo == codigo)
        {
            if (voos[i].estado == Voo::emCurso)
            {
                voos[i].estado = Voo::finalizadoSucesso;

                for (int j = 0; j < (int)voos[i].CPFs_Astronautas.size(); j++)
                {
                    string cpfBusca = voos[i].CPFs_Astronautas[j];

                    for (int k = 0; k < (int)astronautas.size(); k++)
                    {
                        if (astronautas[k].CPF == cpfBusca)
                        {
                            astronautas[k].disponibilidade = true;
                            break;
                        }
                    }
                }
                cout << "Voo finalizado com sucesso !" << endl;
            }
            else
            {
                cout << "Erro, penas voos em curso podem ser finalizados!" << endl;
            }
            return;
        }
    }
    cout << "Nao existe voo cadastrado com o codigo fornecido!" << endl;
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