#include <chrono>
#include <iostream>
#include <limits.h>
#include <thread>
#include <vector>

void heartbeat() {
  while (true) {
    // Allocate ~1GB of memory (spike)
    std::vector<int> spike;
    for (int i = 0; i < INT_MAX / 4; ++i) { // 4000 chunks of 256KB each
      spike.push_back(1);                   // 262144 bytes = 256KB
    }
    std::cout << "Heartbeat spike (1GB)...\n";

    // Hold the spike for 500ms
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Free memory (drop back)
    spike.clear();
    std::cout << "Rest period...\n";

    // Rest for 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

int main() {
  heartbeat();
  return 0;
}
