#ifndef _LABEL_H_
#define _LABEL_H_

#include <string>

#include "View.h"
#include "utility.h"

using namespace std;

class Label : public View {
    string output;
    Alignment alignment;

   public:
    // Constructor, remeber to set selectable to false
    Label(int sizeX, int sizeY, string output = "", Alignment alignment = Alignment::CENTER);
    ~Label();
    // Setters: remember to call onChange and rerenderWindow() when setter is called
    void setOutput(string output);
    void setAlignment(Alignment alignment);

    void printAlignedText(string& text, Alignment alignment, int width);
    char** render();
   private:
    // Render the label, need to render text for different alignment
    void render_point(){
    }
};

#endif
