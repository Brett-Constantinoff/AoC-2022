#pragma once
#include <chrono>
#include <iostream>

class Timer
{
    public:
        Timer(){};
        void start(void)
        {
             m_start = std::chrono::high_resolution_clock::now();
        }
        void stop(void)
        {
            m_stop = std::chrono::high_resolution_clock::now();
            m_time = std::chrono::duration_cast<std::chrono::duration<double>>(m_stop - m_start);
            std::cout << "Proccess took " << m_time.count() << " seconds." << "\n";
        }
    private:
        std::chrono::high_resolution_clock::time_point m_start;
        std::chrono::high_resolution_clock::time_point m_stop;
        std::chrono::duration<double> m_time;
};
