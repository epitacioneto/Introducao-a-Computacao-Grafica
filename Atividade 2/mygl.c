#include "mygl.h"

Color ColorWhite = {.red = 255, .green = 255, .blue = 255, .alpha = 255};
Color ColorRed = {.red = 255, .green = 0, .blue = 0, .alpha = 255};
Color ColorGreen = {.red = 0, .green = 255, .blue = 0, .alpha = 255};
Color ColorBlue = {.red = 0, .green = 0, .blue = 255, .alpha = 255};
Color ColorRandom = {.red = 100, .green = 59, .blue = 156, .alpha = 255};

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
    const unsigned int inicio = x * 4 + y * IMAGE_WIDTH * 4;
    fb_ptr[inicio] = color->red;
    fb_ptr[inicio + 1] = color->green;
    fb_ptr[inicio + 2] = color->blue;
    fb_ptr[inicio + 3] = color->alpha;
}

void Interpolacao(Color *corAtual, Color cor1, Color cor2, float dist){
    corAtual->red = (cor2.red*dist) + ((1-dist)*cor1.red);
    corAtual->green = (cor2.green*dist) + ((1-dist)*cor1.green);
    corAtual->blue = (cor2.blue*dist) + ((1-dist)*cor1.blue);
}

void DrawLine(int x0, int y0, int x1, int y1, Color *color1, Color *color2) {
	
    int a;
    int invdraw;

    int changeColor = 0;

    int inv;


    if (x1 < x0){
        a = x0;
        x0 = x1;
        x1 = a;
        a = y0;
        y0 = y1;
        y1 = a;
        changeColor = 1;
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
        inv = 0;
        if (dy < 0){
            int a;
            a = y0;
            y0 = y1;
            y1 = a;
            inv = 1;
        }
                   
        for (int i = y0; i < y1; i++){
            Iter += 1/dist;
            if (!changeColor && !inv)
                Interpolacao(&colorRef, *color1, *color2, Iter);
            else
                Interpolacao(&colorRef, *color2, *color1, Iter);
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
                Interpolacao(&colorRef, *color1, *color2, Iter);
            else
                Interpolacao(&colorRef, *color2, *color1, Iter);
            PutPixel(i, y0, &colorRef);
        }
    }else{

        if (MODULO(dy) > MODULO(dx)){ 
            invdraw = 0;
            Iter += 1/dist;

            if (dy < 0){
                dy *= -1;

                invdraw = 1;
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
                        Interpolacao(&colorRef, *color1, *color2, Iter);
                    else
                        Interpolacao(&colorRef, *color2, *color1, Iter);
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
                        Interpolacao(&colorRef, *color1, *color2, Iter);
                    else
                        Interpolacao(&colorRef, *color2, *color1, Iter);
                    PutPixel(x, y, &colorRef);
                }
            }

        } else{ 
            invdraw = 0;
            Iter = 1/dist;

            if (dy < 0){
                dy *= -1;
                invdraw = 1;
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
                    Interpolacao(&colorRef, *color1, *color2, Iter);
                else
                    Interpolacao(&colorRef, *color2, *color1, Iter);
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


void MyGlDraw(void) {
    /*PutPixel(100, 200, &ColorGreen);
    PutPixel(150, 205, &ColorBlue);
    PutPixel(200, 300, &ColorRed);
    PutPixel(60, 150, &ColorWhite);
    PutPixel(80, 100, &ColorRandom);

    
    DrawLine(0, 0, 5, 3, &ColorWhite, &ColorRed);
    DrawLine(511, 0, 0, 511, &ColorWhite, &ColorGreen);
    DrawLine(256, 127, 113, 383, &ColorWhite, &ColorBlue);
    DrawLine(127, 256, 383, 256, &ColorWhite, &ColorRandom);
    
    //DrawLine(383, 0, 127, 511, &ColorWhite, &ColorRed);
    //DrawLine(127, 0, 383, 511, &ColorWhite, &ColorBlue);


     */
     
    DrawTriangle(127, 255, &ColorWhite, 158, 255, &ColorRandom, 179, 349, &ColorRed);
    DrawTriangle(0, 255, &ColorRed, 127, 255, &ColorGreen, 127, 232, &ColorBlue);
    DrawTriangle(383, 255, &ColorRandom, 320, 255, &ColorBlue, 383, 153, &ColorWhite);
    
}
