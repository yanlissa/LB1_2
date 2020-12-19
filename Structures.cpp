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
	out_stream << std::setw(5) << _node.id << " ( " << std::setw(5) << _node.x << std::setw(5) 
		<< _node.y << std::setw(5) << _node.z << ")" << std::setw(9) << _node.isVertex;
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const FiniteElement& _fe)
{
	out_stream << std::setw(8) << _fe.finiteElementId << std::setw(8) << _fe.materialId <<
		std::endl;
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const BoundaryFiniteElement& _bfe)
{
	out_stream << std::setw(8) << _bfe.boundaryFiniteElementId << std::setw(8) << _bfe.boundaryId <<
		std::endl;
	return out_stream;
}
