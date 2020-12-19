#include <iomanip>

#include "Structures.h"

Node::Node(unsigned int _id, double _x, double _y, double _z, bool _versh)
{
	id = _id;
	x = _x;
	y = _y;
	z = _z;
	versh = _versh;
}

std::ostream& operator<<(std::ostream& out_stream, const Node& _node)
{
	out_stream << std::setw(5) << _node.id << " ( " << std::setw(5) << _node.x << std::setw(5) 
		<< _node.y << std::setw(5) << _node.z << ")" << std::setw(9) << _node.versh;
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const FiniteElement& _fe)
{
	out_stream << std::setw(8) << _fe.id_FinElement << std::setw(8) << _fe.id_material <<
		std::endl;
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const BoundaryFiniteElement& _bfe)
{
	out_stream << std::setw(8) << _bfe.id_BoundFinElement << std::setw(8) << _bfe.id_granica <<
		std::endl;
	return out_stream;
}
