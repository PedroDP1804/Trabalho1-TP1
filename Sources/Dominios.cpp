#include <iostream>
#include <string>
#include "..\Headers\Dominios.h"

using namespace std;

void Data::validar(string data) {
    //vefica o tamanho
    if (data.length() != 10) {
        throw invalid_argument("Tamanho do argumento invalido");
    }

    //verifica formato
    int index = 0;
    //percorre a string
    for (char caracter : data) {
        switch (index) {
            case 2:
            case 5:
            //verifica se são barras nos indices 2 e 5
                if (caracter != '/') {
                    throw invalid_argument("Caracter deveria ser '/'");
                }
                break;
            //verifica se são digitos nos índices restantes
            default:
                if (!isdigit(caracter)) {
                    throw invalid_argument("Caracter deveria ser digito");
                }
                break;
        }
        index++;
    }

//verifica se a data é válida
    bool eh_bissexto;
    int dias_no_mes, valor_temp;
    string temp;

    //define temp e valor_temp como o valor do ano
    temp = data[6];
    for (int i=7; i < 10; i++) {
        temp += data[i];
    }
    valor_temp = stoi(temp);

    //verifica se o ano é válido
    if (valor_temp < 2000 || valor_temp > 2100) {
        throw invalid_argument("Ano não é válido");
    }
    //verifica se o ano é bissexto
    if (valor_temp%4 == 0) {
        eh_bissexto = true;
    }

    //define temp e valor_temp como o valor do mês
    temp = data[3];
    temp += data[4];
    valor_temp = stoi(temp);

    //verifica se o mês é válido
    if (valor_temp < 1 || valor_temp > 12) {
        throw invalid_argument("Mes nao e valido");
    }
    //define quantos dias tem no mês
    switch (valor_temp) {
        case 2:
            if (eh_bissexto) {
                dias_no_mes = 29;
            }
            else {
                dias_no_mes = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dias_no_mes = 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias_no_mes = 31;
            break;    
    }  

    //define temp e valor_temp como o valor do dia
    temp = data[0];
    temp += data[1];
    valor_temp = stoi(temp);

    //verifica se o dia é válido
    if (valor_temp < 1 || valor_temp > dias_no_mes) {
        throw invalid_argument("Dia nao e valido");
    }

}

void Data::setData(string data) {
    this->validar(data);
    this->data = data;
}