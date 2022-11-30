#include "../include/LongNumberLib.h"
#include "../include/LongNumberLibTest.h"
#include <chrono>

int main(int argc, char *argv[]) {
	auto begin = std::chrono::steady_clock::now();
	LNL::pow(LNL::LongInt(11000000000000000), LNL::LongInt(10000));
	auto end = std::chrono::steady_clock::now();
	auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << elapsedTime.count();
	// std::cout << "Time: " << elapsedTime.count() << "ms\n";
    return 0;
}
