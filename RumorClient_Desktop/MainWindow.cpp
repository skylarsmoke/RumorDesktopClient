#include "MainWindow.h"
#include <wx/wx.h>
#include <wx/splitter.h>

// main window GUI logic
MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {

	// panel that contains chats created
	wxPanel* chatPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100,100));
	chatPanel->SetBackgroundColour(wxColor(30, 30, 30));
	chatPanel->SetMaxSize(wxSize(300,5000));
	
	// panel that contains messages for current chat
	wxPanel* msgPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 600));
	msgPanel->SetBackgroundColour(wxColor(40, 40, 40));

	// panel that allows the typing of a message
	wxPanel* msgTypePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 50));
	msgTypePanel->SetBackgroundColour(wxColor(33, 33, 33));

	// Send Button
	wxButton* sendMsgButton = new wxButton(msgTypePanel, -1, wxT("Send"));

	// panel sizers
	wxBoxSizer* leftSizer = new wxBoxSizer(wxHORIZONTAL);
	leftSizer->Add(chatPanel, 1, wxEXPAND | wxLEFT);

	wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
	rightSizer->Add(msgPanel, 1, wxEXPAND | wxALL);
	rightSizer->Add(msgTypePanel, 0, wxEXPAND | wxALL);

	leftSizer->Add(rightSizer, 1, wxEXPAND | wxALL);

	this->SetSizerAndFit(leftSizer);
}

MainWindow::~MainWindow() {

}

