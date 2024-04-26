#include "MainWindow.h"
#include <wx/wx.h>
#include <wx/splitter.h>
#include "Version.h"
#include "Message.h"
#include "Chat.h"



wxButton* MainWindow::CreateSendButton(wxPanel* msgTypePanel) {
	// Send Button
	wxButton* sendMsgButton = new wxButton(msgTypePanel, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	sendMsgButton->SetBackgroundColour(wxColor(111, 56, 255));
	sendMsgButton->SetForegroundColour(wxColor(200, 200, 200));

	// send button handlers
	sendMsgButton->Bind(wxEVT_ENTER_WINDOW, &MainWindow::ButtonHover, this);
	sendMsgButton->Bind(wxEVT_LEAVE_WINDOW, &MainWindow::ButtonLeave, this);
	sendMsgButton->Bind(wxEVT_BUTTON, &MainWindow::SendButtonClick, this);
	return sendMsgButton;
}

wxButton* MainWindow::CreateAddChatButton(wxPanel* chatPanel) {
	// add chat button
	wxButton* addChatButton = new wxButton(chatPanel, wxID_ANY, wxT("New Chat"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	addChatButton->SetBackgroundColour(wxColor(111, 56, 255));
	addChatButton->SetForegroundColour(wxColor(200, 200, 200));

	// send button handlers
	addChatButton->Bind(wxEVT_ENTER_WINDOW, &MainWindow::ButtonHover, this);
	addChatButton->Bind(wxEVT_LEAVE_WINDOW, &MainWindow::ButtonLeave, this);
	addChatButton->Bind(wxEVT_BUTTON, &MainWindow::AddChatButtonClick, this);
	return addChatButton;
}

wxPanel* MainWindow::CreateChatPanel(wxFrame *currentFrame) {
	// panel that contains chats created
	wxPanel* chatPanel = new wxPanel(currentFrame, wxID_ANY, wxDefaultPosition, wxSize(100, 100));
	chatPanel->SetBackgroundColour(wxColor(30, 30, 30));
	chatPanel->SetMaxSize(wxSize(300, 5000));
	return chatPanel;
}

wxPanel* MainWindow::CreateMessagePanel(wxFrame* currentFrame) {
	// panel that contains messages for current chat
	wxPanel* msgPanel = new wxPanel(currentFrame, wxID_ANY, wxDefaultPosition, wxSize(500, 600));
	msgPanel->SetBackgroundColour(wxColor(40, 40, 40));
	return msgPanel;
}

wxPanel* MainWindow::CreateMessageTypePanel(wxFrame* currentFrame) {
	// panel that allows the typing of a message
	wxPanel* msgTypePanel = new wxPanel(currentFrame, wxID_ANY, wxDefaultPosition, wxSize(500, 50));
	msgTypePanel->SetBackgroundColour(wxColor(33, 33, 33));
	return msgTypePanel;
}

wxTextCtrl* MainWindow::CreateMessageTypeBox(wxPanel* msgTypePanel) {
	wxTextCtrl* msgTypeBox = new wxTextCtrl(msgTypePanel, wxID_ANY, "Message...", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, wxTextCtrlNameStr);
	msgTypeBox->SetBackgroundColour(wxColour(50, 50, 50));
	msgTypeBox->SetForegroundColour(wxColor(200, 200, 200));
	//msgTypeBox->Bind(wxEVT_LEFT_DOWN, &MainWindow::InitialClearMessageTypeBox, this);
	return msgTypeBox;
}

wxPanel* MainWindow::CreateSubChatPanel(wxPanel* chatPanel) {
	wxPanel* subChatPanel = new wxPanel(chatPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxString("ChatSubPanel"));
	subChatPanel->SetBackgroundColour(wxColor(30, 30, 30));
	return subChatPanel;
}

// main window GUI logic
MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {

	/*
	* MAIN ELEMENTS
	*/

	// Chat Panel Controls
	wxPanel* chatPanel = CreateChatPanel(this); // panel that contains chats
	wxButton* addChatButton = CreateAddChatButton(chatPanel); // add chat button

	// Message Panel Controls
	wxPanel* msgPanel = CreateMessagePanel(this); // panel that contains messages
	wxStaticText* versionText = CreateVersionText(msgPanel);

	// Message Type Panel Controls
	wxPanel* msgTypePanel = CreateMessageTypePanel(this); // panel that allows the typing of a message
	wxButton* sendMsgButton = CreateSendButton(msgTypePanel); // send button
	wxTextCtrl* msgTypeBox = CreateMessageTypeBox(msgTypePanel); // message type box

	/*
	* SIZERS
	*/

	// chat side panel sizer
	wxBoxSizer* leftSizer = new wxBoxSizer(wxHORIZONTAL);
	leftSizer->Add(chatPanel, 1, wxEXPAND | wxLEFT);

	// chat side information sizer
	wxBoxSizer* addChatSizer = new wxBoxSizer(wxVERTICAL);
	chatPanel->SetSizer(addChatSizer);
	addChatSizer->Add(addChatButton, 0, wxALL | wxALIGN_TOP | wxEXPAND);

	// msg side sizers
	wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
	rightSizer->Add(msgPanel, 1, wxEXPAND | wxALL);
	rightSizer->Add(msgTypePanel, 0, wxEXPAND | wxALL);
	leftSizer->Add(rightSizer, 1, wxEXPAND | wxALL); // splits the left chat panel and message panels
	this->SetSizerAndFit(leftSizer);

	if (!isProduction) {
		wxBoxSizer* versionSizer = new wxBoxSizer(wxVERTICAL);
		msgPanel->SetSizer(versionSizer);
		versionSizer->Add(versionText, 0, wxALL | wxALIGN_RIGHT, 2);
	}

	// message type box sizer
	wxBoxSizer* messageTypeSizerLeft = new wxBoxSizer(wxHORIZONTAL);
	msgTypePanel->SetSizer(messageTypeSizerLeft);
	messageTypeSizerLeft->Add(msgTypeBox, 1, wxALL | wxEXPAND, 5);
	messageTypeSizerLeft->Add(sendMsgButton, 0, wxALL | wxEXPAND);

	//CreateStatusBar(2);

	/*
	* Message Logic
	*/
	Message* msg = new Message(msgPanel);
	wxBoxSizer* msgSubSizer = new wxBoxSizer(wxVERTICAL);
	msgPanel->SetSizer(msgSubSizer);
	msgSubSizer->Add(msg, 1, wxALL | wxEXPAND, 50);
		
	/*
	* Chat Logic
	*/
	wxPanel* subChatPanel = CreateSubChatPanel(chatPanel);
	wxBoxSizer* chatPanelSubSizer = new wxBoxSizer(wxVERTICAL);
	chatPanel->SetSizer(chatPanelSubSizer);
	chatPanelSubSizer->Add(addChatButton, 0, wxALL | wxEXPAND | wxALIGN_TOP);
	chatPanelSubSizer->Add(subChatPanel, 1, wxALL | wxEXPAND);
	
	// sub chat panel sizer
	wxBoxSizer* subChatPanelSizer = new wxBoxSizer(wxVERTICAL);
	subChatPanel->SetSizer(subChatPanelSizer);
}

// destructor
MainWindow::~MainWindow() {

}


