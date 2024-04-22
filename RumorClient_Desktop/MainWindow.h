#pragma once

#include <wx/wx.h>

class MainWindow : public wxFrame
{
public:
	MainWindow(const wxString& title,
			   const wxPoint& pos,
			   const wxSize& size);
	~MainWindow();

};

