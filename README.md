# Untitled Game

A fast-paced **top-down arena shooter** inspired by *Borderlands* and *Vampire Survivors*. Fight off hoardes of enemies and collect stronger gear.

---

## Requirements

* **C compiler** with C99 support
  * GCC / Clang / MSVC
* **CMake 3.15+**
* **Git**

### Libraries

* [raylib](https://www.raylib.com/) (graphics, input, audio)

> raylib must be installed on your system or available via your package manager.

---

## Building

This project uses **CMake**

### 1. Clone the repository

```bash
git clone https://github.com/nullptr45/xmas-game
cd xmas-game
```

---

### 2. Create a build directory

```bash
mkdir build
cd build
```

---

### 3. Configure with CMake

```bash
cmake ..
```

If raylib is installed in a custom location, you may need to specify it:

```bash
cmake .. -DCMAKE_PREFIX_PATH=/path/to/raylib
```

---

### 4. Build

```bash
cmake --build .
```

---

### 5. Run

After building, run the executable from the `build` directory:

```bash
./game
```

(On Windows, run the generated `.exe` file.)

---

## Controls

* **Movement** - WASD
* **Aim** - Mouse
* **Shoot** - Left click
* **Reload** - R

---

## Design Notes

* Uses **simple circle-based collision**
* Physics are intentionally lightweight (velocity + friction)

This codebase is meant to be **easy to modify and extend**, not production-ready.

---

## [Roadmap](todo.md)

---

## License

Do whatever you want

---

## Credits

* Built with **raylib**
* Inspired by *Borderlands* and *Vampire Survivors*

