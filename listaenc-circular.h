#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED



#endif // LISTA_H_INCLUDED
//LISTA CIRCULAR é uma lista q ao chegar ao final noa existe null no proximo,
//o ultimo no aponta novamente para o inicio da lista, nela o rocesso para identificar o final da lista eh diferente
//O ultimo no aponta pro inicio da lista

//para vericar se percoorri a lista toda: verificar se o proximo no e diferente do inicio

/*No pro inicio da lista*/
typedef struct noc{
  int valor;
  struct noc *prox;//ponteiro para o prox no
}Noc;
/*Estrutura que define o inicio da lista, em que no main vai ter uma variavel do tipo lista com um ponteiro
para o meu no*/
typedef struct{
    Noc *ini; //pont p/ primeiro no
    Noc * fim; //ponteiro p/ o final
    int tam; //tamanho lista, identificar qnd cheguei ao fim ou o prox e o inicio
}Listac;

/*Procedimento para inicializar o nosso tipo lista*/
void criarlistac(Listac *listac){//recebe ponteiro do tipo lista
    listac->ini = NULL;//acesso a estrutura lista e digo q o inicio e nulo
    listac->fim = NULL;//pont p/ fim
    listac->tam=0;// nao tem nenhum no tamanho e zero
}
//-------------- PROCEDIMENTO INSERCAO INICIO --------------------------------------------//
//Garantir q o final da nossa lista esta apontando p/ inicio

void insere_inicioc(Listac *listac, int num){//procedimento INICIO q recebe ponteiro tipo lista, e num q eh o elemento que quero inserir
  Noc *novo = malloc(sizeof(Noc));//aloco novo no
 //se alocacao for feita com sucesso preencho o novo no
  if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
	 novo->valor = num;//insere numero no csmpo de valor do no
     novo->prox = listac->ini;// o proximo do novo no tem q apontar p/ inicio da lista
     listac->ini = novo; //faco a lista recber novo no
     if(listac->fim == NULL)
        listac->fim = novo;//fim aponta p/ novo no
     //atualizo o fim
     listac->fim->prox = listac->ini;//ultimo no possui pont prox p/ inicio, acesso esse ponteiro de prox,entao lista->fim-> aponta pro final da lista
     listac->tam++;//incrementa tamanho da lista
     }
  else
	  printf("\n\nErro ao alocar memoria..\n\n");
}
//--------------INSERCAO FIM --------------------------------------------//
void insere_fimc(Listac *listac, int num){//procedimento FIM q recebe ponteiro tipo lista, e num q eh o elemento que quero inserir
    Noc *aux, *novo = malloc(sizeof(Noc));//aloco novo no e to criando ponteiro auxiliar

    if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
        novo->valor = num;//o conteudo do novo no e o numero q quero inserir
    //VAZIA-- descobrindo se a lista esta vazia?
    if(listac->ini == NULL){//significa q a lista esta sebdo inserido o primeiro no da lista
        listac->ini = novo; // aponta novo no
        listac->fim = novo; // aponta novo no
        listac->fim->prox = listac->ini;//o fim aponta p/ inicio, acesso o ultimo no da lista q temponteiro p/ proximo
    }   //aq ja sei o final da lista
    //CHEIA---se nao, se nao esta vazia
    else{
        listac->fim->prox = novo;//atualizar o fim, aponta p/ novo que e o ultimo no da lista
        listac->fim = novo;// fim da lista eh o novo no
        //listac->fim->prox = listac->ini; //faco a lista aponta p/ inicio dnv
        novo->prox = listac->ini;//novo no eh o fim da lista
      }
      listac->tam++;//incremento pro if vazia e para if cheia
      //se nao esta nem cheia nem vazia a lista nao e valida , logica  no alocado errado
      }else
            printf("\n\nErro ao alocar memoria..\n\n");
}

