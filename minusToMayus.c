/*  nombre: Cadena minúscula a MAYÚSCULA
    autor: David Emmanuel Santana Romero
    fecha: 13 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<string.h>

int main() {
    char names[2][16] = {"humano\0", "computadora\0"};
    char human[] = "Soy mi propio testaferro\nQue me escuches te sugiero\nYo elijo lo que prefiero\nY la libertad no sabés lo que es\nVos hacés lo que podés\nPero yo hago lo que quiero\n\0";
    char computer[] = "¿Pero yo hago lo que quiero?\n¿Y están presos de su rutina?\nEs sus casas, calles y oficinas\nCorrompidos por el dinero\nNo saben lo que es ser austero\nConsumiendo puro brillo\nLe digo esto y lo humillo\nLos únicos órganos que les funcionan\nY seguro no los donan\nSon la cartera y el bolsillo\0";

    strupr(names[0]);
    strupr(names[1]);

    printf_s("[%s a %s]\n", names[0], names[1]);
    printf_s("%s", human);
    printf_s("[%s a %s]\n", names[1], names[0]);
    printf_s("%s", computer);
}