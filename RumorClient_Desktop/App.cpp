/*
Main project file where we execute the start of the GUI and program
*/

#include <wx/wx.h>
#include "App.h"
#include "Login.h"
#include "MainWindow.h"

wxIMPLEMENT_APP(App);

App::App()
{
}

bool App::OnInit() {
	if (!wxApp::OnInit()) return false;

	// login window
	Login* login = new Login("Rumor", wxDefaultPosition, wxSize(500, 400));
	login->Center();
	login->Show(true);

	loggedIn = false;
	
	// main window
	if (loggedIn) {
		MainWindow* mainWindow = new MainWindow("Rumor", wxDefaultPosition, wxSize(1200, 700));
		mainWindow->Center();
		mainWindow->Show(true);
	}
	


	return true;
}

App::~App() {

}


