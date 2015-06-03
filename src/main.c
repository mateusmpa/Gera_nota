/*
 * main.c
 *
 *  Created on: Jun 2, 2015
 *      Author: mateusalves
 */

#include <stdio.h>

int main(void)
{
	char caminho_alunos[]="alunos.txt", caminho_avaliacao[]="avaliacao.txt", nome[10], sobrenome[10], aprovacao[20];
	int qtde_alunos, qtde_notas=3;
	float peso1, peso2, peso3, nota1, nota2, nota3, media_aprovacao, media;
	FILE *alunos, *avaliacao;

	alunos = fopen(caminho_alunos, "r");
	avaliacao = fopen(caminho_avaliacao, "w");
	if(alunos == NULL || avaliacao == NULL)
	    printf("Erro, não foi possível abrir o arquivo\n");
	else
		fscanf(alunos, "%d", &qtde_alunos);
		fscanf(alunos, "%d", &qtde_notas);
		fscanf(alunos, "%f %f %f", &peso1, &peso2, &peso3);
	    while( (fscanf(alunos, "%s %s %f %f %f\n", &nome, &sobrenome, &nota1, &nota2, &nota3)) != EOF ) {
	    	media = ((nota1*peso1)+(nota2*peso2)+(nota3*peso3))/qtde_notas;
	    	if(media >= media_aprovacao) {
	    		aprovacao = "Aprovado";
	    	}else {
	    		aprovacao = "Reprovado";
	    	}
	    	fprintf(avaliacao, "%s %s %.2f %s\n", nome, sobrenome, media, aprovacao);
	    }

        fclose(alunos);
        fclose(avaliacao);

        return 0;
}

//http://www.cprogressivo.net/2013/11/Como-ler-arquivos-em-C-As-funcoes-fgetc-fscanf-fgets.html
