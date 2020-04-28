//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen

#include <iostream>
#include "shape.hpp"
#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"


int main(int argc, char* argv[]) {
    Catch::Session testing;
    int catchresult;
    catchresult = testing.applyCommandLine(argc, argv);
    if (!catchresult) {
        std::cout << "Begin tests for class shapes and its derived classes: \n";
        catchresult = testing.run();
        std::cout << "End of automated tests.\n"; 
    }

    auto myCircle = makeCircle(50);
    auto myCustom = makeCustom(50,10,20);
    auto myRectangle = makeRectangle(40,60);
    auto myPolygon = makePolygon(5,50);
    auto myRotatedCustom = makeRotatedShape(myCustom, Angle::R90);
    auto myShapeList = {myCircle,myRectangle,myPolygon};
    auto myLayeredShapes = makeLayeredShape(myShapeList);
    auto myTriangle = makeTriangle(100);

    printPostScript(std::cout, myTriangle);
    printPostScript(std::cout, myCircle);
    printPostScript(std::cout, myCustom);
    printPostScript(std::cout, myRectangle);
    printPostScript(std::cout, myPolygon);
    printPostScript(std::cout, myRotatedCustom);
    printPostScript(std::cout, myLayeredShapes);
    return 0;
}