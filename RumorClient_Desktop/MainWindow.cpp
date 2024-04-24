#include "MainWindow.h"
#include <wx/wx.h>
#include <wx/splitter.h>



/// <summary>
/// Creates the send button on the message type panel
/// </summary>
/// <param name="msgTypePanel">Message Type Panel</param>
/// <returns></returns>
wxButton* CreateSendButton(wxPanel* msgTypePanel) {
	// Send Button
	wxButton* sendMsgButton = new wxButton(msgTypePanel, -1, wxT("Send"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	sendMsgButton->SetBackgroundColour(wxColor(50, 50, 50));
	sendMsgButton->SetForegroundColour(wxColor(200, 200, 200));
	
	return sendMsgButton;
}

/// <summary>
/// Creates the Chat Panel
/// </summary>
/// <param name="currentFrame">Current wxFrame</param>
/// <returns></returns>
wxPanel* CreateChatPanel(wxFrame *currentFrame) {
	// panel that contains chats created
	wxPanel* chatPanel = new wxPanel(currentFrame, wxID_ANY, wxDefaultPosition, wxSize(100, 100));
	chatPanel->SetBackgroundColour(wxColor(30, 30, 30));
	chatPanel->SetMaxSize(wxSize(300, 5000));
	return chatPanel;
}

/// <summary>
/// Creates the Message Panel
/// </summary>
/// <param name="currentFrame">Current wxFrame</param>
/// <returns></returns>
wxPanel* CreateMessagePanel(wxFrame* currentFrame) {
	// panel that contains messages for current chat
	wxPanel* msgPanel = new wxPanel(currentFrame, wxID_ANY, wxDefaultPosition, wxSize(500, 600));
	msgPanel->SetBackgroundColour(wxColor(40, 40, 40));
	return msgPanel;
}

/// <summary>
/// Creates the message type panel
/// </summary>
/// <param name="currentFrame">Current wxFrame</param>
/// <returns></returns>
wxPanel* CreateMessageTypePanel(wxFrame* currentFrame) {
	// panel that allows the typing of a message
	wxPanel* msgTypePanel = new wxPanel(currentFrame, wxID_ANY, wxDefaultPosition, wxSize(500, 50));
	msgTypePanel->SetBackgroundColour(wxColor(33, 33, 33));
	return msgTypePanel;
}

// main window GUI logic
MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {

	// panel that contains chats
	wxPanel* chatPanel = CreateChatPanel(this);

	// panel that contains messages
	wxPanel* msgPanel = CreateMessagePanel(this);

	// panel that allows the typing of a message
	wxPanel* msgTypePanel = CreateMessageTypePanel(this);

	// send button
	wxButton* sendMsgButton = CreateSendButton(msgTypePanel);
	// send button handlers
	sendMsgButton->Bind(wxEVT_ENTER_WINDOW, &MainWindow::SendButtonHover, this);
	sendMsgButton->Bind(wxEVT_LEAVE_WINDOW, &MainWindow::SendButtonLeave, this);
	sendMsgButton->Bind(wxEVT_BUTTON, &MainWindow::SendButtonClick, this);

	// chat side sizer
	wxBoxSizer* leftSizer = new wxBoxSizer(wxHORIZONTAL);
	leftSizer->Add(chatPanel, 1, wxEXPAND | wxLEFT);

	// msg side sizers
	wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
	rightSizer->Add(msgPanel, 1, wxEXPAND | wxALL);
	rightSizer->Add(msgTypePanel, 0, wxEXPAND | wxALL);

	leftSizer->Add(rightSizer, 1, wxEXPAND | wxALL);

	// send button sizer
	wxBoxSizer* sendSizer = new wxBoxSizer(wxVERTICAL);
	msgTypePanel->SetSizer(sendSizer);
	sendSizer->Add(sendMsgButton, 0, wxALL | wxALIGN_RIGHT);

	this->SetSizerAndFit(leftSizer);
}

// destructor
MainWindow::~MainWindow() {

}

