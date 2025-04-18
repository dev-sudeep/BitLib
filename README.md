# bitlib – A Physics-Aware, Math-Smart, Cross-Platform C Library

**bitlib** is a high-level C library that brings together real-world **units**, **geometry**, **physics**, and **cross-platform terminal drawing** — all wrapped in simple, readable macros and type-safe structures.

You’ll never write `#define PI 3.14` again.

---

## ✨ Features

- ✅ SI-style units: `Length`, `Time`, `Mass`, `Area`, `Volume`, etc.
- ✅ Real-world math: `Speed`, `Acceleration`, `Force`, `Work`, `Power`
- ✅ Clean macros: `LENGTH(5)`, `SPEED(d, t)`, `AREA(l, b)`
- ✅ Terminal drawing: `draw_circle(x, y, r, "O")`, cross-platform
- ✅ File management: check existence, read/write files
- ✅ Percent, factorial, power, and geometry helpers
- ✅ Pure C89+ compatible, zero dependencies

---

## 📦 Headers
 _____________ _________________________________
| Header      | Purpose                         |
|-------------|---------------------------------|
| `maths.h`   | Physics units, macros, and math |
| `draw.h`    | Terminal-safe drawing functions |
| `files.h`   | File helpers and I/O wrappers   |
 ------------- ---------------------------------


## 🚀 Quick Start

### Option 1. Include the headers:

```c
#include "maths.h"
#include "draw.h"
#include "files.h"
```
### Option 2. Link the library:
```bash
gcc main.c -L./lib -libbitlib -o main
```

Now use the library as per your wish!

