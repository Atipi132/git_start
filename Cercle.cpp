#include "Cercle.h"
#include <iostream>

namespace drawer
{
	Circle::Circle(int diameter)
		: Shape("circle")
	{
		setDiameter(diameter);
	}

	int Circle::getDiameter() const
	{
		return _diameter;
	}

	void Circle::setDiameter(int value)
	{
		if (value < 1 && value > 30)
			throw std::exception("Rectangle height has to be contains between 1 and 30.");

		_diameter = value;
	}

	void Circle::draw() const
	{
		double thickness = 0.5;
		double radius = (_diameter - 1.0) / 2.0;

		double rIn = radius - thickness;
		double rOut = radius + thickness;

		for (int y = 0; y < _diameter; ++y)
		{
			for (int x = 0; x < _diameter; x++)
			{
				double value = (x - radius) * (x - radius) + (y - radius) * (y - radius);

				if (value >= rIn * rIn && value <= rOut * rOut)
				{
					std::cout << '#';
				}
				else
				{
					std::cout << ' ';
				}
			}

			std::cout << std::endl;
		}
	}
}
