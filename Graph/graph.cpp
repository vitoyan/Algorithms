#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <queue>

#include "./util/util.h"
#include "./util/buildDataStructure.h"

int main()
{
	DataStructure::graph test(6);
	DataStructure::Node a(std::string("A"));
	DataStructure::Node b(std::string("B"));
	DataStructure::Node c(std::string("C"));
	DataStructure::Node d(std::string("D"));
	DataStructure::Node e(std::string("E"));
	DataStructure::Node f(std::string("F"));

	test.addNode(&a);
	test.addNode(&b);
	test.addNode(&c);
	test.addNode(&d);
	test.addNode(&e);
	test.addNode(&f);


	test.setValueToMatrixForUndirectedGraph(0,1);
	test.setValueToMatrixForUndirectedGraph(1,2);
	test.setValueToMatrixForUndirectedGraph(1,3);
	test.setValueToMatrixForUndirectedGraph(0,4);
	test.setValueToMatrixForUndirectedGraph(4,5);
	//test.setValueToMatrixForUndirectedGraph(3,5);

	test.printMatrix();
	test.resetNodes();
	test.depthFirstTraverse(0);
	std::cout<<std::endl;
	test.resetNodes();
	test.depthFirstTraverseRecursively(0);
	std::cout<<std::endl;
	test.resetNodes();
	test.breadthFristTraverse(0);
	std::cout<<std::endl;
}