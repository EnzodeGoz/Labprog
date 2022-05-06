#include <stdio.h>
#include <stdlib.h>
/* Código desenvolvido em 29/04/2022 pelo aluno Enzo de Góz Pereira de matrícula 202110644 para a Atividade de Produção U2 da disciplina de Laboratório de Programação
do curso de Análise e Desenvolvimento de Sistemas da Universidade La Salle.
Link replit: https://replit.com/@ENZODE12/Gerenciadorcompras#main.c
*/
// Declaração das variáveis e ponteiros goblais usados para armazenar dinâmicamente o número de itens dos ponteiros de vetores de structs.
int m,*ptr, n, *ptrn;
//Declaração dos structs e dos seus respectivos ponteiros para o estoque e o carrinho de compras
struct produto
{
    int codigo;
    char nome_produto[100];
    int quantidade;
    float preco;
} item, *ptritem, carr, *ptrcarr;

// Função utilizada no main como o print do menu da interface com o usuário
int print_menu(){
    printf("\nEscolha uma das opções no menu abaixo:\n");
    printf("1) Gerenciar o estoque\n2) Exibir a vitrine\n3) Carrinho de compras\n4) Sair\n");
    printf(">");
}
/* Função estoque utilizada para realizar o print do ponteiro onde está armazenado o estoque
    Recebe como parâmetros o ponteiro do struct, armazenado o estoque, e o ponteiro inteiro com o numero total de itens do estoque
    Retorna 1 ou 0 para a função estoque_acervo. 1 Caso não tenha nenhum item no ponteiro e o estoque esteja vazio e 0 caso haja itens no estoque
*/
int estoque(struct produto* ptritem, int *n){
    if (n == 0){
    return 1;
    }
    else if ((ptritem+1)->quantidade != 0)
    {
    puts("|======================|");
    printf("        ESTOQUE\n");
    puts("|======================|");
    printf("CÓDIGO | NOME DO PRODUTO | QUANTIDADE | PREÇO\n");
    for(int i=0;i<(int)n;i++) {
    printf("%i          %-10s       %-10i   R$%.2f\n",(ptritem+i)->codigo,(ptritem+i)->nome_produto, (ptritem+i)->quantidade, (ptritem+i)->preco);
    } 
    return 0;
    }
}
/* Função estoque_acervo utilizada pelo menu_estoque para saber se a função estoque está vazia ou com produtos
    Caso o estoque esteja vazio a função retorna 0 ou retorna 1 caso esteja com produtos
    Chama a função estoque e guarda na variável int "k" o valor retornado pela função estoque
*/
int estoque_acervo(){
    int k = 0;
    k = estoque(ptritem, ptr);
    if (k == 1){
    return 0;
    }
    else {
    return 1;
     }
}
/*  Função addestoque chamada no menu_estoque adiciona itens ao ponteiro do estoque e envia para a função estoque
    Utiliza de um switch como interface com o usuário para registrar dinamicamente na memória do ponteiro do vetor de struct
    1 para alocar na memória do ponteiro struct um novo vetor e 2 para adicionar mais vetores na memória existente do ponteiro struct
    Também define o valor do ponteiro inteiro para o total de itens do estoque
*/
int addestoque(){
    int q = 0;
    printf("Deseja criar uma nova lista de produtos ou adicionar mais produtos a lista existente?\n");
    printf("1)Criar nova lista\n2)Adicionar novos produtos a lista existente\n3)Sair\n>");
    scanf("%d", &q);
    switch(q){
        int o, p;
        int i;
        case 1:
            printf("Adicione o número de produtos:\n>");
            scanf("%d", &ptr);
            ptritem = (struct produto *) malloc((int)ptr * sizeof(struct produto));
                for(i=0;i<(int)ptr;i++){
                    printf("O código do produto %i:\n>", i);
                    scanf("%i", &(ptritem+i)->codigo);
                    printf("O nome do produto %i:\n>", i);
                    scanf("%s", &(ptritem+i)->nome_produto);
                    printf("A quantidade do produto %i:\n>", i);
                    scanf("%i", &(ptritem+i)->quantidade);
                    printf("O preço, em reais, do produto %i:\n>", i);
                    scanf("%f", &(ptritem+i)->preco);
                }
                system("clear");
                estoque(ptritem,ptr);
        break;
        case 2:
            system("clear");
            estoque(ptritem, ptr);
            printf("Deseja adicionar quantos novos produtos?\n>");
            scanf("%i", &o);
            ptritem = (struct produto *) realloc(ptritem, o + 1 * sizeof(struct produto));
            p = (int)ptr + o;
            for(i = p - o;i<p;i++){
                    printf("O código do produto %i:\n>", i);
                    scanf("%i", &(ptritem+i)->codigo);
                    printf("O nome do produto %i:\n>", i);
                    scanf("%s", &(ptritem+i)->nome_produto);
                    printf("A quantidade do produto %i:\n>", i);
                    scanf("%i", &(ptritem+i)->quantidade);
                    printf("O preço, em reais, do produto %i:\n>", i);
                    scanf("%f", &(ptritem+i)->preco);
                }
            system("clear");
            ptr = (int *)p;
            estoque(ptritem, ptr);
        break;
        case 3:
            system("clear");
            printf("Sair foi escolhido.\n");
        break;
        default:
            system("clear");
            puts("|======================================|");
            printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
            puts("|======================================|\n");
        break;
    }
    
    return 0;
}
/* Função delestoque chamada pela função pedido tem como parâmetros o elemento código do produto e a quantidade a ser removida, ambos como valores inteiros 
    Procura o vetor do ponteiro de struct que possui o mesmo código que o parâmetro k informado e subtrai o elemento quantidade do mesmo vetor através do parâmetro l
*/
int delestoque(int k, int l){
    int o;
    for(o = 0; o < (int)ptr; o++){
        if((ptritem + o)->codigo == k){
            (ptritem + o)->quantidade = (int)(ptritem + o)->quantidade - l;
        }
        else{
            printf("Procurando produto...%i\n", o);
        }
        
    }
    
    return 0;
}
/* Função altestoque utilizada na função menu_estoque usada para sobrescrever todos os elementos de um dos vetores do ponteiro de struct
    Chama a função estoque com os parâmetros dos ponteiros globais de struct e de número de itens do ponteiro struct, respectivamente
    Solicita ao usuário o código do produto que deseja alterar e o procura através do loop for com if
*/
int altestoque(){
    int u;
    int t = 0;
    printf("Esse é o estoque atual:\n");
    estoque(ptritem, ptr);
    printf("Qual o código do item que deseja alterar?\n>");
    scanf("%i", &u);
    for(t = 0; t < (int)ptr; t++){
        if((ptritem + t)->codigo == u){
            printf("Novo código:\n>");
            scanf("%i", &(ptritem+t)->codigo);
            printf("Novo nome:\n>");
            scanf("%s", &(ptritem+t)->nome_produto);
            printf("Nova quantidade:\n>");
            scanf("%i", &(ptritem+t)->quantidade);
            printf("Novo preço:\n>");
            scanf("%f", &(ptritem+t)->preco);
            system("clear");
            printf("Item alterado.\n");
        }
        else{
            printf("Procurando produto...%i\n", t);
        }
        
    }
    return 0;
}
/* Função menu_estoque providencia a interface com o usuário do estoque. 
    Chama a função estoque_acervo para saber se o estoque está vazio ou não
    Caso não esteja, chama a função estoque com os ponteiros globais de struct e de número de itens
*/
int menu_estoque(){
    int k;
    k = estoque_acervo();
    if (k == 0){
        printf("O estoque está vazio.\n");
        printf("Deseja cadastrar produtos no estoque?\n");
        printf("1) Sim\n2) Sair\n>");
        int esc01 = 0;
        scanf("%d", &esc01);
        switch (esc01) {
            case 1:
                system("clear");
                addestoque();
                break;
            case 2:
                system("clear");
                printf("Sair foi escolhido.\n");
                break;
            default:
            system("clear");
            puts("|======================================|");
            printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
            puts("|======================================|\n");
        }
    }
    else if(k ==  1){
        system("clear");
        printf("Esse é o estoque atual:\n");
        estoque(ptritem, ptr);  
        printf("\nDeseja adicionar ou alterar a quantidade de um produto do estoque?\n");
        printf("1) Adicionar um produto\n2) Alterar um produto\n3) Sair\n>");
        int esc001 = 0;
        scanf("%d", &esc001);
        switch(esc001){
            case 1:
                system("clear");
                addestoque();
                break;
            case 2:
                system("clear");
                altestoque();
                break;
            case 3:
                system("clear");
                printf("Sair foi escolhido.\n");
                break;
            default:
                system("clear");
                puts("|======================================|");
                printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
                puts("|======================================|\n");
        }
    }

    
}
/* Função vitrine chamada no main realiza um print dos elementos do ponteiro de vetor de struct de estoque similar a função estoque, mas com menos elementos no print
    Chama a função estoque_acervo para saber se o estoque está vazio ou não, realizando um print indicando que está vazio caso esteja.
*/
int vitrine(){
   
    int k = 0;
    k = estoque_acervo();
    system("clear");
    puts("|======================|");
    printf("        VITRINE\n");
    puts("|======================|");
    if (k == 0){
        printf("A vitrine está vazia.\nAdicione produtos no estoque.\n");
    }
    else if (k == 1){
        printf("NOME DO PRODUTO | PREÇO\n");
        for(int i=0;i<(int)ptr;i++) {
        printf(" %s                 R$%.2f\n",(ptritem+i)->nome_produto, (ptritem+i)->preco);
    } 
    }
    return 0;
}
/* Função carrinho_compras, similar a função estoque, realiza um print com todos os elementos dos vetores do ponteiro de struct
   Recebe como parâmetros um ponteiro de vetor de struct e um ponteiro inteiro com o número de itens no ponteiro strucut
   Retorna 0 caso não tenha nenhum item no ponteiro de sctruc ou 1, e consequentemente o print, caso tenha
   Chamada nas funções addcarrinho_compras e menu_carrinho_compras
*/
int carrinho_compras(struct produto* ptrcarr, int *m){
    if (m == 0){
    return 0;
    }
    else if(m != 0){
    system("clear");
    puts("|======================|");
    printf("        CARRINHO\n");
    puts("|======================|");
    printf("CÓDIGO | QUANTIDADE\n");
    for(int i=0;i<(int)m;i++) {
        printf("%i         %i\n",(ptrcarr+i)->codigo,(ptrcarr+i)->quantidade);
    } 
    return 1;
    }
}
/*  Função addcarrinho_compras similar a função addestoque, chamada na função menu_carrinho_compras
adiciona itens ao ponteiro do estoque e envia para a função estoque. Utiliza de switch como interface com o usuário
    Registra dinamicamente na memória dos ponteiros de struct e inteiro, como elementos e vetores e o número total de
itens, respectivamente
*/
int addcarrinho_compras(){
    int p, o;
    printf("Essa é a atual vitrine da loja:\n");
    vitrine();
    printf("\nQual o número de produtos que deseja adicionar?\n>");
    scanf("%d", &ptrn);
    ptrcarr = (struct produto *) malloc((int)ptrn * sizeof(struct produto));
        for(int i=0;i<(int)ptrn;i++){
            printf("\nO código do produto %i:\n>", i);
            scanf("%i", &p);
                for(int r = 0; r < (int)ptr; r++){
                    if((ptritem + r)->codigo == p){
                        printf("\nProduto encontrado.\n");
                        (ptrcarr + r)->codigo = p;
                        (ptrcarr + r)->preco = (ptritem + r)->preco; 
                        printf("A quantidade do produto %i:\n>", r);
                        scanf("%i", &o);
                            if((ptritem + r)->quantidade > o){
                                (ptrcarr + r)->quantidade = o;
                            }
                            else{
                                printf("Checando quantidade no estoque...%i\n", i);
                                printf("Estoque não suficiente.\nRefaça a lista.\n");
                            }
                    } 
                    else if ((ptritem + r)->codigo != p){
                        printf("\nProduto não encontrado.\nRefaça a lista.\n");
                    }

                    else {
                        printf("Procurando produto...%i\nProduto não encontrado...\n", r);
                    }
                }
            }
        system("clear");
        carrinho_compras(ptrcarr,ptrn);
    return 0;
}
/* Função pedido chamada na função menu_carrinho_compras, realiza o print do cálculo da compra dos elementos contidos no ponteiro de vetor carrinho
    Também chama a função delestoque para remover a quantidade comprada no carrinho, do estoque
*/
int pedido(){
    float resultado = 0;
    for (int i = 0; i<(int)ptrn; i++){
       resultado = resultado + (float)(ptrcarr + i)->quantidade * (float)(ptrcarr + i)->preco;
    } 
    for(int u = 0; u<(int)ptrn; u++){
        delestoque((int)(ptrcarr + u)->codigo,(int)(ptrcarr + u)->quantidade);
    }
    printf("\nO valor total do seu pedido é de: R$%.2f\n", resultado);
    printf("\nO estoque foi atualizado.\n\nCaso queira realizar uma nova compra, crie uma nova lista do carrinho de compras.\n");
    return 0;
}
/* Função menu_carrinho_compras realiza a interface com o usuário através de switchs e chama as outras funções 
    Chama a função carrinho_compras para determinar se o ponteiro de vetor de struct do carrinho de compras está vazio ou não
    Caso esteja vazio chama a função addcarrinho. Caso não esteja chama a função pedido e addcarrinho, para finalizar a compra ou aumentar os itens do carrinho
*/
int menu_carrinho_compras(){
    
    if (carrinho_compras(ptrcarr,ptrn) == 0){
        puts("|======================|");
        printf("  CARRINHO DE COMPRAS\n");
        puts("|======================|");
        printf("\nO seu carrinho de compras está vazio.\n\nDeseja adicionar itens ao seu carrinho de compras?\n");
        printf("1) Sim\n2) Sair\n>");
        int esc02 = 0;
        scanf("%d", &esc02);
        switch(esc02){
            case 1:
                system("clear");
                addcarrinho_compras();
                break;
            case 2:
                system("clear");
                printf("Sair foi escolhido.\n");
                break;
            default:
            system("clear");
            puts("|======================================|");
            printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
            puts("|======================================|\n");  
            break;
        }
    }
    else if (carrinho_compras(ptrcarr, ptrn) == 1){
        printf("Deseja finalizar a compra ou criar uma nova lista?\n");
        printf("1) Finalizar a compra\n2) Nova lista\n3) Sair\n>");
        int esc002 = 0;
        scanf("%d", &esc002);
        switch(esc002){
            case 1:
                system("clear");
                pedido();
                break;
            case 2:
                system("clear");
                addcarrinho_compras();
                break;
            case 3:
                system("clear");
                printf("Sair foi escolhido.\n");
                break;
            default:
                system("clear");
                puts("|======================================|");
                printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
                puts("|======================================|\n");
        }
    }
        
}
/* Função main onde é chamada a função print_menu e as depais funçoes de menus para interface com o usuário
    Onde estão atribuídos e enderaçados os ponteiros globais e inicialmente alocados os ponteiros de structs
    Funciona através de um loop do menu onde as funções menu_estoque; vitrine e menu_carrinho_compras são chamadas
*/
int main() {
ptritem = &item;
ptritem = (struct produto *) calloc(2,sizeof(struct produto));
ptr = &m;
ptr = 0;
ptrcarr = &carr;
ptrcarr = (struct produto *) calloc(2,sizeof(struct produto));
ptrn = &n;
ptrn = 0;
printf("Olá! Bem vindo ao programa de gerenciamento de compras.\n");
    for (int escolha = 0; escolha != 4; escolha = escolha) {
        print_menu();
        scanf("%d", &escolha);
        switch(escolha)
        {
        case 1:
            system("clear");
            menu_estoque();
            break;
        case 2:
            system("clear");     
            vitrine();
            break;
        case 3:
            system("clear");     
            menu_carrinho_compras();
            break;
        case 4:
            system("clear");
            puts("Sair foi escolhido.");
            break;
        default:
            system("clear");
            puts("|======================================|");
            printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
            puts("|======================================|\n");
        }
    }
return 0;
}

