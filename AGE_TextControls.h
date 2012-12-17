#include "Common.h"
using std::string;
using std::vector;
using boost::lexical_cast;
using boost::bad_lexical_cast;

//	The purpose of these custom text controls is that you get specified error messages
//	when your mouse cursor focus gets off from a data edit box.

#ifndef AGE_TextControls_h
#define AGE_TextControls_h

class AGETextCtrl: public wxTextCtrl
{
	public:
	AGETextCtrl(wxWindow *parent, wxString value):
	wxTextCtrl(parent, wxID_ANY, value, wxDefaultPosition, wxSize(0, 20)){}

	virtual void OnKillFocus(wxFocusEvent &Event)=0;
	virtual bool SaveEdits()=0;

	void *LinkedBox; // These are for check and combo boxes.
};

class TextCtrl_Byte: public AGETextCtrl
{
	public:
	TextCtrl_Byte(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		container.resize(1);
		SetBackgroundColour(wxColour(255, 235, 215));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Byte::OnKillFocus));	// Must-have
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}

	vector<char*> container;
};

class TextCtrl_AByte: public AGETextCtrl
{
	public:
	TextCtrl_AByte(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		SetBackgroundColour(wxColour(255, 235, 215));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_AByte::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	// For auto-copy
	void resize(int size, int civs)
	{
		container.resize(civs);
		for(int civ=0; civ<civs; civ++)
		container[civ].resize(size);
	}

	vector<vector<char*>> container;
};

class TextCtrl_UByte: public AGETextCtrl
{
	public:
	TextCtrl_UByte(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		container.resize(1);
		SetBackgroundColour(wxColour(255, 235, 215));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_UByte::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}

	vector<unsigned char*> container;
};

class TextCtrl_Float: public AGETextCtrl
{
	public:
	TextCtrl_Float(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		container.resize(1);
		SetBackgroundColour(wxColour(255, 225, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Float::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}

	vector<float*> container;
};

class TextCtrl_AFloat: public AGETextCtrl
{
	public:
	TextCtrl_AFloat(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		SetBackgroundColour(wxColour(255, 225, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_AFloat::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	// For auto-copy
	void resize(int size, int civs)
	{
		container.resize(civs);
		for(int civ=0; civ<civs; civ++)
		container[civ].resize(size);
	}

	vector<vector<float*>> container;
};

class TextCtrl_Long: public AGETextCtrl
{
	public:
	TextCtrl_Long(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		container.resize(1);
		SetBackgroundColour(wxColour(215, 255, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Long::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}

	vector<int32_t*> container;
};

class TextCtrl_ALong: public AGETextCtrl
{
	public:
	TextCtrl_ALong(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		SetBackgroundColour(wxColour(215, 255, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_ALong::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	// For auto-copy
	void resize(int size, int civs)
	{
		container.resize(civs);
		for(int civ=0; civ<civs; civ++)
		container[civ].resize(size);
	}

	vector<vector<int32_t*>> container;
};

class TextCtrl_Short: public AGETextCtrl
{
	public:
	TextCtrl_Short(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		container.resize(1);
		SetBackgroundColour(wxColour(210, 230, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Short::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}

	vector<int16_t*> container;
};

class TextCtrl_AShort: public AGETextCtrl
{
	public:
	TextCtrl_AShort(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		SetBackgroundColour(wxColour(210, 230, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_AShort::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	// For auto-copy
	void resize(int size, int civs)
	{
		container.resize(civs);
		for(int civ=0; civ<civs; civ++)
		container[civ].resize(size);
	}

	vector<vector<int16_t*>> container;
};

class TextCtrl_UShort: public AGETextCtrl
{
	public:
	TextCtrl_UShort(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		container.resize(1);
		SetBackgroundColour(wxColour(210, 230, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_UShort::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}

	vector<uint16_t*> container;
};

class TextCtrl_AUShort: public AGETextCtrl
{
	public:
	TextCtrl_AUShort(wxWindow *parent):
	AGETextCtrl(parent, "0")
	{
		SetBackgroundColour(wxColour(210, 230, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_AUShort::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	// For auto-copy
	void resize(int size, int civs)
	{
		container.resize(civs);
		for(int civ=0; civ<civs; civ++)
		container[civ].resize(size);
	}

	vector<vector<uint16_t*>> container;
};

class TextCtrl_String: public AGETextCtrl
{
	public:
	TextCtrl_String(wxWindow *parent, int16_t CLength = -1):
	AGETextCtrl(parent, "")
	{
		container.resize(1);
		MaxSize = CLength;
		SetBackgroundColour(wxColour(220, 255, 220));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_String::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void resize(int size){container.resize(size);}
	void SetMaxSize(int16_t Size){MaxSize = Size;}

	int16_t MaxSize;
	vector<string*> container;
};

class TextCtrl_AString: public AGETextCtrl
{
	public:
	TextCtrl_AString(wxWindow *parent, int16_t CLength = -1):
	AGETextCtrl(parent, "")
	{
		MaxSize = CLength;
		SetBackgroundColour(wxColour(220, 255, 220));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_AString::OnKillFocus));
	}

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	// For auto-copy
	void resize(int size, int civs)
	{
		container.resize(civs);
		for(int civ=0; civ<civs; civ++)
		container[civ].resize(size);
	}
	void SetMaxSize(int16_t Size){MaxSize = Size;}

	int16_t MaxSize;
	vector<vector<string*>> container;
};

#endif
