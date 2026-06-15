#include <stdio.h>
#include <stdlib.h>

//função para exibir o tabuleiro
void tabuleiro(char casas[3][3]){
    printf("\n\tJOGO DA VELHA\n\n");
    printf("\t %c | %c | %c\n", casas[0][0], casas[0][1], casas[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", casas[1][0], casas[1][1], casas[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", casas[2][0], casas[2][1], casas[2][2]);
    printf("\n===========================\n");
}

int main()
{
    char casas[3][3];
    char resp;
    int cont_jogadas;
    int l, c;
    int vez;
    int i, j;
    
    do{
        //inicializa o tabuleiro vazio
        cont_jogadas = 1;
        vez = 0;
        
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                casas[i][j] = ' ';
            }
        }
        
        do {
            tabuleiro(casas);
            
            if(vez % 2 == 0){
                printf("\033[1;35m");
                printf("Jogador X\n");
                printf("\033[0m");
            } else {
                printf("\033[1;34m");
                printf("Jogador O\n");
                printf("\033[0m");
            }
            
            printf("Digite a linha (1-3): ");
            scanf("%d",&l);
            
            printf("Digite a coluna (1-3): ");
            scanf("%d",&c);
            
            
            
            
            if ((l<1 || l>3) || (c<1 || c>3)  || casas[l - 1][c - 1] != ' '){
                printf("Jogada inválida! Tente novamente.\n");
                continue;
            }
            
            //marcar a jogada com X ou O
            if (vez%2==0){
                casas[l - 1][c - 1]='X';
            } else{
                casas[l - 1][c - 1]='O';
            }
            
            vez++;
            cont_jogadas++;
            
            
            if ((casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X') ||
                (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X') ||
                (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X') ||
                (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X') ||
                (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X') ||
                (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X') ||
                (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X') ||
                (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X')) {
                
                tabuleiro(casas);
                
                printf("\tJogador X venceu!\n\n");
                break;
            }
            //verificar vitorias (O)
            if ((casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O') ||
                (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O') ||
                (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O') ||
                (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O') ||
                (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O') ||
                (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O') ||
                (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O') ||
                (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O')) {
                
                tabuleiro(casas);
                
                printf("\tJogador O venceu!\n\n");
                break;
            }
            
            //empate
            if(cont_jogadas>9){
                tabuleiro(casas);
                
                printf("\tJogo empatado!\n\n");
                break;
            }
            
        } while(1);
        
        printf("Deseja jogar novamente? [S/N]: ");
        scanf(" %c", &resp);
        
    } while(resp == 'S' || resp == 's');
    
    printf("Fim de jogo! Obrigado por jogar!\n");
    
    
    return 0;
}