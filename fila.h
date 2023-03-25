#ifndef FILA_H_INCLUDED //if not defined , se n tiver nenuma definicao de PILHA_H_INCLUDED faz oq ta dentro do if
#define FILA_H_INCLUDED//cria deficao,aaq dentro coloco assinatura das funcoes, constantes, estruturas



#endif // FILA_H_INCLUDED


typedef struct nof{
  int valor;
  struct nof *prox;//ponteiro para o prox no
}Nof;

typedef struct{
    Nof *ini; //pont p/ primeiro no
    Nof *fim; //pont p/ ultimo no
    int tam; //tamanho fila
}Fila;

void criarfila(Fila *fila){//endereco fila, e um pont pra fila
    fila->ini = NULL;//O  INICIO DA PILHA EH NULL
    fila->fim= NULL;
    fila->tam=0;// no inicio a fila tem nenhum no
}

void insereFila(Fila *fila, int num){//procedimento q recebe ponteiro tipo fila, e num q eh o elemento que quero inserir
  Nof *aux, *novo = malloc(sizeof(Nof));//crio no para o elemento e aloco memoria pro tipo no
  if(novo){//verifica se a memoria foi alocada corretamente, se novo for diferente de nulo , so de estar no if faz a verificacao
	 novo->valor = num;//valot do no eh o num que recebemos como parametro
     novo->prox = NULL;//o prox no e nulo pq a insercao e no final da fila
     //agora verificar se a fila esta vazia
     if(fila->ini == NULL){//se o 1° no for nulo a fila esta vazia
        fila->ini = novo;//se fila for null, fila->ini eh o nosso novo no
        fila->fim = novo;//aq o primeiro e ultimo sao mesmo no poq temos apenas umm no nesse momento
        //fila->tam++;
     }
     else{//condicao caso exista alguem na fila
        fila->fim->prox = novo;//faco o primeiro no apontar pro ultimo inserido qie ate o momento eh o 2° no, linkagem final da fila c/ novo no
        fila->fim=novo;//altero fim da fila
        //fila->tam++;//incremento pq acabei de inserir um no
    }
    fila->tam++ ;//uso aqui, independente de ser exe
  }
  else
	  printf("\n\nErro ao alocar memoria..\n\n");
}

Nof* removeFila(Fila *fila){//ponteiro  do tipo fila
    Nof *remover = NULL;//crio no  remover
	if(fila->ini){//se eh diferente de nulo tem alguem na fila
        remover = fila->ini;//remover recebe primeio no
        fila->ini = remover->prox; //se quero remover primeiro no recebe o prox
        fila->tam--;
	}else
        printf("\n\nOps! Fila vazia..\n\n");
    return remover; // funcao retorna o no que foi removido
}

void imprime(Fila *fila){//recbe ponteiro do tipo fila
    Nof *aux = fila->ini;//pont aux p/ primeiro no da fila
  printf("\n.............................. FILA ..............................\n");
  while(aux){//enquanto aux for diferente de nulo
        printf("%d ",aux->valor);//de onde vem o elemento
        aux = aux->prox; //para nao haver loop, quando chegar em nulo vai parar
  }
  printf("\n.............................. FILA ..............................\n");
}
int mainfila(){
    Fila fila;//elemento do tipo fila
    Nof *r;
    int op, valor;
    //criar fila faz fila.ini fila.fim fila.tam serem todos iguais a null
    criarfila(&fila);//procedimenro q pega o endereco do tipo fila
    do{
        printf("\n\n1 - Insercao\n2 - Remocao\n3 - Exibir\n4 - Voltar ao menu principal\n\n");
        scanf("%d",&op);
        //getchar();//limpo o buffer teclado, ele que diz q o topo e null e o tamanho e zero
    switch(op){
    case 1:
        system("cls");//limpa a tela
        printf("\n\tDigite um valor:\n");
        scanf("%d",&valor);
        insereFila(&fila, valor);//por ser ponteiro p ponteiro eu envio o endereco da fila, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na fila
        printf("\n\n\t\tElemento inserido com sucess!\n\n");
        break;
    case 2:
        system("cls");//limpa a tela
        printf("\n\n\t\tRemovendo elemento..\n\n");
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        r = removeFila(&fila); //no q recebe no removido, endereco da pilha
        //se tiver elemento e retornado o 1° no, se for vazia e retornado null
        if(r){//se r e diferente de nulo
            printf("\nElemento [%d] removido com sucesso!\n\n",r->valor);
            free(r);//libero memoria
        }
        else
            printf("\nNao existe no para remocao.\n");
        break;
    case 3:
        system("cls");//limpa a tela
        system("pause");//pausa, pede para clicar em qualquer lugar tela
        printf("\n\n\t\tExibindo elementos..\n\n");
        imprime(&fila);
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
    }while(op != 0);//enquanto diferente de 0 o usuario quer fazer algo
    return 0;//retorno a opcao

}





