#include <fstream>
#include <iostream>
#include "splash_screen.h"

const FakeJPEG* loadBitmap(std::string fileName) {
    FakeJPEG* result = new FakeJPEG();
    result->load(fileName);
    return result;
}

// if GameFile Exception check if fatal and if true then abort() (after writing messages)
// if runtime_error simply print error messages
void displaySplash() {
    // ... start graphics

    const FakeJPEG* splashScreen = loadBitmap(SPLASH_SCREEN_FILENAME); // XXX should work
    //const FakeJPEG* splashScreen = loadBitmap("non_existent_file.fake_jpg"); // XXX test GameFileException
    // const FakeJPEG* splashScreen = loadBitmap("./res/splash_screen_corrupted.fake_jpg"); // XXX test std::runtime_error
    // ... display bitmap
    auto bitmap = splashScreen->getBitmap();
    for (auto bitmapLine : bitmap)
        std::cout << bitmapLine << std::endl;

    // ... stop display
}