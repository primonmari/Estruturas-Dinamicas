#include <stdio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand
#include<time.h>//necessário p/ função time()
#include"pilha.h"
#include"fila.h"
#include"lista.h"
#include"listaenc-circular.h"
#include"listadupla-encad.h"
#include"listadupla-encadCircular.h"

// A LISTA ENCADEADA EH GENERICA, NELA FAZEMOS ALOCAMOS NOS, PREENCHENDO ELES COM INFORMACOES E INSERINDO NA ESTRUTURA TIPO LISTA
//NAO TEM MUITAS RESTRICOES,EH FLEXIVEL , NAO TEM MUITAS REGRAS, SERVE PARA UMA INFINIDADE DE PROBLEMAS
//POSSO: INSERIR (inicio, meio e fim), INSERIR ORDENADO, REMOVER (inicio, meio e fim), BUSCA
//obs:
//criamos sempre um ponteiro aux para referenicia do 1° no da lista, para quando for imprimir, manipular ou qualquer operacao, nao alterar o
//conteudo do ponteiro e perder a referencia, entao aux percorre a lista sempre com a freferencia para o 1° no da lista

//Insercoes: Nao tem exigencia
//meio: linco o novo no na lista, novono->prox(2) aponta para aux->prox(1)(aux->prox aponta pro no da frente(nozin 3) do que eu quero inserir),
//entao o novono(2) aponta para o nozin(3), assim ligamos o novono(1) na lista, ai fazemos o aux->prox(1) aponta para o novono(2) deixando de aponta p/
//nozin(3)

//Remocao:
//ponteiro aux q identifica qual no quero remover,para o meio(mais comum): aux identifica o no anterior(1) ao no que quero remover(2),no1 aponta
//no2 e no2 aponta p/ no3, o anterior do no2 eh no1, marco o no2 com um pont noremover, e o anteror no1 e apontado por aux->prox, o seu
//prox deixa de ser o no2 e passa a ser o proximo do noremover->prox q eh o no3, entao removo o no2 que ficou sobrando
// =================== DECLARACAO DO CORPO DAS FUNCOES ===================
void menu();
int ler_opcao();
void inicio();
void cabec_inicio();
//=================== Globais ===================
//int leitura;//pro suite acessar a op digitada
//=================== MAIN PRINCIPAL ===================
int main(){
int op;
cabec_inicio();
inicio();
menu();
ler_opcao();//funcao q retorna algo, op recebe funcao
}
// FIM DO MAIN

//=================== CORPO DAS FUNCOES DE MENU ===================
void menu(){
printf("\n\nSelecione uma opcao:\n ");
printf("\n1-Lista Encadeada\n2-Lista Encadeada Circular\n3-Lista Duplamente Encadeada\n4-Lista Duplamente Encadeada Circular\n5-Pilha\n6-Fila\n7-Sair\n\n");
}

void cabec_inicio(){
printf("\n\n\t\tSISTEMA IMPLEMENTACAO DE ESTRUTURA DE DADOS\n\n\t\t\t\t'Seja bem-vindo'\n\n");
printf("\n\nDeseja acessar o menu? Digite o seu codigo de acesso\n\n");
}
void inicio(){
    int op=0,aux=0; //a variavel so vai existir no escopo dessa funcao
    int valida=0;//teste para verificar se o usuario digitou uma das opcoes, flag q supoe q o user digitou opcao invalida
    srand(time(NULL));//funcao para nao repetir a senha
    aux= rand() % 100;
    printf("\nSeu cogigo e: %d\n\n ", aux);
    do{//enquanto valida igual a 0 executa o switch ate o user digitar a opcao correta
        scanf("%d",&op);
        if(op==aux){
           printf("\n\t\t\tRedirecionando para o Menu...\n\n");
           system("cls");
           system("pause");
        }else{
            printf("\nPor favor insira seu codigo de acesso:\n");
            //scanf("%d",&op);
            inicio();
        }
        break;//forcando a parada do while para prosseguir pra funcao menu2
    }while(op!=0);
  return 0;
  }

int ler_opcao(){//funcao que le se a opcao digitada e valida ou nao
    int op; //a variavel so vai existir no escopo dessa funcao
    int valida=0;//teste para verificar se o usuario digitou uma das opcoes, flag q supoe q o user digitou opcao invalida

    while(valida == 0){//enquanto valida igual a 0 executa o switch ate o user digitar a opcao correta
        scanf(" %d",&op);
        switch(op){
            case 1:
                mainlista_Enc();
                break;
            case 2:
                mainlista_Enc_Circ();
                break;
            case 3:
                mainlista_DuplaEn();
                break;
            case 4:
                Lista_Dup_Enc_C();
                break;
            case 5:
                mainpilha();
                break;
            case 6:
                mainfila();
                break;
            case 7 :
                printf("\n\nRedirecionando para inicio do sistema..\n\n");
                system("pause");
                system("cls");
                cabec_inicio();
                inicio();
                menu();
                break;
                return op;//se ler qualquer um desses caracteres deu certo entao return op, o return n precisa ser o ultimo comando
                default: //caso nao entre em nenhum dos cases
                printf("\n\nOpcao invalida!\n\n");
                menu();
        }
    }
}


