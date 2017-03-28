#include <cstdio>
#include "graphviewer.h"
#include "Graph.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class NoInfo{
public:
	long long idNo;
	double longitude_radians;
	double latitude_radians;

	NoInfo(long long idNo, double longitude_radians, double latitude_radians){
		this->idNo = idNo;
		this->longitude_radians = longitude_radians;
		this->latitude_radians = latitude_radians;
	}

	friend bool operator==(NoInfo const & left,NoInfo const & right){
		return left.idNo == right.idNo;
	}

	friend bool operator!=(NoInfo const & left,NoInfo const & right){
		return left.idNo != right.idNo;
	}
};

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);

	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->addNode(1);
	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);

	Sleep(2000); // use sleep(1) in linux ; Sleep(2000) on Windows

	gv->removeEdge(0);
	gv->removeNode(1);
	gv->addNode(2);

	gv->rearrange();

	Sleep(2000);

	gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);
	gv->defineEdgeCurved(false);

	gv->setVertexLabel(0, "Isto e um no");
	gv->setEdgeLabel(1, "Isto e uma aresta");

	gv->setVertexColor(2, "green");
	gv->setEdgeColor(1, "yellow");

	gv->setVertexSize(2, 40);
	gv->setVertexIcon(0, "icon.gif");

	gv->setEdgeDashed(1, false);

	gv->rearrange();

}

void exercicio2()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");
	gv->addNode(0,300,50);
	gv->addNode(1,318,58);
	gv->addNode(4,300,100);
	gv->addNode(7,282,58);
	gv->addNode(2,325,75);
	gv->addNode(3,318,93);
	gv->addNode(6,275,75);
	gv->addNode(5,282,93);

	gv->addNode(8,150,200);

	gv->setVertexColor(8, "green");
	gv->setVertexColor(9, "blue");
	gv->setVertexColor(10, "green");
	gv->setVertexColor(11, "blue");
	gv->setVertexColor(12, "green");
	gv->setVertexColor(13, "green");
	gv->addNode(9,300,200);
	gv->addNode(10,450,200);
	gv->addNode(11,300,400);

	gv->addNode(12,200,550);
	gv->addNode(13,400,550);

	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
	gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
	gv->addEdge(2, 2, 3, EdgeType::UNDIRECTED);
	gv->addEdge(3, 3, 4, EdgeType::UNDIRECTED);
	gv->addEdge(4, 4, 5, EdgeType::UNDIRECTED);
	gv->addEdge(5, 5, 6, EdgeType::UNDIRECTED);
	gv->addEdge(6, 6, 7, EdgeType::UNDIRECTED);
	gv->addEdge(7, 7, 0, EdgeType::UNDIRECTED);

	gv->addEdge(8, 4, 9, EdgeType::UNDIRECTED);
	gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
	gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
	gv->addEdge(11, 9, 11, EdgeType::UNDIRECTED);
	gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
	gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);


	gv->rearrange();
	bool first=true;

	while(1)
	{
		Sleep(2000);
		if (first)
		{
			gv->removeNode(12);
			gv->removeNode(13);
			first=false;
		}
		else
		{
			gv->removeNode(20);
			gv->removeNode(21);
		}
		gv->addNode(14,250,550);
		gv->addNode(15,350,550);
		gv->addEdge(14, 11, 14, EdgeType::UNDIRECTED);
		gv->addEdge(15, 11, 15, EdgeType::UNDIRECTED);
		gv->rearrange();

		Sleep(2000);
		gv->removeNode(14);
		gv->removeNode(15);
		gv->addNode(16,300,550);
		gv->addNode(17,300,550);
		gv->addEdge(16, 11, 16, EdgeType::UNDIRECTED);
		gv->addEdge(17, 11, 17, EdgeType::UNDIRECTED);
		gv->rearrange();
		Sleep(2000);

		gv->removeNode(16);
		gv->removeNode(17);
		gv->addNode(18,250,550);
		gv->addNode(19,350,550);
		gv->addEdge(18, 11, 18, EdgeType::UNDIRECTED);
		gv->addEdge(19, 11, 19, EdgeType::UNDIRECTED);
		gv->rearrange();
		Sleep(2000);

		gv->removeNode(18);
		gv->removeNode(19);
		gv->addNode(20,200,550);
		gv->addNode(21,400,550);
		gv->addEdge(20, 11, 20, EdgeType::UNDIRECTED);
		gv->addEdge(21, 11, 21, EdgeType::UNDIRECTED);
		gv->rearrange();
	}
}

