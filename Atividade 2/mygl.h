#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "core.h"

#define MODULO(x) ((x)>=0?(x):-(x)) 

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

typedef struct { 
    unsigned char red;    // defining color red
    unsigned char green;  // defining color green
    unsigned char blue;   // defining color blue
    unsigned char alpha;  // defining opacity alpha
} Color; 

void PutPixel(int x, int y, Color *);
void DrawLine(int, int, int, int, Color *, Color *);
void DrawTriangle(int, int, Color *, int, int, Color *, int, int, Color *);

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

#endif  // MYGL_H
