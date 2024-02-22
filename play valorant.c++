#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "adicionar agente.hpp"
using namespace std;


struct Lista_mapas
{
    string *nome;
    int qnt_mapas;
};


void Adicionar_mapa (Lista_mapas &lista_mapas){
    system("cls");
    string nome;
    cout << "Insira o nome do mapa que voce quer adicionar: ";
    while(getline (cin, nome))
    {
        if (nome != "") break;
    };
    fstream LISTA_MAPAS;
    LISTA_MAPAS.open("mapas_do_jogo.txt", ios::out);
    if (LISTA_MAPAS.is_open())
    {
        for(int i=0;i<lista_mapas.qnt_mapas;i++)
        {
            LISTA_MAPAS << lista_mapas.nome[i] << " ";
        }
        
        LISTA_MAPAS << nome;
        LISTA_MAPAS << " ";
        LISTA_MAPAS << "R3J5";
    }
    else cout << "\nnao foi possivel abrir corretamente";

LISTA_MAPAS.close();

}

void importar_mapas(Lista_mapas &lista_mapas){
    string loop = "banana";
    fstream LISTA_MAPAS;
    LISTA_MAPAS.open("mapas_do_jogo.txt", ios::in);
    if (LISTA_MAPAS.is_open())
    {
        while(loop != "R3J5")
        {
            LISTA_MAPAS >> loop;
            if(loop != "R3J5") lista_mapas.qnt_mapas ++;
        }
        if (lista_mapas.qnt_mapas == 0) cout << "\n\nnao existem mapas registrados, favor adicionar mapa";
    } else cout << "\n\nProblema de leitura, reinicie o sistema";
    LISTA_MAPAS.close();
    
    
    lista_mapas.nome = new string[lista_mapas.qnt_mapas];

    //fstream LISTA_MAPAS;
    LISTA_MAPAS.open("mapas_do_jogo.txt", ios::in);
    if (LISTA_MAPAS.is_open())
    {
       for(int i=0; i<lista_mapas.qnt_mapas; i++)
       {
            LISTA_MAPAS >> lista_mapas.nome[i];
       }
    }
    
}

 



int main() {


   do{
    cout << "======================= VALORANT HELPER =======================\n\n                1. Achar seu agente perfeito\n\n                2. Adiconar Mapa\n\n                3. Adicionar Agente\n\n                4. Sair\n\n";
    int acao = 0;
    Lista_mapas lista_mapas;
    lista_mapas.qnt_mapas = 0;
    importar_mapas(lista_mapas);
   
    do{
        cout << "\nselecione um modo valido: ";
        cin >> acao; 
    } while (acao < 1 or acao > 4);
    

    switch (acao)
    {
    case 1:
        
        break;

    case 2:
        Adicionar_mapa(lista_mapas);
        break;
    
    case 3:
        
        break;
    
    default:
        break;
    }
 
    if (acao == 4) break;
    } while (true);
}