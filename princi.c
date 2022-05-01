#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// foda-se tudo faz um novo branch e mete tudo em array ao inves de structure

int m,*ptr;
struct produto
{
    int codigo;
    char nome_produto[100];
    int quantidade;
    float preco;
} item, *ptritem;


int print_menu(){
    printf("\nEscolha uma das opções no menu abaixo:\n");
    printf("1) Gerenciar o estoque\n2) Exibir a vitrine\n3) Carrinho de compras\n4) Sair\n");
    printf(">");
}

int calculos(){
    
    return 0;
}

int pedido(){
/* 
 tem que fazer os calculos() e depois delestoque() a quantidade de itens | output:
 O valor total do seu pedido é de: R$2500,00
*/
    return 0;
}
int estoque(struct produto* ptritem, int *n){
    if (n == 0){
    return 1;
    }
    else if ((ptritem+1)->quantidade != 0)
    {
    //system("clear");
    puts("|======================|");
    printf("        ESTOQUE\n");
    puts("|======================|");
    printf("CÓDIGO | NOME DO PRODUTO | QUANTIDADE | PREÇO\n");
    for(int i=0;i<(int)n;i++) {
    printf("%i          %-10s       %-10i   R$%2.f\n",(ptritem+i)->codigo,(ptritem+i)->nome_produto, (ptritem+i)->quantidade, (ptritem+i)->preco);
    } 
    return 0;
    }
}

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
int delestoque(){
    // TALVEZ TENHA QUE TIRAR DO MENU_ESTOQUE, COLOCAR PARÂMETROS E COLOCAR NO CARRINHO_MENU()
    int m;
    int n;
    int o;
    printf("Qual o código do produto?\n>");
    scanf("%i", &n);
    printf("A quantidade que deseja remover do produto:\n>");
    scanf("%i",&m);
    for(o = 0; o < (int)ptr; o++){
        if((ptritem + o)->codigo == n){
            (ptritem + o)->quantidade = (int)(ptritem + o)->quantidade - m;
        }
        else{
            printf("Procurando produto...%i\n", o);
        }
        
    }
    
    return 0;
}
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
            printf("Item alterado.\n>");
        }
        else{
            printf("Procurando produto...%i\n", t);
        }
        
    }
    return 0;
}

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
        printf("\nDeseja adicionar, alterar ou remover a quantidade de um produto do estoque?\n");
        printf("1) Adicionar um produto\n2) Alterar um produto\n3) Remover quantidade\n4) Sair\n>");
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
                delestoque();
                break;
            case 4:
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
        printf(" %s                 R$%2.f\n",(ptritem+i)->nome_produto, (ptritem+i)->preco);
    } 
    }
    return 0;
}
int carrinho_compras(){
    return 0;
}

int addcarrinho_compras(){
    printf("Essa é a atual vitrine da loja:\n");
    vitrine();
    return 0;
}

int delcarrinho_compras(){
    printf("Esse é o seu carrinho de compras:\n");
    carrinho_compras();
    return 0;
}

int menu_carrinho_compras(){
    puts("|======================|");
    printf("  CARRINHO DE COMPRAS\n");
    puts("|======================|");
    if (carrinho_compras() == 0){
        printf("O seu carrinho de compras está vazio.\nDeseja adicionar itens ao seu carrinho de compras?\n");
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
    else if (carrinho_compras() == 1){
        printf("Esse é o seu carrinho de compras:\n");
        carrinho_compras();
        printf("Deseja finalizar a compra ou adicionar e remover itens?\n");
        printf("1) Finalizar a compra\n2) Adicionar um item\n3) Remover um item\n4) Sair\n>");
        int esc002 = 0;
        scanf("%d", &esc002);
        switch(esc002){
            case 1:
                pedido();
                break;
            case 2:
                addcarrinho_compras();
                break;
            case 3:
                delcarrinho_compras();
                break;
            case 4:
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

int main() {
ptritem = &item;
ptritem = (struct produto *) calloc(2,sizeof(struct produto));
ptr = &m;
ptr = 0;
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

