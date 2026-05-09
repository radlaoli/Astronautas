#include <iostream>
#include "../include/Agencia.hpp"

using namespace std;

int Agencia::buscarIndiceAstronauta(string &cpf)
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

void Agencia::cadastrarAstronauta(string &cpf, int idade, string &nome)
{
    if (buscarIndiceAstronauta(cpf) != -1)
    {
        cout << "Erro, CPF " << cpf << " ja cadastrado!" << endl;
        return;
    }

    Astronauta novoAstronauta(cpf, nome, idade);
    astronautas.push_back(novoAstronauta);
    cout << "Astronauta com o CPF " << cpf << " cadastrado com sucesso!" << endl;
}

void Agencia::cadastrarVoo(int codigo)
{
    if (buscarIndiceVoo(codigo) != -1)
    {
        cout << "Erro, ja existe um voo com o codigo " << codigo << " !" << endl;
        return;
    }

    Voo novoVoo(codigo);
    voos.push_back(novoVoo);
    cout << "O novo voo com o codigo " << codigo << " foi cadastrado!" << endl;
}

void Agencia::addAstronautaEmVoo(string &cpf, int codigo)
{
    int idAstronauta = buscarIndiceAstronauta(cpf);
    int idVoo = buscarIndiceVoo(codigo);

    if (idAstronauta == -1)
    {
        cout << "Erro, astronauta com CPF " << cpf << " nao encontrado!" << endl;
        return;
    }
    if (idVoo == -1)
    {
        cout << "Erro, voo com codigo " << codigo << " nao encontrado!" << endl;
        return;
    }
    if (voos[idVoo].estado != Voo::planejado)
    {
        cout << "Erro, o voo " << codigo << " nao esta planejado!" << endl;
        return;
    }
    if (astronautas[idAstronauta].estado == false)
    {
        cout << "Erro, o astronauta com o CPF " << cpf << " esta morto" << endl;
        return;
    }
    for (int i = 0; i < (int)voos[idVoo].CPFs_Astronautas.size(); i++)
    {
        if (voos[idVoo].CPFs_Astronautas[i] == cpf)
        {
            cout << "Erro, o astronauta de CPF " << cpf << " ja esta escalado para o voo " << codigo << endl;
            return;
        }
    }

    voos[idVoo].CPFs_Astronautas.push_back(cpf);
    cout << "Astronauta de CPF " << cpf << " adicionado ao voo " << codigo << " com sucesso!" << endl;
}

void Agencia::rmAstronautaDoVoo(string &cpf, int codigo)
{
    int idAstronauta = buscarIndiceAstronauta(cpf);
    int idVoo = buscarIndiceVoo(codigo);

    if (idAstronauta == -1)
    {
        cout << "Erro, astronauta com CPF " << cpf << " nao encontrado!" << endl;
        return;
    }
    if (idVoo == -1)
    {
        cout << "Erro, voo com codigo " << codigo << " nao encontrado!" << endl;
        return;
    }
    if (voos[idVoo].estado != Voo::planejado)
    {
        cout << "Erro, o voo " << codigo << " nao esta planejado!" << endl;
        return;
    }

    for (int i = 0; i < (int)voos[idVoo].CPFs_Astronautas.size(); i++)
    {
        if (voos[idVoo].CPFs_Astronautas[i] == cpf)
        {
            voos[idVoo].CPFs_Astronautas.erase(voos[idVoo].CPFs_Astronautas.begin() + i);
            cout << "Astronauta de CPF " << cpf << " removido do voo " << codigo << " com sucesso!" << endl;
            return;
        }
    }
    cout << "Erro, o astronauta de CPF " << cpf << " nao estava escalado no voo " << codigo << endl;
}

