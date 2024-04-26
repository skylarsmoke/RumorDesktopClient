#pragma once

#include <wx/wx.h>

using namespace std;

/// <summary>
/// Chat class that creates chat objects displaying chat info
/// </summary>
class Chat : public wxPanel
{
public:
	Chat(wxPanel* chatPanel);

	// event handlers
	
	/// <summary>
	/// Changes the color of a chat panel when hovering over it
	/// </summary>
	/// <param name="event"></param>
	void HoverOverChat(wxMouseEvent& event) {
		wxPanel* currentChatPanel = wxDynamicCast(event.GetEventObject(), wxPanel);
		currentChatPanel->SetBackgroundColour(wxColor(40, 40, 40));
		currentChatPanel->Refresh();
	}

	/// <summary>
	/// Changes the color of the chat panel back to its original color
	/// </summary>
	/// <param name="event"></param>
	void MouseLeftChat(wxMouseEvent& event) {
		wxPanel* currentChatPanel = wxDynamicCast(event.GetEventObject(), wxPanel);
		if (!isActive) {
			currentChatPanel->SetBackgroundColour(wxColor(30, 30, 30));
			currentChatPanel->Refresh();
		}
		
	}

	/// <summary>
	/// Performs logic when a chat is clicked
	/// </summary>
	/// <param name="event"></param>
	void ChatClicked(wxMouseEvent& event) {
		if (!isActive) {
			wxPanel* currentChatPanel = wxDynamicCast(event.GetEventObject(), wxPanel);
			currentChatPanel->SetBackgroundColour(wxColor(40, 40, 40));
			currentChatPanel->Refresh();
		}
		
		isActive = true; // set this chat as the active chat
	}

	// variables
	bool isActive;
	int chatID;
	string username;
	string lastMessage;

};

