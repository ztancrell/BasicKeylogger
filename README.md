# BasicKeylogger

A simple, educational C++ console keylogger application with a menu, fun easter eggs, and support for both Windows and Linux/macOS terminals.

---

## ⚠️ DISCLAIMER

> **This project is for educational and demonstration purposes only.**
>
> Do not use this software to violate other people's privacy or break the law. Always obtain explicit permission before running any keylogger on a system you do not own or control.

---

## Features

- **Menu-based interface** with options to start logging, read about the project, or exit.
- **Keylogging**:
  - Windows: Uses native API to capture keystrokes (including special keys).
  - Linux/macOS: Uses raw terminal mode for basic keystroke capture.
- **Easter Eggs**: Enter secret menu options "69" or "420" for a surprise.
- **Cross-platform**: Works on both Windows and Linux/macOS.
- **Colorful and fun**: Includes playful ASCII art and beeps.

---

## Building

### Requirements

- **Windows:** MinGW or MSVC (Visual Studio)
- **Linux/macOS:** g++ and build-essential tools

### Build steps

```sh
# On Linux/macOS
./build.sh

# On Windows (MinGW)
./build.sh
# Or manually:
g++ -std=c++11 -o build/BasicKeylogger src/BasicKeylogger.cpp -pthread
```

---

## Usage

```sh
./build/BasicKeylogger
```

- Use the menu to start the keylogger, view information, or exit.
- Press `ESC` to stop keylogging.
- Try menu options `69` and `420` for easter eggs!

---

## Project Structure

```
src/BasicKeylogger.cpp   # Main source code
build.sh                 # Build script
clean.sh                 # Clean build artifacts
README.md                # This file
```

---

## About

Originally written as a programming exercise on Windows 10, this project was improved, cleaned up, and made cross-platform with modern C++.  
It is intended purely for learning and demonstration.

---

**Author:** Zachary Tancrell ([ztancrell](https://github.com/ztancrell))

---

## License

This project is released under the GNU General Public License v3.0 (GPL-3.0). See [LICENSE](LICENSE) for details.

---

**Free software, free as in freedom!**