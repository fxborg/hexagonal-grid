#include "hexgrid.h"

#include <iostream>

#include <vector>

using namespace hex;

void test(double radius, Layout layout, vector<Point> pt)
{
	HexGrid hexgrid(radius, layout);

	std::cout << "point(x, y)\t center(q, r, s) \t hexagon(q, r, s)" << std::endl;
	for (int i = 0; i < int(pt.size()); i++) 
	{
		Hexagon hex = hexgrid.pixel_to_hex(pt[i]);
		Hexagon grid = hexgrid.round_hex(hex.q(),hex.r(),hex.s());

		hexgrid.add_point(grid, pt[i]);

		//std::cout << "xy:(" << pt[i].x << "," << pt[i].y <<")->qrs:(" << hex.q() << "," << hex.r()<<"," << hex.s()<< ")->(" << rhex.q() << "," << rhex.r() << "," << rhex.s() << ")" <<  std::endl;

		std::cout << pt[i].x << ", " << pt[i].y << "\t\t" << grid.q() << ", " << grid.r() << ", " << grid.s() << "\t\t" << hex.q() << ", " << hex.r() << ", " << hex.s()  << std::endl;

	}

	auto hexmap = hexgrid.get_hexagon_map();

	for (const auto& kv : hexmap)
	{ 
		
		for (auto pt : kv.second) {
//			std::cout << "(" << pt.x << "," << pt.y << ") ";
		}
	}

}



int main() {

	vector<Point> pt{ Point(1, 1), Point(1, 5), Point(5, 1),Point(5, 5),Point(3, 3)};
	std::cout << "VERTICAL(Pointy) LAYOUT" << std::endl;
	test(1,Layout::VERTICAL,pt);

	std::cout << std::endl; 

	std::cout << "HORIZONTAL(Flat Top) LAYOUT" << std::endl;
	test(1, Layout::HORIZONTAL, pt);

	system("PAUSE");
	return 0;
}

