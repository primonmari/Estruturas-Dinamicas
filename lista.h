#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//LISTA SIMPLESMENTE ENCADEADA: É simples, permite formar um encadeamento simples entre os elementos,
//onde cada elemento armazena um ponteiro que aponta para o  próximo elemento da lista, nao e recomendada para a retirada de elementos

#endif // LISTA_H_INCLUDED
/*No pro inicio da lista*/
typedef struct nol{
  int valor;
  struct nol *prox;//ponteiro para o prox no
}Nol;
/*Estrutura que define o inicio da lista, em que no main vai ter uma variavel do tipo lista com um ponteiro
para o meu no*/
typedef struct{
    Nol *ini; //pont p/ primeiro no
    int tam; //tamanho lista
}Lista;

/*Procedimento para inicializar o nosso tipo lista*/
void criarlista(Lista *lista){//recebe ponteiro do tipo lista
    lista->ini = NULL;//acesso a estrutura lista e digo q o inicio e nulo
    lista->tam=0;// nao tem nenhum no tamanho e zero
}
//-------------- PROCEDIMENTO INSERCAO INICIO --------------------------------------------//
void insere_inicio(Lista *lista, int num){//procedimento INICIO q recebe ponteiro tipo lista, e num q eh o elemento que quero inserir
  Nol *novo = malloc(sizeof(Nol));//aloco novo no

  if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
	 novo->valor = num;//insere numero no csmpo de valor do no
     novo->prox = lista->ini;// o proximo do novo no tem q apontar p/ inicio da lista
     lista->ini = novo; //faco a lista recber novo no
     lista->tam++;//incrementa tamanho da lista
     }
  else
	  printf("\n\nErro ao alocar memoria..\n\n");
}
//--------------INSERCAO FIM --------------------------------------------//
void insere_fim(Lista *lista, int num){//procedimento FIM q recebe ponteiro tipo lista, e num q eh o elemento que quero inserir
    Nol *aux, *novo = malloc(sizeof(Nol));//aloco novo no e to criando ponteiro auxiliar

    if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
        novo->valor = num;//insere numero no csmpo de valor do no
        novo->prox = NULL;// como a insercao e no final vou dizer q o proximo no e nulo

    //VAZIA-- descobrindo se a lista esta vazia?
    if(lista->ini == NULL){//significa q a lista esta vazia
        lista->ini = novo; // novo no q acabamos de criar
    }
    //CHEIA---se nao, se nao esta vazia
    else{
        aux = lista->ini;//aux aponta p/ inicio
        while(aux->prox)//enquanto diferente de nulo
            aux = aux->prox;//caminha p/ proximo
            aux->prox = novo;//quando prox for nulo entao o aux recebe o novo no
      }
      lista->tam++;//incremento pro if vazia e para if cheia
      //se nao esta nem cheia nem vazia a lista nao e valida , logica  no alocado errado
      }else
            printf("\n\nErro ao alocar memoria..\n\n");
}
//--------------INSERCAO MEIO --------------------------------------------//
/*recebe 3 parametros, insercao feita apos o valor de referencia, se n existir e feita no final*/
void insere_meio(Lista *lista, int num, int refe){// ponteiro tipo lista, e num q eh o elemento que quero inserir, e refe para referencia
    Nol *aux, *novo = malloc(sizeof(Nol));//aloco novo no e to criando ponteiro auxiliar

    if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
        novo->valor = num;//preenche campo valor , ate o momento nao sei que e meu proximo

    //VAZIA-- descobrindo se a lista esta vazia?
    if(lista->ini == NULL){//se a lista esta vazia
        novo->prox = NULL;//sabemos q o prox eh nulo
        lista->ini = novo;//lista->inicio e o novo no q acabei de preencher
    }
    //CHEIA---se nao, se nao esta vazia e percorro a lista
    else{
        aux = lista->ini;//aux aponta p/ inicio
        while(aux->valor != refe && aux->prox)//enquanto aux->valor for diferente do elemento procurado e aux->prox diferente de nulo
            aux = aux->prox;//caminha p/ proximo
        novo->prox = aux->prox;//neste caso recebe o aux->prox q ou sera nulo ou sera o proximo no apos o elemnto que entao sera o no anterior
        aux->prox = novo;//o proximo aponta para p no atual
      }
      lista->tam++;//indepemndente da insercao ser na lista vazia ou nao ja estou incrementando para as duas
      //se nao esta nem cheia nem vazia a lista nao e valida , logica  no alocado errado
      }else
            printf("\n\nErro ao alocar memoria..\n\n");
}
// ---------------------- REMOVER ---------------------------------------------
//retorno ponteiro para o no e recebo pon p/ tipo lista e o valor q quero  remover
//remover no e retornar o ponteiro p/ esse no
Nol *removLi(Lista *lista, int num){
    Nol *aux, *remover = NULL;//inializo remover como nulo
    //1° teste= verificar lista vazia
    if(lista->ini){/*se eh diferente de null*/
     //verifico se o elemento esta no 1° no da lista
        if(lista->ini->valor==num){//pego o valor/ conteudo do 1° no da lista e verifico se e igual a num q to procurando
            remover = lista->ini; //remover aponta pro inicio, ele e o ponteiro p/ no q quero remover
            //altero o inicio da minha lista e digo q o prox
            lista->ini = remover->prox; //recebe o no q esta depois do que eu quero remover
            lista->tam--;
        }
        else{/*condicao para lista nao esta vazia e o elemento na ta no 1° no*/
            aux = lista->ini;//ponteiro p/ inicio da lista
            //verifico se existe prox no e se o valor do prox no e fifernte do que quero remover
            while(aux->prox && aux->prox->valor != num)//eh diferente de null
                aux = aux->prox;//percorro a lista
                //teste para saber se achou o numero:
                //a repeticao quebra se nao for encontrado o valor, ou se valor for igual a num
            if(aux->prox){// se e diferente de nulo
                remover = aux->prox;//remover aponta pro no q quero remover
                aux->prox = remover->prox;//digo que o prox do aux eh o que vem em seguida depois do no q quero remover. liguei os dois
                lista->tam--;//repeti a instrucai porque abaixo nao ia da certo
            }
        }
    }
    return remover; //return no ponteiro, retorno o valor nulo
}



