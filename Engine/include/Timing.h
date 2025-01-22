#pragma once
#include <chrono>

namespace HookBill {
	class Timing
	{
	public:
		std::chrono::system_clock::time_point prev_time;
		std::chrono::system_clock::time_point start_time;
		double fps = 0;
		int count = 0;

	public:
		Timing() {
			start_time = std::chrono::system_clock::now();
			prev_time = start_time;
		}

		void update_timing() {
			const auto current_time = std::chrono::system_clock::now();

			prev_time = current_time;

			
			const auto elapsed_duration = std::chrono::duration_cast<std::chrono::milliseconds>(
				current_time - start_time);
			const double elapsed_ms = static_cast<double>(elapsed_duration.count()); 


			count++;
			if (elapsed_ms > 1000) 
			{ 
				fps = count / (elapsed_ms / 1000.0); 
				start_time = current_time;
				count = 0;
			}
		}

		double get_fps() const { return fps; }
	};
}
