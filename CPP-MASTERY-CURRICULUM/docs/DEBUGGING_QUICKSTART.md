# Quick Start: Debugging in VS Code

## ✅ Your Setup is Fixed!

I've configured your VS Code environment for proper C++ debugging. Here's what changed:

### Fixed Issues

1. ✅ **launch.json** - Corrected debugger configuration (removed conflicting types)
2. ✅ **tasks.json** - Added `-O0` flag for better debugging (no optimization)
3. ✅ **Added helpful flags** - `-Wall`, `-Wextra`, `-std=c++17` for better error detection
4. 🐛 **Fixed bug in area_calculator.cpp** - Resolved an issue with the area calculation example code

### Your Debugger Options

You now have **two working configurations**:

1. **(lldb) Launch - Current File** ← **Recommended** (Native LLDB)
2. **(cppdbg) Launch - Current File** (Microsoft's cross-platform adapter)

Both will work on your macOS system. Use option 1 for best performance.

---

## 🚀 Test Your Debugging Setup Now

### Step 1: Open Test File

Open `debug_test.cpp` in VS Code

### Step 2: Set Breakpoints

Click in the **gutter** (left of line numbers) on these lines:

- **Line 38**: `int sum = x + y;`
- **Line 43**: `int result = factorial(5);`

Red dots should appear.

### Step 3: Start Debugging

Press **F5** (or click Run → Start Debugging)

### Step 4: Verify It Works

You should see:

- ✅ Program builds automatically
- ✅ Debugger pauses at line 38
- ✅ Yellow arrow on current line
- ✅ Variables panel (left) shows `x = 10`, `y = 20`
- ✅ Call Stack panel shows `main()`

### Step 5: Practice Controls

- **F10** (Step Over) - Move to next line
- **F11** (Step Into) - Enter functions
- **F5** (Continue) - Run to next breakpoint
- **Shift+F5** (Stop) - End debugging

---

## 📝 Debug Your Assignments

### For area_calculator.cpp

1. Open the file
2. Set breakpoint on line 34: `double rect_area = rectangle_area(width, height);`
3. Press F5
4. Enter width: `10`
5. Enter height: `20`
6. At breakpoint:
   - Check `width` = 10
   - Check `height` = 20
   - Press F11 to **step into** `rectangle_area()`
   - Watch as it validates inputs and calculates area

### For temperature_converter.cpp

1. Set breakpoint before calculation
2. Press F5, enter temperature
3. Step through conversion formula
4. Verify calculation is correct

---

## 🔍 Essential Debugging Features

### 1. Inspect Variables

**Three ways:**

- Hover mouse over variable in code
- Look at **Variables** panel (left sidebar)
- Type in **Debug Console**: `print x` or just `x`

### 2. Watch Expressions

- Click "+" in **Watch** panel
- Add: `width * height` or `x + y`
- Updates automatically as you step

### 3. Call Stack

Shows function call hierarchy:

```
main() → line 43
factorial(5) → line 10
factorial(4) → line 10
```

Click any line to jump to that function's context.

### 4. Conditional Breakpoints

Right-click breakpoint → **Edit Breakpoint**

- Expression: `width > 100` (breaks only when true)
- Hit count: `= 5` (breaks on 5th hit)

---

## 🐛 Troubleshooting

### Breakpoints are gray/hollow

**Cause:** Program wasn't compiled with debug symbols

**Fix:** Rebuild by pressing `Cmd+Shift+B` or:

```bash
clang++ -g -O0 program.cpp -o program
```

### "Cannot find task"

**Cause:** Task name mismatch

**Fix:** Check `preLaunchTask` in launch.json matches `label` in tasks.json

### Variables show `<optimized out>`

**Cause:** Optimization flags present

**Fix:** Already fixed! Your tasks.json now has `-O0`

### Debugger doesn't launch

**Check:**

1. Extensions installed: `code --list-extensions | grep lldb`
2. Executable exists after building
3. VS Code Output panel (View → Output → select "LLDB")

---

## 📚 Full Documentation

For comprehensive information, see **DEBUGGING_GUIDE.md**:

- Complete explanation of all configuration options
- Platform comparison (macOS vs Linux)
- Advanced debugging techniques
- Detailed troubleshooting guide

---

## 🎯 Learning Objectives

As you progress through the curriculum, use debugging to:

**Week 1-2:** Watch variables change, understand control flow   
**Week 3:** Step into/out of functions, observe call stack  
**Week 4:** Inspect arrays element by element   
**Week 5-6:** Watch object construction/destruction, memory management  
**Week 7-8:** Inspect containers (vectors, maps), understand iterators

**Remember:** Debugging is more efficient than `std::cout` debugging!

---

## Quick Reference Card

| Action            | Key       | Use When                  |
| ----------------- | --------- | ------------------------- |
| Start Debug       | F5        | Launch program            |
| Step Over         | F10       | Execute current line      |
| Step Into         | F11       | Enter function            |
| Step Out          | Shift+F11 | Exit function             |
| Continue          | F5        | Resume to next breakpoint |
| Stop              | Shift+F5  | End debugging             |
| Toggle Breakpoint | F9        | Add/remove breakpoint     |

---

## ✨ Your Setup is Ready!

Everything is configured correctly. Press **F5** on `debug_test.cpp` to verify debugging works!

**Questions?** Check DEBUGGING_GUIDE.md for detailed explanations.

Happy debugging! 🐛🔧
