#ifndef E131DIALOG_H
#define E131DIALOG_H

//(*Headers(E131Dialog)
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class E131Output;
class OutputManager;

class E131Dialog: public wxDialog
{
    E131Output* _e131;
    OutputManager* _outputManager;
    void ValidateWindow();

public:

    E131Dialog(wxWindow* parent, E131Output* e131, OutputManager* outputManager, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~E131Dialog();

    //(*Declarations(E131Dialog)
    wxTextCtrl* TextCtrlIpAddr;
    wxRadioButton* RadioButtonMulticast;
    wxSpinCtrl* SpinCtrl_NumUniv;
    wxRadioButton* RadioButtonUnicast;
    wxTextCtrl* TextCtrl_Description;
    wxSpinCtrl* SpinCtrl_StartUniv;
    wxButton* Button_Cancel;
    wxStaticText* StaticText1;
    wxStaticText* StaticText10;
    wxButton* Button_Ok;
    wxStaticText* StaticText3;
    wxCheckBox* CheckBox_SuppressDuplicates;
    wxCheckBox* MultiE131CheckBox;
    wxStaticText* StaticText8;
    wxSpinCtrl* SpinCtrl_LastChannel;
    wxStaticText* StaticText7;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText2;
    wxStaticText* StaticText6;
    wxSpinCtrl* SpinCtrl_Priority;
    wxStaticText* StaticText9;
    //*)

protected:

    //(*Identifiers(E131Dialog)
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT5;
    static const long ID_RADIOBUTTON1;
    static const long ID_RADIOBUTTON2;
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL_IP_ADDR;
    static const long ID_STATICTEXT2;
    static const long ID_SPINCTRL1;
    static const long ID_STATICTEXT3;
    static const long ID_SPINCTRL2;
    static const long ID_STATICTEXT7;
    static const long ID_CHECKBOX1;
    static const long ID_STATICTEXT6;
    static const long ID_SPINCTRL_LAST_CHANNEL;
    static const long ID_STATICTEXT8;
    static const long ID_TEXTCTRL_DESCRIPTION;
    static const long ID_STATICTEXT9;
    static const long ID_CHECKBOX2;
    static const long ID_STATICTEXT10;
    static const long ID_SPINCTRL_PRIORITY;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

private:

    //(*Handlers(E131Dialog)
    void OnRadioButtonUnicastSelect(wxCommandEvent& event);
    void OnRadioButtonMulticastSelect(wxCommandEvent& event);
    void OnSpinCtrl_NumUnivChange(wxSpinEvent& event);
    void OnTextCtrl_DescriptionText(wxCommandEvent& event);
    void OnTextCtrlIpAddrText(wxCommandEvent& event);
    void OnMultiE131CheckBoxClick(wxCommandEvent& event);
    void OnButton_OkClick(wxCommandEvent& event);
    void OnButton_CancelClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};
#endif
