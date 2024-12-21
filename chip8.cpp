#include <cstdint>
#include <iostream>
#include <cstring>

class Chip8
{
private:
    uint8_t registers[0xF]{};
    uint8_t memory[0xFFF]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t st[16]{};
    uint8_t sp{};
    uint8_t delay_timer{};
    uint8_t audio_timer{};
    uint16_t keypad[16]{};
    uint32_t screen[64 * 32]{};
    uint16_t opcode{};

    // CLS operation: clear screen
    void Chip8::OP_00E0()
    {
        memset(screen, 0, sizeof(screen));
    }

    // RET operation: return from subroutine
    void Chip8::OP_00EE()
    {
        --sp;
        pc = st[sp];
    }

    // JUMP operation: move pc to address
    void Chip8::OP_1NNN()
    {
        pc = (opcode & 0x0FFFu);
    }

    // CALL operation: call subroutine at specified address
    void Chip8::OP_2NNN()
    {
        st[sp++] = pc;
        pc = (opcode & 0x0FFFu);
    }

    // SKIP operation: skip next operation if register = value
    void Chip8::OP_3XNN()
    {
        if (registers[(opcode & 0x0F00u) >> 8u] = (opcode & 0x00FFu))
            pc += 2;
    }

    // SKIP operation: skip next operation if register != value
    void Chip8::OP_4XNN()
    {
        if (registers[(opcode & 0x0F00u) >> 8u] != (opcode & 0x00FFu))
            pc += 2;
    }

    // SKIP operation: skip next operation if registerX = registerY
    void Chip8::OP_5XY0()
    {
        if (registers[(opcode & 0x0F00u) >> 8u] == registers[(opcode & 0x00F0) >> 4u])
            pc += 2;
    }

    // SKIP b nm
};