// ---------------------- FUNCAO REMOVER ---------------------------------------------
//retorno ponteiro para o no e recebo pon p/ tipo lista e o valor q quero  remover
//remover no e retornar o ponteiro p/ esse no
Noc *removLic(Listac *listac, int num){//num eh o elemento q quero remover
    Noc *aux, *remover = NULL;//inializo remover como nulo
    //1° teste= verificar lista vazia
    if(listac->ini){/*se eh diferente de null*/
        //verifico se inicio eh igual a fim, pq se tem um no so tem q altera o ponteiro p/ fim e pro inicio
        //if exclusivo para quando exista so 1 No
        if(listac->ini == listac->fim &&listac->ini->valor == num){//uso o listac poq os dois sao iguais na condicao, Num eh o que quero remover
            remover = listac->ini;//removo o unico no
            listac->ini = NULL;
            listac->fim = NULL;
            listac->tam--;//devcremento o no

        //ELSE  IF para inicio e diferente de fim, MAIS DE UM NÓ
        //Caso eu queira remover o 1° NO
        }else if(listac->ini->valor == num){
            remover = listac->ini;//removo o unico no
            listac->ini = remover->prox;//alterei o inicio da lista
            listac->fim->prox = listac->ini;//o fim aponta pro inicio agora
            //finalizei acima os 2 ponteiros estao emendados ja
            listac->tam--;//devcremento o no
        }
        // OU O ELEMENTO ESTA NO MEIO OU ELE ESTA NO FINAL
        else {/*condicao para lista nao esta vazia e o elemento na ta no 1° no*/
            aux = listac->ini;//ponteiro p/ inicio da lista
            //verifico se existe prox no e se o valor do prox no e fifernte do que quero remover
            while(aux->prox != listac->ini && aux->prox->valor != num)//enquanto prox e diferente d einicio para n entra em loop, e enquanto valor e diferente do numero q eu digitei
                aux = aux->prox;//percorro a lista
            if(aux->prox->valor == num){//achei no que quero remover
                //no prox pode estar no meio ou no fim da lista
                if(listac->fim == aux->prox){//se um ponteiro e igual a outro ponteiro
                    remover = aux->prox;
                    aux->prox = remover->prox; //aux aponta p/ no seguinte, pois e lista circular
                    listac->fim = aux;   //atualizo o fim
                }
                //ESSE ELSE FAZ A REMOCAO NO MEIO, PARA ISSO BASTA CONECTAR OS PONTEIROS
                else{//quando o fim do if nao for igual ao no que uero remover
                    remover = aux->prox;//remover recebe o elemnto q quero remover
                    aux->prox = remover->prox; //aux aponta para o no seguinte
                }
                listac->tam--;//devcremento da lista
            }
        }
    }
    return remover; //return no ponteiro, retorno o valor nulo
}



// --------------------------------------- IMPRIMIR -------------------------------------------------------
void imprimec(Listac listac){//elemento lista/ copia da lista
    Noc *noc = listac.ini;//elemento da struct usa ponto, no aponta p/ inicio da fila
  printf("\n..............................  LISTA  tam: %d:..............................\n",listac.tam);//vem do elemento lista.tam
  if(noc){//enquanto no for diferente de nulo
        do{
            printf("%d ",noc->valor);//imprime valor do no
            noc = noc->prox; //para nao haver loop, quando chegar em nulo vai parar

        }while(noc != listac.ini);//caminho ate o ponteiro nao ser nulo
        printf("\n\n(Inicio: %d)", noc->valor);//comprovo qq voltei p/ inicio da lista
  }
  printf("\n\n.............................. LISTA tam: %d..............................\n",listac.tam);
}

//--------------MAIN --------------------------------------------//


int mainlista_Enc_Circ(){

    int op, valor,ant;
    Listac listac;//variavel do tipo lista chamada lista, nao e ponteiuro
    criarlistac(&listac);//procedimenro q diz q o lista.inicio e nulo e o lista.tam e  zero
    Noc *removido;
    do{
        printf("\n\n1 - Insercao - Inicio\n2 - Insere - Fim\n3 - Remover\n4 - Exibir\n5 - Voltar ao menu principal\n\n");
        scanf("%d",&op);
        //getchar();//limpo o buffer teclado, ele que diz q o topo e null e o tamanho e zero
    switch(op){
    case 1:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        insere_inicioc(&listac, valor);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na lista
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
      case 2:
            system("cls");//limpa a tela
            printf("\n\tDigite um valor:\n");
            scanf("%d",&valor);
            insere_fimc(&listac, valor);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
            //valor que quero inserir na lista
            printf("\n\n\t\tElemento inserido com sucess!\n\n");
            break;

        case 3:
            system("cls");//limpa a tela
            printf("\n\tDigite um valor:\n");
            scanf("%d",&valor);
            printf("\n\n\t\tRemovendo elemento..\n\n");
            system("pause");//pausa, pede para clicar em qualquer lugar tela
            removido = removLic(&listac,valor); //endereco lista e conteudo a ser reovido
            if(removido){
                printf("\n\n\t\tElemento [%d] removido com sucess!\n\n", removido->valor);
                free(removido);
            }
            else
                printf("\n\n\t\tElemento inesistente!\n");
            break;
        case 4:
            system("cls");//limpa a tela
            system("pause");//pausa, pede para clicar em qualquer lugar tela
            printf("\n\n\t\tExibindo elementos..\n\n");
            imprimec(listac);/*envio o elemento lista*/
            break;
        case 5:
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
        }while(op != 0);//enquanto diferente de 0 o usuario quer fazer algo
        return 0;//retorno a opcao

    }








