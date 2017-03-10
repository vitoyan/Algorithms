#include <queue>

#include "buildDataStructure.h"


namespace DataStructure
{

Node::Node(std::string data)
{
	mData = data;
	isVisited = false;
}

graph::graph(int capacity)
{
	if(capacity <= 0)
		return;

	mCapacity = capacity;
	mNodeCount = 0;
	pNodeArray = new Node[mCapacity];
	pMatrix = new int[mCapacity * mCapacity];
	std::memset(pMatrix, 0, mCapacity * mCapacity * sizeof(int));
}

graph::~graph()
{
	delete[] pNodeArray;
	delete[] pMatrix;
}

bool 
graph::addNode(Node *pNode)
{
	if(!pNode)
		return false;
	if(mNodeCount >= mCapacity)
		return false;
	pNodeArray[mNodeCount].mData = pNode->mData;
	mNodeCount++;
	return true;
}

void
graph::resetNodes()
{
	for(int i = 0; i < mNodeCount; i++)
		pNodeArray[i].isVisited = false;
} 

bool 
graph::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= mNodeCount)
		return false;
	if(col < 0 || col >= mNodeCount)
		return false;

	pMatrix[row*mNodeCount + col] = val;
	return true;
}

bool
graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= mNodeCount)
		return false;
	if(col < 0 || col >= mNodeCount)
		return false;

	pMatrix[row*mNodeCount + col] = val;
	pMatrix[col*mNodeCount + row] = val;
	return true;
}

void
graph::printMatrix()
{
	for(int i = 0; i < mNodeCount; i++)
	{
		for(int j = 0; j < mNodeCount; j++)
		{
			std::cout<<pMatrix[i*mNodeCount + j]<<" ";
		}
		std::cout<<std::endl;
	}
}

void
graph::depthFirstTraverse(int nodeIndex)
{	
	if(nodeIndex < 0 || nodeIndex >= mNodeCount)
		return;
	int nextNode = nodeIndex;
	while(nextNode >= 0)
	{
		std::cout<<pNodeArray[nextNode].mData<<" ";
		pNodeArray[nextNode].isVisited = true;
		nextNode = -1;
		for(int i = 0; i < mNodeCount; i++)
		{
			if(pMatrix[nextNode*mNodeCount + i] == 1 && pNodeArray[i].isVisited == false)
			{
				nextNode = i;
				break;
			}
		}
		if(nextNode < 0)
		{
			for(int i = 0; i < mNodeCount; i++)
			{
				if(!pNodeArray[i].isVisited)
				{
					nextNode = i;
					break;
				}
			}
		}
	}
}

void 
graph::depthFirstTraverseRecursively(int nodeIndex)
{
	if(nodeIndex < 0 || nodeIndex >= mNodeCount)
		return;
	std::cout<<pNodeArray[nodeIndex].mData<<" ";
	pNodeArray[nodeIndex].isVisited = true;	
	for(int i = 0; i < mNodeCount; i++)
	{
		if(pMatrix[nodeIndex*mNodeCount + i] == 1 && pNodeArray[i].isVisited == false)
		{
			depthFirstTraverseRecursively(i);
		}
	}
}

void
graph::breadthFristTraverse(int nodeIndex)
{

}

bool
graph::getValueFromMatrix(int row, int col, int &val)
{
	if(row < 0 || row >= mNodeCount)
		return false;
	if(col < 0 || col >= mNodeCount)
		return false;

	val = pMatrix[row*mNodeCount + col];
	return true;
}

bool
graph::breadthrFristTraverseImpli(std::vector<int> preVec)
{

}

}