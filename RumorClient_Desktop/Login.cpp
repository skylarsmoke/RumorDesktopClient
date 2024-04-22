#include "Login.h"
#include <wx/wx.h>

// contains logic for the Login Frame

// Login Frame Object
Login::Login(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {

	// login window GUI logic
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel->SetBackgroundColour(wxColor(30, 30, 30));

}

// Login Destructor
Login::~Login() {

}