void Agencia::lancarVoo(int codigo)
{
    int idVoo = buscarIndiceVoo(codigo);

    if (idVoo == -1)
    {
        cout << "Erro, voo com o codigo " << codigo << " nao encontrado!" << endl;
        return;
    }
    if (voos[idVoo].estado != Voo::planejado)
    {
        cout << "Erro, o voo " << codigo << " nao esta planejado!" << endl;
        return;
    }
    if (voos[idVoo].CPFs_Astronautas.size() <= 0)
    {
        cout << "Erro, nao pode lancar o voo " << codigo << " sem astronautas" << endl;
        return;
    }

    for (int i = 0; i < (int)voos[idVoo].CPFs_Astronautas.size(); i++)
    {
        string cpf = voos[idVoo].CPFs_Astronautas[i];
        int idAstronauta = buscarIndiceAstronauta(cpf);

        if (astronautas[idAstronauta].estado == false || astronautas[idAstronauta].disponibilidade == false)
        {
            cout << "Erro, o lancamento do voo " << codigo << " foi abortado pois o astronauta de CPF " << cpf << " esta morto ou indisponivel!" << endl;
            return;
        }
    }

    voos[idVoo].estado = Voo::emCurso;

    for (int i = 0; i < (int)voos[idVoo].CPFs_Astronautas.size(); i++)
    {
        string cpf = voos[idVoo].CPFs_Astronautas[i];
        int idAstronauta = buscarIndiceAstronauta(cpf);

        astronautas[idAstronauta].disponibilidade = false;
        astronautas[idAstronauta].historicoVoos.push_back(codigo);
    }

    cout << "Voo " << codigo << " lançado com sucesso!" << endl;
}

void Agencia::explodirVoo(int codigo)
{
    int idVoo = buscarIndiceVoo(codigo);

    if (idVoo == -1)
    {
        cout << "Erro, voo com o codigo " << codigo << " nao encontrado!" << endl;
        return;
    }
    if (voos[idVoo].estado != Voo::emCurso)
    {
        cout << "Erro, apenas voos em curso podem ser explodidos! Voo " << codigo << " invalido." << endl;
        return;
    }
    voos[idVoo].estado = Voo::finalizadoExplosao;

    for (int i = 0; i < (int)voos[idVoo].CPFs_Astronautas.size(); i++)
    {
        string cpf = voos[idVoo].CPFs_Astronautas[i];
        int idAstronauta = buscarIndiceAstronauta(cpf);

        astronautas[idAstronauta].estado = false;
        astronautas[idAstronauta].disponibilidade = false;
    }

    cout << "Voo " << codigo << " finalizado com explosao!" << endl;
}

void Agencia::finalizarVooSucesso(int codigo)
{
    int idVoo = buscarIndiceVoo(codigo);

    if (idVoo == -1)
    {
        cout << "Erro, voo com o codigo " << codigo << " nao encontrado!" << endl;
        return;
    }
    if (voos[idVoo].estado != Voo::emCurso)
    {
        cout << "Erro, apenas voos em curso podem ser finalizados! Voo " << codigo << " invalido." << endl;
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

void Agencia::listarVoos()
{
    cout << "Lista de voos" << endl;
    if (voos.size() <= 0)
    {
        cout << "Nao ha voos cadastrados" << endl;
        return;
    }

    string nomesEstados[] = {"PLANEJADOS", "EM CURSO", "FINALIZADOS COM SUCESSO", "FINALIZADOS COM EXPLOSAO"};

    for (int estado = 0; estado < 4; estado++)
    {
        cout << endl
             << "--- " << nomesEstados[estado] << " ---" << endl;

        for (int i = 0; i < (int)voos.size(); i++)
        {
            if (voos[i].estado == estado)
            {
                voos[i].exibirVoo();
                cout << endl
                     << "Passageiros:" << endl;

                if (voos[i].CPFs_Astronautas.size() <= 0)
                {
                    cout << "Nenhum astronauta escalado" << endl;
                }
                else
                {
                    for (int j = 0; j < (int)voos[i].CPFs_Astronautas.size(); j++)
                    {
                        string cpfBusca = voos[i].CPFs_Astronautas[j];
                        int idAstronauta = buscarIndiceAstronauta(cpfBusca);
                        cout << "  - CPF: " << cpfBusca << " | Nome: " << astronautas[idAstronauta].nome << endl;
                    }
                    cout << endl;
                }
                cout << "----------------" << endl;
            }
        }
    }
}

void Agencia::listarAstronautasMortos()
{
    cout << "Lista de astronautas mortos:" << endl;
    bool encontrouMorto = false;
    for (int i = 0; i < (int)astronautas.size(); i++)
    {
        if (astronautas[i].estado == false)
        {
            encontrouMorto = true;
            cout << "CPF: " << astronautas[i].CPF << " | Nome: " << astronautas[i].nome << endl;
            cout << "Historico de Voos: " << endl
                 << "| ";
            for (int j = 0; j < (int)astronautas[i].historicoVoos.size(); j++)
            {
                cout << astronautas[i].historicoVoos[j] << " | ";
            }
            cout << endl;
        }
    }
    if (!encontrouMorto)
        cout << "Nenhuma fatalidade registrada." << endl;
}