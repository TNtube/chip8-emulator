#pragma once
#include <cstdint>

#include "CPU.hpp"
#include "Keys.hpp"
#include "Memory.hpp"
#include "Screen.hpp"

namespace Chip8
{
    class Machine
    {
        Memory& m_memory;
        CPU m_cpu;
        // avoids to allocate/destroy this struct
        // a lot of time per second
        SDL_Event m_event {};
        Key m_key = Key::NONE;

    public:
        Machine(Screen& screen, Memory& memory, Keyboard& keyboard) noexcept;

        void ExecuteNextInstruction() noexcept;
        void Execute(std::uint16_t opcode) noexcept;
        void HandleEvents() noexcept;
    };
}
