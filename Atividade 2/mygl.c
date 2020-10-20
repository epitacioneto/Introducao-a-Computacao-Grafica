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

void ApplyInterpolation(Color *corAtual, Color cor1, Color cor2, float dist){
    corAtual->red = (cor2.red*distancia) + ((1-distancia)*cor1.red);
    corAtual->green = (cor2.green*distancia) + ((1-distancia)*cor1.green);
    corAtual->blue = (cor2.blue*distancia) + ((1-distancia)*cor1.blue);
}

void DrawLine(void) {
	
	    int a;
    bool invdraw;

    bool changeColor = false;

    bool inv;


    if (x1 < x0){
        a = x0;
        x0 = x1;
        x1 = a;
        a = y0;
        y0 = y1;
        y1 = a;
        changeColor = true;
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    float Iter = 0.0;
    float dist = sqrt((dx*dx)+(dy*dy));
    Color colorRef;

    if (changeColor){
        colorRef.red = color2->red;
        colorRef.green = color2->green;
        colorRef.blue = color2->blue;
    }else{ 
        colorRef.red = color1->red;
        colorRef.green = color1->green;
        colorRef.blue = color1->blue;
    }
    colorRef.alpha = 255; // Alpha sempre em 255 para ter a maior visibilidade

    if (dx == 0){       
        inv = false;
        if (dy < 0){
            int a;
            a = y0;
            y0 = y1;
            y1 = a;
            inv = true;
        }
                   
        for (int i = y0; i < y1; i++){
            Iter += 1/dist;
            if (!changeColor && !inv)
                ApplyInterpolation(&colorRef, *color1, *color2, Iter);
            else
                ApplyInterpolation(&colorRef, *color2, *color1, Iter);
            PutPixel(x0, i, &colorRef);
        }
    }else if (dy == 0){ 
        if (dx < 0){
            int a;
            a = x0;
            x0 = x1;
            x1 = a;
        }
        
        for (int i = x0; i < x1; i++){
            Iter += 1/dist;
            if (!changeColor)
                ApplyInterpolation(&colorRef, *color1, *color2, Iter);
            else
                ApplyInterpolation(&colorRef, *color2, *color1, Iter);
            PutPixel(i, y0, &colorRef);
        }
    }else{

        if (MODULO(dy) > MODULO(dx)){ 
            invdraw = false;
            Iter += 1/dist;

            if (dy < 0){
                dy *= -1;

                invdraw = true;
            }
            
            int d = 2 * dx - dy;
            int incrE = 2 * dx;
            int incrNE = 2 * (dx - dy);

            int x = x0;
            int y = y0;
            
            PutPixel(x, y, &colorRef);

            if (invdraw){ 
                while (y > y1){
                    if (d <= 0){
                        d += incrE;
                        if (invdraw)
                            y--;
                        else
                            y++;
                    }
                    else{
                        d += incrNE;
                        if (invdraw)
                            y--;
                        else
                            y++;
                        x++;
                    }
                    Iter += 1/dist;
                    if (!changeColor)
                        ApplyInterpolation(&colorRef, *color1, *color2, Iter);
                    else
                        ApplyInterpolation(&colorRef, *color2, *color1, Iter);
                    PutPixel(x, y, &colorRef);
                }
            }else{                 
                while (y <= y1){
                    if (d <= 0){
                        d += incrE;
                        if (invdraw)
                            y--;
                        else
                            y++;
                    }
                    else{
                        d += incrNE;
                        if (invdraw)
                            y--;
                        else
                            y++;
                        x++;
                    }
                    Iter += 1/dist;
                    if (!changeColor)
                        ApplyInterpolation(&colorRef, *color1, *color2, Iter);
                    else
                        ApplyInterpolation(&colorRef, *color2, *color1, Iter);
                    PutPixel(x, y, &colorRef);
                }
            }

        } else{ 
            invdraw = false;
            Iter = 1/dist;

            if (dy < 0){
                dy *= -1;
                invdraw = true;
            }

            int d = 2 * dy - dx; // d inicial
            int incrE = 2 * dy;
            int incrNE = 2 * (dy - dx);

            int x = x0;
            int y = y0;

            PutPixel(x, y, &colorRef);

            while (x <= x1){
                if (d <= 0){
                    d += incrE;
                    x++;
                }
                else{
                    d += incrNE;
                    x++;
                    if (invdraw)
                        y--;
                    else
                        y++;
                }
                Iter += 1/dist;

                if (!changeColor)
                    ApplyInterpolation(&colorRef, *color1, *color2, Iter);
                else
                    ApplyInterpolation(&colorRef, *color2, *color1, Iter);
                PutPixel(x, y, &colorRef);
            }
        }
    }
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
