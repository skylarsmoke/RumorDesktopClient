#pragma once

#include <wx/wx.h>

class MainWindow : public wxFrame
{
public:
	MainWindow(const wxString& title,
			   const wxPoint& pos,
			   const wxSize& size);

	// send button hover event handler
	void SendButtonHover(wxMouseEvent& event) {
		this->SetBackgroundColour(wxColor(120, 20, 10));
		this->Refresh();
	}

	void SendButtonLeave(wxMouseEvent& event) {
		this->SetBackgroundColour(wxColor(50, 50, 50));
		this->Refresh();
	}

	void SendButtonClick(wxCommandEvent& event) {
		SetBackgroundColour(wxColor(300, 300, 300));
		Refresh();
		Update();
	}

	~MainWindow();

};