// --------------------------------------- IMPRIMIR -------------------------------------------------------
void imprimel(Lista lista){//elemento lista/ copia da lista
    Nol *nol = lista.ini;//elemento da struct usa ponto, no aponta p/ inicio da fila
  printf("\n..............................  LISTA  tam: %d:..............................\n",lista.tam);//vem do elemento lista.tam
  while(nol){//enquanto no for diferente de nulo
        printf("%d ",nol->valor);//imprime valor do no
        nol = nol->prox; //para nao haver loop, quando chegar em nulo vai parar
  }
  printf("\n.............................. LISTA tam: %d..............................\n",lista.tam);
}

//--------------MAIN --------------------------------------------//


int mainlista_Enc(){

    int op, valor,ant;
    Lista lista;//variavel do tipo lista chamada lista, nao e ponteiuro
    criarlista(&lista);//procedimenro q diz q o lista.inicio e nulo e o lista.tam e  zero
    Nol *removido;
    do{
        printf("\n\n1 - Insercao - Inicio\n2 - Insercao - Meio \n3 - Insere - Fim\n4 - Remover\n5 - Exibir\n6 - Voltar ao menu principal\n\n");
        scanf("%d",&op);
        //getchar();//limpo o buffer teclado, ele que diz q o topo e null e o tamanho e zero
    switch(op){
    case 1:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        insere_inicio(&lista, valor);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na lista
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
     case 2:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor para insercao e valor de referencia anterior:\n");
        scanf("%d%d",&valor,&ant);
        insere_meio(&lista, valor, ant);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
      case 3:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        insere_fim(&lista, valor);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na lista
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;

    case 4:
         system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        printf("\n\n\t\tRemovendo elemento..\n\n");
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        removido = removLi(&lista,valor); //endereco lista e conteudo a ser reovido
        if(removido){
            printf("\n\n\t\tElemento [%d] removido com sucess!\n\n", removido->valor);
            free(removido);
        }
        else
            printf("\n\n\t\tElemento inesistente!\n");
        break;


    case 5:
        system("cls");//limpa a tela
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        printf("\n\n\t\tExibindo elementos..\n\n");
        imprimel(lista);/*envio o elemento lista*/
        break;
    case 6:
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








