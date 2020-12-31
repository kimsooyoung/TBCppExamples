
#include "Worker.h"
#include "Timer.h"

void Worker::doSomething(){
    Timer timer;

    // do something
    std::cout << "Passsed time : ";

    timer.elapsed();
}