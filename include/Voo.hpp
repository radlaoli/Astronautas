#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;
class Voo
{
public:
    int codigo;
    vector<string> CPFs_Astronautas;
    enum estado
    {
        planejado,
        emCurso,
        finalizadoSucesso,
        finalizadoExplosao
    };

    Voo(int codigo);
    ~Voo();

    void adicionarPassageiro(string cpf);
    void removerPassageiro(string cpf);
    void exibirVoo();
};
#endif