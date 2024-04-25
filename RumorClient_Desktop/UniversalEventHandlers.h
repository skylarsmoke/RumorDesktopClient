#pragma once

#include <wx/wx.h>

class UniversalEventHandlers : public wxFrame {
public:
	/// <summary>
	/// changes the buttons color when hovering
	/// </summary>
	/// <param name="event"></param>
	void ButtonHover(wxMouseEvent& event) {
		wxButton* currentButton = wxDynamicCast(event.GetEventObject(), wxButton);
		currentButton->SetBackgroundColour(wxColor(124, 104, 255));
		currentButton->Refresh();
	}

	/// <summary>
	/// changes the buttons color when leaving the button
	/// </summary>
	/// <param name="event"></param>
	void ButtonLeave(wxMouseEvent& event) {
		wxButton* currentButton = wxDynamicCast(event.GetEventObject(), wxButton);
		currentButton->SetBackgroundColour(wxColor(111, 56, 255));
		currentButton->Refresh();
	}
};