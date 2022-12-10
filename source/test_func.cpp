// Copyright 2022 Mikhail Oborotov, Ivan Borisenkov, Elveg Khunshaev
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "../include/LongNumberLib.h"
#include "../include/LongNumberLibTest.h"
#include <chrono>

int main(int argc, char *argv[]) {
	auto begin = std::chrono::steady_clock::now();
	LNL::pow(LNL::LongInt(2), LNL::LongInt(101000));
	auto end = std::chrono::steady_clock::now();
	auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << elapsedTime.count();
	// std::cout << "Time: " << elapsedTime.count() << "ms\n";
    return 0;
}
