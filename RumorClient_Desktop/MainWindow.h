#pragma once

#include <wx/wx.h>
#include "Chat.h"
#include <vector>

using namespace std;

class MainWindow : public wxFrame
{
public:
	MainWindow(const wxString& title,
			   const wxPoint& pos,
			   const wxSize& size);

	vector<Chat*> chats;

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

		wxPanel* subChatPanel = wxDynamicCast(currentButton->FindWindowByName(wxString("ChatSubPanel")), wxPanel);
		Chat* chat = new Chat(subChatPanel);
		wxPanel* chatBoxPanel = chat->GetChatBoxPanel();
		clearActiveChat();

		// add chat to chat list
		chats.push_back(chat);
		chat->isActive = true;
		chatBoxPanel->SetBackgroundColour(wxColor(40, 40, 40));

		wxBoxSizer* sizer = wxDynamicCast(subChatPanel->GetSizer(), wxBoxSizer);
		sizer->Add(chatBoxPanel, 1, wxEXPAND);
		subChatPanel->Layout();
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
	void InitialClearMessageTypeBox(wxMouseEvent& event) {
		wxTextCtrl* currentTextBox = wxDynamicCast(event.GetEventObject(), wxTextCtrl);
		string initialMessage = "Messages...";
		string text = currentTextBox->GetValue().ToStdString();

		if (text.compare(initialMessage)) {
			currentTextBox->Clear();
			currentTextBox->Refresh();
		}

	}

	/// <summary>
	/// When a chat is switched to active this function unactives all the chats first
	/// </summary>
	void clearActiveChat() {
		for (int i = 0; i < chats.size(); i++) {
			if (chats[i]->isActive) {
				chats[i]->isActive = false;
				wxPanel* chatBoxPanel = chats[i]->GetChatBoxPanel();
				chatBoxPanel->SetBackgroundColour(wxColor(30, 30, 30));
				chatBoxPanel->Refresh();

				break;
			}
		}
	}

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

	/// <summary>
	/// Builds the panel where chats are listed
	/// </summary>
	/// <param name="chatPanel"></param>
	/// <returns></returns>
	wxPanel* CreateSubChatPanel(wxPanel* chatPanel);

};

