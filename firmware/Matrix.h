#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

#include "MCP23S17.h"

class Matrix {
  public:
    enum class Dim {
      Row = 7,
      Col = 12,
    };

    struct Key {
      uint8_t r;
      uint8_t c;
    };

    Matrix(void);
    void begin(void);
    bool scan(void);
    bool pressed(const Key k) const;

  private:
    struct KeyState {
      uint8_t pressTime;
      bool pressed;
    };

    MCP mcp;
    KeyState keys[(int)Dim::Row][(int)Dim::Col];

    static const uint8_t rowPins[];
    static const uint8_t colPins[];
    static const uint8_t debounceTime = 5;
};

#endif
