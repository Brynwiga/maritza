#include <iostream>
#include "Application.h"
#include "XmlDocument.h"
using namespace std;
int main(int argc, char *argv[])
{
    /*

        Here is where I'm testing modules.

    */

    XmlDocument doc;
    doc.AddToDocument("<hello tag=\"value\" anothertag='another value'>some inner stuff<innertag>inside</innertag><another /></hello>");
    cout << doc.Serialized << endl;
    doc.ListAttributes();

    Application MainApplication;
    if (argc == 1)
    {
        MainApplication.StartConsole();
    }
    else if (argc == 2)
    {
        string argument = argv[1];
        if (argument == "console")
        {
            MainApplication.StartConsole();
        }
        else if (argument == "editor")
        {
            MainApplication.StartEditor();
        }
        else if (argument == "info")
        {
            MainApplication.ShowInfo();
        }
        else if (argument == "help")
        {
            MainApplication.ShowHelp();
        }
        else
        {
            MainApplication.AnnounceIncorrectArguments();
        }
    }
    else if (argc == 3)
    {
        string argument = argv[1];
        if (argument == "literal")
        {
            MainApplication.PerformLiteral(argv[2]);
        }
        else
        {
            MainApplication.AnnounceIncorrectArguments();
        }
    }
    else
    {
        MainApplication.AnnounceIncorrectArguments();
    }
    return 0;
}
