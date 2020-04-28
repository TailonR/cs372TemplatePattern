//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen

#include <iostream>
#include "shape.hpp"
#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"


int main(int argc, char* argv[]) {

    auto myCircle = makeCircle(50);
    auto myCustom = makeCustom(50,10,20);
    auto myRectangle = makeRectangle(40,60);
    auto myPolygon = makePolygon(5,50);
    auto myRotatedCustom = makeRotatedShape(myCustom, Angle::R90);
    auto myShapeList = {myCircle,myRectangle,myPolygon};
    
    auto myLayeredShapes = makeLayeredShape(myShapeList);
    auto myVerticalShapes = makeVerticalShape(myShapeList);
    auto myHorizontalShapes = makeHorizontalShape(myShapeList);

    //printPostScript(std::cout, myCircle);
    //printPostScript(std::cout, myCustom);
    //printPostScript(std::cout, myRectangle);
    //printPostScript(std::cout, myPolygon);
    printPostScript(std::cout, myRotatedCustom);
    printPostScript(std::cout, myLayeredShapes);
    printPostScript(std::cout, myVerticalShapes);
    printPostScript(std::cout, myHorizontalShapes);
    return 0;
}