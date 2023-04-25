#include <stdio.h>
#include "lib_ppm.h"

int main()
{

	/*
	TRABALHO 1 - PROGRAMACAO DE BAIXO NIVEL
	Giovanni Shardong e Leonardo Oliveira - Turma 11
	Professor Edson Moreno
	*/	
	struct image_s data;
	struct image_s dataGerada;
	struct image_s *image = &data;
	struct image_s *imagem_gerada = &dataGerada; // Struct para geracao da nova imagem

	int i, j, r;
	int controle = 0; // Utilizada para controle na navegação da matriz
	int aux = 0;	  // Utilizada para controle na navegação da matriz
	int balaio = 0;// Utilizada para controle na navegação da matriz

	r = read_ppm("lena.ppm", image);

	imagem_gerada->width = (image->width * 3);	 // Imagem de sáida possuí uma dimensão 3x maior.
	imagem_gerada->height = (image->height * 3); // Imagem de sáida possuí uma dimensão 3x maior.

	r = new_ppm(imagem_gerada, imagem_gerada->width, imagem_gerada->height); // Cria uma nova ppm, com o endereço de memória da "nova" imagem gerada e suas dimensões.

	if (r == 0)
	{
		// printf("width: %d, height: %d\n", image->width, image->height);
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				int pixelVerde = image->pix[j * image->width + i].g;
				int pixelAzul = image->pix[j * image->width + i].b;
				int pixelVermelho = image->pix[j * image->width + i].r;
				balaio = controle;

				// Verificações PIXEL VERDE (g)
				if (pixelVerde > 0 && pixelVerde < 75)
				{ // Todos Pixels Pretos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = 0;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = 0;
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = 0;
				}
				if (pixelVerde > 75 && pixelVerde < 135)
				{ // Somente o do meio colorido
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = 0;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g; // Pixel Do Meio
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = 0;
				}
				if (pixelVerde > 135 && pixelVerde < 180)
				{ // Somento o do meio preto
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = 0; // Pixel do Meio
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
				}
				if (pixelVerde > 179 && pixelVerde < 256)
				{ // Todos coloridos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
				}
				// Verificações PIXEL VERMELHO (r)
				if (pixelVermelho > 0 && pixelVermelho < 75)
				{ // Todos Pixels Pretos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = 0;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = 0;
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = 0;
				}
				if (pixelVermelho > 75 && pixelVermelho < 135)
				{ // Somente o do meio colorido
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = 0;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r; // Pixel Do Meio
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = 0;
				}
				if (pixelVermelho > 135 && pixelVermelho < 180)
				{ // Somento o do meio preto
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = 0; // Pixel do Meio
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
				}
				if (pixelVermelho > 179 && pixelVermelho < 256)
				{ // Todos coloridos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
				}
				// Verificações PIXEL AZUL (b)
				if (pixelAzul > 0 && pixelAzul < 75)
				{ // Todos Pixels Pretos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = 0;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = 0;
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = 0;
				}
				if (pixelAzul > 75 && pixelAzul < 135)
				{ // Somente o do meio colorido
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = 0;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b; // Pixel Do Meio
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = 0;
				}
				if (pixelAzul > 135 && pixelAzul < 180)
				{ // Somento o do meio preto
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = 0; // Pixel do Meio
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
				}
				if (pixelAzul > 179 && pixelAzul < 256)
				{ // Todos coloridos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
					balaio = controle + 1;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
					balaio = controle + 2;
					imagem_gerada->pix[balaio * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
				}

				aux = aux + 3; // Navegação
			}
			controle = controle + 3; // Navegação
			aux = 0;				 // Zera a Nevagação "Anterior"
		}

		write_ppm("lena_resultado.ppm", imagem_gerada); // gera o resultado da imagem gerada
		free_ppm(imagem_gerada);
	}

	return 0;
}
