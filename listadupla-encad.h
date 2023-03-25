#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
//LISTA DUPLAMENTE ENCADEADA:  cada elemento tem um ponteiro para o próximo elemento e
//um ponteiro para o elemento anterior, nela existe null


#endif // LISTA_H_INCLUDED
/*No pro inicio da lista*/
typedef struct noe{
  int valor;
  struct noe *prox;//ponteiro para o prox no
  struct noe *ant;//ponteiro para o no anterior
}Noe;

//-------------- PROCEDIMENTO INSERCAO INICIO --------------------------------------------//
void insere_inicioe(Noe **listae, int num){//ponteiro p/ incio da lista e elemnto q vou inserir
  Noe *novo = malloc(sizeof(Noe));//aloco novo no

  if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
	 //QUANDO N TEM NINGUEM NA LISYTA
	 novo->valor = num;//valor do novo no eh o elemnto  quero inserir
     novo->prox = *listae;// o proximo eh o inicio da lista
     novo->ant = NULL;//ponteiro p manter atualizado, q eh o anterior, o 1° NO DA LISTA N TEM NINGUEM ANTES DELE

     //QUANDO TIVER ALGUEM NA LISTA
     if(*listae)//se o conteudo da lista eh diferente de null
        //acesso o 1° no que tem o anterior e ele aponta pro novo no:
        (*listae)->ant = novo;//linko o inicio da lista apontando o anterior para o novo no
    *listae = novo;//altero o inicio da lista, inicio eh o novo no
    }
  else
	  printf("\n\nErro ao alocar memoria..\n\n");
}
//--------------INSERCAO FIM --------------------------------------------//
void insere_fime(Noe **listae, int num){//procedimento FIM q recebe ponteiro tipo lista, e num q eh o elemento que quero inserir
    Noe *aux, *novo = malloc(sizeof(Noe));//aloco novo no e to criando ponteiro auxiliar

    if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
        novo->valor = num;//preencho o conteuro
        novo->prox = NULL;// como a insercao e no final vou dizer q o proximo no e nulo

    //VAZIA-- descobrindo se a lista esta vazia?
    if(*listae == NULL){//significa q a lista esta vazia
        *listae = novo; // esse eh o 1° no da lista, signifca q eh o unico no da lista
        novo->ant = NULL;//eh nulo porq eh o unico no da lista ate o momento
    }
    //EXISTE ALGUEM NA LISTA
    else{
        aux = *listae;//aux aponta p/ inicio
        while(aux->prox)//caminho ate o final enquanto diferente de nulo
            aux = aux->prox;//caminha p/ proximo
        aux->prox = novo;//quando o teste for falso nao existe o prox, encontrei a posicao para inserir novo no
        novo->ant = aux;//descobri quem eh o anterior
        //linko os nos
      }

      //se nao esta nem cheia nem vazia a lista nao e valida , logica  no alocado errado
      }else
            printf("\n\nErro ao alocar memoria..\n\n");
}
//--------------INSERCAO MEIO --------------------------------------------//
/*recebe 3 parametros, insercao feita apos o valor de referencia, se n existir e feita no final*/
void insere_meioe(Noe **listae, int num, int refe){// ponteiro tipo lista, e num q eh o elemento que quero inserir, e refe para referencia
    Noe *aux, *novo = malloc(sizeof(Noe));//aloco novo no e to criando ponteiro auxiliar

    if(novo){// se novo for diferente de nulo , so de estar no if faz a verificacao
        novo->valor = num;//preenche campo valor , ate o momento nao sei que e meu proximo

    //VAZIA-- descobrindo se a lista esta vazia?
    if(*listae == NULL){//se a lista esta vazia
        novo->prox = NULL;//sabemos q o prox eh nulo
        novo->ant = NULL;//tanto o prox como o anterior eh null
        *listae = novo;//lista->inicio e o novo no q acabei de preencher
    }
    //ELSE PARA A LISTA CHEIA
    else{
        aux = *listae;//aux aponta p/ inicio
        while(aux->valor != refe && aux->prox)//enquanto aux->valor for diferente do elemento procurado e aux->prox diferente de nulo(se existe um proximo?)
            aux = aux->prox;//caminha p/ proximo
        novo->prox = aux->prox;//neste caso recebe o aux->prox q ou sera nulo ou sera o proximo no apos o elemnto que entao sera o no anterior
        if(aux->prox)//so faco se existir proximo no
            aux->prox->ant = novo;//linkagem do proximo no com o anterior
        novo->ant = aux;//mantenho a lista ligada
        aux->prox = novo;//o proximo aponta para p no atual
      }
      //lista->tam++;//indepemndente da insercao ser na lista vazia ou nao ja estou incrementando para as duas
      //se nao esta nem cheia nem vazia a lista nao e valida , logica  no alocado errado
      }else
            printf("\n\nErro ao alocar memoria..\n\n");
}
// ---------------------- REMOVER ---------------------------------------------
//retorno ponteiro para o no e recebo pon p/ tipo lista e o valor q quero  remover
//remover no e retornar o ponteiro p/ esse no
Noe *removLie(Noe **listae, int num){
    Noe *aux, *remover = NULL;//inializo remover como nulo
    //1° teste= verificar lista vazia
    if(*listae){/*se eh diferente de null*/
     //REMOVENDO O 1° NO DA LISTA
        if((*listae)->valor == num){//
            remover = *listae; //remover aponta pro ponteiro p/ 1° No
            //altero o inicio da minha lista e digo q o prox
            *listae = remover->prox; //atualizo o 1° No
            //teste caso a lista tenha um unico no p/ remover
            if(*listae)
                (*listae)->ant = NULL;//atualizo o ponteiro anterior
        }


        else{//ELSE LISTA COM MAIS NOS
            aux = *listae;//ponteiro p/ inicio da lista
            //verifico se existe prox no e se o valor do prox no e fifernte do que quero remover
            while(aux->prox && aux->prox->valor != num)//eh diferente de null
                aux = aux->prox;//percorro a lista
                //teste para saber se achou o numero:
                //a repeticao quebra se nao for encontrado o valor, ou se valor for igual a num
            //EXECUTA QUANDO QUEBRA A REPETICAO
            if(aux->prox){// se e diferente de nulo
                remover = aux->prox;//remover aponta pro no q quero remover
                aux->prox = remover->prox;//atualizar o proximo do no aux, digo que o prox do aux eh o que vem em seguida depois do no q quero remover. liguei os dois
                //ou ele e nulo ou tem anterior , entao vou fazer:
                if(aux->prox)//exite?Se o no proximo nao for nulo, preciso atualizar o anterior dele
                //se existe nao aponta mais para o no remover
                    aux->prox->ant = aux;//novo anterior aux
            }
        }
    }
    return remover; //return no ponteiro, retorno o valor nulo
}



