#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
    // TODO: Configure uma janela 600*600
    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->setBackground("../earth.jpg");
    gv->createWindow(600, 600);

    // TODO: Configure a cor dos nós para azul
    // Nota: para configurar a cor dos nós deve utilizar o seguinte comando:
    gv->defineVertexColor("blue");

    // TODO: Configure a cor das arestas para preto
    // Nota: para configurar a cor das arestas deve utilizar o seguinte comando:
    gv->defineEdgeColor("black");

    // TODO: Crie um nó com os seguintes atributos: Id: 0
    // Nota: para criar um nó deve utilizar o seguinte comando:
    gv->addNode(0);
    // Nota: para atribuir as novas alterações ao grafo é necessário executar o comando:
    gv->rearrange();

    // TODO: Crie um nó com os seguintes atributos: Id: 1
    gv->addNode(1);
    gv->rearrange();

    // TODO: Crie uma aresta entre os dois nós anteriores.
    // Nota: para criar uma aresta deve utilizar o seguinte comando:
    // para arestas bidireccionais: gv->addEdge(idAresta,idNoOrigem,idNoDestino,EdgeType::UNDIRECTED);
    // para arestas direccionais: gv->addEdge(idAresta,idNoOrigem,idNoDestino, EdgeType::DIRECTED);
    gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
    gv->rearrange();

    // TODO: Remova o nó 1
    // Nota: para remover um nó deve utilizar o seguinte comando:
    gv->removeNode(1);
    gv->rearrange();

    // TODO: Adicione um novo nó com os seguintes atributos: Id: 2
    gv->addNode(2);
    gv->rearrange();

    // TODO: Adicione uma aresta entre os dois nós criados anteriormente
    gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);
    gv->rearrange();

    // TODO: Coloque uma legenda no nó 2 com um texto à sua escolha
    // Nota: para adicionar uma legenda num nó deve utilizar o seguinte comando:
    gv->setVertexLabel(2, "Isto e o no numero 2");

    // TODO: Coloque uma legenda na aresta com um texto à sua escolha
    // Nota: para adicionar uma legenda numa aresta deve utilizar o seguinte comando:
    gv->setEdgeLabel(1, "Isto e a aresta numero 1");

    // TODO: Coloque o nó 2 a Verde
    // Nota: para configurar a cor de um nó deve utilizar o seguinte comando:
    gv->setVertexColor(2, "green");

    // TODO: Coloque a aresta a Amarelo
    // Nota: para configurar a cor de uma aresta deve utilizar o seguinte comando:
    gv->setEdgeColor(1, "yellow");

    // TODO: Coloque a imagem “background.jpg” como fundo
    // Nota: para configurar uma imagem de fundo deve utilizar o seguinte comando:
    //tem ser colocado antes do comando gv->createWindow(600, 600);
    //gv->setBackground("background.jpg"); -> no sítio certo
}

void exercicio2()
{
    // TODO: Adicione nós com os seguintes atributos: (...)
    //Nota: para definir a colocação dos nós deve iniciar o GraphViewer com o último argumento “false”:
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("../earth.jpg");
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("red");

    gv->addNode(0, 300, 50);
    gv->addNode(1, 318, 58);
    gv->addNode(2, 325, 75);
    gv->addNode(3, 318, 93);
    gv->addNode(4, 300, 100);
    gv->addNode(5, 282, 93);
    gv->addNode(6, 275, 75);
    gv->addNode(7, 282, 58);
    gv->addNode(8, 150, 200);
    gv->addNode(9, 300, 200);
    gv->addNode(10, 450, 200);
    gv->addNode(11, 300, 400);

    // TODO: Adicione arestas com os seguintes atributos: (...)
    gv->addEdge(0, 0, 1, 1);
    gv->addEdge(1, 1, 2, 1);
    gv->addEdge(2, 2, 3, 1);
    gv->addEdge(3, 3, 4, 1);
    gv->addEdge(4, 4, 5, 1);
    gv->addEdge(5, 5, 6, 1);
    gv->addEdge(6, 6, 7, 1);
    gv->addEdge(7, 7, 0, 1);
    gv->addEdge(8, 4, 9, 1);
    gv->addEdge(9, 9, 8, 1);
    gv->addEdge(10, 9, 10, 1);
    gv->addEdge(11, 9, 11, 1);

    gv->rearrange();

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            gv->addNode(12, 200, 550);
            gv->addNode(13, 400, 550);
            gv->addEdge(12, 11, 12, 1);
            gv->addEdge(13, 11, 13, 1);
            gv->rearrange();
            Sleep(1000/2);
            gv->removeNode(12);
            gv->removeNode(13);
        }
        else
        {
            gv->addNode(14, 250, 550);
            gv->addNode(15, 350, 550);
            gv->addEdge(14, 11, 14, 1);
            gv->addEdge(15, 11, 15, 1);
            gv->rearrange();
            Sleep(1000/2);
            gv->removeNode(14);
            gv->removeNode(15);
        }
    }

    gv->rearrange();

    // TODO: Animação
    /*Nota: para simular a animação dos grafos deve efectuar as alterações que pretende no grafo e em
    seguida voltar a dar a instrução para desenhá-lo. Para que esta animação seja perceptível pode, por
    exemplo, utilizar uma instrução de pausa de execução (sleep(numSegundos) em Linux ;
    Sleep(numMiliSegundos) em Windows)*/

    // TODO: Com base nos conceitos que aprendeu faça com que a animação seja progressiva e cíclica
    /*Nota: Devido às definições actuais da API de visualização não é possível alterar a posição de um nó.
    Para efectuar esta alteração deve remover o nó e adicionar um novo com um identificador diferente e
    com a posição pretendida.*/

}

void exercicio3()
{
    // TODO: Implement here exercise 3!
    // To read map files, use relative paths:
    // Vertices data: "../resources/mapa1/nos.txt"
    // Edges data: "../resources/mapa1/arestas.txt"
    string line;
    int idNo, x, y;
    int idAresta, idNoOrigem, idNoDestino;

    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("../earth.jpg");
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("red");

    ifstream nos("../resources/mapa1/nos.txt");
    if (nos.is_open())
    {
        while (getline(nos, line))
        {
            replace(line.begin(), line.end(), ';', ' ');
            stringstream ss(line);
            ss >> idNo; ss >> x; ss >> y;
            gv->addNode(idNo, x, y);
        }
        nos.close();
    }

    ifstream arestas("../resources/mapa1/arestas.txt");
    if (arestas.is_open())
    {
        while (getline(arestas, line))
        {
            replace(line.begin(), line.end(), ';', ' ');
            stringstream ss(line);
            ss >> idAresta; ss >> idNoOrigem; ss >> idNoDestino;
            gv->addEdge(idAresta, idNoOrigem, idNoDestino, 1);
        }
        arestas.close();
    }
    gv->rearrange();
}

int main() {
    /*
     * Uncomment the line below to run Exercise 1
     */
    //exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */
	//
	exercicio3();

	getchar();
	return 0;
}
