#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../raygui.h"
#include <iostream>

const int buttonWidth = 50;
const int buttonHeight = 50;
const int buttonSpacing = 14;

const int startY = 70;
const int rowSpacing = 10; 

char textBoxText[256] = "0";
bool operationSet = false;
char currentOperation = '\0';
int operand1 = 0;
int operand2 = 0;

const int screenWidth = 300;
const int screenHeight = 300;

// Calculate the total width of all buttons including spacing
int totalButtonsWidth = (buttonWidth * 3) + (buttonSpacing * 2);
// Calculate the starting x position for the first button
float startX = (screenWidth - totalButtonsWidth) / 4;

Rectangle oneNumber = {startX, startY, buttonWidth, buttonHeight};
Rectangle twoNumber = {startX + buttonWidth + buttonSpacing, startY, buttonWidth, buttonHeight};
Rectangle threeNumber = {startX + (buttonWidth + buttonSpacing) * 2, startY, buttonWidth, buttonHeight};
Rectangle addition = {startX + (buttonWidth + buttonSpacing) * 3, startY, buttonWidth, buttonHeight};

Rectangle fourNumber = {startX, startY + (buttonHeight + rowSpacing) * 1, buttonWidth, buttonHeight};
Rectangle fiveNumber = {startX + buttonWidth + buttonSpacing, startY + (buttonHeight + rowSpacing), buttonWidth, buttonHeight};
Rectangle sixNumber = {startX + (buttonWidth + buttonSpacing) * 2, startY + (buttonHeight + rowSpacing), buttonWidth, buttonHeight};
Rectangle subtraction = {startX + (buttonWidth + buttonSpacing) * 3, startY + (buttonHeight + rowSpacing), buttonWidth, buttonHeight};

Rectangle sevenNumber = {startX, startY + (buttonHeight + rowSpacing) * 2, buttonWidth, buttonHeight};
Rectangle eightNumber = {startX + buttonWidth + buttonSpacing, startY + (buttonHeight + rowSpacing) * 2, buttonWidth, buttonHeight};
Rectangle nineNumber = {startX + (buttonWidth + buttonSpacing) * 2, startY + (buttonHeight + rowSpacing) * 2, buttonWidth, buttonHeight};
Rectangle equals = {startX + (buttonWidth + buttonSpacing) * 3, startY + (buttonHeight + rowSpacing) * 2, buttonWidth, buttonHeight};

Rectangle zero = {startX + buttonWidth/2 + buttonSpacing, 245, buttonWidth * 2, buttonHeight/1.1};

Rectangle clearBox = {190, 245, buttonWidth, buttonHeight/1.1};
Rectangle textBox = {50, 10, 200, 40};

static void DrawCalculator(void);
static void UpdateCalculator(void);

int main(void){
    InitWindow(screenWidth,screenHeight, "simple little calculator");
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        UpdateCalculator();
        DrawCalculator();
    }
    CloseWindow();
    return 0;
}

void DrawCalculator(void)
{
    BeginDrawing();
        ClearBackground(WHITE);
        GuiTextBox(textBox, textBoxText, 256, false);

        if(GuiButton(oneNumber, "1")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 1;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 1;
                sprintf(textBoxText, "%d", operand2);
            }
        }
        if(GuiButton(twoNumber, "2")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 2;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 2;
                sprintf(textBoxText, "%d", operand2);
            }
        }
        if(GuiButton(threeNumber, "3")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 3;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 3;
                sprintf(textBoxText, "%d", operand2);
            }
        }

        if(GuiButton(fourNumber, "4")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 4;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 4;
                sprintf(textBoxText, "%d", operand2);
            }
        }
        if(GuiButton(fiveNumber, "5")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 5;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 5;
                sprintf(textBoxText, "%d", operand2);
            }
        }
        if(GuiButton(sixNumber, "6")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 6;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 6;
                sprintf(textBoxText, "%d", operand2);
            }
        }

        if(GuiButton(sevenNumber, "7")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 7;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 7;
                sprintf(textBoxText, "%d", operand2);
            }
        }
        if(GuiButton(eightNumber, "8")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 8;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 8;
                sprintf(textBoxText, "%d", operand2);
            }
        }
        if(GuiButton(nineNumber, "9")) {
            if (!operationSet) {
                operand1 = operand1 * 10 + 9;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10 + 9;
                sprintf(textBoxText, "%d", operand2);
            }
        }

        if(GuiButton(zero, "0")){
            if (!operationSet) {
                operand1 = operand1 * 10;
                sprintf(textBoxText, "%d", operand1);
            } else {
                operand2 = operand2 * 10;
                sprintf(textBoxText, "%d", operand2);
            }
        }

        // Operations
        if (GuiButton(addition, "+")) {
            operationSet = true;
            currentOperation = '+';
            sprintf(textBoxText, "PLUS");
        }
        if (GuiButton(subtraction, "-")) {
            operationSet = true;
            currentOperation = '-';
            sprintf(textBoxText, "MINUS");
        }
        if (GuiButton(equals, "=")) {
             switch (currentOperation) {
                case '+':
                    sprintf(textBoxText, "%d", operand1 + operand2);
                break;
                case '-':
                    sprintf(textBoxText, "%d", operand1 - operand2);
                break;
        }
        operand1 = atoi(textBoxText);
        operand2 = 0;
        operationSet = false;
    }
    if(GuiButton(clearBox, "CLR")) {
        sprintf(textBoxText, "0");
        operand1 = 0;
        operand2 = 0;
        operationSet = false;
    }
        
    EndDrawing();
}

void UpdateCalculator(void)
{

}
