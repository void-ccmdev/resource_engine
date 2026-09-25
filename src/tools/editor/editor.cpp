#include "application/editor_app.h"

int main(void)
{
    Editor::App app;
    app.title = "Resource Engine - Editor";
    return app.run();
}