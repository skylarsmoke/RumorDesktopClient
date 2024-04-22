#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif


class App : public wxApp {
public:
	// constructor
	App();
	bool OnInit();

	// destructor
	~App();

};

DECLARE_APP(App);
