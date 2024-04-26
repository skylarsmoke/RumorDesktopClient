#pragma once

/*
Contains logic for the message object that displays a message
*/

#include <wx/wx.h>
#include <iostream>


using namespace std;

class Message : public wxPanel
{
public:
	// constructor
	Message(wxWindow* parent);

	string message;

	~Message();


};

