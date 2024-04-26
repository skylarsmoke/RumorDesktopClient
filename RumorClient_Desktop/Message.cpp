#include "Message.h"

/*
Contains logic for the messages object
*/


Message::Message(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(200, 50)) {
	this->SetBackgroundColour(wxColor(30, 30, 30));

	// incoming message panel
	wxPanel* incomingMessagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2621440L, wxT("IncomingMessagePanel"));
	incomingMessagePanel->SetBackgroundColour(wxColor(30, 30, 30));

	// outbound message panel
	wxPanel* outboundMessagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2521440L, wxT("OutboundMessagePanel"));
	outboundMessagePanel->SetBackgroundColour(wxColor(30, 30, 30));

	// sizer for splitting outbound and incoming message panels
	wxBoxSizer* messagePanelSplitSizer = new wxBoxSizer(wxHORIZONTAL);
	messagePanelSplitSizer->Add(incomingMessagePanel, 1, wxEXPAND | wxLEFT);
	messagePanelSplitSizer->Add(outboundMessagePanel, 1, wxEXPAND | wxRIGHT);
	this->SetSizer(messagePanelSplitSizer);
	
	// create message 
	wxStaticText* msg = new wxStaticText(outboundMessagePanel, wxID_ANY, wxT("Test Message"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxALIGN_CENTRE_HORIZONTAL);
	msg->SetBackgroundColour(wxColor(111, 56, 255));
	msg->SetForegroundColour(wxColor(200, 200, 200));
	msg->SetMaxSize(wxSize(200, 50));
	

	// outbound side sizer
	wxBoxSizer* outboundSizer = new wxBoxSizer(wxVERTICAL);
	outboundSizer->Add(msg, 0, wxEXPAND | wxCENTER);
	outboundMessagePanel->SetSizer(outboundSizer);
	
	// center message
	/*wxBoxSizer* msgSizer = new wxBoxSizer(wxVERTICAL);
	msgSizer->Add(msg, 0, wxCENTER);
	this->SetSizer(msgSizer);
	this->Layout();*/


}

Message::~Message() {

}