#include "Login.h"
#include <wx/wx.h>
#include "Version.h"

// contains logic for the Login Frame

wxTextCtrl* Login::CreateUsernameField(wxPanel* parent) {
	wxTextCtrl* usernameField = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	usernameField->SetBackgroundColour(wxColor(30, 30, 30));
	usernameField->SetForegroundColour(wxColor(200, 200, 200));
	usernameField->SetMaxLength(20);
	return usernameField;
}

wxTextCtrl* Login::CreatePasswordField(wxPanel* parent) {
	wxTextCtrl* passwordField = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_PASSWORD);
	passwordField->SetBackgroundColour(wxColor(30, 30, 30));
	passwordField->SetForegroundColour(wxColor(200, 200, 200));
	passwordField->SetMaxLength(20);
	return passwordField;
}

wxButton* Login::CreateButton(wxPanel* parent, wxString buttonText) {
	wxButton* button = new wxButton(parent, wxID_ANY, buttonText, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	button->SetBackgroundColour(wxColor(111, 56, 255));
	button->SetForegroundColour(wxColor(200, 200, 200));
	button->SetMinSize(wxSize(0, 40));
	button->Bind(wxEVT_ENTER_WINDOW, &Login::ButtonHover, this);
	button->Bind(wxEVT_LEAVE_WINDOW, &Login::ButtonLeave, this);

	return button;
}

// Login Frame Object
Login::Login(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {

	this->SetMaxSize(wxSize(500, 400));

	// login window GUI logic
	wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	mainPanel->SetBackgroundColour(wxColor(30, 30, 30));

	// rumor image panel
	wxPanel* rumorImgPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(75, 10));
	rumorImgPanel->SetBackgroundColour(wxColor(50, 50, 50));
	rumorImgPanel->SetMinSize(wxSize(45, 100));

	// temp text to be replaced by an image
	wxStaticText* rumorText = new wxStaticText(rumorImgPanel, wxID_ANY, wxT("Rumor"));
	auto rumorFont = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	rumorText->SetFont(rumorFont);

	// temp sizer for text
	wxBoxSizer* tempSizer = new wxBoxSizer(wxVERTICAL);
	tempSizer->Add(rumorText, 0, wxCENTER | wxTOP, 30);
	rumorImgPanel->SetSizer(tempSizer);

	// main sizer
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(rumorImgPanel, 0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 30);
	mainPanel->SetSizer(mainSizer);

	// panel containing username fields
	wxPanel* usernamePanel = new wxPanel(mainPanel, wxID_ANY);
	usernamePanel->SetBackgroundColour(wxColor(30, 30, 30));
	mainSizer->AddSpacer(30);
	mainSizer->Add(usernamePanel, 0, wxEXPAND | wxLEFT | wxRIGHT, 60);

	// username field
	auto loginFont = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxStaticText* usernameText = new wxStaticText(usernamePanel, wxID_ANY, wxT("Username"));
	usernameText->SetBackgroundColour(wxColor(30,30,30));
	usernameText->SetForegroundColour(wxColor(200, 200, 200));
	usernameText->SetFont(loginFont);

	wxTextCtrl* usernameField = CreateUsernameField(usernamePanel);
	usernameField->SetFont(loginFont);

	// username styling panel
	wxPanel* usernameStylePanel = new wxPanel(usernamePanel, wxID_ANY);
	usernameStylePanel->SetBackgroundColour(wxColor(200, 200, 200));
	usernameStylePanel->SetMinSize(wxSize(0, 1));

	// username sizer
	wxBoxSizer* usernameSizer = new wxBoxSizer(wxVERTICAL);
	usernameSizer->Add(usernameText, 0, wxEXPAND);
	usernameSizer->AddSpacer(5);
	usernameSizer->Add(usernameField, 0, wxEXPAND | wxBOTTOM, 1);
	usernameSizer->AddSpacer(5);
	usernameSizer->Add(usernameStylePanel, 0, wxEXPAND);
	usernamePanel->SetSizer(usernameSizer);

	// panel containing password fields
	wxPanel* passwordPanel = new wxPanel(mainPanel, wxID_ANY);
	passwordPanel->SetBackgroundColour(wxColor(30, 30, 30));
	mainSizer->AddSpacer(20);
	mainSizer->Add(passwordPanel, 0, wxEXPAND | wxLEFT | wxRIGHT, 60);

	// password field
	wxStaticText* passwordText = new wxStaticText(passwordPanel, wxID_ANY, wxT("Password"));
	passwordText->SetBackgroundColour(wxColor(30, 30, 30));
	passwordText->SetForegroundColour(wxColor(200, 200, 200));
	passwordText->SetFont(loginFont);

	wxTextCtrl* passwordField = CreatePasswordField(passwordPanel);
	passwordField->SetFont(loginFont);

	// password styling panel
	wxPanel* passwordStylePanel = new wxPanel(passwordPanel, wxID_ANY);
	passwordStylePanel->SetBackgroundColour(wxColor(200, 200, 200));
	passwordStylePanel->SetMinSize(wxSize(0, 1));

	// password sizer
	wxBoxSizer* passwordSizer = new wxBoxSizer(wxVERTICAL);
	passwordSizer->Add(passwordText, 0, wxEXPAND);
	passwordSizer->AddSpacer(5);
	passwordSizer->Add(passwordField, 0, wxEXPAND | wxBOTTOM, 1);
	passwordSizer->AddSpacer(5);
	passwordSizer->Add(passwordStylePanel, 0, wxEXPAND);
	passwordPanel->SetSizer(passwordSizer);

	// button controls
	wxPanel* loginButtonPanel = new wxPanel(mainPanel, wxID_ANY);
	loginButtonPanel->SetBackgroundColour(wxColor(30, 30, 30));
	mainSizer->AddSpacer(8);
	mainSizer->Add(loginButtonPanel, 0, wxEXPAND | wxLEFT | wxRIGHT, 60);

	// buttons
	wxButton* loginButton = CreateButton(loginButtonPanel, wxT("Log In"));
	loginButton->Bind(wxEVT_BUTTON, &Login::LoginClick, this);

	wxButton* signUpButton = CreateButton(loginButtonPanel, wxT("Sign Up"));
	signUpButton->Bind(wxEVT_BUTTON, &Login::SignUpClick, this);

	// button sizer
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	buttonSizer->Add(loginButton, 1, wxEXPAND | wxRIGHT, 3);
	buttonSizer->Add(signUpButton, 1, wxEXPAND | wxLEFT, 3);
	loginButtonPanel->SetSizer(buttonSizer);

	wxStaticText* versionText = CreateVersionText(mainPanel);
	mainSizer->AddSpacer(25);
	mainSizer->Add(versionText, 0, wxALIGN_RIGHT | wxRIGHT, 5);

}

bool Login::AuthenticateLogin(wxString username, wxString password) {
	return true;
}

// Login Destructor
Login::~Login() {

}