// --------------------------------------- IMPRIMIR -------------------------------------------------------
void imprimee(Noe *noe){//elemento lista/ copia da lista
  printf("\n..............................  LISTA ..............................\n");//vem do elemento lista.tam
  while(noe){//enquanto no for diferente de nulo
        printf("%d ",noe->valor);//imprime valor do no
        noe = noe->prox; //para nao haver loop, quando chegar em nulo vai parar
  }
  printf("\n.............................. LISTA ..............................\n");
}
Noe* ultimo(Noe **listae)
{//ponteiro p lista
    Noe *aux = *listae ;//no aux q recebe o inicio da lista
    while(aux->prox)//eh diferente de nulo
        aux = aux->prox;
    return aux ;
}
void imprimirContr(Noe *noe){//ponteiro p/ final da lista
      printf("\n..............................  LISTA ORDEM ANTERIOR ..............................\n");//vem do elemento lista.tam
  while(noe){//enquanto no for diferente de nulo
        printf("%d ",noe->valor);//imprime valor do no
        noe = noe->ant; //para nao haver loop, quando chegar em nulo vai parar
  }
  printf("\n.............................. LISTA ORDEM ANTERIOR..............................\n");
}
//--------------MAIN --------------------------------------------//


int mainlista_DuplaEn(){

    int op, valor, ant;
    Noe *removido, *listae = NULL;
    do{
        printf("\n\n1 - Insercao - Inicio\n2 - Insercao - Meio \n3 - Insere - Fim\n4 - Remover\n5 - Exibir\n6 - Exibir ao contrario\n7 - Voltar ao menu principal\n\n");
        scanf("%d",&op);
        //getchar();//limpo o buffer teclado, ele que diz q o topo e null e o tamanho e zero
    switch(op){
    case 1:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        insere_inicioe(&listae, valor);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na lista
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
     case 2:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor para insercao e valor de referencia anterior:\n");
        scanf("%d%d",&valor,&ant);
        insere_meioe(&listae, valor, ant);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
      case 3:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        insere_fime(&listae, valor);//por ser ponteiro p ponteiro eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na lista
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;

    case 4:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        printf("\n\n\t\tRemovendo elemento..\n\n");
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        removido = removLie(&listae,valor); //endereco lista e conteudo a ser reovido
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
        imprimee(listae);/*envio o elemento lista*/
        break;

    case 6:
        system("cls");//limpa a tela
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        printf("\n\n\t\tExibindo elementos..\n\n");
        imprimirContr(ultimo(&listae));
        break;

    case 7:
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








