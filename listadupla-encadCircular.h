#ifndef LISTADUPLA-ENCADEADACIRCULAR_H_INCLUDED
#define LISTADUPLA-ENCADEADACIRCULAR
//LISTA DUPLAMENTE ENCADEADA:  cada elemento tem um ponteiro para o próximo elemento e
//um ponteiro para o elemento anterior, nela existe null


#endif // LISTADUPLA-ENCADEADACIRCULAR_H_INCLUDED


/*No pro inicio da lista*/
typedef struct no_dc {
    int val;
    struct no_dc *ante;
    struct no_dc *prox;
} No_dc;
//tipo lista
typedef struct List_dc {
    No_dc *ini;
    No_dc *fim;
    size_t tam;
} List_dc;
//criando meu no
No_dc *Cria_Noec(int val) {
    No_dc *novo = (No_dc*) calloc(1, sizeof(No_dc));
    novo->val = val;
    novo->ante = novo;
    novo->prox = novo;

    return novo;
}
//free pro meu no
void destruir_No_dec(List_dc **novo_ref) {
    No_dc *novo = *novo_ref;
    free(novo);
    *novo_ref = NULL;
}
//crio minha lista
List_dc *Cria_Lista_dec() {
    List_dc *il = (List_dc*) calloc(1, sizeof(List_dc));
    il->ini = NULL;
    il->fim = NULL;
    il->tam = 0;

    return il;
}
//para saber se minha lista ta vazia
int Vazia_list_dec(const List_dc *il) {
    return il->tam == 0;
}
//-------------- PROCEDIMENTO INSERCAO --------------------------------------------//
void insere_listdec(List_dc *il, int val) {
    No_dc *p = Cria_Noec(val);//val eh o valor  q quero inserir

    if (Vazia_list_dec(il)) {//se vazio e diferente de nulo
        //QUANDO N TEM NINGUEM NA LISYTA
        il->ini = p;//inico recebe p q e ponteiro do ponteiro do inicio
    }
    else {//QUANDO TIVER ALGUEM NA LISTA
        il->fim->prox = p;//prox recebe p
        p->ante = il->fim; //anterior ta ligado n inicio e recebe fim

        // terminando a parte circular
        il->ini->ante = p;//meu anteriot ta linado no inicio e recebe p
        p->prox = il->ini;//meu proximo entende que tem inicio
    }

    il->fim = p;//linko tudo
    il->tam++;
}

void imprime_lis_dc(const List_dc *il) {
    if (Vazia_list_dec(il)) {//condicao para se nao tem nada na lista

        printf("\n.............................. TAMANHO LISTA DUPLA ENC. CIRC: %lu ..............................\n\n\n" , il->tam);

        printf("\n.............................. TAMANHO LISTA DUPLA ENC. CIRC: %lu ..............................\n\n" , il->tam);
    }
    else {//ELSE: Para se houver valor na lista
        No_dc *p = il->ini;
        printf("\n.............................. TAMANHO LISTA DUPLA ENC. CIRC: %lu..............................\n\n" , il->tam);
        for (int i = 0; i < il->tam; i++) {
            printf("%d ", p->val);
            p = p->prox;
        }
        printf("\n\nInicio: %d", il->ini->val);
        printf("\nFim: %d\n", il->fim->val);
        printf("\n.............................. TAMANHO LISTA DUPLA ENC. CIRC: %lu..............................\n" , il->tam);
    }


}
// ---------------------- REMOVER ---------------------------------------------
//retorno ponteiro para o no e recebo pon p/ tipo lista e o valor q quero  remover
//remover no e retornar o ponteiro p/ esse no
int remover_lista_dc(List_dc *il, int val) {

    //------------ TA CHEIA OU VAZIA? -----------------------
    //VAZIA-- descobrindo se a lista esta vazia?
    if (!Vazia_list_dec(il)) {//pego a fmncao de vazia q recebe parametro li
        No_dc *p = il->ini;//ponteiro tipo no aponta pro inicio
        if (il->ini->val == val) {
            // Unico elemento lista
            if (il->ini == il->fim){ //comparo inicio e fim e digo q sao null
                il->ini = NULL;
                il->fim = NULL;
            }
            // mais de um elemento na lista
            else {
                il->ini = p->prox;//percorro o porximo
                il->ini->ante = il->fim;//anterior aponta p/ fim
                il->fim->prox = il->ini;//o proximo do fim aponta pro inicio
            }

            destruir_No_dec(&p);//chamo a funcao q faz o free
            il->tam--;//decremento 1

        }
        //--------------POSICOES ELEMENTOS--------------
        //******* Meu elemento esta no meio da lista
        else {
            p = p->prox;//percorro com o ponteiro do pontteiro do inicio o prox no

            while (p != il->ini) {//equanto inicio n e igual inicio quer dizer q n ta no inicio
                if (p->val == val) {//acho val

                    //**********o elemento está no final da lista
                    if (il->fim == p) {//se fim e igual inicio
                        il->fim = p->ante;//ini->fim recebe o anterior
                    }
                    p->ante->prox = p->prox;//linko anterior com o prox
                    p->prox->ante = p->ante;//prox recebe o q aponta pra lista anterior
                    destruir_No_dec(&p);//free no no
                    il->tam--;
                    break;
                }
                //se nao esta nem cheia nem vazia a lista nao e valida , logica  no alocado errado
                else {
                    //p = p->prox;
                    printf("\n\nErro ao alocar memoria..\n\n");
                }
            }
        }
    }
}
//--------------MAIN --------------------------------------------//
void Lista_Dup_Enc_C(){
    int op, val;
   // No_dc *Removl;
	List_dc *listadc = Cria_Lista_dec();
	do{
        printf("\n\n1 - Insercao\n2 - Remover\n3 - Exibir\n4 - Voltar ao menu principal\n\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                system("cls");//limpa a tela
                printf("\n\tDigite um valor:\n");
                scanf("%d",&val);
                insere_listdec(listadc, val);//eu envio o endereco da listaa, e ai envio o parametro que quero inserir q eh o
        //valor que quero inserir na lista
                printf("\n\n\t\tElemento inserido com sucess!\n\n");
                break;
            case 2:
                system("cls");//limpa a tela
                printf("\n\tDigite um valor para remocao:\n");
                scanf("%d",&val);
                printf("\n\n\t\tRemovendo elemento..\n\n");
                system("pause");//pausa, pede para clicar em qualquer lugar tela
                remover_lista_dc(listadc, val);
                //removl = remover_lista_dc(listadc, val);
/*
                if(removl){
                    printf("\n\n\t\tElemento removido com sucess!\n");
                }
                else{
                    printf("\n\n\t\tElemento inesistente!\n\n");
                }*/
                break;
            case 3:
                system("cls");//limpa a tela
                system("pause");//pausa, pede para clicar em qualquer lugar tela
                printf("\n\n\t\tExibindo elementos..\n\n");
                imprime_lis_dc(listadc);/*envio o elemento lista*/
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


