#include "Chat.h"
#include <chrono>
using namespace std;

Chat::Chat(wxPanel* chatPanel) {
	chatBoxPanel = new wxPanel(chatPanel, wxID_ANY, wxDefaultPosition, wxSize(300, 75), wxBORDER_SIMPLE);
	
	chatBoxPanel->SetBackgroundColour(wxColor(30, 30, 30));
	chatBoxPanel->SetMaxSize(wxSize(300, 75));

	// chat panel bindings
	chatBoxPanel->Bind(wxEVT_ENTER_WINDOW, &Chat::HoverOverChat, this);
	chatBoxPanel->Bind(wxEVT_LEAVE_WINDOW, &Chat::MouseLeftChat, this);
	chatBoxPanel->Bind(wxEVT_LEFT_UP, &Chat::ChatClicked, this);

	// initialize member variables
	username = "Test Username";
	isActive = false;
	lastMessage = "This is the last message that was sent in the chat.";
	chatID = 0;

	// display username of other user
	wxStaticText* displayUsername = new wxStaticText(chatBoxPanel, wxID_ANY, wxString::FromUTF8(username.c_str()));
	displayUsername->SetForegroundColour(wxColor(200, 200, 200));
	auto usernameFont = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	displayUsername->SetFont(usernameFont);

	// display last message
	wxStaticText* displayLastMessage = new wxStaticText(chatBoxPanel, wxID_ANY, wxString::FromUTF8(lastMessage.c_str()));
	displayLastMessage->SetForegroundColour(wxColor(170, 170, 170));
	auto lastMessageFont = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	displayLastMessage->SetFont(lastMessageFont);

	wxBoxSizer* chatInfoSizer = new wxBoxSizer(wxVERTICAL);
	chatInfoSizer->Add(displayUsername, 0, wxEXPAND | wxLEFT | wxTOP, 10);
	chatInfoSizer->Add(displayLastMessage, 0, wxEXPAND | wxLEFT, 12);
	chatBoxPanel->SetSizer(chatInfoSizer);
	chatBoxPanel->Layout();
}

wxPanel* Chat::GetChatBoxPanel()
{
	return chatBoxPanel;
}
