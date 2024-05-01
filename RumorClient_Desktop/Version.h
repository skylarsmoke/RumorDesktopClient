#pragma once

/*
Contains version information
*/

#include <wx/wx.h>

/// <summary>
/// Creates a static text label displaying the version information
/// </summary>
/// <param name="panel"></param>
/// <returns></returns>
wxStaticText* CreateVersionText(wxPanel* panel) {
	wxStaticText* versionText = new wxStaticText(panel, wxID_ANY, wxT("Build v0.1.2"));
	
	versionText->SetForegroundColour(wxColor(50, 50, 50));
	return versionText;
}

bool isProduction = false;


