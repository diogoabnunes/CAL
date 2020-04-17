#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
    // TODO: Configure uma janela 600*600
    GraphViewer *gv = new GraphViewer(600, 600, true);
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
    //gv->removeNode(1);
    //gv->rearrange();

    // TODO: Adicione um novo nó com os seguintes atributos: Id: 2
    //gv->addNode(2);
    //gv->rearrange();

    // TODO: Adicione uma aresta entre os dois nós criados anteriormente
    //gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);
    //gv->rearrange();

    // TODO: Coloque uma legenda no nó 2 com um texto à sua escolha
    // Nota: para adicionar uma legenda num nó deve utilizar o seguinte comando:
    //gv->setVertexLabel(2, "Isto e o no numero 2");

    // TODO: Coloque uma legenda na aresta com um texto à sua escolha
    // Nota: para adicionar uma legenda numa aresta deve utilizar o seguinte comando:
    //gv->setEdgeLabel(1, "Isto e a aresta numero 1");

    // TODO: Coloque o nó 2 a Verde
    // Nota: para configurar a cor de um nó deve utilizar o seguinte comando:
    //gv->setVertexColor(2, "green");

    // TODO: Coloque a aresta a Amarelo
    // Nota: para configurar a cor de uma aresta deve utilizar o seguinte comando:
    //gv->setEdgeColor(1, "yellow");

    // TODO: Coloque a imagem “background.jpg” como fundo
    // Nota: para configurar uma imagem de fundo deve utilizar o seguinte comando:
    //tem ser colocado antes do comando gv->createWindow(600, 600);
    //gv->setBackground("background.jpg"); -> no sítio certo
}

void exercicio2()
{
// TODO: Implement here exercise 2!
// ...
}

void exercicio3()
{
// TODO: Implement here exercise 3!
// To read map files, use relative paths:
// Vertices data: "../resources/mapa1/nos.txt"
// Edges data: "../resources/mapa1/arestas.txt"
// ...
}

int main() {
    /*
     * Uncomment the line below to run Exercise 1
     */
    exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */
	//
	//exercicio3();

	getchar();
	return 0;
}
