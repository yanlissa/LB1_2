#include <iomanip>

#include "Structures.h"

Node::Node(unsigned int _id, std::array<double, 3> _coordinates, bool _isVertex)
{
	id = _id;
	coordinates = _coordinates;
	isVertex = _isVertex;
}

std::ostream& operator<<(std::ostream& out_stream, const Node& _node)
{
	out_stream << std::setw(3) << _node.id << " (" << std::setw(5) << _node.coordinates[0]  << std::setw(5)
		<< _node.coordinates[1] << std::setw(5) << _node.coordinates[2] << ")" << std::setw(3) << _node.isVertex;
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
	out_stream << std::setw(3) << _bfe.boundaryFiniteElementId << std::setw(5) << _bfe.boundaryId << std::setw(5) << _bfe.nodeIds[0]
		<< std::setw(5) << _bfe.nodeIds[1] << std::setw(5) << _bfe.nodeIds[2] << std::setw(5) << _bfe.nodeIds[3];
	return out_stream;
}
