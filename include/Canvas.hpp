#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "raylib.h"
#include "raygui.h"

namespace kai
{
	class Canvas
	{
	private:

	public:
		Vector2 position;
		Vector2 size;
		bool isActive = false;

		virtual ~Canvas() = default;
		void draw() { if (isActive) drawGUI(); };
		virtual void drawGUI() = 0;

		void setPosition(float x, float y) { position = { x, y }; }
		void setSize(float width, float height) { size = {width, height}; }
		void setActive(bool isActive) { isActive = isActive; }
		void show() { isActive = true; }
		void hide() { isActive = false; }
		void toggle() { isActive = !isActive;}
		//bool isActive() = return true;

	};

	//inline Canvas::Canvas() : position{0,0};
	//inline Canvas::~Canvas() : position{0,0};


}
#endif // !KAI_GUI_HPP