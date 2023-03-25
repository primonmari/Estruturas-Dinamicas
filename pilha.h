#ifndef PILHA_H_INCLUDED //if not defined , se n tiver nenuma definicao de PILHA_H_INCLUDED faz oq ta dentro do if
#define PILHA_H_INCLUDED//cria deficao,aaq dentro coloco assinatura das funcoes, constantes, estruturas



#endif // PILHA_H_INCLUDED


typedef struct{ //struct para o valor recebido
int numero;
}valor;

typedef struct no{//apelido para a estrutura
    valor p;//variavel do tipo valor que e preenchida por lendo_valor
    struct no *prox;//ponteiro p/ o prox no
}No;//nome da estrutura

typedef struct{ //dentro do tipo pilha teremos um ponteiro para o tipo no chamado de topo
    No *topo;//ponteiro para o topo, topo eh nulo
    int volume;//quando crio a pilha o tamanho dela eh 0 e vai
    //aumentando ou diminuindo, por isso vou criar o void criarpilha
}pilha;

void criarpilha( pilha *p){//recebe ponteiro que vem da funcao main

   p->topo = NULL;//O TOPO DO INICIO DA PILHA EH NULL
   p->volume= 0;//TAMANHO DA PILHA E 0, como recebi o endereco
   //da pilha la na funcao main eu nao preciso retornar nada
   //as setas indicam a manipulacao de ponteiro, da pilha q vem d FUNCAO MAIN
}
valor lendo_valor(){//preenche a variavel v do estruct no
    valor p;//variavel do tipo valor
    printf("\nDigite um numero:\n");
    scanf("%d",&p.numero);
    return p;//retorna valor
}
void imprimir_valor(valor p){//recebe variavel do tipo valor e imprime o valor
printf("\nvalor: %d", p.numero);
}
//----------- FUNCAO PARA OPERACOES PUSH E POP
void empilhar(pilha *p){//ponteiro p pilha
    No *novono = malloc (sizeof(No));//crio o novo no

    if (novono){//se o novo no foi criado corretamente entao:
        novono->p = lendo_valor();// inseri um valor
        novono->prox = p->topo;//proximo aonta p/ topo atual
        p->topo = novono;//atualizando topo
        p->volume++;//atualiza tamanho da pilha
    }else
        printf("\nErro ao alocar memoria...\n");

}
No* desempilhar(pilha *p){//retorno no que remove
    if (p->topo){//topo eh um ponteiro , autmaticamente faz o teste diferente de nulo
        No *remover = p->topo;//pego o topo da pilha
        p->topo = remover->prox;//pego o prox do no que quero remover
        p->volume--;//atualiza tamanho da pilha
        return remover;//retorno no que estou removendo
    }
   else
        printf("\nOPS!Pilha vazia...\n");
        return NULL;
}

void imprimir(pilha *p){
    No *aux = p->topo;//em aux p nao dar erro em alterar a pilha
    printf("\n.............................. PILHA (tamanho: %d ) ..............................\n",p->volume);
    while(aux){//pego o topo
        imprimir_valor(aux->p);//ponteiro aux para percorrer a pilha
        aux = aux->prox;
    }
    printf("\n.............................. FIM PILHA (tamanho: %d ) ..............................\n",p->volume);
}


int mainpilha(){
    No *remover;
    pilha p;
    int op;

    criarpilha(&p);//passo endereco da pilha
    do{
        printf("\n\n1 - Insercao - PUSH\n2 - Remocao - POP\n3 - Exibir\n4 - Voltar ao menu principal\n\n");
        scanf("%d",&op);
        getchar();//limpo o buffer teclado, ele que diz q o topo e null e o tamanho e zero
    switch(op){
    case 1:
        system("cls");//limpa a tela
        //system("pause");//pausa, pede para clicar em qualquer lugar tela
        empilhar(&p);
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
    case 2:
        system("cls");//limpa a tela
        printf("\n\n\t\tRemovendo elemento..\n\n");
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        remover = desempilhar(&p);//no q recebe no removido, endereco da pilha
        if(remover){
            printf("\nElemento removido com sucesso!\n\n");
            imprimir_valor(remover->p);

            free(remover);//libero no remover p nao ficar na memoria
        }
        else
            printf("\nNao existe no para remocao.\n");
        break;
    case 3:
        system("cls");//limpa a tela
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        printf("\n\n\t\tExibindo elementos..\n\n");
        imprimir(&p);
        break;
    case 4:
        printf("\n\nRedirecionando para o menu principal..\n\n");
        system("pause");
        system("cls");
        menu();
        ler_opcao();
        break;
    default:
        printf("\n\nOpcao invalida!\n\n");
        break;
    }
    }while(op != 0);
    return 0;//retorno a opcao

}

