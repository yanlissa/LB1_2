#include <iomanip>

#include "Structures.h"

Node::Node(unsigned int _id, double _x, double _y, double _z, bool _isVertex)
{
	id = _id;
	x = _x;
	y = _y;
	z = _z;
	isVertex = _isVertex;
}

std::ostream& operator<<(std::ostream& out_stream, const Node& _node)
{
	out_stream << std::setw(3) << _node.id << " (" << std::setw(5) << _node.x << std::setw(5) 
		<< _node.y << std::setw(5) << _node.z << ")" << std::setw(3) << _node.isVertex;
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const FiniteElement& _fe)
{
	out_stream << std::setw(3) << _fe.finiteElementId << std::setw(5) << _fe.materialId << std::setw(5) << _fe.nodeIds[0]
		<< std::setw(5) << _fe.nodeIds[1] << std::setw(5) << _fe.nodeIds[2] << std::setw(5) << _fe.nodeIds[3];
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const BoundaryFiniteElement& _bfe)
{
	out_stream << std::setw(8) << _bfe.boundaryFiniteElementId << std::setw(8) << _bfe.boundaryId;
	return out_stream;
}
