#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    lab_07::mainForm form;
    Application::Run(%form);
}
