#include <stdio.h>
#include <stdlib.h>
/* Vê se algumas funções não podem ser void() e https://www.daniweb.com/programming/software-development/threads/164292/menu-function-choose-with-switch-and-return-to-menu
 tentar consertar o bug caso o usuário inputa algo != int
*/
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

int estoque(){
    return 0;
}

int addestoque(){
    printf("Esse é o estoque atual:\n");
    return 1;
}

int delestoque(){
    printf("Esse é o estoque atual:\n");
    return 0;
}

int menu_estoque(){
    puts("|======================|");
    printf("        ESTOQUE\n");
    puts("|======================|");
    if (estoque() == 0){
        printf("O estoque está vazio.\n");
        printf("Deseja cadastrar produtos no estoque?\n");
        printf("1) Sim\n2) Sair\n>");
        int esc01 = 0;
        scanf("%d", &esc01);
        switch (esc01) {
            case 1:
                system("CLS");
                addestoque();
                break;
            case 2:
                system("CLS");
                printf("Sair foi escolhido.\n");
                break;
            default:
            system("CLS");
            puts("|======================================|");
            printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
            puts("|======================================|\n");
        }
    }
    else if(estoque() ==  1){
        printf("Esse é o estoque atual:\n");
        estoque();
        printf("\nDeseja adicionar ou remover um produto do estoque?\n");
        printf("1) Adicionar um produto\n2) Remover um produto\n3) Sair\n>");
        int esc001 = 0;
        scanf("%d", &esc001);
        switch(esc001){
            case 1:
                system("CLS");
                addestoque();
                break;
            case 2:
                system("CLS");
                delestoque();
                break;
            case 3:
                system("CLS");
                printf("Sair foi escolhido.\n");
                break;
            default:
                system("CLS");
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
    if (estoque() == 0){
        printf("A vitrine está vazia.\n");
    }
    else if (estoque() == 1){
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
                system("CLS");
                addcarrinho_compras();
                break;
            case 2:
                system("CLS");
                printf("Sair foi escolhido.\n");
                break;
            default:
            system("CLS");
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
                system("CLS");
                printf("Sair foi escolhido.\n");
                break;
            default:
                system("CLS");
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
            system("CLS");
            menu_estoque();
            break;
        case 2:
            system("CLS");     
            vitrine();
            break;
        case 3:
            system("CLS");     
            menu_carrinho_compras();
            break;
        case 4:
            puts("Sair foi escolhido.");
            break;
        default:
            system("CLS");
            puts("|======================================|");
            printf(" Comando inválido.\n Por favor insira uma escolha válida.\n");
            puts("|======================================|\n");
        }
    }
return 0;
}

