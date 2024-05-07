#include <iostream>
#include <stdexcept>

class TriangleApp {
public:
    TriangleApp();
    ~TriangleApp();
private:
    void mainLoop();
};

int main() {
    try{
        auto app = TriangleApp();
        return EXIT_SUCCESS;
    } catch(const std::exception& ex) {
        std::cout << ex.what();
        return EXIT_FAILURE;
    }
}

TriangleApp::TriangleApp() {}
TriangleApp::~TriangleApp() {}
