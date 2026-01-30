# C++ Debugging Guide for VS Code

## Critical Configuration Fields Explained

### launch.json

```json
{
  "name": "(lldb) Launch - Current File", // Display name in debug dropdown
  "type": "lldb", // CRITICAL: Debugger type
  "request": "launch", // "launch" = start program, "attach" = connect to running process
  "program": "${fileDirname}/${fileBasenameNoExtension}", // Path to executable
  "args": [], // Command-line arguments to pass to program
  "cwd": "${fileDirname}", // Working directory
  "preLaunchTask": "C/C++: clang++ build active file", // Build before debugging
  "stopOnEntry": false, // If true, pauses at main() entry
  "externalConsole": false, // Use VS Code integrated terminal
  "terminal": "integrated" // Where program output appears
}
```

### Debugger Types

| Extension             | Type     | Debugger         | Use When                          |
| --------------------- | -------- | ---------------- | --------------------------------- |
| `vadimcn.vscode-lldb` | `lldb`   | Native LLDB      | macOS, Modern setup               |
| `ms-vscode.cpptools`  | `cppdbg` | LLDB/GDB wrapper | Cross-platform, Microsoft adapter |

**Your System:** macOS with LLVM → Use `"type": "lldb"` (recommended)

### VS Code Variables

| Variable                     | Expands To                 | Example                |
| ---------------------------- | -------------------------- | ---------------------- |
| `${file}`                    | Current file full path     | `/path/to/program.cpp` |
| `${fileBasenameNoExtension}` | Filename without extension | `program`              |
| `${fileDirname}`             | Directory of current file  | `/path/to`             |
| `${workspaceFolder}`         | Root workspace folder      | `/path/to/project`     |

---

## Step-by-Step Debugging Workflow

### 1. Open Your C++ File

Open `debug_test.cpp` in VS Code.

### 2. Set Breakpoints

Click in the gutter (left of line numbers) to set breakpoints:

- Line 7: Inside `factorial()` function
- Line 38: Before printing sum
- Line 43: Before calling `factorial()`
- Line 54: Inside conditional

**Breakpoints should appear as red dots.**

### 3. Start Debugging

**Method 1:** Press `F5`  
**Method 2:** Click "Run and Debug" → Select "(lldb) Launch - Current File"  
**Method 3:** Menu: Run → Start Debugging

### 4. What Should Happen

