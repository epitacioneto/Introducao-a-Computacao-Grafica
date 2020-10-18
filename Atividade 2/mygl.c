#include "mygl.h"

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

void PutPixel(int x, int y, Color *color){
    const unsigned int startPoint = x * 4 + y * IMAGE_WIDTH * 4;
    fb_ptr[startPoint] = color->red;
    fb_ptr[startPoint + 1] = color->green;
    fb_ptr[startPoint + 2] = color->blue;
    fb_ptr[startPoint + 3] = color->alpha;
}

void DrawLine(void) {
}

void DrawTriangle(int x1, int y1, Color *cor1, int x2, int y2, Color *cor2, int x3, int y3, Color *cor3){
    DrawLine(x1, y1, x2, y2, cor1, cor2);
    DrawLine(x2, y2, x3, y3, cor2, cor3);
    DrawLine(x3, y3, x1, y1, cor3, cor1);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
}
