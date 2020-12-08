# Introdução à Computação Gráfica - Atividade 3
## <b>Alunos:</b>

### Epitácio Pessoa de Brito Neto

### Almir Cassimiro Queiroga

## Densenvolvimento

#### No desenvolvimento foi utilizado o sistema operacional ArchLinux, foram encontrados problemas ao tentar importar suas dependências glm e GLEW, foi superado seguindo os passos orientados pelo professor na descrição do projeto.
#### Após ser implementado o Template com as dependências utilizando o programa Sublime 3 e as orientações deixadas na descrição do projeto, utilizou-se o MakeFile para gerar a Imagem 1, então partiu-se para a implementação da atividade (2.5.1) que os resultados alcançados podem ser vistos na Imagem 2


![59461e84-da2a-485c-b4fd-4f73b782391c](https://user-images.githubusercontent.com/28552417/101514721-5887c780-395c-11eb-8324-7af0d47d26a6.jpg)
###### Imagem 1


![fd6ff6b1-5f8e-4412-94c9-1ceca800b007](https://user-images.githubusercontent.com/28552417/101514935-9258ce00-395c-11eb-8ff4-1de55f440051.jpg)
###### Imagem 2

#### Para implementação da atividade 2.5.1 de escala foi modificado a matriz model_array a seguir, modificano princripalmente o 1.0f para 0.333f e 1.0f para 1.5f


```

float model_array[16] = {0.333f, 0.0f, 0.0f, 0.0f, 
                             0.0f, 1.5f, 0.0f, 0.0f, 
                             0.0f, 0.0f, 1.0f, 0.0f, 
                             0.0f, 0.0f, 0.0f, 1.0f};
```
                             
###### Matrix 1

#### Foi realizada modificação da escala na primeira coordenada, provocando o "enrugamento" da imagem. Desta forma modificando a escala da imagem.
#### Foi realizada a mesma forma no atividade 2.5.2 para modificação de translação, fi modificada a coordenada refenrente e com a Matrix 2 a seguir se alcançou o resultado apresentado na Imagem 3.

```

float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                             0.0f, 1.0f, 0.0f, 0.0f, 
                             0.0f, 0.0f, 1.0f, 0.0f, 
                             0.7f, 0.0f, 0.0f, 1.0f};
```

##### Matrix 2

![3f973e97-c434-4854-8b34-77a157566890](https://user-images.githubusercontent.com/28552417/101520269-0007f880-3963-11eb-9d0c-85156e7d6dde.jpg)

##### Imagem 3

#### Para a atividade 2.5.3 foi realizado um processo diferente, foi necessário modificar a matrix proj_array para realizar a modificação de perspectiva necessária na atividade.
#### utilizando d = 1/-8 foi encontrada a Matrix 3 que foi utilizada e apresentou os resultados da Imagem 4

```
float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f, -8.0f, 
                            0.0f, 0.0f, 0.125f, 0.0f};
                            
 ```
 ##### Matrix 3
 
 ![828475bb-2948-4f35-922a-c8fb71bf0d72](https://user-images.githubusercontent.com/28552417/101521097-1a8ea180-3964-11eb-91e3-4c0718f34c02.jpg)
 
 ##### Imagem 4
 
 #### Seguindo para a atividade 2.5.4 continuamos com a matrix proj_array da atividade anterior, foi criado a seguinte função para conseguirmos ajustar a posição de câmera que a imagem será vista 
 
 ```
 float camera_position[3] = {-0.1f, 0.1f, 0.1f},
float camera_up[3] = {0.0f, 1.0f, 0.0f},
float camera_pointer[3] = {0.0f, 0.0f, -1.0f};
          
    glm::vec3 cam_pos  = glm::make_vec3(camera_pos);
    glm::vec3 cam_up   = glm::make_vec3(camera_up);
    glm::vec3 cam_pont = glm::make_vec3(camera_pont);

    glm::vec3 cam_Z = glm::make_vec3(glm::normalize(cam_pos - cam_pont));
    glm::vec3 cam_X = glm::make_vec3(glm::normalize(glm::cross(cam_up, cam_Z)));
    glm::vec3 cam_Y = glm::make_vec3(glm::cross(cam_Z, cam_X));

    glm::mat4 B = glm::mat4 ( glm::vec4(cam_X.x, cam_Y.x, cam_Z.x, 0.0f),
                              glm::vec4(cam_X.y, cam_Y.y, cam_Z.y, 0.0f),
                              glm::vec4(cam_X.z, cam_Y.z, cam_Z.z, 0.0f),
                              glm::vec4(0.0f,   0.0f,   0.0f, 1.0f));

    glm::mat4 T = glm::mat4 ( glm::vec4(1.0f, 0.0f, 0.0f, 0.0f),
                          glm::vec4( 0.0f, 1.0f, 0.0f, 0.0f),
                          glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),
                          glm::vec4(-cam_pos.x, -cam_pos.y, -cam_pos.z, 1.0f));

    glm::mat4 view_mat = B * T;
    

```
#### Desta forma a imagem apresentada vai ter a posição de câmera modificada, modificando a perspectiva como mostrado na Imagem 5

![cb8ae793-b9e5-47a0-89dd-22d56a74fc11](https://user-images.githubusercontent.com/28552417/101523372-48c1b080-3967-11eb-9ad8-8a1251f31f04.jpg)

##### Imagem 5

#### Para a atividade 2.5.5 foram realizadas modificações nas 3 matrizes model_array, view_array e proj_array como mostrado no código a seguir. 


```

float model_array[16] = {0.5f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.4f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         0.0f, 0.0f, 0.0f, 1.0f};
glm::mat4 model_mat = glm::make_mat4(model_array);
Matriz View

float view_array[16] = {1.7f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 2.7f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         0.0f, 0.0f, 0.0f, 1.0f};
glm::mat4 view_mat = glm::make_mat4(view_array);
Matriz Projection

float proj_array[16] = {-0.6f, 0.0f, 0.0f, 0.0f, 
                        0.0f, 1.0f, 0.0f, 0.0f, 
                        0.0f, 0.0f, 1.0f, -7.0f, 
                        0.0f, 0.0f, 0.142f, 1.0f};
glm::mat4 proj_mat = glm::make_mat4(proj_array);

```

#### Foram alcançadas modificações demonstrados na imagem 6 derivado das mudanças das 3 matrizes, como a inversão de triangulos, tamanho e perspectiva

![830f82ab-d088-4658-88c9-4abfc46402af](https://user-images.githubusercontent.com/28552417/101524020-29775300-3968-11eb-8020-8fec0f1f4968.jpg)

##### Imagem 6

