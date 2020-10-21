# Introdução à Computação Gráfica - Atividade 2
<h2><b>Alunos:</b></h2>

<h3>Epitácio Pessoa de Brito Neto</h3>

<h3>Almir Cassimiro Queiroga</h3>


<h3>1. Rasterização</h3>
Chamamos de rasterização o processo de conversão de uma curva vetorial para uma imagem raster, tornando possível a representação gráfica de pontos, retas e figuras representadas vetorialmente em forma de imagem. Nesta atividade, buscamos aplicar o conhecimento de rasterização aprendido nas aulas ministradas, portanto, abordaremos as seguintes exigências: criação de uma função PutPixel(), de forma que possamos representar um ponto em uma tela; criação de uma função DrawLine(), de forma que possamos representar uma reta em uma tela; criação de uma função DrawTriangle(), de forma que possamos representar um triângulo em uma tela; criação do algoritmo do ponto médio, discutido em sala; criação de uma função interpoladora, de forma com que as retas (e, por consequência, os triângulos) possam ser criados em octantes diferentes, fazendo com que possam ser criados em formas e lugares diferentes na tela.

<h3>2. Casos de testes e resultados</h3>


Chamada da função PutPixel():


![alt text](https://i.imgur.com/BUtFpRw.png)

Resultado do teste da função PutPixel():


![alt text](https://i.imgur.com/IgQ1X1c.png)

Chamada da função DrawLine():


![alt text](https://i.imgur.com/dQg7EKX.png)


Resultado do teste da função DrawLine():


![alt text](https://i.imgur.com/wemHw2n.png)


Chamada da função DrawTriangle():


![alt text](https://i.imgur.com/bK4g3bK.png)

  
Resultado do teste da função DrawTriangle():


![alt text](https://i.imgur.com/DpTTgbC.png)


Chamada do segundo teste da função DrawTriangle():


![alt text](https://i.imgur.com/pj2wGdU.png)


Resultado do segundo teste da função DrawTriangle():


![alt text](https://i.imgur.com/uoUcWEd.png)


<h3>3. Conclusão e dificuldades encontradas</h3>
Após conseguirmos nos adaptar à estrutura do código-fonte disponibilizada pelo professor, o processo de criação do projeto foi gradual, portanto, cada etapa que uma função foi implementada foi seguida de um teste de compilação até chegarmos nesse resultado final. No geral, o desenvolvimento do código-fonte foi bem sucedido quando vemos os poucos exemplos de testes colocados anteriormente, as funções criadas agiram de forma comportada nestes casos de teste, após conseguirmos chegar na versão final do código-fonte. Fora isso, a única alteração feita no código-fonte base, além dos arquivos mygl.c e mygl.h, foi uma alteração no arquivo Makefile, portanto, adicionamos uma flag -lm, de forma que o executável pudesse ser compilado corretamente.

![alt text](https://i.imgur.com/9fqbYeQ.png)
