// AboutDialog.cpp

#include "StdAfx.h"

#include "../../../../C/CpuArch.h"

#include "../../MyVersion.h"

#include "AboutDialog.h"
#include "PropertyNameRes.h"

#include "HelpUtils.h"
#include "LangUtils.h"

static const UInt32 kLangIDs[] =
{
  IDT_ABOUT_INFO
};

#define kHomePageURL  TEXT("http://www.7-zip.org/")
#define kHomePageURL2 TEXT("http://github.com/mcmilk/7-Zip-zstd/")
#define kHelpTopic "start.htm"

#define LLL_(quote) L##quote
#define LLL(quote) LLL_(quote)

bool CAboutDialog::OnInit()
{
  LangSetDlgItems(*this, kLangIDs, ARRAY_SIZE(kLangIDs));
  SetItemText(IDT_ABOUT_VERSION, UString("7-Zip " MY_VERSION_CPU));
  SetItemText(IDT_ABOUT_DATE, LLL(MY_DATE));
  
  LangSetWindowText(*this, IDD_ABOUT);
  NormalizePosition();
  return CModalDialog::OnInit();
}

void CAboutDialog::OnHelp()
{
  ShowHelpWindow(kHelpTopic);
}

bool CAboutDialog::OnButtonClicked(int buttonID, HWND buttonHWND)
{
  LPCTSTR url;
  switch (buttonID)
  {
    case IDB_ABOUT_HOMEPAGE: url = kHomePageURL; break;
    case IDB_ABOUT_HOMEPAGE2: url = kHomePageURL2; break;
    default:
      return CModalDialog::OnButtonClicked(buttonID, buttonHWND);
  }

  SHELLEXECUTEINFO s;
  memset(&s, 0, sizeof(s));
  s.cbSize = sizeof(s);
  s.lpFile = url;
  ::ShellExecuteEx(&s);

  return true;
}