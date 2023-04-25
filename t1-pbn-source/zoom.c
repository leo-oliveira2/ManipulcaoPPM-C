#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s dataGerada;
	struct image_s *imagem_gerada = &dataGerada; 
	
	int i, j, r;
	int controle  = 0 ;
	int aux = 0;

	r = read_ppm("lena.ppm", image);

	imagem_gerada->width = (image->width * 3); // Imagem de sáida possuí uma dimensão 3x maior.
	imagem_gerada->height = (image->height * 3); // Imagem de sáida possuí uma dimensão 3x maior.

	r = new_ppm(imagem_gerada, imagem_gerada->width, imagem_gerada->height); // Cria uma nova ppm, com o endereço de memória da "nova" imagem gerada e suas dimensões.

	if (r == 0)
	{
		//printf("width: %d, height: %d\n", image->width, image->height);
		for (j = 0; j < image->height; j++){
			for (i = 0; i < image->width; i++){	
				int pixelVerde = image->pix[j * image->width + i].g;
				if(pixelVerde > 0 && pixelVerde < 75){ // Todos Pixels Pretos 
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = 0;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].g = 0;
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].g = 0;
				}
				if (pixelVerde > 75  && pixelVerde < 135){ // Somente o do meio colorido
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = 0;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g; //Pixel Do Meio
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].g = 0;
				}
				if(pixelVerde > 135 && pixelVerde < 180){ // Somento o do meio preto
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].g = 0;  //Pixel do Meio
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
				}
				if(pixelVerde > 179 && pixelVerde < 256){ // Todos coloridos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g; 
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].g = image->pix[j * image->width + i].g;
				}

				int pixelVermelho = image->pix[j * image->width + i].r;
				if(pixelVermelho > 0 && pixelVermelho < 75){ // Todos Pixels Pretos 
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = 0;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].r = 0;
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].r = 0;
				}
				if (pixelVermelho > 75  && pixelVermelho < 135){ // Somente o do meio colorido
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = 0;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r; //Pixel Do Meio
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].r = 0;
				}
				if(pixelVermelho > 135 && pixelVermelho < 180){ // Somento o do meio preto
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].r = 0;  //Pixel do Meio
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
				}
				if(pixelVermelho > 179 && pixelVermelho < 256){ // Todos coloridos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r; 
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].r = image->pix[j * image->width + i].r;
				}
				int pixelAzul = image->pix[j * image->width + i].b;
				if(pixelAzul > 0 && pixelAzul < 75){ // Todos Pixels Pretos 
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = 0;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].b = 0;
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].b = 0;
				}
				if (pixelAzul > 75  && pixelAzul < 135){ // Somente o do meio colorido
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = 0;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b; //Pixel Do Meio
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].b = 0;
				}
				if(pixelAzul > 135 && pixelAzul < 180){ // Somento o do meio preto
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].b = 0;  //Pixel do Meio
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
				}
				if(pixelAzul > 179 && pixelAzul < 256){ // Todos coloridos
					imagem_gerada->pix[controle * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
					imagem_gerada->pix[(controle + 1) * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b; 
					imagem_gerada->pix[(controle + 2) * imagem_gerada->width + aux].b = image->pix[j * image->width + i].b;
				}

				aux = aux + 3; //Navegação 
			}
			controle = controle + 3; //Navegação 
			aux = 0;
		}
		
		write_ppm("lena_resultado.ppm", imagem_gerada);
		free_ppm(imagem_gerada);
	}

	return 0;
}
