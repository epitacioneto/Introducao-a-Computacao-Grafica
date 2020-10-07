# Introdução à Computação Gráfica - Atividade 1
<h2><b>Alunos:</b></h2>

<h3>Epitácio Pessoa de Brito Neto</h3>

<h3>Almir Cassimiro Queiroga</h3>

Após os códigos-fonte serem disponibilizados pelo professor, criamos um ambiente de virtual machine para utilizarmos o Ubuntu. Em seguida, via terminal, após o comando <i>make</i> 
podemos ver o comportamento do programa que pelo makefile executa o comando $(CC) -Wall -Wextra -Wpedantic -std=c99 -O0 -g3 main.c -lglut -lGLU -lGL -o moderngl_hello_world
que irá nos redirecionar para o arquivo <i>main.c</i> utilizando da API OpenGL.

<img src="https://i.imgur.com/nfhwG6y.png">

OpenGL é um conjunto de bibliotecas que como pode-se observar na imagem acima utiliza linguagem C e OpenGL Utility Toolkit para abstrair sistema de janelas, utilizando assim destas ferramentas, cheaga-se no resultado: 

<img src="https://i.imgur.com/dX4ZXOQ.png">

<img src="https://i.imgur.com/yy7h62V.png">

Após identificarmos os warnings, - que já eram esperados - compilamos o arquivo com o comando <i>./moderngl_hello_world</i> e obtivemos o seguinte resultado:

<img src="https://i.imgur.com/v72cH2l.png">

Portanto, conseguimos chegar no resultado esperado para a atividade proposta.
