#include <stdio.h>
#include <stdlib.h>
// foda-se tudo faz um novo branch e mete tudo em array ao inves de structure

struct produto
{
    int codigo;
    char nome_produto[100];
    int quantidade;
    float preco;
};


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
int estoque(struct produto* item, int n){
    system("clear");
    puts("|======================|");
    printf("        ESTOQUE\n");
    puts("|======================|");
    printf("CÓDIGO | NOME DO PRODUTO | QUANTIDADE | PREÇO\n");
    for(int i=0;i<n;i++) {
    printf("%i          %-10s       %-10i   R$%2.f\n",(item+i)->codigo,(item+i)->nome_produto, (item+i)->quantidade, (item+i)->preco);
    } 
    return 0;
}

int estoque_acervo(){
    return 0;
    system("clear");
     return 1;
}

int addestoque(){
    int q = 0;
    printf("Deseja criar uma nova lista de produtos ou adicionar mais produtos a lista existente?\n");
    printf("1)Criar nova lista\n2)Adicionar novos produtos a lista existente\n3)Sair\n");
    scanf("%d", &q);
    switch(q){
        case 1:
            int  i, n;
            printf("Adicione o número de produtos:\n>");
            scanf("%d", &n);
            // Talvez tenha que criar um objeto da struct e daí colocar o ponteiro para apontar no objeto
            struct produto *item;
            item = (struct produto *) malloc(n * sizeof(struct produto));
                for(i=0;i<n;i++){
                    printf("O código do item:\n>");
                    scanf("%i", &(item+i)->codigo);
                    printf("O nome do produto:\n>");
                    scanf("%s", &(item+i)->nome_produto);
                    printf("A quantidade:\n>");
                    scanf("%i", &(item+i)->quantidade);
                    printf("O preço, em reais:\n>");
                    scanf("%f", &(item+i)->preco);
                }
                system("clear");
                estoque(item,n);
        break;
        case 2:
        // fug :DDDD
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
    printf("Esse é o estoque atual:\n");
    return 0;
}

int menu_estoque(){
    puts("|======================|");
    printf("        ESTOQUE\n");
    puts("|======================|");
    if (estoque_acervo() == 0){
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
    else if(estoque_acervo() ==  1){
        printf("Esse é o estoque atual:\n");
        estoque_acervo();
        printf("\nDeseja adicionar ou remover um produto do estoque?\n");
        printf("1) Adicionar um produto\n2) Remover um produto\n3) Sair\n>");
        int esc001 = 0;
        scanf("%d", &esc001);
        switch(esc001){
            case 1:
                system("clear");
                addestoque();
                break;
            case 2:
                system("clear");
                delestoque();
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

int vitrine(){
    puts("|======================|");
    printf("        VITRINE\n");
    puts("|======================|");
    if (estoque_acervo() == 0){
        printf("A vitrine está vazia.\n");
    }
    else if (estoque_acervo() == 1){
        printf("Fudeu :DDDDD");
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