void exercicio3()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("nos.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	std::string   line;

	int idNo=0;
	int X=0;
	int Y=0;

	while(std::getline(inFile, line))
	{
		std::stringstream linestream(line);
		std::string         data;

		linestream >> idNo;

		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> X;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> Y;
		gv->addNode(idNo,X,Y);

	}

	inFile.close();


	//Ler o ficheiro arestas.txt
	inFile.open("arestas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	int idAresta=0;
	int idNoOrigem=0;
	int idNoDestino=0;

	while(std::getline(inFile, line))
	{
		std::stringstream linestream(line);
		std::string data;


		linestream >> idAresta;

		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> idNoOrigem;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> idNoDestino;
		gv->addEdge(idAresta,idNoOrigem,idNoDestino, EdgeType::UNDIRECTED);

	}

	inFile.close();

	gv->rearrange();

}

//calculate haversine distance for linear distance // coordinates in radians
long double haversine_km(long double lat1, long double long1, long double lat2, long double long2) {
	long double dlong = (long2 - long1);
	long double dlat = (lat2 - lat1);
	long double a = pow(sin(dlat / 2.0), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2.0), 2);
	long double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	long double d = 6367 * c;

	return d;
}

void readFiles(GraphViewer *gv, Graph<NoInfo> graf){
	gv->createWindow(1000, 1000);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	ifstream inFile;

	//Ler o ficheiro FileNodes.txt
	inFile.open("FileNodes.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	std::string   line;

	long long idNo=0;
	double latitude_degrees=0;
	double longitude_degrees=0;
	double longitude_radians=0;
	double latitude_radians=0;

	while(std::getline(inFile, line))
	{
		std::stringstream linestream(line);
		std::string data;

		linestream >> idNo;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> latitude_degrees;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> longitude_degrees;

		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> longitude_radians;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> latitude_radians;

		gv->addNode(idNo);

		NoInfo no(idNo,longitude_radians, latitude_radians);
		graf.addVertex(no);
	}

	ifstream inFile2;
	//Ler o ficheiro FileConection.txt
	inFile2.open("FileConection.txt");

	if (!inFile2) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	long long roadId=0;
	long long node1_id=0;
	long long node2_id=0;
	long i = 0;

	while(std::getline(inFile2, line))
	{
		std::stringstream linestream(line);
		std::string data;

		linestream >> roadId;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> node1_id;
		std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> node2_id;

		gv->addEdge(i, node1_id, node2_id, EdgeType::DIRECTED);
		NoInfo origem = graf.getVertex(NoInfo(node1_id,0,0))->getInfo();
		NoInfo destino = graf.getVertex(NoInfo(node2_id,0,0))->getInfo();
		graf.addEdge(origem,destino,haversine_km(origem.latitude_radians,origem.longitude_radians,destino.latitude_radians,destino.longitude_radians));
		i++;

	}

	gv->rearrange();
}

int main() {
	GraphViewer *gv = new GraphViewer(1000, 1000, true);
	Graph<NoInfo> graf;
	readFiles(gv, graf);
	//exercicio1();
	//exercicio2();
	//exercicio3();

	if(graf.getVertex(NoInfo(25632365,0,0)) != NULL){
		vector<NoInfo> caminho = graf.getPath(NoInfo(25632365,0,0),NoInfo(421576155,0,0));

		for(unsigned int i = 0; i <caminho.size(); i++){
			Sleep(100);

			cout << caminho[i].idNo << endl;
			gv->setVertexColor(caminho[i].idNo,GREEN);
		}

//		for(unsigned int i = 0; i < 20 ; i++)
//			gv->setEdgeColor(i,GREEN);
	}

	getchar();
	cout << "END";
	return 0;
}
