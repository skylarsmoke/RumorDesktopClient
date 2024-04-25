#pragma once

#include <wx/wx.h>

using namespace std;

class MainWindow : public wxFrame
{
public:
	MainWindow(const wxString& title,
			   const wxPoint& pos,
			   const wxSize& size);

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

	/// <summary>
	/// Performs logic when the add chat button is clicked
	/// </summary>
	/// <param name="event"></param>
	void AddChatButtonClick(wxCommandEvent& event) {
		wxButton* currentButton = wxDynamicCast(event.GetEventObject(), wxButton);
		currentButton->SetBackgroundColour(wxColor(155, 142, 255));
		currentButton->Refresh();
	}

	/// <summary>
	/// Performs logic when the send button is clicked
	/// </summary>
	/// <param name="event"></param>
	void SendButtonClick(wxCommandEvent& event) {
		wxButton* currentButton = wxDynamicCast(event.GetEventObject(), wxButton);
		currentButton->SetBackgroundColour(wxColor(155, 142, 255));
		currentButton->Refresh();
	}

	///// <summary>
	///// Clears the message type box text when initially clicked
	///// </summary>
	///// <param name="event"></param>
	//void InitialClearMessageTypeBox(wxMouseEvent& event) {
	//	wxTextCtrl* currentTextBox = wxDynamicCast(event.GetEventObject(), wxTextCtrl);
	//	string initialMessage = "Messages...";
	//	string tet = currentTextBox->GetValue().ToStdString();

	//	if (tet.compare(initialMessage)) {
	//		currentTextBox->Clear();
	//		currentTextBox->Refresh();
	//	}

	//}

	~MainWindow();

private:
	/// <summary>
	/// Creates the send button on the message type panel
	/// </summary>
	/// <param name="msgTypePanel">Message Type Panel</param>
	/// <returns></returns>
	wxButton* CreateSendButton(wxPanel* msgTypePanel);

	/// <summary>
	/// Creates the add chat button on the chat panel
	/// </summary>
	/// <param name="chatPanel"></param>
	/// <returns></returns>
	wxButton* CreateAddChatButton(wxPanel* chatPanel);

	/// <summary>
	/// Creates the Chat Panel
	/// </summary>
	/// <param name="currentFrame">Current wxFrame</param>
	/// <returns></returns>
	wxPanel* CreateChatPanel(wxFrame* currentFrame);

	/// <summary>
	/// Creates the Message Panel
	/// </summary>
	/// <param name="currentFrame">Current wxFrame</param>
	/// <returns></returns>
	wxPanel* CreateMessagePanel(wxFrame* currentFrame);

	/// <summary>
	/// Creates the message type panel
	/// </summary>
	/// <param name="currentFrame">Current wxFrame</param>
	/// <returns></returns>
	wxPanel* CreateMessageTypePanel(wxFrame* currentFrame);

	/// <summary>
	/// Creates a message type box for users to type out there messages
	/// </summary>
	/// <param name="msgTypePanel">Message Type Panel</param>
	/// <returns></returns>
	wxTextCtrl* CreateMessageTypeBox(wxPanel* msgTypePanel);

};

