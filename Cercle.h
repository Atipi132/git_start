#pragma once
#include "shape.h"

namespace drawer
{
	class Circle: public Shape
	{
	private:
		//Diameter of the circle
		int _diameter;

	public:
		/**
		 * Constructor
		 * @param diameter: Diameter of the circle
		 */
		Circle(int diameter);

		/**
		 * Getter on diameter attribute
		 */
		int getDiameter() const;
		
		/**
		 * Setter on diameter attribute
		 */
		void setDiameter(int value);

		/**
		 * Draws the circle
		 */
		void draw() const;
	};
}
