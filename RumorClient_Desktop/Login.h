#pragma once
#include <wx/wx.h>

class Login : public wxFrame
{
public:
	Login(const wxString &title,
		  const wxPoint &pos,
		  const wxSize &size);
	~Login();

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
	/// Logic that fires when the log in button is clicked
	/// </summary>
	/// <param name="event"></param>
	void LoginClick(wxCommandEvent& event) {
		wxButton* currentButton = wxDynamicCast(event.GetEventObject(), wxButton);
		currentButton->SetBackgroundColour(wxColor(155, 142, 255));
		currentButton->Refresh();
	}

	/// <summary>
	/// Logic that fires when the sign up button is clicked
	/// </summary>
	/// <param name="event"></param>
	void SignUpClick(wxCommandEvent& event) {
		wxButton* currentButton = wxDynamicCast(event.GetEventObject(), wxButton);
		currentButton->SetBackgroundColour(wxColor(155, 142, 255));
		currentButton->Refresh();
	}

private:

	/// <summary>
	/// Creates the username field
	/// </summary>
	wxTextCtrl* CreateUsernameField(wxPanel* parent);

	/// <summary>
	/// Creates the password field
	/// </summary>
	wxTextCtrl* CreatePasswordField(wxPanel* parent);

	/// <summary>
	/// Creates a rumor themed button
	/// </summary>
	wxButton* CreateButton(wxPanel* parent, wxString buttonText);

};

