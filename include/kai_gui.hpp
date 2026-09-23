#ifndef KAI_GUI_HPP
#define KAI_GUI_HPP

#include "Canvas.hpp"
#include "resources_manager.h"

namespace kai
{
	class MenuGUI : public Canvas
	{
	public:
		MenuGUI();
		~MenuGUI() = default;
		void drawGUI() override;
		int playBttnId;
		Sound buttonSound;

	};

	class PlayGUI : public Canvas {
	public:
		PlayGUI();
		~PlayGUI() = default;
		void drawGUI() override;
	};



}
#endif // !KAI_GUI_HPP