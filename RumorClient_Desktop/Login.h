#pragma once
#include <wx/wx.h>


class Login : public wxFrame
{
public:
	Login(const wxString &title,
		  const wxPoint &pos,
		  const wxSize &size);
	~Login();
};

