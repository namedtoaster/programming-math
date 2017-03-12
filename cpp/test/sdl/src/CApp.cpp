#include "CApp.h"

CApp::CApp() {
  Surf_Window = NULL;
  Surf_Display = NULL;
  Surf_Test = NULL;
  
  Running = true;
};

int CApp::OnExecute() {
  if (OnInit() == false)
    return -1;

  SDL_Event Event;

  while (Running) {
    while (SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }

    OnLoop();
    OnRender();
  }

  OnCleanup();
  
  return 0;
}

int main(int argc, char* argv[]) {
  CApp theApp;

  return theApp.OnExecute();
}