1. ✅ Program builds automatically (you'll see compiler output)
2. ✅ Debugger launches and stops at first breakpoint
3. ✅ Yellow arrow appears on current line
4. ✅ Variables panel shows local variables
5. ✅ Call stack panel shows function hierarchy

### 5. Debugging Controls

| Key             | Action    | What It Does                                |
| --------------- | --------- | ------------------------------------------- |
| `F5`            | Continue  | Run until next breakpoint or end            |
| `F10`           | Step Over | Execute current line, don't enter functions |
| `F11`           | Step Into | Enter function calls                        |
| `Shift+F11`     | Step Out  | Exit current function                       |
| `Ctrl+Shift+F5` | Restart   | Stop and restart debugging                  |
| `Shift+F5`      | Stop      | End debugging session                       |

### 6. Inspect Variables

**Three Methods:**

1. **Variables Panel** (left sidebar)
   - Shows all local variables automatically
   - Expand objects to see members

2. **Hover Over Variables**
   - Hover mouse over any variable in code
   - Shows current value

3. **Debug Console**
   - Type variable names directly
   - Evaluate expressions: `x + y`, `numbers.size()`

### 7. Watch Expressions

- Click "+" in Watch panel
- Add expressions to monitor: `x * 2`, `numbers[0]`
- Updates automatically as you step

---

## Testing Your Debugging Setup

### Minimal Test Program

1. **Open** `debug_test.cpp`
2. **Set breakpoint** on line 38 (the `int sum = x + y;` line)
3. **Press F5** to start debugging
4. **Verify:**
   - ✅ Program builds without errors
   - ✅ Debugger stops at line 38
   - ✅ Variables panel shows `x = 10`, `y = 20`
   - ✅ `sum` is either 0 or uninitialized (hasn't been assigned yet)
5. **Press F10** (Step Over)
6. **Verify:**
   - ✅ Yellow arrow moves to next line
   - ✅ `sum` now shows `30`

**If all checks pass: ✅ Your debugging setup is working correctly!**

---

## Troubleshooting Checklist

### Problem: Breakpoints are gray/hollow (not red)

**Cause:** Debug symbols missing or source file path mismatch

**Fixes:**

1. Verify compilation includes `-g`:
   ```bash
   clang++ -g -O0 program.cpp -o program
   ```
2. Check `file program` shows "with debug_info"
3. Rebuild: `Cmd+Shift+B` or manually compile
4. Clean and rebuild:
   ```bash
   rm program
   clang++ -g -O0 program.cpp -o program
   ```

### Problem: Debugger says "Unable to open 'file.cpp'"

**Cause:** Executable path is wrong or doesn't exist

**Fixes:**

1. Check `program` path in launch.json matches actual executable
2. Verify executable exists: `ls -la ${fileDirname}/${fileBasenameNoExtension}`
3. Try absolute path: `"program": "/full/path/to/program"`

### Problem: Variables show `<optimized out>`

**Cause:** Compiler optimization removed or renamed variables

**Fixes:**

1. Add `-O0` flag to disable optimization
2. Remove `-O2`, `-O3`, `-Ofast` flags
3. Rebuild program

### Problem: Debugger doesn't stop at breakpoints

**Causes & Fixes:**

1. **Missing `-g` flag**

   ```bash
   # Check
   file program  # Should show debug_info

   # Fix
   clang++ -g -O0 program.cpp -o program
   ```

2. **Wrong executable being debugged**
   - Check `launch.json` program path
   - Verify preLaunchTask built successfully
   - Look for build errors in Terminal

3. **Code not executed**
   - Breakpoint is in unreachable code
   - Condition prevents execution
   - Try breakpoint in `main()` first

### Problem: "Cannot find task 'C/C++: clang++ build active file'"

**Cause:** `preLaunchTask` name doesn't match `tasks.json` label

**Fix:**

```json
// launch.json
"preLaunchTask": "C/C++: clang++ build active file"

// tasks.json - MUST match exactly
"label": "C/C++: clang++ build active file"
```

### Problem: Extension not working

**Fixes:**

1. Verify extension installed:
   ```bash
   code --list-extensions | grep -E "(lldb|cpptools)"
   ```
2. Reload VS Code: `Cmd+Shift+P` → "Reload Window"
3. Check extension enabled: Extensions panel → search for "lldb" or "C++"

---

## Advanced Debugging Features

### Conditional Breakpoints

**Right-click breakpoint → Edit Breakpoint**

- **Expression:** Break when condition is true

  ```cpp
  i == 5         // Break when i equals 5
  x > 100        // Break when x exceeds 100
  ```

- **Hit Count:** Break after N hits
  ```
  = 10           // Break on 10th hit
  % 5            // Break every 5th hit
  ```

### Logpoints (Breakpoints that don't stop)

**Right-click gutter → Add Logpoint**

```cpp
Value of x: {x}, y: {y}    // Prints without stopping
```

Useful for tracing without interrupting flow.

### Data Breakpoints (watchpoints)

**Right-click variable in Variables panel → Break on Value Change**

Breaks whenever variable is modified.

### Call Stack Navigation

**Call Stack panel shows:**

```
main() → line 43
factorial(5) → line 7
factorial(4) → line 7
factorial(3) → line 7
```

Click any frame to see that function's variables and code.

---

## Comparison: GCC/GDB vs Clang/LLDB

### Linux (GCC + GDB)

**tasks.json:**

```json
{
  "label": "g++ build",
  "command": "/usr/bin/g++",
  "args": [
    "-g",
    "-O0",
    "-Wall",
    "-std=c++17",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}"
  ]
}
```

**launch.json:**

```json
{
  "name": "(gdb) Launch",
  "type": "cppdbg",
  "request": "launch",
  "program": "${fileDirname}/${fileBasenameNoExtension}",
  "MIMode": "gdb",
  "preLaunchTask": "g++ build"
}
```

### macOS (Clang + LLDB) - Your Setup

**tasks.json:**

```json
{
  "label": "clang++ build",
  "command": "/opt/homebrew/opt/llvm/bin/clang++",
  "args": [
    "-g",
    "-O0",
    "-Wall",
    "-std=c++17",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}"
  ]
}
```

**launch.json (Option 1 - Recommended):**

```json
{
  "name": "(lldb) Launch",
  "type": "lldb",
  "request": "launch",
  "program": "${fileDirname}/${fileBasenameNoExtension}",
  "preLaunchTask": "clang++ build"
}
```

**launch.json (Option 2 - Cross-platform):**

```json
{
  "name": "(cppdbg) Launch",
  "type": "cppdbg",
  "request": "launch",
  "program": "${fileDirname}/${fileBasenameNoExtension}",
  "MIMode": "lldb",
  "preLaunchTask": "clang++ build"
}
```

---

## Verification Commands

### Confirm Debugger Configuration

```bash
# Check which debugger VS Code will use
cat .vscode/launch.json | grep -E '"type"|"MIMode"'

# Check compilation flags
cat .vscode/tasks.json | grep -A 10 '"args"'
```

### Verify Build Output

```bash
# Build manually to see actual command
cd /path/to/your/file
/opt/homebrew/opt/llvm/bin/clang++ -g -O0 -Wall debug_test.cpp -o debug_test

# Verify debug symbols present
file debug_test
nm debug_test | head -20

# Verify binary is recent
ls -lh debug_test
```

### Test Debugger Directly

```bash
# Test LLDB can load your program
lldb ./debug_test
# In LLDB:
# (lldb) b main           # Set breakpoint in main
# (lldb) run              # Run program
# (lldb) p x              # Print variable x
# (lldb) quit
```

---

## Common Debugging Scenarios

### Scenario 1: Segmentation Fault

```cpp
int* ptr = nullptr;
*ptr = 42;  // Crash here
```

**Debugging:**

1. Run without breakpoints (will crash)
2. Debugger stops at crash location
3. Check Call Stack to see how you got there
4. Inspect variables to find null pointer

### Scenario 2: Wrong Output

```cpp
int average = sum / count;  // Integer division!
```

**Debugging:**

1. Set breakpoint before calculation
2. Step through line-by-line (F10)
3. Watch variables change
4. Identify incorrect calculation

### Scenario 3: Infinite Loop

```cpp
int i = 0;
while (i < 10) {
    // Forgot i++
}
```

**Debugging:**

1. Set breakpoint inside loop
2. Press F5 (continue) several times
3. Watch variables - notice `i` never changes
4. Identify missing increment

### Scenario 4: Off-by-One Error

```cpp
for (int i = 0; i <= vec.size(); ++i) {  // Should be <, not <=
    std::cout << vec[i];
}
```

**Debugging:**

1. Set breakpoint in loop
2. Add watch expression: `i`, `vec.size()`, `vec[i]`
3. Step through iterations
4. Notice `i == vec.size()` causes crash

---

## Best Practices

### Do's ✅

- Always compile with `-g` for debugging
- Use `-O0` to disable optimization during development
- Set breakpoints strategically (function entries, before complex logic)
- Use Step Over (F10) to trace logic flow
- Use Step Into (F11) only when you need to debug a function
- Add watch expressions for complex calculations
- Check Call Stack to understand execution flow

### Don'ts ❌

- Don't debug optimized code (`-O2`, `-O3`)
- Don't set too many breakpoints (slows debugging)
- Don't use `printf` debugging when debugger works (less efficient)
- Don't ignore compiler warnings (fix them first)
- Don't assume variables have default values (check initialization)

---

## Understanding Debug Symbols

### What Are Debug Symbols?

Debug symbols map compiled machine code back to source code:

- Line numbers
- Variable names
- Function names
- Type information

### With Debug Symbols (-g)

```
Machine Address    Source Location
0x1000            → program.cpp:15 (int x = 10;)
0x1008            → program.cpp:16 (int y = 20;)
```

### Without Debug Symbols

```
Machine Address    ???
0x1000            → Unknown
0x1008            → Unknown
```

### Checking Debug Symbols

```bash
# Method 1: file command
file program
# Good: "with debug_info, not stripped"
# Bad: "stripped"

# Method 2: objdump (detailed)
objdump -h program | grep debug
# Should see sections: .debug_info, .debug_line, etc.

# Method 3: nm (symbol table)
nm program | grep -i debug
# Should show debug-related symbols

# Method 4: Size comparison
clang++ program.cpp -o program_nodebug           # ~20 KB
clang++ -g program.cpp -o program_debug          # ~200 KB
# Debug version is much larger
```

---

## Quick Reference

### Essential Keyboard Shortcuts

| Action            | macOS       | Description                |
| ----------------- | ----------- | -------------------------- |
| Start Debugging   | `F5`        | Build and launch debugger  |
| Step Over         | `F10`       | Execute current line       |
| Step Into         | `F11`       | Enter function             |
| Step Out          | `Shift+F11` | Exit function              |
| Continue          | `F5`        | Resume execution           |
| Stop              | `Shift+F5`  | End debugging              |
| Toggle Breakpoint | `F9`        | Add/remove breakpoint      |
| Run to Cursor     | `⌘F10`      | Execute to cursor position |

### Essential Compiler Flags

```bash
# Minimum for debugging
clang++ -g program.cpp -o program

# Recommended for debugging
clang++ -g -O0 -Wall -Wextra -std=c++17 program.cpp -o program

# Production build (no debugging)
clang++ -O2 -DNDEBUG program.cpp -o program
```

### Quick Diagnosis

```bash
# Is my program compiled with debug symbols?
file program | grep -i debug

# Which compiler am I using?
which clang++
clang++ --version

# Which debugger am I using?
which lldb
lldb --version

# Are my VS Code extensions installed?
code --list-extensions | grep -E "cpptools|lldb"

# Does my executable exist?
ls -lh ${fileDirname}/${fileBasenameNoExtension}
```

---

## Next Steps

1. ✅ **Test with** `debug_test.cpp` (verify all breakpoints work)
2. ✅ **Practice stepping** through code (F10, F11)
3. ✅ **Inspect variables** (hover, Variables panel, Debug Console)
4. ✅ **Use Call Stack** to understand function calls
5. ✅ **Try conditional breakpoints** for specific scenarios
6. ✅ **Debug your actual assignments** with confidence

**Remember:** Debugging is a skill that improves with practice. Start simple, experiment with controls, and gradually explore advanced features.

---

## Getting Help

If debugging still doesn't work:

1. **Collect diagnostic information:**

   ```bash
   clang++ --version
   lldb --version
   code --list-extensions | grep -E "cpptools|lldb"
   cat .vscode/launch.json
   cat .vscode/tasks.json
   ```

2. **Check VS Code Output:**
   - View → Output
   - Select "C/C++" or "LLDB" from dropdown
   - Look for error messages

3. **Enable verbose logging:**
   - Add to launch.json: `"logging": { "engineLogging": true }`
   - Check Debug Console for detailed logs

4. **Test outside VS Code:**
   ```bash
   clang++ -g -O0 program.cpp -o program
   lldb program
   # (lldb) b main
   # (lldb) run
   ```
   If this works but VS Code doesn't, it's a configuration issue.

Good luck with your C++ learning journey! 🚀
