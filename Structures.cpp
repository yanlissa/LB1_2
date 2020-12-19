#include "Structurs.h"

#include <iomanip>

Node::Node(int _id, double _x, double _y, double _z, bool _versh)
{
	id = _id;
	x = _x;
	y = _y;
	z = _z;
	versh = _versh;
}

bool Node::operator==(const Node& right_node) const
{
	if (id == right_node.id && x == right_node.x && y == right_node.y &&
			z == right_node.z && versh == right_node.versh)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Node::operator<(const Node& right_node) const
{
	return (id < right_node.id);
}

std::ostream& operator<<(std::ostream& out_stream, const Node& _node)
{
	out_stream << std::setw(5) << _node.id << " ( " << std::setw(5) << _node.x << std::setw(5) 
		<< _node.y << std::setw(5) << _node.z << ")" << std::setw(9) << _node.versh << 
		std::endl;
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
	out_stream << std::setw(8) << _bfe.id_BonFinElement << std::setw(8) << _bfe.id_granica <<
		std::endl;
	return out_stream;
}
