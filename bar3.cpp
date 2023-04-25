#include <iostream>
#include <iomanip>
#include <cctype> // para a função isdigit()

using namespace std;

int main()
{
    char sexo;
    int qtdCervejas = 0, qtdRefri = 0, qtdEspetinhos = 0;
    float valorConsumo, valorCouvert = 0, valorIngresso;

    bool continuar = true;
    while (continuar) {

        cout << "Sexo (F/M): ";
        while (!(cin >> sexo) || (sexo != 'F' && sexo != 'f' && sexo != 'M' && sexo != 'm')) {
            cout << "Sexo inválido. Tente novamente (F/M): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Recebe e verifica a quantidade de cervejas
        cout << "Quantidade de cervejas: ";
        while (!(cin >> qtdCervejas) || qtdCervejas < 0) {
            cout << "Por favor, insira um valor válido: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Recebe e verifica a quantidade de refrigerantes
        cout << "Quantidade de refrigerantes: ";
        while (!(cin >> qtdRefri) || qtdRefri < 0) {
            cout << "Por favor, insira um valor válido: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Recebe e verifica a quantidade de espetinhos
        cout << "Quantidade de espetinhos: ";
        while (!(cin >> qtdEspetinhos) || qtdEspetinhos < 0) {
            cout << "Por favor, insira um valor válido: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Calcula o valor do consumo
        valorConsumo = qtdCervejas * 5 + qtdRefri * 3 + qtdEspetinhos * 7;

        // Verifica se o valor do consumo é maior que 30 reais
        if (valorConsumo > 30) {
            valorCouvert = 0;
        }
        else {
            valorCouvert = 4;
        }

        // Verifica o valor do ingresso de acordo com o sexo
        if (sexo == 'F' || sexo == 'f') {
            valorIngresso = 8;
        }
        else {
            valorIngresso = 10;
        }

        // Calcula o valor total a ser pago
        float valorTotal = valorConsumo + valorCouvert + valorIngresso;

        // Imprime o relatório
        cout << fixed << setprecision(2);
        cout << "Consumo = R$ " << valorConsumo << endl;
        if (valorCouvert > 0) {
            cout << "Couvert = R$ " << valorCouvert << endl;
        }
        else
        {
            cout << "Isento de couvert" << endl;
        }
        cout << "Ingresso = R$ " << valorIngresso << endl;
        cout << "Valor total a pagar = R$ " << valorTotal << endl;

        // Pergunta ao usuário se deseja continuar
        char resposta;
        cout << "Deseja realizar outra operação? (S/N) ";
        cin >> resposta;
        if (resposta == 'N' || resposta == 'n') {
            continuar = false;
        }
    }

    return 0;
}