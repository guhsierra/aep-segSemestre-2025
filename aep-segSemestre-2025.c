#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define NUM_SINTOMAS 6

char *nomes_sintomas[NUM_SINTOMAS] = {
    "Febre",
    "Tosse Seca",
    "Coriza (Nariz escorrendo)",
    "Dor no corpo / Cansaco",
    "Dor de cabeca",
    "ALERTA: Falta de ar intensa / Dor no peito / Desmaio"
};
int sintomas_presentes[NUM_SINTOMAS] = {0, 0, 0, 0, 0, 0};

void imprimir_menu() {
	int i;
    printf("\n--- Selecione seus Sintomas ---\n");
    for (i = 0; i < NUM_SINTOMAS; i++) {
        printf("[%d] %s\n", i + 1, nomes_sintomas[i]);
    }
    printf("[0] FINALIZAR Selecao\n");
    printf("------------------------------\n");
}

void coletar_sintomas() {
    int escolha = -1;
    while (escolha != 0) {
        imprimir_menu();
        printf("Digite o numero do sintoma que voce sente (0 para finalizar): ");

        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n');
            escolha = -1;
            continue;
        }
        
        if (escolha >= 1 && escolha <= NUM_SINTOMAS) {
            int indice = escolha - 1;
            sintomas_presentes[indice] = 1;
            printf("Sintoma '%s' registrado!\n", nomes_sintomas[indice]);
        } else if (escolha == 0) {
            printf("\nFinalizando coleta de sintomas...\n");
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}
void triagem_principal() {
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("\n--- RESULTADO DA TRIAGEM ---\n");
    
    if (sintomas_presentes[5] == 1) {
        printf("ALERTA VERMELHO: EMERGENCIA!\n");
        printf("Sua vida ou a de terceiros pode estar em risco devido a falta de ar intensa, dor no peito ou sensacao de desmaio.\n");
        printf("RECOMENDACAO: Procure ATENDIMENTO MEDICO DE EMERGENCIA IMEDIATAMENTE (ligue para 192 ou dirija-se a um hospital).\n");
        return;
    }
    if (sintomas_presentes[0] == 1) { 
        if (sintomas_presentes[3] == 1 && sintomas_presentes[4] == 1) { 
            if (sintomas_presentes[1] == 1 || sintomas_presentes[2] == 1) { 
                printf("Condicao Sugerida: GRIPE (Influenza)\n");
                printf("RECOMENDACAO: Repouso, hidratacao intensa, alimentacao leve e medicacao para sintomas (analgesicos/antifebris).\n");
                printf("Se a febre persistir por mais de 3 dias ou a falta de ar piorar, procure uma unidade de saude.\n");
            } else {
                printf("Condicao Sugerida: VIROSE FORTE (Possivel Dengue ou virose sem sintomas respiratorios)\n");
                printf("RECOMENDACAO: Hidratacao rigorosa (muita agua e soro oral) e repouso absoluto. NUNCA tome medicacoes com AAS/Ibuprofeno sem orientacao medica (pode aumentar o risco de sangramento na dengue).\n");
                printf("Busque atendimento se surgirem manchas vermelhas, sangramentos ou dor abdominal intensa.\n");
            }

        } else {
             printf("Condicao Sugerida: INICIO DE VIROSE COMUM\n");
             printf("RECOMENDACAO: Monitore a temperatura, hidrate-se e descanse. Os sintomas devem melhorar em 48h.\n");
        }
    }
    else {        
        if (sintomas_presentes[2] == 1 || sintomas_presentes[1] == 1) {
            printf("Condicao Sugerida: RESFRIADO COMUM\n");
            printf("RECOMENDACAO: Hidratacao, gargarejo com agua e sal para dor de garganta, e repouso. E uma condicao autolimitada que deve passar em poucos dias.\n");
        }
        else if (sintomas_presentes[3] == 1 || sintomas_presentes[4] == 1) {
            printf("Condicao Sugerida: CANSACO/ESTRESSE/DESIDRATAÇÃO\n");
            printf("RECOMENDACAO: Aumente a ingestao de agua, durma bem e evite esforco fisico. Se os sintomas persistirem ou piorarem, consulte um medico.\n");
        }
        else {
             printf("Condicao Sugerida: BEM-ESTAR GERAL\n");
             printf("RECOMENDACAO: Voce nao selecionou sintomas relevantes. Continue com habitos saudaveis e monitore qualquer alteracao.\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Bem-vindo ao MedSys Mentor - Triagem de Sintomas.\n");
    printf("---------------------------------------------------\n");

    coletar_sintomas();

    triagem_principal();

    printf("\nObrigado por usar o MedSys Mentor. Este nao substitui um diagnostico medico.\n");


}
