#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "bguil.h"

std::string font_path;

void parse_args(int argc, char **argv) {
  for(int i = 1; i < argc; ++i) {
    std::string arg = argv[i-1];
    if(arg == "-f" || arg == "--font") {
      font_path = argv[i];
    }
  }
}

// bguil::Component component(bguil::Props<UserDefinedProps> props) {
//   // initialize state
//   struct state {
//     int counter = 0;
//     int other_data = props.passed_from_parent;
//   } init_state;
//   bguil::State state = bguil::State(init_state);

//   return bguil::Render("   \
//     <div class='my-class'> \
//       Hello world :)       \
//     </div>                 \
//   ");
// }

int main(int argc, char **argv) {
  bguil gui = bguil();
  gui.RenderText(0, 0, "Hello world :]", { 255, 255, 255, 0 });
  gui.RenderLoop();

  return 0;
}