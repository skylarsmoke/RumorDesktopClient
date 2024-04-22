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


	MainWindow *mainWindow = new MainWindow("Rumor", wxDefaultPosition, wxSize(1200, 700));
	mainWindow->Show(true);


	return true;
}

App::~App() {

}


