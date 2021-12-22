#include "RxHelperMain.h"

wxIMPLEMENT_APP(RxHelperMain);

RxHelperMain::RxHelperMain()
{

}

RxHelperMain::~RxHelperMain()
{

}

bool RxHelperMain::OnInit()
{
	primary_frame = new PrimaryFrame();
	primary_frame->Show();

	return true;
}